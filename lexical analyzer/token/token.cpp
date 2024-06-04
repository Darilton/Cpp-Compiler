#include <string>
#include "token.h"


token::token(int token_type, int line, std::string lexeme){
    this->lexeme = lexeme;
    this->line = line;
    this->token_type = token_type;
}

std::string token::toString(){
    return std::to_string(token_type) + " - " + lexeme + " - " + std::to_string(line);
}