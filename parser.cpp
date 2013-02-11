/* 
 * File:   parser.cpp
 * Author: taubc
 * 
 * Created on 16 May 2012, 13:15
 */

#include "syntaxtree.h"
#include "branch.h"

#include <sstream>
#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

#include <vector>
using std::vector;

int initialise_parser(vector<string> tokens, vector<string>::iterator token)
{
        //create new syntaxtree object
        syntaxtree tree; 
        string tokenString;
        
        //foreach token in vector, print
        for (token=tokens.begin(); token<tokens.end(); token++){ 
                //create branch object and add it to tree object
                //if token == 'end_stmt', create new branch
            //http://www.cse.chalmers.se/edu/year/2011/course/TIN321/lectures/proglang-02.html
                branch newBranch(token);
                tokenString = newBranch.returnBranch();
                tree.addBranch(tokenString); 
                //cout << " " << *token << endl;
        }
    
    return 0;
}


/* +------------------------------------------------------------------------------+ */

/*
parser::parser() {
}

parser::parser(const parser& orig) {
}

parser::~parser() {
}
 */

