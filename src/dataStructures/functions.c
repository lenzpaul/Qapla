#define FUNCDEBUG 0

#include "Nodes.h"
#include "functions.h"

#include <stdarg.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//evaluates a node and all its children
struct DataNode* evaluate(struct DataNode *node, ...)
{
   //bad evaluation
   if(node->dtype == -1 ) {
      return node;


      //vardecl
   }else if(node->dtype == 0){

      //assuming inner scopes have full access to outer scopes
      return findVar(node->name);
      //return findLocalVar(node->name);

   //int
   }else if(node->dtype == 1){
      return node;


      //check if being passed a var of this type or literal
      // struct DataNode *variable = findVar(node->name);
      // if (variable->dtype == -1) return node;  //a literal
      // return variable ;                         //a variable

   //real
   }else if(node->dtype == 2){
      return node;
   //string
   }else if(node->dtype == 3){

      return node;
   //bool
   }else if(node->dtype == 4){

      return node;
     
   //operators
   }else if(node->dtype == 5){

      //ASSIGNMENT 
      if(strcmp(node->name,"opEqual") == 0){
         //child 0 is variable | child 1 is expression to be assigned
         //can only assign to var "accessible in the current scope"


         //result will hold value to be returned
         struct DataNode *result = constructNode(1) ;

         //Expression to evaluate. 
         //The result of which we assign to the leftChild
         struct DataNode *rightChild = evaluate(node->children[1]); 

         //evaluating variable [NECESSARY?!]
         struct DataNode *leftChild = evaluate(node->children[0]); //var to assign to 


         //int ldt = leftChild->dtype;
         int rdt = rightChild->dtype;

         if(rdt==1){              //int
            leftChild->ival = rightChild->ival; 
            leftChild-> dtype = 1 ;
         }else if(rdt==2){        //real
            //default value is 0, just add all the values
            leftChild->fval= rightChild->fval ;
            leftChild-> dtype = 2 ;
         }else if(rdt==3){        //string
            strcpy(leftChild->str, rightChild->str);
            leftChild-> dtype = 3 ;
         }else if(rdt==4){        //bool
            leftChild->bval= rightChild->bval ;
            leftChild-> dtype = 4 ;
         }

         return leftChild ;

      }


      //node->dtype == 5
      //Addition + 
      if(strcmp(node->name,"opPlus") == 0){
         //First, evaluate both children recursively
         //leftChild is the return val of leftChild evaluation
         //rightChild the right one

         //ADD 2 children if string
         //Concatenate if both are string
         //Float + Int = Floatexpr
         //NOT valid for bool


         struct DataNode *result = constructNode(2);
         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         int ldt = leftChild->dtype;
         int rdt = rightChild->dtype;


         if(ldt==1 && rdt==1){              //int
            result->ival = leftChild->ival + rightChild->ival; 
            result -> dtype = 1 ;
         }else if((ldt==1 || rdt==2) && (ldt==1 || rdt==2)){        //real
            //default value is 0, just add all the values
            result->fval = leftChild->ival + leftChild->fval
               + rightChild->ival + rightChild->fval ;
            result -> dtype = 2 ;
         }else if(ldt==3 && rdt==3){        //string
            char str[4096];
            strcat(str, leftChild->str);
            strcat(str, rightChild->str);
            strcpy(result->str,str);
            result -> dtype = 3 ;
         }

         //N/A to BOOLEAN type


         result->parent = programContainer;
         insertChild(programContainer, result);

         return result ; // value returned to caller

      }else if (strcmp(node->name,"opMinus") == 0){
         //First, evaluate both children recursively
         //leftChild is the return val of leftChild evaluation
         //rightChild the right one

         //ADD 2 children if string
         //Concatenate if both are string
         //Float + Int = Floatexpr
         //NOT valid for bool


         struct DataNode *result = constructNode(2);
         result->parent = programContainer;
         insertChild(programContainer, result);

         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         int ldt = leftChild->dtype;
         int rdt = rightChild->dtype;


         if(ldt==1 && rdt==1){              //int
            result->ival = leftChild->ival - rightChild->ival; 
            result -> dtype = 1 ;
         }else if((ldt==1 || rdt==2) && (ldt==1 || rdt==2)){        //real
            //default value is 0, just add all the values
            result->fval = leftChild->ival - leftChild->fval
               - rightChild->ival - rightChild->fval ;
            result -> dtype = 2 ;
         }

         //N/A to BOOLEAN type


         return result ; // value returned to caller



      //multiplication
      }else if(strcmp(node->name,"opTimes") == 0){
         //First, evaluate both children recursively
         //leftChild is the return val of leftChild evaluation
         //rightChild the right one

         struct DataNode *result = constructNode(2);
         result->parent = programContainer;
         insertChild(programContainer, result);

         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         int ldt = leftChild->dtype;
         int rdt = rightChild->dtype;

         //int
         if(ldt==1 && rdt==1){              
            result->ival = leftChild->ival * rightChild->ival; 
            result -> dtype = 1 ;

         //real
         }else if(ldt==1 && rdt==2){ 
            result->fval = leftChild->ival * rightChild->fval;
            result -> dtype = 2 ;
         }else if(ldt==2 && rdt==1){
            result->fval = leftChild->fval * rightChild->ival;
            result -> dtype = 2 ;
         }else if(ldt==2 && rdt==2){ 
            result->fval = leftChild->fval * rightChild->fval;
            result -> dtype = 2 ;
         }

         //N/A to BOOLEAN type or string

         return result ; // value returned to caller


      //division
      }else if(strcmp(node->name,"opDiv") == 0){
         //First, evaluate both children recursively
         //leftChild is the return val of leftChild evaluation
         //rightChild the right one

         struct DataNode *result = constructNode(2);
         result->parent = programContainer;
         insertChild(programContainer, result);

         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         int ldt = leftChild->dtype;
         int rdt = rightChild->dtype;

         //int
         if(ldt==1 && rdt==1){              
            result->ival = leftChild->ival / rightChild->ival; 
            result -> dtype = 1 ;

         //real
         }else if(ldt==1 && rdt==2){ 
            result->fval = leftChild->ival / rightChild->fval;
            result -> dtype = 2 ;
         }else if(ldt==2 && rdt==1){
            result->fval = leftChild->fval / rightChild->ival;
            result -> dtype = 2 ;
         }else if(ldt==2 && rdt==2){ 
            result->fval = leftChild->fval / rightChild->fval;
            result -> dtype = 2 ;
         }

         //N/A to BOOLEAN type or string

         return result ; // value returned to caller

      }

      //dtype 5 cont'd --> boolean operators
      if(strcmp(node->name,"opAND") == 0){
         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 

         //to delete at program end life
         struct DataNode *result = constructNode(1);
         result->parent = programContainer ;
         insertChild(programContainer, result);


         result->bval = leftChild->bval && rightChild->bval;   
         result->dtype=4;
         return result;

      }

      if(strcmp(node->name,"opOR") == 0){
         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 

         //to delete at program end life
         struct DataNode *result = constructNode(1);
         result->parent = programContainer ;
         insertChild(programContainer, result);

         result->bval = leftChild->bval || rightChild->bval;   
         result->dtype=4;
         return result;

      }

      if(strcmp(node->name,"opNOT") == 0){

         //printf("\n\n\n\n HERE \n\n\n " ) ;
         struct DataNode *child = evaluate(node->children[0]);

         //to delete at program end life
         struct DataNode *result = constructNode(1);
         result->parent = programContainer ;
         insertChild(programContainer, result);

         result->bval = !child->bval ;
         result->dtype=4;
         return result;

      }

      //if we find these labels,
      //evaluate, compare, and return boolean
      if(strcmp(node->name,"opLT") == 0){
         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         struct DataNode *result = constructNode(1);

         //to delete at program end life
         result->parent = programContainer ;
         insertChild(programContainer, result);



         //printf("WE GET HERE \n\n\n\n");
         int ldt = leftChild->dtype; 
         int rdt = rightChild->dtype; 

         if( (ldt == 1 ) && (rdt == 1) ) {
            result->bval = leftChild->ival < rightChild->ival; 
            result->dtype = 4 ;
            return result;
         }else if ( (ldt==1 && rdt==2) || (ldt==2 && rdt==1) 
               || (ldt==2 && rdt==2) ){ 
            result->bval = (leftChild->ival + leftChild->fval) < 
               (leftChild->ival + rightChild->fval); 
            result->dtype = 4 ;
            return result;

         }else if (ldt == 3 && rdt == 3 )  {  
            result->bval = (strcmp(leftChild->str, rightChild->str) ) < 0;
            result->dtype = 4 ;
            return result;

         }
      }

      //node->dtype == 5 cont'd
      if(strcmp(node->name,"opEVAL") == 0){    // ==

         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         struct DataNode *result = constructNode(1);

         //to delete at program end life
         result->parent = programContainer ;
         insertChild(programContainer, result);
         result->bval = false;
         result->dtype = 4 ;

         int ldt = leftChild->dtype; 
         int rdt = rightChild->dtype; 

         if( (ldt == 1 ) && (rdt == 1) ) {
            result->bval = leftChild->ival == rightChild->ival; 
         }else if ( ldt==2 && rdt==2 ) { 
            result->bval = leftChild->fval == rightChild->fval; 

         }else if (ldt == 3 && rdt == 3 )  {  
            result->bval = (strcmp(leftChild->str, rightChild->str) ) == 0;
         }else if (ldt == 4 && rdt == 4 )  {  
            result->bval = leftChild->fval == rightChild->fval; 

         }
         return result;

      }

      if(strcmp(node->name,"opNEQ") == 0){
         struct DataNode *leftChild = evaluate(node->children[0]);
         struct DataNode *rightChild = evaluate(node->children[1]); 
         struct DataNode *result = constructNode(1);


         //to delete at program end life
         result->parent = programContainer ;
         insertChild(programContainer, result);


         int ldt = leftChild->dtype; 
         int rdt = rightChild->dtype; 

         node -> bval = true;
         if( (ldt == 1 ) && (rdt == 1) ) {
            result->bval = leftChild->ival != rightChild->ival; 
            result->dtype = 4 ;
            return result;
         }else if ( ldt==2 && rdt==2 ) { 
            result->bval = leftChild->fval != rightChild->fval; 
            result->dtype = 4 ;
            return result;

         }else if (ldt == 3 && rdt == 3 )  {  
            result->bval = (strcmp(leftChild->str, rightChild->str) ) != 0;
            result->dtype = 4 ;
            return result;

         }

      }


   }else if(node->dtype == 6){                           //function
      // || functions ||


      /* FUNCTION EVALUATION */
      //for functions, evaluate() should always be called with 2 parameters
      //  - parameter 1: function to evaluate
      //  - parameter 2: parameter node 
      //     (node containing parameters as its children.
      //      Will have 0 children (size 0) if no parameters)


      /* 
       *    - local varContainer was already created 
       *       (its the first 'housekeeping' node of a func declaration,
       *         just need to evaluate it)
       *
       */


      //get parameters node
      va_list paramList;
      va_start(paramList,node); //node is the last 'named' argument of evaluate

      //getting param node
      struct DataNode *parameters = va_arg(paramList, struct DataNode *);
      //int numParams = parameters->size;


      //evaluate every node in the function 
      //when function gets called, evaluate every one of its children
      //child 0 (housekeeping) : create localVarContainer (local scope)
      //child 1+ (housekeeping) : declare a var in local scope for every param 
      //... this will happen for as many times as there are parameters,
      //or 0 times if there aren't any

      //Next children are instructions (ie: happen on funcall only): 
      // - Assign passed values to the params. 
      //    These are stored in parameters argument as a va_list
      // - Evaluate (execute) every statement (the function body).
      //    Note: The function body is an array

      //nb of instructions in the function - 1 
      //the last one is the return value
      //[this node is paramassign_list from yacc file] 
      int instructsCount = node->size ;
      for(int i=0; i<instructsCount-1; i++) 
         evaluate(node->children[i], parameters); 



      //last statment returned to caller
      struct DataNode *localRetVal = 
         evaluate(node->children[instructsCount - 1], parameters); 

      struct DataNode *retVal = copyNode(localRetVal);        
      retVal->parent = programContainer;
      //insertChild(programContainer, retVal);


      va_end(paramList);


      return retVal;


      /*
      //CASE 1: w/o parameters
      if(numParams == 0) 
      {
      //FIXME
      //return ? ;
      }
      //printf("PARAMETERS 1 : %d \n" , parameters->children[0]->ival);
      */

      //CASE 2: with parameters
      //assign, positionally, the parameters provided to varContainer 
      //parameters declared



      /*
      //FIXME This doesnt actually happen here
      //This happens on evaluate(functionName, parameters)
      for(int i=0;i<numParams;i++)
      {
      varContainer->children[i]->dtype = parameters->children[i]->dtype;
      varContainer->children[i]->ival = parameters->children[i]->ival;
      varContainer->children[i]->fval = parameters->children[i]->fval;
      strcpy(varContainer->children[i]->str, parameters->children[i]->str);
      varContainer->children[i]->bval = parameters->children[i]->bval;
      printf("VARCONTAINER->CHILDREN[%d];  With varname %s; value is now: %d \n", 
      i, varContainer->children[i]->name, 
      varContainer->children[i]->ival);
      //
      //FIXME
      }
      */


   }else if(node->dtype == 7){

      //INSTRUCTIONS
   }else if(node->dtype == 8){

      //VAR DECLARATION
      if(strcmp(node->name,"declareVar") == 0){ 
         //insert IDENTIFIER in varContainer (variable array of current scope)
         //ie: create var 

         insertChild(varContainer,node->children[0]);

         //FUNCTION RETURN VAL    | return |
         //returnInstr node is a Node with a single child:
         //the expression to be evaluated and returned
      }else if(strcmp(node->name,"returnInstr") == 0){
         struct DataNode *localRetVal = evaluate(node->children[0]);         
         struct DataNode *retVal = copyNode(localRetVal);        
         retVal->parent = programContainer; //to be deleted at program end
         insertChild(programContainer, retVal);



         //destroy local scope
         struct DataNode *localScope = varContainer;
         varContainer = varContainer -> parent; 

         localScope->parent = NULL;
         freeNode(localScope);
         return retVal;


         //PARAMETERS ASSIGNMENT
      }else if(strcmp(node->name,"parametersAssign") == 0){

         va_list paramList;
         //node is the last 'named' argument of evaluate
         va_start(paramList,node); 
         //getting param node
         struct DataNode *parameters = va_arg(paramList, struct DataNode *);

         int numParams = parameters -> size ; //nb of parameters
         for(int i=0;i<numParams;i++)
         {

            struct DataNode *parameter = evaluate(parameters->children[i]);

            varContainer->children[i]->dtype = parameter->dtype;
            varContainer->children[i]->ival = parameter->ival;
            varContainer->children[i]->fval = parameter->fval;
            strcpy(varContainer->children[i]->str, parameter->str);
            varContainer->children[i]->bval = parameter->bval;

         }

         va_end(paramList);  

         //node->dtype == 8
         //FUNCTION CALL 
      }else if(strcmp(node->name,"funCall") == 0){
         // - evaluate leftChild, which is a function Node (dtype 6)
         //MUST also pass optional argument of parameter node to evaluate
         //even if there are no parameters
         //(in which case, the parameter node size will be 0, and nothing
         // will be done with the parameter node)


         //returns actual node of function to be called
         struct DataNode *func = findVar(node->children[0]->name); 
         //parameters to be passed to function
         struct DataNode *params = node->children[1]; 
         return evaluate(func, params);  

         //
         //node->dtype == 8
         //CREATE NEW SCOPE
      }else if(strcmp(node->name,"createNewScope") == 0){

         //printf("\n\n\nPARAMETERS HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n");
#if FUNCDEBUG
         printf("\n\n   ~SCOPE CHG~ address GLOBAL scope is : %p\n", varContainer);
#endif

         struct DataNode *localVarContainer = constructNode(2);
         //make current scope a parent of new local scope 
         localVarContainer->parent = varContainer;
         //make new local scope the new varContainer
         varContainer = localVarContainer;

#if FUNCDEBUG
         printf("            ...address of new LOCAL scope is : %p\n", varContainer);
         printf("            ...address of parent scope is: %p \n\n", varContainer->parent);
#endif

         //node->dtype == 8
         //PRINT STATEMENT
      }else if(strcmp(node->name,"print") == 0){

         //- First evaluate child node recursively
         //- Then, print the child node's return value, based on its type

         struct DataNode *child = evaluate(node->children[0]); 
         if(child->dtype == 1){              //int
            printf("%d\n", child->ival);  
         }else if(child->dtype == 2){        //real
            printf("%f\n", child->fval);    
         }else if(child->dtype == 3){        //string
            printf("%s\n", child->str);    
         }else if(child->dtype == 4){        //bool
            (child->bval) ? 
               printf("true\n") : printf("false\n");
         }
         return child;

         //node->dtype == 8
         //SELECTION IF ELSE
      }else if(strcmp(node->name,"selectBlock") == 0){   
         //select block is an array of 
         //ifBlock, elseIfBlock(s) or elseBlock

         //evaluate its children until one return true
         //nb: selection must have bool condition (cannot be if () ) 
         int condBlockCount = node->size ;
         bool conditionMet = node -> bval;  //starts at false

         for(int i=0; i<condBlockCount; i++) {
            struct DataNode *currentBlock = evaluate(node->children[i]) ;
            conditionMet = currentBlock->bval;
            if(conditionMet) break;
         }
         //nothing to return??

         //node->dtype == 8
      }else if(strcmp(node->name,"ifBlock") == 0){   

         struct DataNode *currentBlock = evaluate(node->children[0]) ;//condition
         bool conditionMet = currentBlock->bval;

         int instructsCount = node->size;  //number of statements

         //printf("child 0 is %s " , node -> children[0] ->name);

         if(conditionMet){
            for(int i=0; i<instructsCount; i++)
               evaluate(node->children[i]);
         }
         node->bval = conditionMet;
         return node;


         //node->dtype == 8
      }else if(strcmp(node->name,"elseIfBlock") == 0){


         struct DataNode *currentBlock = evaluate(node->children[0]) ;//condition
         bool conditionMet = currentBlock->bval;

         int instructsCount = node->size;  //number of statements

         if(conditionMet){
            for(int i=0; i<instructsCount; i++)
               evaluate(node->children[i]);
         }
         node->bval = conditionMet;
         return node;

         //node->dtype == 8
      }else if(strcmp(node->name,"elseBlock") == 0){   

         int instructsCount = node->size;  //number of statements
         for(int i=0; i<instructsCount; i++)
            evaluate(node->children[i]);

         node->bval = true;
         return node;
      }
   }else if(node->dtype == 9){


   }
}


struct DataNode* findVar(char* varName)
{

   struct DataNode *localVarContainer = varContainer;

   while(localVarContainer != NULL) 
   {
      for(int i=0; i<localVarContainer->size; i++)
      {
         //if the var exists
         if(strcmp(localVarContainer->children[i]->name,varName) == 0)
         {
            return localVarContainer->children[i];
         }
      }
      //not found in local scope, look in next greater scope
      localVarContainer = localVarContainer->parent;
   }

   //var not found
   printf("Oops: VAR %s doesn't exist in this scope!\n", varName);
   return dummyNode;

}

struct DataNode* findLocalVar(char* varName)
{
   for(int i=0; i<varContainer->size; i++)
   {
      //if the var exists
      //and the var is NOT of type 0 (ie: uninitialized)...
      if(strcmp(varContainer->children[i]->name,varName) == 0)
      {
         return varContainer->children[i];
      }
   }
   //not found in local scope
   return dummyNode;

}



void setOperator(char *operator, struct DataNode *op,
      struct DataNode *leftOperand, struct DataNode *rightOperand)
{
   //create an OpNode and insert in parent 
   op->dtype = 5;
   strcpy(op->name, operator);
   op->children[0] = leftOperand;
   op->children[1] = rightOperand;
}

