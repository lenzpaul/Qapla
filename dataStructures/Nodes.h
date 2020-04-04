#ifndef NODES_H
#define NODES_H

#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>

//dtypes: 0:var, 1:int, 2:float, 3:str, 4:bool, 5:operator,
//        6:functions, 7: io, 8:while


//default container for IDENTIFIERs, INTEGERs, REALs, 
//STRINGs, BOOLs, and FUNCTIONs 
struct DataNode {
   struct DataNode *parent;
   struct DataNode **children ;
   size_t size;
   size_t capacity;

   long ival, dtype; 
   double fval;
   char str[4096], name[256]; 
   bool bval;
};

//
typedef union { 
   struct DataNode *datanode;
} YYSTYPE;


//variables container
//struct DataNode varContainer



//expects a capacity, returns the new node
struct DataNode* constructNode(size_t capacity);

void insertChild(struct DataNode *node, struct DataNode *element);

void freeNode(struct DataNode *node) ;


#endif
