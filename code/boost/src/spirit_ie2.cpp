/*=============================================================================
    Copyright (c) 2002-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
///////////////////////////////////////////////////////////////////////////////
//
//  A parser for arbitrary tuples. This example presents a parser
//  for an employee structure.
//
//  [ JDG May 9, 2007 ]
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>

#include <iostream>
#include <string>
#include <complex>
#include <fstream>

namespace client
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    ///////////////////////////////////////////////////////////////////////////
    //  Our employee struct
    ///////////////////////////////////////////////////////////////////////////
    //[tutorial_employee_struct
    struct employee
    {
        double Tick;
        double Cycle;
        std::string PacketType;
        int OpGroup;
        int Opcode;
        std::string Address;
        int CQid;
        int UQid;
        std::string Rest;
    };
    //]
}

// We need to tell fusion about our employee struct
// to make it a first-class fusion citizen. This has to
// be in global scope.

//[tutorial_employee_adapt_struct
BOOST_FUSION_ADAPT_STRUCT(
    client::employee,
    (double, Tick)
    (double, Cycle)
    (std::string, PacketType)
    (int, OpGroup)
    (int, Opcode)
    (std::string, Address)
    (int, CQid)
    (int, UQid)
    (std::string, Rest)
)
//]

namespace client
{
    ///////////////////////////////////////////////////////////////////////////////
    //  Our employee parser
    ///////////////////////////////////////////////////////////////////////////////
    //[tutorial_employee_parser
    template <typename Iterator>
    struct employee_parser : qi::grammar<Iterator, employee(), ascii::space_type>
    {
        employee_parser() : employee_parser::base_type(start)
        {
            using qi::int_;
            using qi::lit;
            using qi::double_;
            using qi::lexeme;
            using ascii::char_;

            quoted_string %= lexeme['"' >> +(char_ - '"') >> '"'];

            start %=
                lit("employee")
                >> double_ >> ','
                >> double_ >> ','
                >> lit("C2U_Request") >> ','
                >> int_ >> ','
                >> int_ >> ','
                >> +(char_ - ',') >> ','
                >> int_ >> ','
                >> int_ >> ','
                >> +(char_)
                ;
        }

        qi::rule<Iterator, std::string(), ascii::space_type> quoted_string;
        qi::rule<Iterator, employee(), ascii::space_type> start;
    };
    //]
}

////////////////////////////////////////////////////////////////////////////
//  Main program
////////////////////////////////////////////////////////////////////////////
int
main()
{
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "\t\tA exmple parser for Spirit...\n\n";
    std::cout << "/////////////////////////////////////////////////////////\n\n";


    using boost::spirit::ascii::space;
    typedef std::string::const_iterator iterator_type;
    typedef client::employee_parser<iterator_type> employee_parser;

    employee_parser g; // Our grammar

    std::ifstream infile("/nfs/site/disks/fm_vt_0073/work/dmedin2/home/dmv_home/code/boost/logs/log.txt");
    //std::ifstream infile("/nfs/site/disks/fm_vt_0073/work/dmedin2/FXR_ordering_logs/idi_tracker_hang34.log");
    std::string str;
    while (std::getline(infile, str))
    {
        client::employee emp;
        std::string::const_iterator iter = str.begin();
        std::string::const_iterator end = str.end();
        bool r = phrase_parse(iter, end, g, space, emp);

        if (r && iter == end)
        {
            std::cout << boost::fusion::tuple_open('[');
            std::cout << boost::fusion::tuple_close(']');
            std::cout << boost::fusion::tuple_delimiter(", ");

            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << "got: " << boost::fusion::as_vector(emp) << std::endl;
            std::cout << "\n-------------------------\n";
        }
        else
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "-------------------------\n";
        }
    }

    std::cout << "Bye... :-) \n\n";
    return 0;
}
