 
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
#include "dataStructures/Nodes.h"
#include "dataStructures/functions.h"
#define DEBUGTAG 0
//#define YYSTYPE dataNode
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdbool.h>

//#include "dataStructures/functions.c"
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

/*
%union {
   struct {
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

*/


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

               printf(" \n");

            #endif

            $<datanode>$ = $<datanode>1;

            printf("This statement Node's address is: %p \n", $<datanode>$);
            printf("This statement Node's type is: %d \n", $<datanode->dtype>$);
            printf("This statement Node's name is: %s \n", $<datanode->name>$);
            printf("This statement Node's children 0'address is: %p \n", $<datanode->children[0]>$);
            printf("This statement Node's children 0's type is : %d \n", $<datanode->children[0]->dtype>$);
            printf("This statement Node's children 0's value is : %d \n", $<datanode->children[0]->ival>$);
            printf("This statement Node's children 1's address is: %p \n", $<datanode->children[1]>$);
            printf("This statement Node's children 1's type is : %d \n", $<datanode->children[1]->dtype>$);
            printf("This statement Node's children 1's value is : %d \n", $<datanode->children[1]->ival>$);
            
         }
      ;

expression:
        intexpr ';'
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> intexpr ';' \n");    //DEBUG
            #endif
            //$<datanode->dtype>$ = $<datanode->dtype>1;
            //$<datanode->ival>$ = $<datanode->ival>1;

            $<datanode>$ = $<datanode>1;

         }
      ;

intexpr: INTEGER
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> INTEGER \n");    //DEBUG
            #endif
            
            $<datanode>$ = $<datanode>1;
            //$<datanode>$ = constructNode(0);

            //$<datanode->dtype>$ = 1;
            //$<datanode->ival>$ = $<datanode->ival>1;
            #if DEBUGTAG
               printf("%d is an integer \n",$<datanode->ival>1);
               printf("It is also an intexpr with address: %p\n",$<datanode>$);
            #endif
         }
      /*
      | '-' intexpr    %prec '*' 
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> '-' intexpr  prec '*' \n");    //DEBUG
            #endif
            $<datanode->dtype>$ = 2;
            $<datanode->ival>$ = - $<datanode->ival>2;
            #if DEBUGTAG
               printf("negative %d, using unary negation \n",$<datanode->ival>2);
            #endif
         }
      */
      | intexpr '+' intexpr
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> intexpr + intexpr \n");    //DEBUG
            #endif
           
           
           
           struct DataNode *op = constructNode(2);
           op->dtype = 5; //operator type
           strcpy(op->name, "+");
           op->children[0] = $<datanode>1 ;
           op->children[1] = $<datanode>3 ;
           
           $<datanode>$ = op ;

           //op->children[0] = constructNode(0);
           //op->children[0]->dtype = 1;
           //op->children[0]->ival = $<datanode->ival>1;
           
          // op->children[1] = constructNode(0);
          // op->children[1]->dtype = 1;
          // op->children[1]->ival = $<datanode->ival>3; 

           //setOperator("+",op); 
           
           // $<datanode->dtype>$ = 1;
           // $<datanode->ival>$ = $<datanode->ival>1 + $<datanode->ival>3;
            #if DEBUGTAG
               //printf("%d + %d is %d \n",$<datanode->ival>1, $<datanode->ival>3, $<datanode->ival>$);
               printf("The address is %p \n",op);
               printf("The address is %p \n",$<datanode>$);
            #endif
         }
      /*
      | intexpr '*' intexpr
         {
            #if DEBUGTAG
               printf(" ~RULE: intexpr--> intexpr * intexpr \n");    //DEBUG
            #endif
            $<datanode->dtype>$ = 1;
            $<datanode->ival>$ = $<datanode->ival>1 * $<datanode->ival>3;
            #if DEBUGTAG
               printf("%d * %d is %d \n",$<datanode->ival>1, $<datanode->ival>3, $<datanode->ival>$);
            #endif
         }
      */
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


