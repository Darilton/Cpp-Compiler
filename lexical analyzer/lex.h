#ifndef LEX_H
#define LEX_H

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
#define BANG 279                // !
#define MINUX 280               // -
#define PLUS 281                // +
#define TIMES 282               // *
#define DIV 283                 // /
#define MOD 284                 // %
#define NUM 285                 // decimal or integers
#define ID 286                  // words

void scanToken();

#endif