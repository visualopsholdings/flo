/*
  processor.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_processor
#define H_processor

#include <istream>
#include <boost/json.hpp>

using namespace std;
using json = boost::json::value;

class Functions;

class Processor
{
public:
  Processor(istream &infile, Functions &functions);
  Processor(json &json, Functions &functions);
  
  optional<json> transform(istream &transform);
  optional<json> transform(json &jt);
 
  static void pretty_print( ostream& os, json const& jv, string* indent = 0 );
 
private:
  Functions &_functions;
  json _json;
  
};

#endif // H_processor
