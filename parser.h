/* 
 * File:   parser.h
 * Author: taubc
 *
 * Created on 16 May 2012, 13:15
 */

#ifndef PARSER_H
#define	PARSER_H

#include <sstream>
#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

#include <vector>
using std::vector; 

int initialise_parser(vector<string> tokens, vector<string>::iterator);



#endif	/* PARSER_H */
        
/* +------------------------------------------------------------------------------+ */


/*
class parser {
public:
    parser();
    parser(const parser& orig);
    virtual ~parser();
private:

};
*/
