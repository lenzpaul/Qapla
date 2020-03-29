 /* sample lex file for a language where:
    - integers are one or more digits
    - identifiers are one or more alphabetic characters
    - strings begin and end with a ", and cannot contain a "
    - operators are + and =
    - comments go from a semi-colon to a newline
    - tracks row/column in source file as it processes
  */

 /* ---- part 1: declarations ---- */

 /* part 1a: any character sets we want to identify */
Alpha [a-zA-Z]
Digit [0-9]

 /* part 1b: the C setup */
%{
#include<stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
int yywrap();
int yyerror(char* s);
int row = 0;
int col = 0;
%}

%%

 /* ---- part 2: token rules ---- */

 /* initialize identifiers default values and store the name */
({Alpha})+ { col+=strlen(yytext);
             strncpy(yylval.info.name,yytext,255);
             yylval.info.dtype = 0;
             yylval.info.inum = 0;
             yylval.info.str[0] = '\0';
             return(IDENTIFIER); }

 /* initialize integers with their int value and copy the text version as their str value */
({Digit})+ { col+=strlen(yytext);
             yylval.info.inum = atoi(yytext);
             strncpy(yylval.info.str, yytext, 4095);
             yylval.info.name[0] = '\0';
             yylval.info.dtype = 1;
             return(INTEGER); }

"="        { col++; return('='); }
"+"        { col++; return('+'); }

 /* string literals, begin and end with " and do not contain a " */
(["][^"]*["]) { col+=strlen(yytext);
                strncpy(yylval.info.str, (yytext+1), (strlen(yytext)-2));
                yylval.info.inum = atoi(yytext);
                yylval.info.name[0] = '\0';
                yylval.info.dtype = 2;
                return(STRING); }

 /* strip out comments, which go from a ; to a newline */
([;](.)*[\n]) { col=0; row++; }

 /* identify any characters that are just to be skipped, e.g. whitespace */
[ \t\f\v]  { col++; }

 /* adjust row/column after a newline */
([\n]) { row++; col=0; }

 /* anything else is an error, return it as a token so the yacc rules can reject it */
.          { char errmsg[] = "Unknown char in input: x";
             errmsg[23] = yytext[0];
             yyerror(errmsg);
             return(yytext[0]); }



%%

 /* ---- part 3: supporting code ---- */

 /* cleanup any loose ends at the end of input */
int yywrap()
{
   return(1);
}

 /* process any error messages generated */
int yyerror(char* s)
{
   fprintf(stderr, "\n***Error detected: %s\n   on/after row %d, col %d.\n\n", s, row, col);
   return 1;
}

