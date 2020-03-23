
 /* sample starter file for the lex portion of your project,
  * currently just accepts variable definitions where the
  *    variable name is alphabetic
  */

 /* Define alphabetic chars */
Alpha [a-zA-Z]
Num \d
Bool [TF]
DoubleQuote "
Neg -
EmbdQuote \\" 
EmbdBkSlash \\\\ 
SemiColon ;

 /****** setup the C/lex infrastructure ******/
%{
#include <stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
int yywrap();
int yyerror(char* s);
int row = 0;
int column = 0;
const int MaxLen = 128;
%}


%%

 /****** Rules for tokens ******/

 /* for the keyword "VAR" return VAR as the type */
"VAR"      { return(VAR); }

"print"    { return(PRINT); } 


 /* Matches string 
 * alphabetic identifiers are one or more Alphas,
  *    store the actual text for the identifier
  *    and return IDENTIFIER as the type */
({Alpha})+ { yylval.str = strdup(yytext); return(IDENTIFIER); }

 /*Match a Real Number
  *    store the converted value, string to float,
  *    for the identifier
  *    and return REAL as the type */
 ^({Neg})?({Num})+\.({Num})+$ { yylval.real = atof(yytext); return(REAL); }

 /* Match an Integer
  *    store the converted value, string to integer 
  *    for the identifier
  *    and return INTEGER as the type */
 ^({Neg})?({Num})+$ { yylval.integer = atoi(yytext); return(INTEGER); }

 /* Match exactly 1 Boolean */
 ^({Bool})$ { yylval.boolean = yytext[0]; return(BOOLEAN); }

 /* the semi-colon */
";"        { return(';'); }

 /* skip whitespace (spaces, tabs, form feeds etc */
[ \t\f\v]  { }

 /* treat any other char as an error,
  *    store an error message in an array,
  *    replace the "c" in the message with the offending character,
  *    pass the array to yyerror, and
  *    return the offending char as a token (which the yacc rules will reject as invalid) */
.          { char errmsg[] = "Unrecognized char: c"; errmsg[19] = yytext[0]; yyerror(errmsg); return(yytext[0]); }

%%

 /****** supporting C code ******/

 /* cleanup any loose ends at the end of input,
  * currently just returns true (1) */
int yywrap()
{
   return 1;
}

 /* print any generated error messages (to stderr) */
int yyerror(char* s)
{
   fprintf(stderr, "***Error detected: %s\n   continuing with processing.\n", s);
   return 1;
}

