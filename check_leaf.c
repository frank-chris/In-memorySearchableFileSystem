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


bool check_leaf(imsfs_tree_node *cur){
    if(!cur){
        return false;
    }

    if(cur -> isfile){
        return true;
    }

    for(int i = 0; i < (cur -> end_of_children); i++){
        imsfs_tree_node *child = cur -> children[i];
        if(child != NULL){
            return true;
        }
    }
    return false;
}

