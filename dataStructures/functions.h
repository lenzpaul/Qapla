#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Nodes.h"
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>






//void declareVar(struct DataNode var);

//for: string, boolean, integer or real
//void setConstant(struct DataNode* con);


void setOperator(char *operator, struct DataNode *op);
//   struct DataNode *leftOperand, struct DataNode *rightOperand);



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

#endif
