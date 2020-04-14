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
   // for(int i=0; i<node->size; i++)
   // {
   //struct DataNode *child = node->children[i];

   //
   if(node->dtype == -1 ) {
      return node;


   //vardecl
   }else if(node->dtype == 0){
      
      //struct DataNode *var = findLocalVar(node->children[0]->name); //EVALUATE ?? FIXME

      //assuming inner scopes have full access to outer scopes
      return findVar(node->name);


      //return findLocalVar(node->name);

      //return node;

   }else if(node->dtype == 1){
      return node;


      //check if being passed a var of this type or literal
     // struct DataNode *variable = findVar(node->name);
     // if (variable->dtype == -1) return node;  //a literal
     // return variable ;                         //a variable

   }else if(node->dtype == 2){

   }else if(node->dtype == 3){

      return node;

   }else if(node->dtype == 4){

      return node;

   }else if(node->dtype == 5){
      //ASSIGNMENT 
      if(strcmp(node->name,"opEqual") == 0){
         //child 0 is variable | child 1 is expression to be assigned
         //can only assign to var "accessible in the current scope"





         
         //DELETE ME ///////////////////////

         //struct DataNode *var = findLocalVar(node->children[0]->name); //EVALUATE ?? FIXME

         //printf("var name is : %s", var->name); 
         
            //printf("\n\n   ~SCOPE address before evaluating leftChild : %p\n", varContainer);
         ////////////////////////////////////:w




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
            //return???
         }else if(rdt==2){        //real
            //default value is 0, just add all the values
            leftChild->fval= rightChild->fval ;
            leftChild-> dtype = 2 ;
         }else if(rdt==3){        //string
            strcat(leftChild->str, rightChild->str);
            leftChild-> dtype = 3 ;
         }else if(rdt==4){        //bool
            leftChild->bval= rightChild->bval ;
            leftChild-> dtype = 4 ;
         }

         /* 
         if(ldt==1 && rdt==1){              //int
            node->ival = leftChild->ival + rightChild->ival; 
            node -> dtype = 1 ;
         }else if((ldt==1 || rdt==2) && (ldt==1 || rdt==2)){        //real
            //default value is 0, just add all the values
            node->fval = leftChild->ival + leftChild->fval
                           + rightChild->ival + rightChild->fval ;
         }else if(ldt==3 && rdt==3){        //string
            strcat(leftChild->str, rightChild->str);
         }
         */


         //FIXME Do you ever need to return an opEqual node to someone???? 
         return leftChild ;



         //return node ; // value returned to caller




/////////////////////////////////////////////////////////////////////////







         //FIXME: for children[1] it should be evaluate(children[1])
         //          and return a node

         //"expr is a valid expression (of any data type)"
         //////DELETE ME /////////////////////////////////
         /*
         if(node->children[1]->dtype == 1){              //int
            var->dtype = 1;
            var->ival = node->children[1]->ival;

         }else if(node->children[1]->dtype == 2){        //real
            var->dtype = 2;
            var->fval = node->children[1]->fval;

         }else if(node->children[1]->dtype == 3){        //string
            var->dtype = 3;
            strcpy(var->str, node->children[1]->str);

         }else if(node->children[1]->dtype == 4){        //bool
            var->dtype = 4;
            var->bval = node->children[1]->bval;
         }
         */
         /////////////////////////////////////////////////////////////
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
            //strcat(leftChild->str, rightChild->str);
            strcpy(result->str,str);
            node -> dtype = 3 ;
         }

         //BOOL FIXME
 
         result->parent = programContainer;
         insertChild(programContainer, result);

         return result ; // value returned to caller


         /*

            int dt1 = node->children[0]->dtype ;
            int dt2 = node->children[1]->dtype ;

         if(dt1==1 && dt2==1){              //int
            node->ival = node->children[0]->ival + node->children[1]->ival ;
         }else if((dt1==1 || dt2==2) && (dt1==1 || dt2==2)){        //real
            //default value is 0, just add all the values
            node->fval = node->children[0]->ival + node->children[0]->fval
               + node->children[1]->ival + node->children[1]->fval ;
         }else if(dt1==3 && dt2==3){        //string
            strcat(node->children[0]->str, node->children[1]->str);
         }

         */
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


         //printf("VARCONTAINER->CHILDREN[0] name is %s \n", varContainer->children[0]->name);
      
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


         //DELETE ME
         //printf("HERE IN VAR DECLARE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n");

         insertChild(varContainer,node->children[0]);

      //FUNCTION RETURN VAL    | return |
      //returnInstr node is a Node with a single child:
      //the expression to be evaluated and returned
      }else if(strcmp(node->name,"returnInstr") == 0){
         struct DataNode *localRetVal = evaluate(node->children[0]);         
         struct DataNode *retVal = copyNode(localRetVal);        
         retVal->parent = programContainer; //to be deleted at program end
         insertChild(programContainer, retVal);

         
         /*
         ///DELETE ME /// 
         printf("\n\n\n\n");
         for(int i=0; i<varContainer->size; i++){
            printf("COMING OUT: varContainer->children[%d]->name is: %s \nvarContainer->ival[%d] is: %d \n",
                  i,  varContainer->children[i]->name, i, varContainer->children[i]->ival);
          }
         printf("\n\n\n\n");
         /////////////////
         */






         
         //destroy local scope
         struct DataNode *localScope = varContainer;
         varContainer = varContainer -> parent; 

         localScope->parent = NULL;
         freeNode(localScope);
         return retVal;


      //PARAMETERS ASSIGNMENT
      }else if(strcmp(node->name,"parametersAssign") == 0){
         
         //DELETE ME
         //printf("PARAMETERS HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n");

         va_list paramList;
         va_start(paramList,node); //node is the last 'named' argument of evaluate
         //getting param node
         struct DataNode *parameters = va_arg(paramList, struct DataNode *);

         int numParams = parameters -> size ; //nb of parameters
            //printf("PARAMETERS HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n");    //DELETE ME
            //printf("node -> size is : %d \n !!!!!!!!!!!!!     \n", numParams);                   //DELETE ME
         for(int i=0;i<numParams;i++)
         {
            //printf("PARAMETERS HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n")       //DELETE ME;
          
            //DELETE ME ///////////////
            struct DataNode *parameter = evaluate(parameters->children[i]);
            
            //DELETE ME 
            //printf("\n\nparam name is: %s \n\n ", parameter->name);
            //printf("\n\nparam type is: %d \n\n ", parameter->dtype);
            ///////////////////////////////////////////
            
            //
            varContainer->children[i]->dtype = parameter->dtype;
            varContainer->children[i]->ival = parameter->ival;
            varContainer->children[i]->fval = parameter->fval;
            strcpy(varContainer->children[i]->str, parameter->str);
            varContainer->children[i]->bval = parameter->bval;
            
            ///////////////////////////////////
            
            /*
            varContainer->children[i]->dtype = parameters->children[i]->dtype;
            varContainer->children[i]->ival = parameters->children[i]->ival;
            varContainer->children[i]->fval = parameters->children[i]->fval;
            strcpy(varContainer->children[i]->str, parameters->children[i]->str);
            varContainer->children[i]->bval = parameters->children[i]->bval;
            */



            //printf("VARCONTAINER->CHILDREN[%d];  With varname %s; value is now: %d \n",             //DELETE ME
            //   i, varContainer->children[i]->name, 
            //  varContainer->children[i]->ival);
            //
            //FIXME
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
         
            //printf("\n\n\nNAME IS %s\n\n",node->children[0]->name);

         //FIXME: RETURN VALUE NEEDED HERE??
            //struct DataNode *funcName = node->children[0]; //name of function to be called

            struct DataNode *func = findVar(node->children[0]->name); //returns actual node of function to be called
         //printf("\n\n\nPARAMETERS HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n");
            struct DataNode *params = node->children[1]; //parameters to be passed to function
         /////DELETE ME FIXME ///////////////////////////////
         // printf("EVALUATING FUNCTION NAME: %s \n", func->name);
         //printf("EVALUATING FUNCTION NAME: %s \n", node->children[0]->name);
         /////////////////////////////////////////////////////// 
         
         //printf("\n\n\n params->name: %s \n\n\n",params->name);
         return evaluate(func, params);  //TODO : Add return here : *return = evaluate ... 

      //
      //node->dtype == 8
      //CREATE NEW SCOPE
      }else if(strcmp(node->name,"createNewScope") == 0){
            
         //printf("\n\n\nPARAMETERS HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                 \n\n\n");
         #if FUNCDEBUG
            printf("\n\n   ~SCOPE CHG~ address GLOBAL scope is : %p\n", varContainer);
         #endif
         
         /*
         ///DELETE ME /// 
         printf("\n\n\n\n");
         for(int i=0; i<varContainer->size; i++){
            printf("COMING IN: varContainer->children[%d]->name is: %s \n varContainer->ival[%d] is: %d \n",
                  i,  varContainer->children[i]->name, i, varContainer->children[i]->ival);
         }
         printf("\n\n\n\n");
         /////////////////
         */

         struct DataNode *localVarContainer = constructNode(2);
         //make current scope a parent of new local scope 
         localVarContainer->parent = varContainer;
         //make new local scope the new varContainer
         varContainer = localVarContainer;

         
         ///DELETE ME /// 
         printf("\n\n\n\n");
         for(int i=0; i<varContainer->size; i++){
            printf("AT CREATION: varContainer->ival[%d] is: %d \n",i, varContainer->children[i]->ival);
         }
         printf("\n\n\n\n");
         /////////////////
        




         #if FUNCDEBUG
            printf("            ...address of new LOCAL scope is : %p\n", varContainer);
            printf("            ...address of parent scope is: %p \n\n", varContainer->parent);
         #endif

      //node->dtype == 8
      //PRINT STATEMENT
      }else if(strcmp(node->name,"print") == 0){
         
         //- First evaluate child node recursively
         //- Then, print the child node's return value, based on its type
         //printf("child info %s \n\n\n\n ", node->children[0]->name);
         //printf("child info %d \n\n\n\n ", node->children[0]->dtype);

         struct DataNode *child = evaluate(node->children[0]); 

            //printf( " \n\n\n HERERERERERE \n\n\n\n");
            //printf( " \n child -> dtype %d \n", child->dtype);
         //printf("child->name: %s \n\n\n\n",child->name); 
           // printf("Type of child: %s \n", child -> name);
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
         //ELSE EVALUATE??? ///
         //FIXME
            //else{evaluate(node->children[0]) ;}  
         //FIXME
         return child;

//
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
   //}//for loop
}


struct DataNode* findVar(char* varName)
{
   //FIXME DELETE ME////////
   //struct DataNode *deleteMe = constructNode(0);
   //strcpy(deleteMe->name,"deleteMe");
   //deleteMe->ival=0;
   ////////////////

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

   /*
   do{
      for(int i=0; i<localVarContainer->size; i++)
      {
         //if the var exists
         //and the var is NOT of type 0 (ie: uninitialized)...
         if(strcmp(localVarContainer->children[i]->name,varName) == 0)
         {
            //printf("Parent is NULL? : %d\n",localVarContainer->parent == NULL);
            //printf("localVarContainer size: %d\n",localVarContainer->size);
            return localVarContainer->children[i];
            //printf("Found var \n");

            //if(localVarContainer->children[i]->dtype != 0) // ie: var is uninitialized
            //{   return localVarContainer->children[i]; }

            //here: var is found but dtype is 0 FIXME: add error msg
         }
      }
      //IF NOT FOUND LOCALLY, FINDVAR IN VARCONTAINER'S PARENT 
         //
         //FIXME : localVarContainer = localVarContainer -> parent ; 

      //localVarContainer = localVarContainer->parent;
      //return deleteMe;
   }while(localVarContainer->parent != NULL);

   //DELETE ME ////////FIXME
   //printf("Oops: VAR doesn't exist!\n");
   //return deleteMe;
   ///////^^^^DELETE ME^^^^ ////////

   //here: var is NOT found
   //THERE SHOULD BE AN ERROR UP HERE IF VAR NOT FOUND FIXME: add error msg
   */

   /*
   //DELETE ME ////////FIXME
   struct DataNode *deleteMe = constructNode(0);
   strcpy(deleteMe->name,"deleteMe");
   deleteMe->ival=deleteMe->fval=deleteMe->bval=0;
   strcpy(deleteMe->str,"\0");
   printf("Oops: VAR %s doesn't exist in this scope!\n", varName);
   return deleteMe;
   ///////^^^^DELETE ME^^^^ ////////
   */

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

   /*
   //FIXME DELETE ME////////
   struct DataNode *deleteMe = constructNode(0);
   strcpy(deleteMe->name,"deleteMe");
   deleteMe->ival=0;
   printf("Oops: VAR %s doesn't exist in this scope!\n", varName);
   return deleteMe;
   ////////////////
   //FIXME : here var is NOT found
   //THERE SHOULD BE AN ERROR UP HERE IF VAR NOT FOUND FIXME: add error msg
   */
}
   


/*
   void declareVar(struct DataNode *var)
   {

   return;
//set children to 0
//set every field to 0 except name
//use constructNode(0);

//eg:
//declareVar alpha;
//
//struct DataNode *node = constructNode(0);
//node -> type = var->type;
//node -> name = var->name;
//HERE there should be a statement to assign alpha to mem
}
*/
//for: string, boolean, integer or real
void setConstant(struct DataNode* con)
{
   //set children to 0
   //set every field to 0 except name
   //use constructNode(0);

   //eg: This could hold: 3
   //
   //struct DataNode *node = constructNode(0);
   //node -> type = con->type;
   //if(con->type = 1) node -> ival = con->ival;
   //if(con->type = 2) node -> fval = con->fval;
   //if(con->type = 3) node -> str = con->str;
   //if(con->type = 4) node -> bval = con->bval;
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



/*
   struct DataNode* setOperator(char* operator, struct OpNode *op, 
   struct DataNode leftOperand, struct DataNode rightOperand)
   {

   strcpy(op->operator,operator);
   int lot = leftOperand.dtype ;
   int rot = rightOperand.dtype;

   struct DataNode *node = constructNode(1) ;

   if(strcmp(operator, "+") == 0)
   {
   if(lot==1 && rot==1){ //int
   node->dtype = 1;
   node->ival = leftOperand.ival + rightOperand.ival;

   }
//if(lot==2 && rot==2 || lot==1 && lot==2 || lot==2 && rot==1) //float
}         

return node;

}
*/
