 
 /* process the language grammar rules,
  *    currently just displays a summary of valid rules it parses
  *
  * currently the valid token types are
  *    VAR          the VAR keyword
  *    IDENTIFIER   any alphabetic identifier
  *    ;            the semicolon terminator
  *
  * currently the heirarchy of grammar rules (with script as the top level) are:
  *    script --> vardecl
  *    vardecl --> VAR IDENTIFIER ;
  */


 /****** declarations and C support ******/

%{
#define DEBUGTAG 0
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdbool.h>
int yylex(void);
int yywrap();
int yyerror(char* s);
%}



 /* identify the top level language component */
%start script


 /* every component of the program has the same data type:
  *    node is a struct with five fields
  *       ival - a long, used for integer and intexpr
  *       fval - a double, used for float and floatexpr
  *       str  - a char*, used for string and strexpr
  *       name - a char*, used for the name of identifiers
  *       dtype - an int, used to indicate the current datatype,
  *               0 for unknown, 1 for integer, 2 for float. 3 for string,
  *               4 for boolean    
  */

/*
%union { 
   struct DataNode 
   { 
      long ival, dtype; 
      double fval;
      char str[4096], name[256]; 
      bool bval;
   } node; 
}
*/

%union {
   struct DataNode {
      struct DataNode *parent;
      struct DataNode **children ;
      size_t size;
      size_t capacity;

      long ival, dtype; 
      double fval;
      char str[4096], name[256]; 
      bool bval;
   } node;
}
 /* identify what kind of values can be associated with the language components */

 /* for the token types that have an associated value, identify its type */
%token<struct DataNode> INTEGER REAL IDENTIFIER STRING BOOLEAN PRINT VAR MOD

/* %type<struct DataNode>  */



/* Operator Precedence */ 
%right '='
%left  '+'  '-'
%left  '*'  '/' MOD
%left  '^'  
/*%left UMINUS  */  /* UNARY Minus */ 
/* Parantheses??? */ 


%%
/*
YOURE STILL UNDOING 
STOP UNDOING
THIS IS A SAVE POINT RIGHT HERE
*/
 /****** grammar rules ******/

script: statements
         { 
            #if DEBUGTAG
               printf(" ~RULE~: script--> statement \n"); 
            #endif
         }
      ;

statements:
        statement 
      | statements statement
      ;

statement:
       expression
         { 
            #if DEBUGTAG
               printf(" ~RULE:statement--> expression \n"); 
            #endif
            $<node>$ = $<node>1;
         }
      ;

expression:
        intexpr ';'
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> intexpr ';' \n");    //DEBUG
            #endif
            $<node.dtype>$ = $<node.dtype>1;
            $<node.ival>$ = $<node.ival>1;
         }
      ;

intexpr: INTEGER
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> INTEGER \n");    //DEBUG
            #endif
            $<node.dtype>$ = 1;
            $<node.ival>$ = $<node.ival>1;
            #if DEBUGTAG
               printf("%d is an integer \n",$<node.ival>1);
            #endif
         }
      | '-' intexpr    %prec '*' /*unary negation, same prec a multip */
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> '-' intexpr  prec '*' \n");    //DEBUG
            #endif
            $<node.dtype>$ = 2;
            $<node.ival>$ = - $<node.ival>2;
            #if DEBUGTAG
               printf("negative %d, using unary negation \n",$<node.ival>2);
            #endif
         }
      | intexpr '+' intexpr
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> intexpr + intexpr \n");    //DEBUG
            #endif
            $<node.dtype>$ = 1;
            $<node.ival>$ = $<node.ival>1 + $<node.ival>3;
            #if DEBUGTAG
               printf("%d + %d is %d \n",$<node.ival>1, $<node.ival>3, $<node.ival>$);
            #endif
         }
      | intexpr '*' intexpr
         {
            #if DEBUGTAG
               printf(" ~RULE: intexpr--> intexpr * intexpr \n");    //DEBUG
            #endif
            $<node.dtype>$ = 1;
            $<node.ival>$ = $<node.ival>1 * $<node.ival>3;
            #if DEBUGTAG
               printf("%d * %d is %d \n",$<node.ival>1, $<node.ival>3, $<node.ival>$);
            #endif
         }
      ;

%%

 /****** supporting C to carry out parsing ******/


int main()
{
   printf("Beginning syntax checking:\n\n");
   int result = yyparse();
   printf("\nSyntax checking complete\n\n");
   return result;
}


