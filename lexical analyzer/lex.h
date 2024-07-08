#ifndef LEX_H
#define LEX_H

#include <string>
#include <map>
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
#define EQUALS 274              // ==
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
#define STRING 288              //String literals
#define CHAR 289                // Charachters
#define IF 290                  // if
#define ELSE 291                // else
#define WHILE 292               // while
#define FOR 293                 // for
#define INT 294                 // int
#define DOUBLE 295              // double
#define SHORT 296               // short
#define SWITCH 297              // switch
#define CASE 298                // case
#define RETURN 299              // return
#define ALIGNAS 300
#define ALIGNOF 301
#define AND 302
#define AND_EQ 303
#define ASM 304
#define ATOMIC_CANCEL 305
#define ATOMIC_COMMIT 306
#define ATOMIC_NOEXCEPT 307
#define AUTO 308
#define BIT_AND 309
#define BITOR 310
#define BOOL 311
#define BREAK 312
#define CATCH 313
#define CHAR8_T 314
#define CHAR16_T 315
#define CHAR32_T 316
#define CLASS 317
#define COMPL 318
#define COMCEPT 319
#define FLOAT 320
#define CONST 321
#define CONSTEVAL 322
#define CONSTEXPR 323
#define CONSTINT 324
#define CONST_CAST 325
#define CONTINUE 326
#define CO_WAIT 327
#define CO_RETURN 328
#define CO_YIELD 329
#define DECLTYPE 330
#define DEFAULT 331
#define DELETE 332
#define DO 333
#define DYNAMIC_CAST 334
#define ENUM 335
#define EXPLICIT 336
#define EXPORT 337
#define EXTERN 338
#define FALSE 339
#define FRIEND 340
#define GOTO 341
#define INLINE 342
#define LONG 343
#define MUTABLE 344
#define NAMESPACE 345
#define NEW 346
#define NOT 347
#define NOT_EQ 348
#define NULLPTR 349
#define OPERATOR 350
#define OR 351
#define OR_EQ 352
#define PRIVATE 353
#define PROTECTED 354
#define PUBLIC 355
#define REFLEXPR 356
#define REGISTER 357
#define REINTERPRET_CAST 358
#define REQUIRES 359
#define SIGNED 360
#define SIZEOF 361
#define STATIC 362
#define STATIC_ASSERT 363
#define STATIC_CAST 364
#define STRUCT 365
#define SYNCHRONIZED 366
#define TEMPLATE 367
#define THIS 368
#define THREAD_LOCAL 369
#define THROW 370
#define TRUE 371
#define TRY 372
#define TYPEDEF 373
#define TYPEID 374
#define TYPENAME 375
#define UNION 376
#define UNSIGNED 377
#define USING 378
#define VIRTUAL 379
#define VOID 380
#define VOLATILE 381
#define WCHAR_T 382
#define XOR 383
#define XOR_EQ 384
#define AMPER 385                   // &
#define ASSIGN 386                  // =



class lex{
    public:
       lex(std::string source);
       map<string, int> keywords;
       list<token> scanTokens();
       list<string> errors;
       
    private:
        list<token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
        string source;

        int getColNumber();
        void scanChar();
        void scanRealNumber();
        void addError(std::string);
        void scanId();
        void onelineComment();
        void multilineComment();
        char peekTwice();
        void scanNumber();
        void scanToken();
        bool isAtEnd();
        char advance();
        char peek();
        bool match(char);
        void addToken(string, int);
};
#endif