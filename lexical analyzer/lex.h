#ifndef LEX_H
#define LEX_H

#include <string>
#include <list>
#include "token/token.h"

using namespace std;
//Token types
#define LEFT_PAREN 257          // (
#define RIGHT_PAREN 258         // )
#define LEFT_BRACE 259          // {
#define RIGHT_BRACE 269         // }
#define COMMA 270               // ,    
#define SEMI 271                // ;
#define COLON 272               // :
#define DOT 272                 // .
#define HASH 273                // #
#define EQUALS 274              // =
#define GREATER 275             // >
#define LESS 276                // <
#define GREATER_EQUALS 277      // >=
#define LESS_EQUALS 278         // <=
#define BANG 279                // \!
#define MINUS 280               // -
#define PLUS 281                // +
#define TIMES 282               // \*
#define DIV 283                 // /
#define MOD 284                 // %
#define NUM 285                 // decimal or integers
#define ID 286                  // words
#define RIGHT_BRACKET 287       //]
#define LEFT_BRACKET 287        //[
#define STRING 288        //[

class lex{
    public:
       lex(std::string source);
       list<token> scanTokens();
       list<string> errors;
       
    private:
        list<token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
        string source;

        int getColNumber();
        void scanRealNumber();
        void addError(std::string);
        void scanId();
        void scanNumber();
        void scanToken();
        bool isAtEnd();
        char advance();
        char peek();
        bool match(char);
        void addToken(string, int);
};
#endif