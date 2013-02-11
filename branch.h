/* 
 * File:   branch.h
 * Author: craigtaub
 *
 * Created on May 18, 2012, 12:03 PM
 */

#ifndef BRANCH_H
#define	BRANCH_H

#include<string>
using std::string;

#include <vector>
using std::vector;

class branch {
public:
    branch(vector<string>::iterator);
    branch(const branch& orig);
    virtual ~branch();
    /*string createBranch(vector<string>::iterator);*/
    string returnBranch();
private:

};

#endif	/* BRANCH_H */

