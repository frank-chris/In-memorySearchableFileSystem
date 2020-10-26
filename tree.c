#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char name[256];                         //name of node
//     char path;                     //full path of node
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int num_children;                       //number of children
// 
//     char **data;						//data for read and write
//     long int data_len;
// 
// } imsfs_tree_node;



imsfs_tree_node* root;

void initialize_imsfs(){

    root = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node)); // Malloc the root. Now we can enter data.
    // printf("Root node at location %p\n", root);

    root -> isfile = 0;

    root -> name = NULL; // Root has no file name or directory name

    root -> path = (char *) malloc(sizeof(char));
    strcpy(root -> path, "/");

    root -> parent = NULL;
    root -> children = NULL;
    root -> num_children = 0;

    root -> data = NULL;
    root ->data_len = 0;
}


