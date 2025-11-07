/*
  flo.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 31-MAy-2024
    
  Command line driver for Flo.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "processor.hpp"
#include "functions.hpp"
#include "dict.hpp"

#include <iostream>
#include <boost/program_options.hpp> 
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <fstream>

namespace po = boost::program_options;

using namespace std;
using namespace vops::flo;
using namespace vops;
namespace fs = std::filesystem;

int main(int argc, char *argv[]) {

  string logLevel;
  string transform;
  string scenario;
  
  po::options_description desc("Allowed options");
  desc.add_options()
    ("transform", po::value<string>(&transform)->required(), "The transform JSON file")
    ("scenario", po::value<string>(&scenario), "The name of the scenario to run")
    ("logLevel", po::value<string>(&logLevel)->default_value("info"), "Logging level [trace, debug, warn, info].")
    ("help", "produce help message")
    ;
  po::positional_options_description p;
  p.add("transform", 1);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).
          options(desc).positional(p).run(), vm);
          
  try {
    po::notify(vm);   
  }
  catch (boost::program_options::required_option &ex) {
    cout << ex.what() << endl;
    cout << desc << endl;
    return 1;
  }

  if (logLevel == "trace") {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
  }
  else if (logLevel == "debug") {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::debug);
  }
  else if (logLevel == "warn") {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::warning);
  }
  else {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
  }

  boost::log::formatter logFmt =
         boost::log::expressions::format("%1%\tFlo\t[%2%]\t%3%")
        %  boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f") 
        %  boost::log::expressions::attr< boost::log::trivial::severity_level>("Severity")
        %  boost::log::expressions::smessage;
  boost::log::add_common_attributes();
  boost::log::add_console_log(clog)->set_formatter(logFmt);

  if (vm.count("help")) {
    cout << desc << endl;
    return 1;
  }
 
  fs::path transformp = transform;

  ifstream transforms(transform);
  if (!transforms) {
    cerr << transform << " not found" << endl;
    return 1;
  }
  
  // use the file format of the transformer to determine the format
  // of the file we are transforming.
  
  auto trg = Dict::parseStream(transforms, transformp.extension());
  if (!trg) {
    cerr << "could not parse from " << transform << " as " << transformp.extension() << endl;
    return 1;
  }
  
  auto tr = Dict::getObject(*trg);
  if (!tr) {
    cerr << "transform is not an object" << endl;
    return 1;
  }

  Functions f(*tr);
  Processor process(f);
  
  if (vm.count("scenario")) {
    auto result = process.transform(*tr, scenario);
    if (result) {
      cout << Dict::toString(*result, transformp.extension()) << endl;
    }
    return 0;
  }
 
  auto in = Dict::parseStream(std::cin, transformp.extension());
  if (!in) {
    cerr << "could not parse" << endl;
    return 1;
  }
  
  auto result = process.transform(*tr, *in);
  if (result) {
    cout << Dict::toString(*result, transformp.extension()) << endl;
  }
  
  return 0;
  
}
