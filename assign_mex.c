#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char *name;                         //name of node
//     char *path;                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int end_of_children;                       //number of children
//     int mex;                                 // lowest unfilled location
// 
//     char *data;						//data for read and write
//     unsigned long int data_len;
//
//     unsigned int permissions;        // Permissions
// 
// } imsfs_tree_node;


void assign_mex(imsfs_tree_node *parent_node){
    int i = 0;
    while(i < (parent_node -> end_of_children)){
        if((parent_node -> children[i]) == NULL){
            break;
        }
        i++;
    }
    parent_node -> mex = i;
}

