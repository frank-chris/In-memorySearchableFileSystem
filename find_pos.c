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


int find_pos(imsfs_tree_node *child, imsfs_tree_node *parent_node){
    if(!child){
        return -1;
    }

    char *child_name = child -> name;

    int i = 0;
    while(i < (parent_node -> end_of_children)){
        imsfs_tree_node *cur_child = parent_node -> children[i];
        if(!cur_child){
            i++;
            continue;
        }
        char *curname = cur_child -> name;
        if(strcmp(curname, child_name) == 0){
            i++;
            return i;
        }
    }
    return -1;
}

