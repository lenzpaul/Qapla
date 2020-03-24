
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


%%


 /****** grammar rules ******/


 /* script --> vardecl */
script:
	vardecl
   | script printout
   |
	;


 /* vardecl --> VAR IDENTIFIER ;
  *    where there is some character string associated with IDENTIFIER */
vardecl: VAR IDENTIFIER ';'
	{
	   /* display the text associated with IDENTIFIER (field $2) */
	   printf("...declared variable %s...\n", $2);
	};

 /* print --> IDENTIFIER 
  */
printout: PRINT '(' STRING ')'
   {
      /* print text associated with IDENTIFIER (field $3) */
	   printf("%s \n", $3);
   };


%%

 /****** supporting C to carry out parsing ******/


int main()
{
   printf("Beginning syntax checking:\n\n");
   int result = yyparse();
   printf("\nSyntax checking complete\n\n");
   return result;
}


