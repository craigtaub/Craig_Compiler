/* 
 * File:   main.cpp
 * Author: craigtaub
 *
 * Created on May 9, 2012, 7:23 PM
 */

#include <sstream>
#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;
using std::getline;

#include <vector>
using std::vector; 

#include "lexer.h"
#include "parser.h"

using namespace std;

int main()
{
        /* declare vectors */
        vector<string> tokens (0);
        vector<string>::iterator token;
        
        /* lex: */
        tokens = initialise_lex(tokens, token); //lex into tokens
        reverse(tokens.begin(),tokens.end()); //reverse elements order
        
        /* parse */
        initialise_parser(tokens, token);
        
	return 0;
}

/* +------------------------------------------------------------------------------+ */

/*
 * sudo g++ -o fuck main.cpp lexer.cpp parser.cpp branch.cpp syntaxtree.cpp  -I/usr/local/Cellar/boost/1.49.0/lib/ -lboost_regex-mt
 * +need to link to several files for compilation..need to include directory and library file.
 
 * NETBEANS COMPILATION CONFIG:
 * + compiler->include directories => /usr/local/Cellar/boost/1.49.0/lib
 * + linker->libraries/libraries => regex-mt
 * + linker->command line/options => lexer.cpp parser.cpp branch.cpp syntaxtree.cpp
  
 * TRIED:
 * -lboost_regex-mt
 * -lboost_regex
 * -I/opt/local/lib/
 * -L/usr/local/lib/libboost_regex-mt.a
 * -Wl, -L/opt/local/lib/
 * -m32
 * -Wl, -L/opt/local/lib/
 * -L/usr/local/Cellar/boost/1.49.0/include/boost/ 
 * -L/opt/local/include/boost/
 * -L/usr/include -L/usr/include/c++/4.2.1 
 * -L/usr/lib/gcc/i686-apple-darwin10/4.2.1/include
 * -L/usr/local/lib/
 * -Wno-deprecated
 */


/* 
sudo g++ -o main main.cpp
./main < code.crg

fuck the other shit compilers, if my language works, END OF

1) take in character stream
2) lex/convert to token
3) create syntax tree with tokens
4) parse syntax tree
5) convert into native c/c++ or assembly (maybe use opcode)
6) execute commands
7) print output
*/




/* example C++ code */
	/*
	string s;
	cout << "Please enter your first name followed by a newline\n";
	cin >> s;
	cout << "Hello, " << s << '\n';
	*/


/* lex:
    method A (seems right)
    1) take in entire string into var
    2) split var by whitespaces into seperate items
    3) create token by items in STACK
    OR
    method B
    1) take each item/word in seperately and create it into token before taking next char.
    */

/* parser:
    method A:
        1) parse inside lexer line by line
        - cant take line as single command as might have 2 commands on 1 line.
        - not really using end_stmt token
    method B:
        2) after all lexing use pain to pass all tokens into parser
        - just runs on tokens
        - stays sequential in main
        */

/* string stream */
    /* std::string s;
    std::cout << "\n";
    std::getline(std::cin, s); // changed this line
    std::cout << s.c_str(); */


/*
#include <cstdlib>
using namespace std;
int main(int argc, char** argv) {
    return 0;
}=--[
*/