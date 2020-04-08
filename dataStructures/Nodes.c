#include "Nodes.h"
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>

//dtypes: 0:var, 1:int, 2:float, 3:str, 4:bool, 5:operator

//expects a capacity, returns the new node
struct DataNode* constructNode(size_t capacity){
   struct DataNode* node;
   //allocate memory for new node
   node = malloc(sizeof(struct DataNode));

   if(capacity > 0)
   {   
      node->children = malloc(capacity * sizeof(struct DataNode *));

      //initialize children? FIXME
      for(int i=0; i<capacity; i++){
         struct DataNode *child = malloc(sizeof(struct DataNode));
         node->children[i] = child;
      }
   }
   node->size = 0;
   node->capacity = capacity;
   return node;
}






struct DataNode* insertChild(struct DataNode *node, struct DataNode *element){
   //grow if necessary
   if (node->size == node->capacity) {
      node->capacity *= 2;
      node->children = realloc(node->children, 
            node->capacity * sizeof(struct DataNode));
   }
   //insert
   node->children[node->size++] = element;
   return node;
}

void freeNode(struct DataNode *node) {
   //free each inner node
   for(int i=node->size-1; i>=0; i--){
      free(node->children[i]);
      node->children[i] = NULL;
   }
   //free array of nodes
   free(node->children);
   node->children = NULL;

   //free root
   free(node);
   node->size = node->capacity = 0;
   node = NULL;
}






/*
   int main()
   {


//construct root with 1 child capacity
struct DataNode *root = constructNode(1);
struct DataNode *node1 = constructNode(1);
struct DataNode *node2 = constructNode(1);
struct DataNode *node3 = constructNode(1);

//create nodes and insert as child to root
insertChild(root, node1);
insertChild(root, node2);
insertChild(root, node3);
insertChild(root, constructNode(1));
insertChild(root, constructNode(1));

root->children[3]->size = 4;
root->children[3]->size = 4;
//print new size and capacity
printf("%d\n", root->size);
printf("%d\n", root->capacity);
freeNode(root);
}

*/
