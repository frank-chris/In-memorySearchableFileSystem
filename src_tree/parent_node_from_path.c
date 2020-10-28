#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char *name;                         //name of node
//     char *path;                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int end_of_children;                       //number of children
// 
//     char *data;						//data for read and write
//     unsigned long int data_len;
// 
// } imsfs_tree_node;


imsfs_tree_node *parent_node_from_path(const char *path){
    char *parent_path = parent_from_path(path);
    if(!parent_path){
        error_msg("parent_from_path()", "Invalid Path");
        return NULL;
    }
    return get_node(parent_path);
}

