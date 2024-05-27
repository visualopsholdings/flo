/*
  processor.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "processor.hpp"

#include <boost/log/trivial.hpp>

Processor::Processor(istream &infile) {
  
  _json = boost::json::parse(infile);
  
}

json Processor::transform(istream &transform) {

  json t = boost::json::parse(transform);
	BOOST_LOG_TRIVIAL(trace) << "transforming with " << t;
  
  return _json;
}

void Processor::pretty_print( ostream& os, json const& jv, string* indent ) {

    string indent_;
    if(! indent)
        indent = &indent_;
    switch(jv.kind())
    {
    case boost::json::kind::object:
    {
        os << "{\n";
        indent->append(4, ' ');
        auto const& obj = jv.get_object();
        if(! obj.empty())
        {
            auto it = obj.begin();
            for(;;)
            {
                os << *indent << boost::json::serialize(it->key()) << " : ";
                pretty_print(os, it->value(), indent);
                if(++it == obj.end())
                    break;
                os << ",\n";
            }
        }
        os << "\n";
        indent->resize(indent->size() - 4);
        os << *indent << "}";
        break;
    }

    case boost::json::kind::array:
    {
        os << "[\n";
        indent->append(4, ' ');
        auto const& arr = jv.get_array();
        if(! arr.empty())
        {
            auto it = arr.begin();
            for(;;)
            {
                os << *indent;
                pretty_print( os, *it, indent);
                if(++it == arr.end())
                    break;
                os << ",\n";
            }
        }
        os << "\n";
        indent->resize(indent->size() - 4);
        os << *indent << "]";
        break;
    }

    case boost::json::kind::string:
    {
        os << boost::json::serialize(jv.get_string());
        break;
    }

    case boost::json::kind::uint64:
    case boost::json::kind::int64:
    case boost::json::kind::double_:
        os << jv;
        break;

    case boost::json::kind::bool_:
        if(jv.get_bool())
            os << "true";
        else
            os << "false";
        break;

    case boost::json::kind::null:
        os << "null";
        break;
    }

    if(indent->empty())
        os << "\n";
}