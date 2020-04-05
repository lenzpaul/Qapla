 
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



 /* identify what kind of values can be associated with the language components */

 /* for the token types that have an associated value, identify its type */
%token<struct DataNode> INTEGER REAL IDENTIFIER STRING BOOLEAN PRINT VAR MOD FUNC
/* %type<struct DataNode>  */



/* Operator Precedence */ 
%right '='
%left  '+'  '-'
%left  '*'  '/' MOD
%left  '^'  
/*%left UMINUS  */  /* UNARY Minus */ 
/* Parantheses??? */ 


%%
 /****** grammar rules ******/

/*
   script -> program
   
   
   program -> evaluations
   program -> declarations

   evaluations -> evaluation
   evaluations -> evaluations evaluation

   evaluation -> statement  
            //evaluation -> funcall //DELETE 
   
   statements -> statement 
   statements -> statements statement

   statement -> expression ; 

   declarations -> declaration
   declarations -> declarations declaration
   declaration -> fundecl
   declaration -> vardecl

   fundecl -> FUNC IDENTIFIER { statements }
   funcall -> IDENTIFIER ( IDENTIFIER ) //REVIEW
   funcall -> IDENTIFIER ( statement )  //REVIEW

   vardecl -> VAR IDENTIFIER ; 
   
   expression -> funcall
   expression -> print ( expression ) //  ie: print ( 3 + 4 * 5 ) ;
   expression -> reads ( expression ) 
   expression -> readi ( expression )
   expression -> readr ( expression )

   expression -> intexpr 
   expression -> floatexpr
   expression -> strexpr 
   expression -> boolexpr
   
   intexpr -> INTEGER 


   
 */  


script: 
        threads 
         {
            #if DEBUGTAG 
               printf(" ~RULE: script --> threads \n "); 
            #endif
            
         }
      ;

threads: 
        thread
      | threads thread
      ;

thread: 
        evaluations
         {
            #if DEBUGTAG 
               printf(" ~RULE:threads --> evaluations \n "); 
            #endif
            
         }
      | declarations /* Creating space for var/func */ 
         {
            #if DEBUGTAG 
               printf(" ~RULE:threads --> declarations \n "); 
            #endif
            
         }
      ;

evaluations: 
        evaluation
         { 
            #if DEBUGTAG
               printf(" ~RULE~: evaluations --> evaluation \n"); 
            #endif
         }

      | evaluations evaluation
         { 
            #if DEBUGTAG
               printf(" ~RULE~: evaluations --> evaluations evaluation \n"); 
            #endif
         }
      ;

evaluation: 
        statement 
         { 
            #if DEBUGTAG
               printf(" ~RULE~: evaluation --> statement \n"); 
            #endif
         }
      ;

statements:
        statement 
      | statements statement
      | 
         { 
            #if DEBUGTAG
               printf(" ~RULE~:statement \n"); 
            #endif
         }
      ;

statement:
       expression ';'
         { 
            #if DEBUGTAG
               printf(" ~RULE:statement--> expression ; \n"); 
               //printf("expression children[0]: %d \n", $<datanode->children[0]->    ival>1 ); 
               printf(" \n");
            #endif

            $<datanode>$ = $<datanode>1;
         }
      ;

declarations: 
        declaration 
      | declarations declaration 
      ;
      
declaration: 
        fundecl
      | vardecl
      ;

fundecl: 

        FUNC IDENTIFIER '(' ')' '{' statements '}' /* NO PARAMETERS CASE */
         {
            #if DEBUGTAG 
               printf(" ~RULE:fundecl --> ");
               printf("FUNC IDENTIFIER '(' ')' '{' statements '}'\n"); 
            #endif           
         }
      | FUNC IDENTIFIER '(' parameters ')' '{' statements '}'
         {
            #if DEBUGTAG 
               printf(" ~RULE:fundecl --> ");
               printf("FUNC IDENTIFIER '(' parameters ')' '{' statements '}'\n"); 

               
               printf(" paramater node name: %s\n", $<datanode->name>4); 
               printf(" paramater node type: %d\n", $<datanode->dtype>4); 
               printf(" Parameter 1: %s\n", $<datanode->children[0]->name>4); 
               printf(" Parameter 2: %s\n", $<datanode->children[1]->name>4); 
               printf(" Parameter 3: %s\n", $<datanode->children[2]->name>4); 
               printf(" Parameter 4: %s\n", $<datanode->children[3]->name>4); 
            #endif
         }
      ;

parameters:
        parameter
         {   
            #if DEBUGTAG 
               printf(" ~RULE: parameters --> parameter \n ");
               //printf("$<datanode->name>$ : %s \n ",$<datanode->name>$ );
               //printf("$<datanode->name>1 : %s \n ",$<datanode->name>1 );
               //printf("$<datanode->name>$ : %p \n ",$<datanode>$ );
               //printf("$<datanode->name>1 : %p \n ",$<datanode>1 );
               //printf(" $<datanode->children[0]->name>1: %s\n", $<datanode->children[0]->name$); 
            #endif
            $<datanode>$ = constructNode(2);
            $<datanode->dtype>$ = 7; //parameters
            strcpy($<datanode->name>$,"parameters");
            insertChild($<datanode>$, $<datanode>1);

         }
      | parameters ':' parameter      
         {   

            #if DEBUGTAG 
               printf(" ~RULE: parameters --> parameters : parameter \n ");
               printf(" $<datanode->name>$: %s\n", $<datanode->name>$); 
               //printf(" $<datanode->children[0]->name>$: %s\n", $<datanode->children[0]->name>$); 
            #endif

            insertChild($<datanode>$, $<datanode>3);

            //printf(" $<datanode->children[1]->name>$: %s\n", $<datanode->children[1]->name>$); 

         }
      ;

/* ! might conflict with vardecl */
parameter:
        IDENTIFIER    
         { 
            #if DEBUGTAG 
               printf(" ~RULE: parameter --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", $<datanode->name>1);
            #endif

            //$<datanode>$ = $<datanode>1;
         }

      ;


/* REVIEW THIS 
funcall:
        IDENTIFIER '(' IDENTIFIER ')'
      | IDENTIFIER '(' st
*/

vardecl: VAR IDENTIFIER ;




expression:
        intexpr 
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> intexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;

         }
      
               
      | ioexpr
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> ioexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;

         }
      ;


ioexpr: 
        PRINT '(' expression ')' 
         { 
            #if DEBUGTAG
               printf(" ~RULE:ioexpr --> PRINT '(' expression ')' \n");    //DEBUG
            #endif

            struct DataNode *io = constructNode(1);
            io->dtype = 8; //io type
            strcpy(io->name, "print");
            io->children[0] = $<datanode>3 ;

            $<datanode>$ = io ;

         }

intexpr: INTEGER
         {
            #if DEBUGTAG
               printf(" ~RULE:intexpr--> INTEGER \n");    //DEBUG
            #endif
            
            $<datanode>$ = $<datanode>1;

            #if DEBUGTAG
               printf("%d is an integer \n",$<datanode->ival>1);
               printf("It is also an intexpr with address: %p\n",$<datanode>$);
            #endif
         }

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


            #if DEBUGTAG
               //printf("%d + %d is %d \n",$<datanode->ival>1, $<datanode->ival>3, $<datanode->ival>$);
               printf("The address is %p \n",op);
               printf("The address is %p \n",$<datanode>$);
            #endif
         }

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


