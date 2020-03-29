 
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
%}



 /* identify the top level language component */
%start script


 /* every component of the program has the same data type:
  *    info is a struct with five fields
  *       ival - a long, used for integer and intexpr
  *       fval - a double, used for float and floatexpr
  *       str  - a char*, used for string and strexpr
  *       name - a char*, used for the name of identifiers
  *       dtype - an int, used to indicate the current datatype,
  *               0 for unknown, 1 for integer, 2 for float. 3 for string,
  *               4 for boolean    
  */


%union { 
   struct nodeinfo 
   { 
      long ival, dtype; 
      double fval;
      char str[4096], name[256]; 
   } info; 
}


 /* identify what kind of values can be associated with the language components */

 /* for the token types that have an associated value, identify its type */
%token<struct nodeinfo> INTEGER REAL IDENTIFIER STRING BOOLEAN

%type<struct nodeinfo> script statements statement expr
%type<struct nodeinfo> intexpr floatexpr strexpr boolexpr


/* Operator Precedence */ 
%right '='
%left  '+'  '-'
%left  '*'  '/'
%left UMINUS   /* UNARY Minus */ 
/* Parantheses??? */ 


%%


 /****** grammar rules ******/

      script --> statements
      statements --> statement
      statements --> statement statements
      statement --> IDENTIFIER = expression
      expression --> strexpr
      expression --> intexpr
      expression --> floatexpr
      expression --> boolexpr
      
      
      /* string expressions. dtype must == 3  */ 
      strexpr --> STRING
      strexpr --> IDENTIFIER                    *dtype must be 3 to succeed

      strexpr --> IDENTIFIER = strexpr          *assignment: dtype must be 3

      strexpr --> STRING == IDENTIFIER          *equals: evaluation, returns bool
      strexpr --> IDENTIFIER == strexpr         *equals: evaluation, returns bool

      strexpr --> STRING <>  strexpr            *not-equals, return bool
      strexpr --> IDENTIFIER <> strexpr         *not-equals, return bool

      strexpr --> STRING <  strexpr             *less than, return bool
      strexpr --> IDENTIFIER <  strexpr         *less than, return bool

      strexpr --> STRING + strexpr              *concatenation, dtype must be 3 
      strexpr --> IDENTIFIER + strexpr          *concatenation, dtype must be 3 

      strexpr --> STRING [ index : index ]      *substring, 0-based, inclusive) 
      strexpr --> IDENTIFIER [ index : index ]  *substring

      


      *** 
      For binary operations, if both operands are integer then the result is
        integer, if one or both operands are real then the result is real.
      ***

      intexpr --> INTEGER
      intexpr --> - INTEGER                     *unary negation
      intexpr --> IDENTIFIER                    *dtype must be 1 
      intexpr --> - IDENTIFIER                  *unary negation
      
      intexpr --> INTEGER + intexpr
      intexpr --> IDENTIFIER + intexpr          *dtype must be 1 to succeed
      intexpr --> INTEGER - intexpr
      intexpr --> IDENTIFIER - intexpr          *dtype must be 1 to succeed
      intexpr --> INTEGER * intexpr
      intexpr --> IDENTIFIER * intexpr          *dtype must be 1 to succeed
      intexpr --> INTEGER / intexpr
      intexpr --> IDENTIFIER / intexpr          *dtype must be 1 to succeed
      intexpr --> INTEGER ^ intexpr
      intexpr --> IDENTIFIER ^ intexpr          *dtype must be 1 to succeed
      intexpr --> INTEGER MOD intexpr
      intexpr --> IDENTIFIER MOD intexpr        *dtype must be 1 to succeed
      intexpr --> IDENTIFIER < INTEGER          *dtype must be 1 to succeed
      intexpr --> IDENTIFIER == INTEGER         *dtype must be 1 to succeed
      intexpr --> IDENTIFIER <> INTEGER         *dtype must be 1 to succeed


      ***
      * If IDENTIFIER is INTEGER (dtype 1), return a floatexpr *
      ***
      floatexpr --> REAL
      floatexpr --> - REAL                        *unary negation
      floatexpr --> IDENTIFIER                    *dtype must be 2 
      floatexpr --> - IDENTIFIER                  *unary negation, dtype 2
      
      floatexpr --> REAL + floatexpr
      floatexpr --> IDENTIFIER + floatexpr          *dtype must be 1 or 2 
      floatexpr --> REAL - floatexpr
      floatexpr --> IDENTIFIER - floatexpr          *dtype must be 1 or 2 
      floatexpr --> REAL * floatexpr
      floatexpr --> IDENTIFIER * floatexpr          *dtype must be 1 or 2 
      floatexpr --> REAL / floatexpr
      floatexpr --> IDENTIFIER / floatexpr          *dtype must be 1 or 2 
      floatexpr --> REAL ^ floatexpr
      floatexpr --> IDENTIFIER ^ floatexpr          *dtype must be 1 or 2 
      floatexpr --> REAL MOD floatexpr
      floatexpr --> IDENTIFIER MOD floatexpr        *dtype must be 1 or 2 
      floatexpr --> IDENTIFIER < REAL               *dtype must be 2
      floatexpr --> IDENTIFIER == REAL              *dtype must be 2
      floatexpr --> IDENTIFIER <> REAL              *dtype must be 2

      ***
      Boolean
      ***
      boolexpr --> BOOLEAN
      boolexpr --> IDENTIFIER                      *dtype 4
      
      boolexpr --> IDENTIFIER = boolexpr            *assignement: dtype 4
      boolexpr --> BOOLEAN == boolexpr
      boolexpr --> IDENTIFIER == boolexpr
      boolexpr --> BOOLEAN <> boolexpr
      boolexpr --> IDENTIFIER <> boolexpr
      boolexpr --> BOOLEAN AND boolexpr
      boolexpr --> IDENTIFIER AND boolexpr
      boolexpr --> NOT BOOLEAN
      boolexpr --> NOT IDENTIFIER
      boolexpr --> BOOLEAN OR boolexpr
      boolexpr --> IDENTIFIER OR boolexpr











      floatexpr --> REAL 
      floatexpr --> IDENTIFIER                  *dtype must be 2
      
      floatexpr --> REAL + floatexpr
      floatexpr --> IDENTIFIER                *dtype must be 2 to succeed
      floatexpr --> IDENTIFIER + floatexpr    *dtype must be 2 to succeed



      boolexpr --> BOOLEAN
      boolexpr --> IDENTIFIER                 *dtype must be 2 to succeed
  */













 /* script --> vardecl */

script: 
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


