
 /* sample starter file for the lex portion of your project,
  * currently just accepts variable definitions where the
  *    variable name is alphabetic
  */

 /* Define alphabetic chars */
Alpha [a-zA-Z]
Num [0-9]

String \"(\\\\|\\\"|[^"\\])*\"

Bool [TF]
Neg [-]
SemiColon ;
eq =

 /****** setup the C/lex infrastructure ******/
%{
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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

"MOD"      { return (MOD); } 

 /* for the keyword "VAR" return VAR as the type */
"VAR"      { return(VAR); }

"print"    { return(PRINT); } 



 /* Matches string (ie: begins & ends with ", may include escaped \ or " */
({String}) { 

      //remove outer quotes from string
		int slen = strlen(yytext)-2;
		memmove(yytext, &yytext[1], strlen(yytext)-2);
		yytext[slen] = '\0';

      //creating space for storing yytext (input)
		   //yylval.node.str = calloc(strlen(yytext), sizeof(char)); //size defined in struct in yacc file
     

      /*REMOVE BACKSLASHES IN STRING 
       *  and keep escaped chars (ie: \" or \\) 
      */ 

      /*Here we remove any escaping \ before getting the string content
       * Im using a bool to keep track of whether or not the next char
       * should be taking literally 
         
       *- Loop through the every char in the string 
       *  (ie: yytext does not have outer quotes at this point)
       *  copying every char from yytex to the string type yylval.node.str
       
       *- If we find an escape char \ we insert it 
       *  We switch escaped to true 
       *  then we overwrite the in the next loop with the escaped char (\ or ")
       */  
      int yylvalPos = 0;
      int yytextPos = 0;
      bool escaped = false;
      while(yytextPos < strlen(yytext)) 
      {
         yylval.node.str[yylvalPos] = yytext[yytextPos];
         if((yylval.node.str[yylvalPos] == '\\')  && (!escaped))
         {
            escaped=true;
         }else{   
            escaped=false;
            yylvalPos++;
         }
         yytextPos++;
      }

      //insert Null terminator to end yylval string
      yylval.node.str[yylvalPos] = '\0'; 

      yylval.node.ival = atoi(yytext);
      yylval.node.fval = atof(yytext);
      yylval.node.bval = false;
      yylval.node.name[0] = '\0';
      yylval.node.dtype = 3;

		return(STRING); 
   } 


 /* Match exactly 1 Boolean */
 ({Bool}) { 
      ( *yytext == 'T' ) ? 
         (yylval.node.bval = true ) : (yylval.node.bval = false);

      yylval.node.str[0] = '\0'; 
      yylval.node.ival = 0;
      yylval.node.fval = 0;
      yylval.node.name[0] = '\0';
      yylval.node.dtype = 4;
      return(BOOLEAN); 
    }


 /* alphabetic identifiers are one or more Alphas,
  *    store the actual text for the identifier
  *    and return IDENTIFIER as the type */
({Alpha})+ { 

   //yylval.alpha = strdup(yytext); 

   yylval.node.str[0] = '\0';
   yylval.node.ival = 0;
   yylval.node.fval = 0;
   yylval.node.bval = false;
   strncpy(yylval.node.name, yytext, 255);
   yylval.node.dtype = 0;
   return(IDENTIFIER); 
   
   }

 /*Real Number
  *    store the converted value, string to float,
  *    for the identifier
  *    and return REAL as the type */
 ({Neg})?({Num})+\.({Num})+ { 
   yylval.node.fval = atof(yytext); 

   yylval.node.str[0] = '\0';
   yylval.node.ival = 0;         //FIXME 
   yylval.node.bval = false;
   yylval.node.name[0] = '\0';
   yylval.node.dtype = 2;
    
   return(REAL); 
    
   }

 /*Integer
  *    store the converted value, string to integer 
  *    for the identifier
  *    and return INTEGER as the type */
 ({Neg})?({Num})+ { 
   yylval.node.ival = atoi(yytext); 
   yylval.node.fval = atof(yytext);

   yylval.node.str[0] = '\0';
   yylval.node.bval = false;
   yylval.node.name[0] = '\0';
   yylval.node.dtype = 1;

   return(INTEGER);
   
   }


 ")"         { return *yytext; }

 "("         { return *yytext; }

 "+"         { return *yytext; }

 "-"         { return *yytext; }

 "="         { return *yytext; }

 "*"         { return *yytext; }

 "/"         { return *yytext; }

 "^"         { return *yytext; }


 /* the semi-colon */
";"        { return *yytext; }

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

