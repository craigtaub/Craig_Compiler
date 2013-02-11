///functions.h///
#include <map>
#include <string>

#ifndef LEXER_H
#define LEXER_H

#include <vector>
using std::vector; 

using std::string;

vector<string> initialise_lex(vector<string>, vector<string>::iterator);
vector<string> lex(string, vector<string>, vector<string>::iterator);

#endif 

/* +------------------------------------------------------------------------------+ */

/* testing*/
void print(char*);
int increment(int);
int sum(int,int);
void setTokens();
void vectors();
/* end testing */
