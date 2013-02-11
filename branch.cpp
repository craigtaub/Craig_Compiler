/* 
 * File:   branch.cpp
 * Author: craigtaub
 * 
 * Created on May 18, 2012, 12:03 PM
 */

#include "branch.h"

#include<string>
using std::string;

#include <vector>
using std::vector;
//const string tokenString;

string tokenString;

branch::branch(vector<string>::iterator token) {
    /* constructor */
    tokenString = *token;
    
    //return tokenString;
    //got error for returning something from constructor
}

branch::branch(const branch& orig) {
}

branch::~branch() {
}

/*
string branch::createBranch(vector<string>::iterator token){
    string tokenString = *token;
    
    return tokenString;
}
*/

string branch::returnBranch(){
   
    return tokenString;
}