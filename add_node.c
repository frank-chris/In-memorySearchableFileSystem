#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char name[MAX_NAME_SIZE];                         //name of node
//     char *path;                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int num_children;                       //number of children
// 
//     char *data;						//data for read and write
//     long int data_len;
// 
// } imsfs_tree_node;


imsfs_tree_node *add_node(const char *path_to_add, char *name, bool file){
    //file == 1 if file, file == 0 if directory

    imsfs_tree_node *tmp_node = get_node(path_to_add);
    // We will add the file/directory on this node
    
    if(!tmp_node){
        error_msg("NULL returned by get_node()", "Invalid Path");
    }


}

