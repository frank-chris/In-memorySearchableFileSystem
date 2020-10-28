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

/**
 * Return -2 if file exists on path, 
 * -1 if path invalid, 
 * 0 if path valid but directory not empty. 
 * 1 if path exists and directory is empty(success)
*/


int remove_empty_dir(const char *path){
    imsfs_tree_node *cur = get_node(path);

    if(!cur){
        return -1;
    }

    if(cur -> isfile == true){
        return -2;
    }

    if(!check_leaf(cur)){ // If the directory is not empty (no leaves)
        return 0;
    }

    return free_dir_node_recursive(cur);
}

