#include <iostream>
#include <string>
#include <cctype>
#include <list>
#include "lex.h"
#include "../file/file.h"
#include "token/token.h"

#define IS_UNDERSCORE(ch) (ch == '_')
#define CURRENT_LEXEME source.substr(start, current - start)

lex::lex(string source){
    int i = CHAR;
    for(string a: getFileLines("docs/keywords.txt")){
        this->keywords[a] = i++;
    }
    this->source = source;
}

bool lex::isAtEnd(){
    return current >= source.length();
}

list<token> lex::scanTokens(){
    while(!isAtEnd()){
        //beggining of the next lexeme
        start = current;
        scanToken();
    }

    return this->tokens;
}

void lex::scanToken(){
    int ch = advance();
    
    switch(ch){
        case '(': addToken("(", LEFT_PAREN); break;
        case '/': match('/')? onelineComment() : match('*')? multilineComment() : addToken("/", DIV); 
                  break;
        case '\'': scanChar(); break;
        case ')': addToken(")", RIGHT_PAREN); break;
        case '|': match('|')? addToken("||", OR) : addToken("|", BITOR);
        case '{': addToken("{", LEFT_BRACE); break;
        case '}': addToken("}", RIGHT_BRACE); break;
        case '[': addToken("[", LEFT_BRACKET); break;
        case ']': addToken("]", RIGHT_BRACKET); break;
        case ';': addToken(";", SEMI); break;
        case ':': addToken(":", COLON); break;
        case ',': addToken(",", COMMA); break;
        case '.': addToken(".", DOT); break;
        case '#': addToken("#", HASH); break;
        case '=': match('=')? addToken("==", EQUALS): addToken("=", ASSIGN); break;
        case '>': match('=') ? addToken(">=", GREATER_EQUALS) : addToken(">", GREATER); break;
        case '<': addToken("<", LESS); break;
        case '!': addToken("!", BANG); break;
        case '-': addToken("-", MINUS); break;
        case '+': addToken("+", PLUS); break;
        case '*': addToken("*", TIMES); break;
        case '&': addToken("&", AMPER); break;
        case '%': addToken("%", MOD); break;
        case '"': while(peek() != '"'){
                    if(peek() == EOF){
                        string error = "Unterminated string at line ";
                        error += to_string(line);
                        addError(error);
                        return;
                    }
                    advance();
                  } 
                  advance();
                  addToken(CURRENT_LEXEME, STRING); break;
        case ' ': 
        case '\t': break;   
        case '\n': line++; break;
        default: if(isalpha(ch) || IS_UNDERSCORE(ch)) scanId();
                 else if(isdigit(ch)) scanNumber();
                 else {
                    string error = "Unexpected character \"";
                    error += ch;
                    error +=  "\" at line ";
                    error += to_string(line);
                    addError(error);
                 }
    }
}

void lex::scanChar(){
    advance();
    if(peek() != '\''){
        string error = "Malformed characther literal at line ";
        error += to_string(line);
        addError(error);
        char ch = advance();
        while(ch != '\'' && ch != EOF && ch != '\n')
            ch = advance();
        advance();
        return;
    }
    advance();
    addToken(CURRENT_LEXEME, CHAR);
}

void lex::onelineComment(){
    while(peek() != '\n' && peek() != '\0')
        advance();
}

void lex::multilineComment(){
    while(peek() != '\0' && peek() != '*' && peekTwice() != EOF && peekTwice() != '/'){
        if(advance() == '\n')
            line++;
    }

    if(peek() == '\0' || peekTwice() == EOF){
        string error = "Non Terminated multiline comment at line ";
        error += to_string(line);
        addError(error);
        return;
    }

    advance();
    advance();
}

void lex::scanId(){
    while(isalnum(peek()))
        advance();

    map<string,int>::iterator it = this->keywords.find(CURRENT_LEXEME);
    if(it != this->keywords.end())
        addToken(CURRENT_LEXEME, this->keywords[CURRENT_LEXEME]);
    else
        addToken(CURRENT_LEXEME, ID);

}

void lex::scanRealNumber(){
    while(isdigit(peek()))
        advance();

    addToken(CURRENT_LEXEME, NUM);
}

void lex::scanNumber(){
    while(true){
        if(peek() == '.'){
            advance();
            scanRealNumber();
            return;
        }

        if(isdigit(peek()))
            advance();
        else
            break;
    }
    
    addToken(CURRENT_LEXEME, NUM);
}

char lex::advance(){
    return source[current++];
}

char lex::peek(){
    if(isAtEnd())
        return EOF;

    return source[current];
}

char lex::peekTwice(){
    if(isAtEnd())
        return EOF;

    return source[current + 1];
}

void lex::addError(string error){
    this->errors.push_back(error);
}

void lex::addToken(string lexeme, int token_type){
    token newToken(token_type, this->line, lexeme);
    this->tokens.push_back(newToken);
}

bool lex::match(char ch){
    if(isAtEnd()) return false;
    if(source[current] != ch) return false;

    current += 1;
    return true;
}