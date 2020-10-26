#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char name[MAX_NAME_SIZE];                         //name of node
//     char *path[MAX_PATH_DEPTH];                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int num_children;                       //number of children
// 
//     char *data;						//data for read and write
//     long int data_len;
// 
// } imsfs_tree_node;


void initialise_imsfs(){

    root = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node)); // Malloc the root. Now we can enter data.
    // printf("Root node at location %p\n", root);

    root -> isfile = 0;

    root -> name = NULL; // Root has no file name or directory name

    root -> path[0] = (char *) malloc(sizeof(char));
    strcpy(root -> path[0], "/");
    root -> path[1] = (char *) malloc(sizeof(char));
    strcpy(root -> path[1], "$");

    root -> parent = NULL;
    root -> children = NULL;
    root -> num_children = 0;

    root -> data = NULL;
    root ->data_len = 0;
}

