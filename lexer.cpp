///lexer.cpp///

#ifndef LEXER_CPP
#define LEXER_CPP

#include <stdlib.h>

#include <boost/regex.hpp>
using namespace boost;

/*input file */
#include <fstream>
using std::ifstream;

#include "lexer.h"
#include <iostream>
#include <map>
#include<string>
using std::string;

//used isntead of array
#include <vector>
using std::vector; 

using namespace std;


vector<string> initialise_lex(vector<string> myvector, vector<string>::iterator it)
{
      	/* file stream */
	ifstream in_file("code.crg");
	//if(in_file.fail()){
    	//	return -1;
	//}
	string input;     
        
        //foreach line
	while(getline(in_file, input)){
    		//cout << input << endl;
		//for each line split by white space            
		istringstream iss(input);
                //foreach word on that line
		do
    		{
        		string sub;
        		iss >> sub;
                        //lex input into token 
                        myvector = lex(sub, myvector, it);
        		//cout << "String: " << sub << "\n" << endl;
    		} while (iss);
	}
        
        return myvector;
        //return 0;  
}

vector<string> lex(string str, vector<string> myvector, vector<string>::iterator it)
{

    map<string, string> m;
    
    m["^\\$\\w+(;?)"] = "VAR"; //value starting $ with possibly ; on end
    m["%"] = "ERROR_TOKEN";
    m["if"] = "IF";
    m["\\("] = "BRACKET_OPEN";
    m["\\)"] = "BRACKET_CLOSE";
    m["\\}else\\{"] = "ELSE";
    m["\\{"] = "SQUARE_BRACKET_OPEN";
    m["\\}"] = "SQUARE_BRACKET_CLOSED";
    
    m["="] = "ASSIGN";
    m["=="] = "IS_EQUAL_TO";
    m["print"] = "PRINT";
    //m["(?'tea')"] = "STRING_SIX"; //kind of worked
    m["\"(.*?)\"(;?)"] = "STRING"; //string in " " and possibly with ; on end
    m["^;$"] = "END_STMT"; //; ,but needs space before it...cant catch if something before.
    //find whitespace. (.*?)
    m["\\s*"] = "NEWLINE_NEWSTMT"; //newline/newstmt
    //m["[^\\s$]"] = "EMPTY_SPACE"; //nearly worked
           
    /* regex lookup using c++ boost/regex libs */
    const string s = str;
    smatch matches;
    map<string, string>::iterator curr,end;
    //iterate through item in associate array m
    for( curr = m.begin(), end = m.end();  curr != end;  curr++ ){
        //set current key as regex e
        regex e(curr->first);
        //for each check if current string matches
        if(regex_match(s, matches, e)){           
            //add item/token to vector
            it = myvector.begin();
            it = myvector.insert ( it , curr->second );
            //token = curr->second...word/char = e/curr->first   
            //cout << curr->second << endl; //-> just token
            //cout << "char caught=>" << s << ": " << e << "/" << curr->first  << " str=" << str << " token=>" << curr->second << endl;
        } 
    }

    //foreach item in vector, print
    //for (it=myvector.begin(); it<myvector.end(); it++){
        //cout << " " << *it << endl;
    //}
    
    return myvector;
    //return 0;
}
#endif 


/* +------------------------------------------------------------------------------+ */


/* testing */
void print(char* input)
{
  cout<<input<<endl;
}
int increment(int a)
{
  return (a+1);
}
int sum(int a, int b)
{
  return (a+b);
}
void vectors()
{
        //Adds a new element at the end of the vector, after its current last element..
        //insert/add new items to its stack  
     
        /* vector ints
        vector<int> myvector (1,11);
        vector<int>::iterator it;
        it = myvector.begin();
        it = myvector.insert ( it , 22 );
        myvector.insert (it,1,33);
        // "it" no longer valid, get a new one:
        it = myvector.begin();
        it = myvector.insert ( it , 44 );
        for (it=myvector.begin(); it<myvector.end(); it++){
            cout << " " << *it << endl;
        }*/
        
        //vector strings
        vector<string> myvector (1,"heero");
        vector<string>::iterator it;
        //vector<string>::const_iterator it; //didnt work
        it = myvector.begin();
        it = myvector.insert ( it , "git" );
        //myvector.insert (it,1,"love"); //not required but works
        // "it" no longer valid, get a new one:
        it = myvector.begin();
        it = myvector.insert ( it , "it" );
        for (it=myvector.begin(); it<myvector.end(); it++){
            cout << " " << *it << endl;
        }

        //boost::array 
        //only handles statically sized arrays (C-style arrays if you will)
        //#include <boost/array.hpp>
        //using boost::array;
        //array billy [40];
}
void setTokens()
{
    map<string, string> m;
    m["Harold"] = "515 Northland Dr NW";
    m["Jackson"] = "515 Northland Dr NW";
    m["Janice"] = "515 Northland Dr NW";
    
   map<string, string>::iterator curr,end;
   for( curr = m.begin(), end = m.end();  curr != end;  curr++ ){
       cout <<  curr->first + " : " + curr->second << endl;
   }
}
/* end testing */



/* 'call functions':
 in main:
        print("hello world!");
        return 0;
    
#sudo g++ functions.cpp  -o fun main.cpp 
 */

// BOOST:
//=>downloaded boost via brew
//added /usr/local/Cellar/boost/1.49.0/lib/ as include inside linker..
//added libboost_regex-mt.a as library item (appears without .a)
//#sudo g++ main.cpp functions.cpp -o fun -I/usr/local/Cellar/boost/1.49.0/lib/ -lboost_regex-mt
//-I/opt/local/include/ => not used anymore (-I and -L the same)



/*
 Regex quick reference
[abc]     A single character: a, b or c
[^abc]     Any single character but a, b, or c
[a-z]     Any single character in the range a-z
[a-zA-Z]     Any single character in the range a-z or A-Z
^     Start of line
$     End of line
\A     Start of string
\z     End of string
.     Any single character
\s     Any whitespace character
\S     Any non-whitespace character
\d     Any digit
\D     Any non-digit
\w     Any word character (letter, number, underscore)
\W     Any non-word character
\b     Any word boundary character
(...)     Capture everything enclosed
(a|b)     a or b
a?     Zero or one of a
a*     Zero or more of a
a+     One or more of a
a{3}     Exactly 3 of a
a{3,}     3 or more of a
a{3,6}     Between 3 and 6 of a
 
  
  
 
/\{([^}]+)\}/

/        - delimiter
\{       - opening literal brace escaped because it is a special character used for quantifiers eg {2,3}
(        - start capturing
[^}]     - character class consisting of
    ^    - not
    }    - a closing brace (no escaping necessary because special characters in a character class are different)
+        - one or more of the character class
)        - end capturing
\}       - the closing literal brace
/        - delimiter
  
 
 */