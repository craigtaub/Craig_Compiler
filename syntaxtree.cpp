/* 
 * File:   syntaxtree.cpp
 * Author: craigtaub
 * 
 * Created on May 18, 2012, 11:52 AM
 */

#include "syntaxtree.h"

#include <sstream>
#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

#include <vector>
using std::vector;

//class syntaxtree
syntaxtree::syntaxtree() {
    //called when created
    cout << "created syntaxtree" << endl;
    
}

syntaxtree::syntaxtree(const syntaxtree& orig) {
}

syntaxtree::~syntaxtree() {
}

//mathod branch
void syntaxtree::addBranch(string token) {
    cout << token << endl;
}


/* +------------------------------------------------------------------------------+ */

/*  
int tree()
{
    return 22;
}
 */ 
  

/*

 */

