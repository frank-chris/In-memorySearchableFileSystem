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


imsfs_tree_node *get_file_node(const char *path){
    imsfs_tree_node *cur = get_node(path);
    if(!cur)
        return NULL;

    if(cur -> isfile == 0)
        return NULL;

    return cur;
}

