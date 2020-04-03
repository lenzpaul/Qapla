
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "growingTree.c"

void declareVar(struct DataNode var)
{
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
