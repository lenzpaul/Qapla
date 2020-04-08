 
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
%token<struct DataNode> INTEGER REAL IDENTIFIER STRING BOOLEAN PRINT VAR MOD 
%token<struct DataNode> FUNC EVAL
/* %type<struct DataNode>  */



/* Operator Precedence */ 
/*%left ';'*/
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
               printf("statement dtype is: %d\n", $<datanode->dtype>1);
               printf("statement name is: %s\n", $<datanode->name>1);
               printf("statement children 0 ival is: %d\n", $<datanode->children[0]->ival>1);
               printf("statement children 0 name is: %s\n", $<datanode->children[0]->name>1);
            #endif
            
            //evaluate statement here
            evaluate($<datanode>1);

            //This needs to happen ON EVALUATE only 
               //insert IDENTIFIER in varContainer (variable array)
               //ie: create var 
            //insertChild(varContainer,$<datanode>1);        
            ///////
         }
      ;

statements:
        statement 
         { 
            #if DEBUGTAG
               printf(" ~RULE~:statements --> statement \n");
            #endif


            //CREATE ARRAY OF STATMENTS//////////////////////
            $<datanode>$ = constructNode(2);
            insertChild($<datanode>$, $<datanode>1);
            //strcpy($<datanode->name>$,"parameters");
            ////////////////////////////////////////
         }
      | statements statement
         { 
            #if DEBUGTAG
               printf(" ~RULE~:statements --> statements statement \n");
            #endif

            //insert addtional statements in statements array as children
            insertChild($<datanode>$, $<datanode>2);
            /////////////////////////////////////////////////////////////
         }
      |  /*empty*/  /*FIXME: NECESSARY????  I need an action */
         { 
            #if DEBUGTAG
               printf(" ~RULE~:statements --> /*empty*/ \n"); 
            #endif
         }
         /* ***************^^^ EMPTY? ^^^**********************************/
      ;

statement:
       assignexpr ';' /* operator node : "opEqual" */
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> assignexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;

         }


      | expression ';'
         { 
            #if DEBUGTAG
               printf(" ~RULE:statement--> expression ; \n"); 
               //printf("expression children[0]: %d \n", $<datanode->children[0]->    ival>1 ); 
               printf("expression dtype is: %d\n", $<datanode->dtype>1);
               printf("expression name is: %s\n", $<datanode->name>1);
               printf(" \n");
            #endif

            $<datanode>$ = $<datanode>1;
         }
      ;
/* NOT NEEDED 
declarations: 
        declaration 
      | declarations declaration 
      ;
*/
      
declarations: 
        fundecl
         {
            #if DEBUGTAG 
               printf(" ~RULE: declarations --> fundecl \n");
               printf(" ~RULE: Declaring function name: %s\n", 
                                                         $<datanode->name>1);
            #endif           

            /*~HACK?~*/ 
            //~~ The function should probably add itself to varContainer
            //         on declaration! ~~ //

            //add function to varContainer local
            insertChild(varContainer, $<datanode>1); 
         }

      | declarations fundecl
      ;

fundecl: 

        /* NO PARAMETERS CASE */
        FUNC IDENTIFIER '(' ')' '{' statements '}' 
         {
            #if DEBUGTAG 
               printf(" ~RULE:fundecl --> ");
               printf("FUNC IDENTIFIER '(' ')' '{' statements '}'\n"); 
            #endif           

            //FIXME FIXME FIXME : Broken? April 6

            //CREATE VAR FOR FUNCTION
            struct DataNode *func = constructNode(4);  
            strcpy(func->name,$<datanode->name>2); //IDENTIFIER
            func->dtype = 6; //function type

            ////// Below are instructions only. 
            // ie: will only get evaluated on a funcall/////
            ////////////////////////////////////////////////

            /*CREATE LOCAL VARCONTAINER (LOCAL SCOPE)*/
            //instruction: createNewScope
            struct DataNode *newScopeInst = constructNode(1);
            strcpy(newScopeInst->name,"createNewScope");
            newScopeInst->dtype = 8; //instruction type
            insertChild(func, newScopeInst);
            //^^when evaluated, this label creates new scope^^//
            
            /*DECLARE PARAMETERS AS VARS */
            //No PARAMS: Do nothing
            //loop through param list here
            /*
            struct DataNode *paramList = $<datanode>4;
            for(int i=0; i<paramList->size; i++)
            {
               struct DataNode *declVarInst = constructNode(1);
               strcpy(declVarInst->name,"declareVar");
               declVarInst->dtype = 8;
               strcpy(declVarInst->children[0]->name, paramList->children[i]->name);
               //printf("declVarInst->children[0]->name:   %s \n" ,declVarInst->children[0]->name);
               insertChild(func,declVarInst);
            }
            */
            //

            //CREATE A PARAMETER NODE THAT WILL DO THE ASSIGNING ON FUNCALL
             //empty at first (on func declare)
             //will be used to store values of the parameters passed

            struct DataNode *paramNode = constructNode(2);
            strcpy(paramNode->name,"parametersAssign");  //this node is empty ( no params) 
            paramNode->dtype = 8;
            insertChild(func,paramNode);


            //INSERT THE LIST OF STATEMENTS
            //ie; storing every instruction of the function
               struct DataNode *stmts = $<datanode>6;
               int numStatements = stmts->size;
               for(int i=0; i<numStatements; i++){
                  insertChild(func,stmts->children[i]);
               }


            $<datanode>$ = func;
         }


      
      | FUNC IDENTIFIER '(' paramdecl_list ')' '{' statements '}'
         {
            #if DEBUGTAG 
               printf(" ~RULE:fundecl --> ");
                  printf("FUNC IDENTIFIER '(' paramdecl_list ')'"); 
                  printf("'{' statements '}'\n");
            #endif           
            /*
               paramdecl_list has the names of the var that we should
               declare in the housekeeping instructions part, before the 
               statements
            */

            /* 
               - create a var, the func name  <- this happens now

               Housekeeping instructions (happens  later, on eval of that var )
               - create local varContainer (local scope)
               - declare parameters as vars 
               - create a parameter node that will do the assigning on 
                  funcall
            */ 

            //CREATE VAR FOR FUNCTION
            struct DataNode *func = constructNode(4);  
            strcpy(func->name,$<datanode->name>2); //IDENTIFIER
            func->dtype = 6; //function type

            ////// Below are instructions only. 
            // ie: will only get evaluated on a funcall/////
            ////////////////////////////////////////////////

            /*CREATE LOCAL VARCONTAINER (LOCAL SCOPE)*/
            //instruction: createNewScope
            struct DataNode *newScopeInst = constructNode(1);
            strcpy(newScopeInst->name,"createNewScope");
            newScopeInst->dtype = 8; //instruction type
            insertChild(func, newScopeInst);
            //^^when evaluated, this label creates new scope^^//
            
            /*DECLARE PARAMETERS AS VARS */
            //loop through param list here
            struct DataNode *paramList = $<datanode>4;
            for(int i=0; i<paramList->size; i++)
            {
               struct DataNode *declVarInst = constructNode(1);
               strcpy(declVarInst->name,"declareVar");
               declVarInst->dtype = 8;
               strcpy(declVarInst->children[0]->name, paramList->children[i]->name);
               //declVarInst->children[0] = paramList->children[i]; 
                  //^^^ not this because separating items from front and back 
               
               //printf("declVarInst->children[0]->name:   %s \n" ,declVarInst->children[0]->name);
               insertChild(func,declVarInst);
            }
            //

            //CREATE A PARAMETER NODE THAT WILL DO THE ASSIGNING ON FUNCALL
             //empty at first (on func declare)
             //will be used to store values of the parameters passed
            struct DataNode *paramNode = constructNode(2);
            strcpy(paramNode->name,"parametersAssign");
            paramNode->dtype = 8;
            insertChild(func,paramNode);


            //INSERT THE LIST OF STATEMENTS
               struct DataNode *stmts = $<datanode>7;
               int numStatements = stmts->size;
               for(int i=0; i<numStatements; i++){
                  insertChild(func,stmts->children[i]);
               }


            $<datanode>$ = func;

 //           #if DEBUGTAG 
               
               /*
               printf(" parameter node name: %s\n", $<datanode->name>4); 
               printf(" parameter node type: %d\n", $<datanode->dtype>4); 
               printf(" Parameter 1: %s\n", $<datanode->children[0]->name>4); 
               printf(" Parameter 2: %s\n", $<datanode->children[1]->name>4); 
               printf(" Parameter 3: %s\n", $<datanode->children[2]->name>4); 
               printf(" Parameter 4: %s\n", $<datanode->children[3]->name>4); 
               */
 //           #endif
         }
      ;

paramdecl_list:
        /*Instruction to declare vars */
        paramdecl
         {   
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl_list --> paramdecl \n ");
               //printf("$<datanode->name>$ : %s \n ",$<datanode->name>$ );
               //printf("$<datanode->name>1 : %s \n ",$<datanode->name>1 );
               //printf("$<datanode->name>$ : %p \n ",$<datanode>$ );
               //printf("$<datanode->name>1 : %p \n ",$<datanode>1 );
               //printf(" $<datanode->children[0]->name>1: %s\n", $<datanode->children[0]->name$); 
            #endif
            //$$ is an array of IDENTIFIER nodes
            //Its children are the IDENTIFIER parameters
            $<datanode>$ = constructNode(2);
            //$<datanode->dtype>$ = 7; //parameters  //FIXME: type 7 for var declaration list??? Useful?
                  //^^ This node is just a container for the var names of the parameters, not their values?
            //strcpy($<datanode->name>$,"parameters");
            insertChild($<datanode>$, $<datanode>1);

         }
      | paramdecl_list ':' paramdecl      
         {   
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl_list --> paramdecl_list : paramdecl \n ");
               printf(" $<datanode->name>$: %s\n", $<datanode->name>$); 
               //printf(" $<datanode->children[0]->name>$: %s\n", $<datanode->children[0]->name>$); 
            #endif
            
            //*USING DEFAULT YACC BEHAVIOUR: $$ = $1 *
            //paramdecl_list was already 'constructed' in 'paramdecl rule'.
            //inserting new paramdecl (IDENTIFIER) as a new children
            insertChild($<datanode>$, $<datanode>3);


         }
      ;

/* ! might conflict with vardecl */
/* this is a declaration of parameter, not for parameter passing on funcall */
paramdecl:
        IDENTIFIER    
         { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", $<datanode->name>1);
            #endif

            //$<datanode>$ = $<datanode>1;
         }

      | INTEGER /*FIXME should be intexpr */   
         { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", $<datanode->name>1);
            #endif
         }
/*
      | REAL    
         { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", $<datanode->name>1);
            #endif
         }


      | STRING    
         { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", $<datanode->name>1);
            #endif
         }


      | BOOLEAN    
         { 
            #if DEBUGTAG 
               printf(" ~RULE: paramdecl --> IDENTIFIER \n ");
               printf("IDENTIFIER name: %s \n ", $<datanode->name>1);
            #endif
         }
      ;
*/


expression:
        vardecl /* instruction node : "declareVar" */ 
         {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> vardecl \n");
            #endif
         }

      | funcall
         {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> funcall \n");
             //  printf("funcall dtype is: %d\n", $<datanode->dtype>1);          // DELETE ME
             //  printf("funcall name is: %s\n", $<datanode->name>1);            // DELETE ME
            #endif
         }

/*    | paramassign   FIXME: Not necessary??*/ 

      | IDENTIFIER
         {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> IDENTIFIER \n");
            #endif
         }

      /*
         expression + expression covers the different types case. 
         ID + ID case; int + ID ; ID + int; int + float ; 
         even int + str (which should cause error)
      */
      | expression '+' expression  
         {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> expression '+' expression \n");
            #endif

            //create operator + node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opPlus");
   
            //insert 2 operands as children
            insertChild(node,$<datanode>1);      
            insertChild(node,$<datanode>3);      

            $<datanode>$ = node ;
            
         }


      /*| IDENTIFIER '+' intexpr 
         {
            #if DEBUGTAG 
               printf(" ~RULE:  expression --> IDENTIFIER '+' intexpr \n");
            #endif
         }
      | IDENTIFIER '*' intexpr

      */


      /* | IDENTIFIER '+' floatexpr */
      /* | IDENTIFIER '+' strexpr */
      /* | IDENTIFIER '*' floatexpr */
      
      /*
      | IDENTIFIER '-'
      | IDENTIFIER '/'
      | IDENTIFIER '^'
      | IDENTIFIER MOD
      | IDENTIFIER EVAL
      */

      | intexpr 
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> intexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;

         }

      | strexpr     
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> strexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;
         }
               
      | ioexpr /* instruction node */
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> ioexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;

         }

      ;

/* expression -> funcall */
funcall: /* $$ should be the return value */
        IDENTIFIER '(' ')'
         {
            #if DEBUGTAG
               printf(" ~RULE: funcall -->  IDENTIFIER '(' ')' \n");   
            #endif

            // CREATE FUNCALL NODE
            struct DataNode *funcall = constructNode(2);
            funcall->dtype = 8; //instruction 
            strcpy(funcall->name,"funCall");
            

            //LEFT CHILD IS FUNCTION TO BE CALLED 
            insertChild(funcall,$<datanode>1);

            //RIGHT CHILD IS PARAMETER LIST TO BE ASSIGNED TO FUNCTION
            //FIXME FIXME Insert empty node as no param list but need for evaluate FIXME//
            struct DataNode *emptyParamList = constructNode(0);
            insertChild(funcall, emptyParamList); //paramassign_list
            $<datanode>$ = funcall;
         }
      | IDENTIFIER '(' paramassign_list ')'
         {
            #if DEBUGTAG
               printf(" ~RULE: funcall --> IDENTIFIER '(' paramassign_list ')'  \n");   
            #endif
                    
            //CALL FUNCTION HERE
            //CREATE FUNCTIOn call node
            /*
               - create funcall node
               - left child is function to be called 
                  - look for function name in varContainer 
               - right child is parameter list to be assigned to function
               - when funcall node gets evaluated.. it uses the 2 
            */

            // CREATE FUNCALL NODE
            struct DataNode *funcall = constructNode(2);
            funcall->dtype = 8; //instruction 
            strcpy(funcall->name,"funCall");
            

            //LEFT CHILD IS FUNCTION TO BE CALLED 
            insertChild(funcall,$<datanode>1);

            //RIGHT CHILD IS PARAMETER LIST TO BE ASSIGNED TO FUNCTION
            insertChild(funcall, $<datanode>3); //paramassign_list
            $<datanode>$ = funcall;
            //evaluate();

         }
      ;

/* REVIEW THIS 
funcall:
        IDENTIFIER '(' IDENTIFIER ')'
      | IDENTIFIER '(' st
*/

paramassign_list:
        paramassign
         {
            #if DEBUGTAG
               printf(" ~RULE: paramassign_list --> paramassign \n");    //DEBUG
            #endif
            //$$ is an array of IDENTIFIER nodes
            //Its children are the IDENTIFIER parameters
            $<datanode>$ = constructNode(2);
            //$<datanode->dtype>$ = 7; //parameters  FIXME should be for decl only ?
            //strcpy($<datanode->name>$,"parameters");
            insertChild($<datanode>$, $<datanode>1);

         }
      | paramassign_list ':' paramassign
         {
            #if DEBUGTAG
               printf(" ~RULE: paramassign_list --> paramassign_list ':' paramassign \n");    //DEBUG
            #endif
            insertChild($<datanode>$, $<datanode>3);
         }
      ;


paramassign:
        expression 
         {
            #if DEBUGTAG
               printf(" ~RULE: paramassign_list --> paramassign_list ':' paramassign \n");    //DEBUG
            #endif
         }

vardecl: 
        VAR IDENTIFIER    /*SEMI COLON HERE? FIXME */
         {
            #if DEBUGTAG
               printf(" ~RULE:vardecl --> VAR IDENTIFIER \n");    //DEBUG
            #endif
            
            //create instruction node: declareVar
            struct DataNode *node = constructNode(1);
            strcpy(node->name,"declareVar");
            node->dtype = 8; //instruction

            //insert the var as instruction node's child
            insertChild(node,$<datanode>2);
            $<datanode>$ = node;

            //This needs to happen ON EVALUATE only 
               //insert IDENTIFIER in varContainer (variable array)
               //ie: create var 
               //insertChild(varContainer,$<datanode>2);        
            ///////

            //$<datanode>$ = $<datanode>2;  //vardecl will be the IDENTIFIER
            
           // #if DEBUGTAG
               //int lastElement = varContainer->size - 1;
               //printf("%d \n", lastElement);
               //printf("varContainer->children[lastElement]->name: %s\n",
                 // varContainer->children[lastElement]->name);   

           // #endif
         }
      ;



assignexpr:
      IDENTIFIER '=' expression
         { 
            #if DEBUGTAG
               printf(" ~RULE: assignexpr --> IDENTIFIER '=' expression \n");    //DEBUG
            #endif
            
            //create operator node
            struct DataNode *node = constructNode(2) ;
            node ->dtype = 5 ; //operator type
            strcpy(node->name,"opEqual");
   
            //insert 2 operands as children
            insertChild(node,$<datanode>1);      
            insertChild(node,$<datanode>3);      

            /* ON EVALUATION
            //find the var node and insert it in operator node
            struct DataNode *var = findVar($<datanode->name>1); 
            insertChild(node, var); // pos = 0 
            insertChild(node, $<datanode>3) ;//pos = 1 
            */

            $<datanode>$ = node ;
            /*
            struct DataNode *node = findVar($<datanode->name>1);
            //printf("node->name: %s\n", node->name);    //DEBUG
            node->dtype = $<datanode->dtype>3;

            node->ival = $<datanode->ival>3;
            $<datanode>$ = node ; 
            */
               // TEMP: DELETE ME 
                  //var->dtype = 1;
                  //var->ival = $<datanode->ival>3;
                  //$<datanode>$ = var ;

               //

            #if DEBUGTAG
               //printf("$<datanode->children[0]->name>$: %s\n", 
                //  $<datanode->children[0]->name>$);
               //printf("$<datanode->children[0]->ival>$: %d\n",
                  //$<datanode->children[0]->ival>$);
            #endif
         }

/*      IDENTIFIER '=' strexpr
         { 
            #if DEBUGTAG
               printf(" ~RULE: assignexpr --> IDENTIFIER '=' strexpr \n");    //DEBUG
            #endif
            struct DataNode *node = findVar($<datanode->name>1);
            //printf("node->name: %s\n", node->name);    //DEBUG
            node->dtype = 2 ;
            node->ival = $<datanode->ival>3;
            $<datanode>$ = node ; 

            #if DEBUGTAG
               printf("$<datanode->name>$: %s\n", $<datanode->name>$);    //DEBUG
               printf("$<datanode->str>$: %d\n",$<datanode->str>$);    //DEBUG
            #endif
         }
*/

/*
      IDENTIFIER '=' floatexpr
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> ioexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;
         }
      
      IDENTIFIER '=' strexpr
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> ioexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;
         }
      IDENTIFIER '=' boolexpr
         { 
            #if DEBUGTAG
               printf(" ~RULE:expression--> ioexpr \n");    //DEBUG
            #endif

            $<datanode>$ = $<datanode>1;
         }
*/  
      ;

ioexpr: 
        PRINT '(' expression ')' 
         { 
            #if DEBUGTAG
               printf(" ~RULE:ioexpr --> PRINT '(' expression ')' \n");    //DEBUG
            #endif

            struct DataNode *io = constructNode(1);
            io->dtype = 8; //instruction type
            strcpy(io->name, "print");

            //insert expression Node as child 
            struct DataNode *expr = $<datanode>3 ;
            insertChild(io,expr);
            $<datanode>$ = io ;
            
            //BROKEN ? //EVALUATION
            /*
            if(io->children[0]->dtype == 1){
               printf("%d\n", io->children[0]->ival);  
            }else if(io->children[0]->dtype == 3){
               printf("%s\n", io->children[0]->str);    
            }
            */
         }


      | PRINT '(' IDENTIFIER ')' 
         { 
            #if DEBUGTAG
               printf(" ~RULE:ioexpr --> PRINT '(' IDENTIFIER ')' \n");    //DEBUG
            #endif

            struct DataNode *io = constructNode(1);
            io->dtype = 8; //instruction type
            strcpy(io->name, "print");

            
            //find and insert var in print node
            struct DataNode *var = findVar($<datanode->name>3);
            insertChild(io,var);
            $<datanode>$ = io ;
            
            /*
            if(io->children[0]->dtype == 1){
               printf("%d\n", io->children[0]->ival);  
            }else if(io->children[0]->dtype == 3){
               printf("%s\n", io->children[0]->str);    
            }
            
            #if DEBUGTAG
               if(io->children[0]->dtype == 1){
                  printf("io->children[0]->ival: %d\n", io->children[0]->ival);    //DEBUG
               }else if(io->children[0]->dtype == 3){
                  printf("io->children[0]->str: %s\n", io->children[0]->str);    //DEBUG
               }
            #endif

            */
         }

      ;


strexpr: 
        STRING 
         {
            #if DEBUGTAG
               printf(" ~RULE:strexpr--> STRING \n");    //DEBUG
            #endif
            
            $<datanode>$ = $<datanode>1;

            #if DEBUGTAG
               printf("%s is a string \n",$<datanode->str>1);
            #endif
         }
  
      ;

intexpr: 
        INTEGER
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
           

            //create operator + node
            struct DataNode *node = constructNode(2) ;
            node->dtype = 5 ; //operator type
            strcpy(node->name,"opPlus");
   
            //insert 2 operands as children
            insertChild(node,$<datanode>1);      
            insertChild(node,$<datanode>3);      

            $<datanode>$ = node ;

            //#if DEBUGTAG
               //printf("%d + %d is %d \n",$<datanode->ival>1, $<datanode->ival>3, $<datanode->ival>$);
               //printf("The address is %p \n",op);
               //printf("The address is %p \n",$<datanode>$);
            //#endif
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
   varContainer = constructNode(2);
   printf("Beginning syntax checking:\n\n");
   int result = yyparse();
   printf("\nSyntax checking complete\n\n");
   return result;
}


