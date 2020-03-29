 
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
#include<stdio.h>
#include<string.h>
int yylex(void);
int yywrap();
int yyerror(char* s);



 /* identify the top level language component */
%start script


 /* every component of the program has the same data type:
  *    info is a struct with five fields
  *       ival - a long, used for integer and intexpr
  *       fval - a double, used for float and floatexpr
  *       str  - a char*, used for string and strexpr
  *       name - a char*, used for the name of identifiers
  *       dtype - an int, used to indicate the current datatype,
  *               0 for unknown, 1 for integer, 2 for string, 3 for float
  */


%union { 
   struct nodeinfo 
   { 
      long ival, dtype; 
      double fval;
      char str[4096], name[256]; 
   } info; 
}




%}






 /* identify what kind of values can be associated with the language components */
%union { char * str; int integer; float real; char boolean; char * alpha;}


/* identify the token types */
%token VAR IDENTIFIER REAL INTEGER BOOLEAN
%token PRINT DbQuote STRING


 /* for the token types that have an associated value, identify its type */
%type<str> STRING
%type<real> REAL
%type<integer> INTEGER
%type<boolean> BOOLEAN

%type<alpha> IDENTIFIER

%type  <nodetype> expr number

/* Operator Precedence */ 
%right '='
%left  '+'  '-'
%left  '*'  '/'
%left UMINUS /* UNARY Minus */ 
/* Parantheses??? */ 


%%


 /****** grammar rules ******/


 /* script --> vardecl */

script: /* blank */  
   | script printout 	
	| script vardecl
   | script expr
	; 

/*
expr:
      '(' expr ')    { $$ = $2 } 
   |  expr '+' expr  { $$ = $1 + $3; } 
   |  expr '-' expr  { $$ = $1 - $3; } 
   |  expr '*' expr  { $$ = $1 * $3; } 
   |  expr '/' expr  { $$ = $1 / $3; } 
   |  '-' expr %prec UMINUS 
   |  number
   ;
*/

/* expr is a valid expression (of any data type)  */ 
expr: 
   |  STRING   { $$ = $1 } /* STRING */
   |  BOOLEAN  { $$ = $1 } /* BOOLEAN */
   |  number
   ;


number: 
      INTEGER  { $$ = 1; }
   |  REAL     { $$ = 1; }
   ;
         


 /* vardecl --> VAR IDENTIFIER ;
  *    where there is some character string associated with IDENTIFIER */
vardecl: VAR IDENTIFIER ';'
	{
	   /* display the text associated with IDENTIFIER (field $2) */
	   printf("...declared variable %s...\n", $2);
	};

  /* printout --> PRINT ( STRING )
  */


printout: PRINT '(' INTEGER ')'
      {
         /* print text associated with IDENTIFIER (field $3) */
         printf("%d \n", $3);
      }
 

	| PRINT '(' REAL ')'
      {
         /* print text associated with IDENTIFIER (field $3) */
         printf("%f \n", $3);
      }
	
   
   | PRINT '(' STRING ')'
      {
         /* print text associated with IDENTIFIER (field $3) */
         printf("%s \n", $3);
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


