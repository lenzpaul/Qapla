#include "Nodes.h"
#include "functions.h"

#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//evaluates a node and all its children
struct DataNode evaluate(struct DataNode *node)
{
   for(int i=0; i<node->size; i++)
   {
      struct DataNode *child = node->children[i];
      
      //vardecl
      if(child->dtype == 0){
           
      }else if(child->dtype == 1){

      }else if(child->dtype == 2){

      }else if(child->dtype == 3){
      }else if(child->dtype == 4){
      }else if(child->dtype == 5){
      }else if(child->dtype == 6){
      }else if(child->dtype == 7){
      }else if(child->dtype == 8){
      }else if(child->dtype == 9){
      }
   }
}


struct DataNode* findVar(char* varName)
{
   for(int i=0; i<varContainer->size; i++)
   {
      //if the var exists
      //and the var is NOT of type 0 (ie: uninitialized)...
      if(strcmp(varContainer->children[i]->name,varName) == 0)
      {
         
         return varContainer->children[i];

         //printf("Found var \n");

         //if(varContainer->children[i]->dtype != 0) // ie: var is uninitialized
         //{   return varContainer->children[i]; }
        
         //here: var is found but dtype is 0 FIXME: add error msg
      }
   }

   //here: var is NOT found
   //THERE SHOULD BE AN ERROR UP HERE IF VAR NOT FOUND FIXME: add error msg
    
}

void declareVar(struct DataNode var)
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
