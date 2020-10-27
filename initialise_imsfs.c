#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char *name;                         //name of node
//     char *path;                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int num_children;                       //number of children
// 
//     char *data;						//data for read and write
//     unsigned long int data_len;
// 
// } imsfs_tree_node;


void initialise_imsfs(){

    root = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node) + 1); // Malloc the root. Now we can enter data.
    // printf("Root node at location %p\n", root);

    root -> isfile = 0;

    root -> name = (char *) malloc(sizeof(char) + 1);
    strcpy(root -> name, "/"); // Root is also named '/'

    root -> path = (char *) malloc(sizeof(char) + 1);
    strcpy(root -> path, "/");

    root -> parent = NULL;
    root -> children = NULL;
    root -> num_children = 0;

    root -> data = NULL;
    root ->data_len = 0;
}

