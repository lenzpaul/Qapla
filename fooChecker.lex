
 /* sample starter file for the lex portion of your project,
  * currently just accepts variable definitions where the
  *    variable name is alphabetic
  */

 /* Define alphabetic chars */
Alpha [a-zA-Z]
Num \d

String \"(\\\\|\\\"|[^"\\])*\"


Bool [TF]
DbQuote ["]
Neg [-]
EmbdQuote \\" 
EmbdBkSlash \\\\ 
SemiColon ;

 /****** setup the C/lex infrastructure ******/
%{
#include <stdio.h>
#include <stdbool.h>
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


 /* Matches string (ie: begins & ends with ", may include escaped \ or "
  * 

*/
({String}) { 

      //remove outer quotes from string
		int slen = strlen(yytext)-2;
		memmove(yytext, &yytext[1], strlen(yytext)-2);
		yytext[slen] = '\0';

      //creating space for storing yytext (input)
		yylval.str = calloc(strlen(yytext), sizeof(char));
     

      /*remove backslashes in strings 
       *  and keep escaped chars (ie: \" or \\) 
       */ 

      //iterate over each char in yytext
      //copy into yylval
      //if copied char in yylval != '\\'
      //yylvalPos++
      int yylvalPos = 0;
      int yytextPos = 0;
      bool escaped = false;

      while(yytextPos < strlen(yytext)) //TODO pointer or string? yytext or *yytext
      {
         yylval.str[yylvalPos] = yytext[yytextPos];
         if((yylval.str[yylvalPos] == '\\')  && (!escaped))
         {
            escaped=true;
         }else{   
            escaped=false;
            yylvalPos++;
         }
         yytextPos++;
      }
      //insert Null terminator to end yylval string
      yylval.str[yylvalPos] = '\0'; 


      /*
		while(*yytext != '\0')
		{
			*yylval.str = *yytext;
			if(*yylval.str != '\\') yylval.str++;  //changes the actual address 
			yytext++;
		}
		*yylval.str = '\0';
		yylval.str = &yylval.str[0];
	   //printf("%c", yylval.str[strlen(yylval.str)-1]);

      */


		return(STRING); 
   }

 /* alphabetic identifiers are one or more Alphas,
  *    store the actual text for the identifier
  *    and return IDENTIFIER as the type */
({Alpha})+ { yylval.alpha = strdup(yytext); return(IDENTIFIER); }

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
 ^({Bool})$ { yylval.boolean = *yytext; return(BOOLEAN); }

 ^({DbQuote})$    { return(DbQuote); }


 ")"         { return *yytext; }

 "("         { return *yytext; }


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

