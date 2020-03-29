 /*
   This interpretter takes statements of the form
      varname = expression
   and evalutes the expression, e.g.
      x = 3 + 17 + 8 + 3
   would be interpretted to the following:
      set x = 31

   ------------------------------------------------------------------------
   NOTE: the interpretter currently evaluates each statement independently,
       e.g. x = 3
            y = x
   does not use the new "x == 3" value for the second statement.
   To correct this, the interpretter still needs something like
   a lookup table to keep track of the current value of each variable,
   and would need to update the correct entry on each variable assignment.
   ------------------------------------------------------------------------

   The valid forms for variable names and expressions are given below.

   valid token types are
      INTEGER any sequence of digits
      STRING any set of characters between double quotes
               (cannot contain a double quote)
      = the assignment operator
      + the addition operator for integers, concatenation for strings

   grammar rules are
      program --> statements
      statements --> statement
      statements --> statement statements
      statement --> IDENTIFIER = expression
      expression --> strexpr
      expression --> intexpr
      intexpr --> INTEGER
      intexpr --> INTEGER + intexpr
      strexpr --> STRING
      strexpr --> STRING + strexpr
 */

 /* ---- part 1: declarations ---- */

 /* C setup code: libraries, prototypes, etc */
%{
#include<stdio.h>
#include<string.h>
int yylex(void);
int yywrap();
int yyerror(char* s);
extern int row;
extern int col;
%}

 /* begin processing the top-level component */
%start program

 /* every component of the program has the same data type:
  *    info is a struct with three fields
  *       inum - a long, used for integer and intexpr
  *       str  - a char*, used for string and strexpr
  *       name - a char*, used for the name of identifiers
  *       dtype - an int, used to indicate the current datatype,
  *               0 for unknown, 1 for integer, 2 for string
  */


%union { struct nodeinfo { long inum, dtype; char str[4096], name[256]; } info; }

 /* identify the valid token types, all have yylval type "info" */
%token<struct nodeinfo> INTEGER IDENTIFIER STRING
%type<struct nodeinfo> program statements statement expression intexpr strexpr
%right '='
%left '+'

 /* ---- part 2: grammar rules ----
      program --> statements
      statements --> statement
      statements --> statement statements
      statement --> IDENTIFIER = expression
      expression --> strexpr
      expression --> intexpr
      intexpr --> INTEGER
      intexpr --> INTEGER + intexpr
      intexpr --> IDENTIFIER           *dtype must be 1 to succeed
      intexpr --> IDENTIFIER + intexpr * dtype must be 1 to succeed
      strexpr --> STRING
      strexpr --> STRING + strexpr
      strexpr --> IDENTIFIER           *dtype must be 2 to succeed
      strexpr --> IDENTIFIER + strexpr * dtype must be 2 to succeed
  */

%%

program: statements ;

statements:
   statement
   | statement statements
   ;

statement: IDENTIFIER '=' expression
    {
       $<info.dtype>1 = $<info.dtype>3;
       if ($<info.dtype>3 == 1) {
          $<info.inum>1 = $<info.inum>3;
          printf("sets %s = %d;\n", $<info.name>1, $<info.inum>3);
       } else if ($<info.dtype>3 == 2) {
          strncpy($<info.str>1, $<info.str>3, 4095);
          printf("sets %s = \"%s\";\n", $<info.name>1, $<info.str>3);
       }
    }
    ;

expression: strexpr
    {
       $<info.dtype>$ = 2;
       strncpy($<info.str>$, $<info.str>1, 4095);
    }
    ;

expression: intexpr
    {
       $<info.dtype>$ = 1;
       $<info.inum>$ = $<info.inum>1;
    }
    ;

intexpr: INTEGER
    {
       $<info.dtype>$ = 1;
       $<info.inum>$ = $<info.inum>1;
    }
    ;

intexpr: IDENTIFIER
    {
       $<info.dtype>$ = 1;
       $<info.inum>$ = $<info.inum>1;
    }
    ;

intexpr: INTEGER '+' intexpr
    {
       $<info.dtype>$ = 1;
       $<info.inum>$ = $<info.inum>1 + $<info.inum>3;
    }
    ;

intexpr: IDENTIFIER '+' intexpr
    {
       $<info.dtype>$ = 1;
       $<info.inum>$ = $<info.inum>1 + $<info.inum>3;
    }
    ;

strexpr: STRING
    {
       $<info.dtype>$ = 2;
       strncpy($<info.str>$, $<info.str>1, 4095);
    }
    ;

strexpr: IDENTIFIER
    {
       $<info.dtype>$ = 2;
       strncpy($<info.str>$, $<info.str>1, 4095);
    }
    ;

strexpr: STRING '+' strexpr
    {
       $<info.dtype>$ = 2;
       strncpy($<info.str>$, $<info.str>1, 4095);
       strncat($<info.str>$, $<info.str>3, 4095);
    }
    ;

strexpr: IDENTIFIER '+' strexpr
    {
       $<info.dtype>$ = 2;
       strncpy($<info.str>$, $<info.str>1, 4095);
       strncat($<info.str>$, $<info.str>3, 4095);
    }
    ;

 /* ---- part 3: supporting programs ---- */

%%

 /* begin parsing */
int main() {
   printf("Compilation begins:\n\n");
   int res = yyparse();
   printf("\nCompilation complete.\n", res);
   return(res);
}

