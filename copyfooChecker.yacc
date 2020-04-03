 
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
#include <stdbool.h>
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
      bool bval;
   } info; 
}


 /* identify what kind of values can be associated with the language components */

 /* for the token types that have an associated value, identify its type */
%token<struct nodeinfo> INTEGER REAL IDENTIFIER STRING BOOLEAN PRINT VAR

%type<struct nodeinfo> script statements statement
%type<struct nodeinfo> intexpr strexpr expression printout



/* Operator Precedence */ 
%right '='
%left  '+'  '-'
%left  '*'  '/'
%left UMINUS   /* UNARY Minus */ 
/* Parantheses??? */ 


%%


 /****** grammar rules ******/

/****************

      script --> statements
      statements --> statement
      statements --> statement statements
      statement --> IDENTIFIER = expression
      expression --> strexpr
      expression --> intexpr
      expression --> floatexpr
      expression --> boolexpr
      
      
      ****
      * string expressions. dtype must == 3 
      ***
      strexpr --> STRING
      strexpr --> IDENTIFIER                    *dtype must be 3 to succeed

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
      intexpr --> INTEGER < intexpr          *dtype must be 1 to succeed
      intexpr --> IDENTIFIER < intexpr          *dtype must be 1 to succeed
      intexpr --> INTEGER == intexpr         *dtype must be 1 to succeed
      intexpr --> IDENTIFIER == intexpr         *dtype must be 1 to succeed
      intexpr --> INTEGER <> intexpr         *dtype must be 1 to succeed
      intexpr --> IDENTIFIER <> intexpr         *dtype must be 1 to succeed


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
      floatexpr --> REALN < floatexpr               *dtype must be 2
      floatexpr --> IDENTIFIER < floatexpr               *dtype must be 2
      floatexpr --> REAL == floatexpr              *dtype must be 2
      floatexpr --> IDENTIFIER == floatexpr              *dtype must be 2
      floatexpr --> IDENTIFIER <> floatexpr              *dtype must be 2
      floatexpr --> IDENTIFIER <> floatexpr              *dtype must be 2

      ***
      Boolean
      ***
      boolexpr --> BOOLEAN
      boolexpr --> IDENTIFIER                      *dtype 4
      
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


******/

script: statements
      | script printout 	
      ;

statements:
        statement
      | statement statements
      | IDENTIFIER '=' expression
      | expression
      ;

expression: 
        strexpr
      | intexpr
      ;




/* printout --> PRINT ( STRING ) */
printout: PRINT '(' expression ')'
      {
         /* print text associated with IDENTIFIER (field $3) */
         if($<info.dtype>3 == 1){
            printf("%d \n", $<info.ival>3);
         }else if($<info.dtype>3 == 2){
            printf("%lf \n", $<info.fval>3);
         }else if($<info.dtype>3 == 3){
            printf("%s \n", $<info.str>3);
         }else if($<info.dtype>3 == 4){
            printf($<info.bval>3 ? "true" : "false");
         }
      }
      ;



statements:
   statement
   | statement statements
   ;

statement: IDENTIFIER '=' expression
    {
       $<info.dtype>1 = $<info.dtype>3;
       if ($<info.dtype>3 == 1) {
          $<info.ival>1 = $<info.ival>3;
          printf("sets %s = %d;\n", $<info.name>1, $<info.ival>3);
       } else if ($<info.dtype>3 == 2) {
          $<info.ival>1 = $<info.ival>3;
          printf("sets %s = %lf;\n", $<info.name>1, $<info.ival>3);
       } else if ($<info.dtype>3 == 3) {
          strncpy($<info.str>1, $<info.str>3, 4095);
          printf("sets %s = \"%s\";\n", $<info.name>1, $<info.str>3);
       } else if ($<info.dtype>3 == 4) {
          $<info.ival>1 = $<info.ival>3;
          printf;
          printf("sets %s = \"%s\";\n", $<info.name>1,  
             ($<info.bval>3 ? "true" : "false"));
       }
    }
    ;

expression: strexpr
    {
       $<info.dtype>$ = 3;
       strncpy($<info.str>$, $<info.str>1, 4095);
    }
    ;

expression: intexpr
    {
       $<info.dtype>$ = 1;
       $<info.ival>$ = $<info.ival>1;
    }
    ;






intexpr: IDENTIFIER
    {
       $<info.dtype>$ = 1;
       $<info.ival>$ = $<info.ival>1;
    }
    ;

intexpr: INTEGER '+' intexpr
    {
       $<info.dtype>$ = 1;
       $<info.ival>$ = $<info.ival>1 + $<info.ival>3;
    }
    ;

intexpr: IDENTIFIER '+' intexpr
    {
       $<info.dtype>$ = 1;
       $<info.ival>$ = $<info.ival>1 + $<info.ival>3;
    }
    ;

strexpr: STRING
    {
       $<info.dtype>$ = 3;
       strncpy($<info.str>$, $<info.str>1, 4095);
    }
    ;

strexpr: IDENTIFIER
    {
       $<info.dtype>$ = 3;
       strncpy($<info.str>$, $<info.str>1, 4095);
    }
    ;

strexpr: STRING '+' strexpr
    {
       $<info.dtype>$ = 3;
       strncpy($<info.str>$, $<info.str>1, 4095);
       strncat($<info.str>$, $<info.str>3, 4095);
    }
    ;

strexpr: IDENTIFIER '+' strexpr
    {
       $<info.dtype>$ = 3;
       strncpy($<info.str>$, $<info.str>1, 4095);
       strncat($<info.str>$, $<info.str>3, 4095);
    }
    ;



 /* vardecl --> VAR IDENTIFIER ;
  *    where there is some character string associated with IDENTIFIER */
vardecl: VAR IDENTIFIER ';'
	{
	   /* display the text associated with IDENTIFIER (field $2) */
	   printf("...declared variable %s...\n", $2);
	};


intexpr: INTEGER
    {
       $<info.dtype>$ = 1;
       $<info.ival>$ = $<info.ival>1;
		 printf("%d is \n",$<info.ival>1);
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

