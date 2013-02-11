/* 
 * File:   syntaxtree.h
 * Author: craigtaub
 *
 * Created on May 18, 2012, 11:52 AM
 */

#ifndef SYNTAXTREE_H
#define	SYNTAXTREE_H

#include<string>
using std::string;


class syntaxtree {
public:
    syntaxtree();
    syntaxtree(const syntaxtree& orig);
    virtual ~syntaxtree();
    void addBranch(string);
private:

};


#endif	/* SYNTAXTREE_H */



/* +------------------------------------------------------------------------------+ */


//int tree();


