#ifndef TOKEN_H
#define TOKEN_H
#include <string>

class token{
    public: 
        int token_type;
        int line;
        std::string lexeme;

        token(int token_type, int line, std::string lexeme);

        std::string toString();
};
#endif