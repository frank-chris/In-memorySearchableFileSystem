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
 * Frees memory of file_ node. 
 * Return -2 if directory node, 
 * -1 if node is null, 
 * 1 for success
*/

int free_file_node(imsfs_tree_node *file_node){
    if(!file_node){
        return -1;
    }

    if(file_node -> isfile == false){
        return -2;
    }

    // If parent originally had greater mex, it now has new mex equal to this position
    imsfs_tree_node *parent_node = file_node -> parent;
    int pos = find_pos(file_node, parent_node);
    parent_node -> children[pos] = NULL;
    // Very important, no deallocation takes place here
    // The pointer to the imsfs_tree_node structure still occupies its 8 bytes
    // However it points to NULL
    // This is so that we have no problems in freeing up memory later
    // free() on NULL is a safe "no-op"
    
    if((parent_node -> mex) > pos){
        parent_node -> mex = pos;
    }

    // Freeing up starts here
    // Only free up malloc'd or realloc'd variables
    // Free up in reverse order of assignment
    free(file_node -> data);
    file_node -> data = NULL;
    free(file_node -> path);
    file_node -> path = NULL;
    free(file_node -> name);
    file_node -> name = NULL;
    free(file_node);
    file_node = NULL;

    return 1; // success
}

