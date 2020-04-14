
#include <stdlib.h> 
#include <stdio.h>

struct Node {
   size_t size;
   size_t capacity;

   struct Node *parent;
   //array of children ptr
   struct Node **children ;
} ;//*root;

struct Node* constructNode(size_t capacity){
   struct Node* node;
   //allocate memory for new node
   node = malloc(sizeof(struct Node));

   node->children = malloc(capacity * sizeof(struct Node));
   node->size = 0;
   node->capacity = capacity;

   return node;
}

void insertChild(struct Node *node, struct Node *element){
   //grow if necessary
   if (node->size == node->capacity) {
      node->capacity *= 2;
      node->children = realloc(node->children, 
            node->capacity * sizeof(struct Node));
   }
   //insert
   node->children[node->size++] = element;

}

void freeNode(struct Node *node) {
   //free each innder node
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
   struct Node *root = constructNode(1);
   struct Node *node1 = constructNode(1);
   struct Node *node2 = constructNode(1);
   struct Node *node3 = constructNode(1);

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
