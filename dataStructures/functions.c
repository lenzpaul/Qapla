#include "Nodes.h"
#include "functions.h"

#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//evaluates a node and all its children
struct DataNode evaluate(struct DataNode *node)
{
   // for(int i=0; i<node->size; i++)
   // {
   //struct DataNode *child = node->children[i];

   //vardecl
   if(node->dtype == 0){

   }else if(node->dtype == 1){

   }else if(node->dtype == 2){

   }else if(node->dtype == 3){
   }else if(node->dtype == 4){
   }else if(node->dtype == 5){
      //ASSIGNMENT (DONT LOOP!)
      if(strcmp(node->name,"opEqual") == 0){
         //child 0 is variable | child 1 is expression to be assigned
         //can only assign to var "accessible in the current scope"
         struct DataNode *var = findLocalVar(node->children[0]->name);
         //printf("OPEQUAL\n");                         //DELETE
         if(node->children[1]->dtype == 1){              //int
            var->dtype = 1;
            var->ival = node->children[1]->ival;
            //printf("HERE!!!!!!!!!!!!!!\n");            //DELETE

         }else if(node->children[1]->dtype == 2){        //real
            var->dtype = 2;
            var->fval = node->children[1]->fval;

         }else if(node->children[1]->dtype == 3){        //string
            var->dtype = 3;
            strcpy(var->str, node->children[1]->str);

         }else if(node->children[1]->dtype == 4){        //bool
            //FIXME
         }
      }
   }else if(node->dtype == 6){
   }else if(node->dtype == 7){

      //INSTRUCTIONS
   }else if(node->dtype == 8){

      //var declaration
      if(strcmp(node->name,"declareVar") == 0){ 
         //insert IDENTIFIER in varContainer (variable array of current scope)
         //ie: create var 
         insertChild(varContainer,node->children[0]);

         //print statement
      }else if(strcmp(node->name,"print") == 0){
         //print the child node's value, based on its type
         if(node->children[0]->dtype == 1){              //int
            printf("%d\n", node->children[0]->ival);  
         }else if(node->children[0]->dtype == 2){        //real
            printf("%f\n", node->children[0]->fval);    
         }else if(node->children[0]->dtype == 3){        //string
            printf("%s\n", node->children[0]->str);    
         }else if(node->children[0]->dtype == 4){        //bool
            //FIXME
         }
      } 
   }else if(node->dtype == 9){
   }
   //}//for loop
}


struct DataNode* findVar(char* varName)
{
   //FIXME DELETE ME////////
   struct DataNode *deleteMe = constructNode(0);
   strcpy(deleteMe->name,"y");
   deleteMe->ival=0;
   ////////////////

   struct DataNode *localVarContainer = varContainer;
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
      //if not found locally, findVar in parent

      //FIXME DELETE ME ////////
      //printf("ONCE!");
      //////////

      //localVarContainer = localVarContainer->parent;
      //return deleteMe;
   }while(localVarContainer->parent != NULL);

   //DELETE ME ////////FIXME
   printf("out of the loop!");
   return deleteMe;
   ///////^^^^DELETE ME^^^^ ////////

   //here: var is NOT found
   //THERE SHOULD BE AN ERROR UP HERE IF VAR NOT FOUND FIXME: add error msg

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
   //FIXME : here var is NOT found
   //THERE SHOULD BE AN ERROR UP HERE IF VAR NOT FOUND FIXME: add error msg
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
