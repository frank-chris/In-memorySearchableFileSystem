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


imsfs_tree_node *add_dir_node(const char *parent_path, const char *name){

    imsfs_tree_node *parent_node = get_node(parent_path);
    if(!parent_node){
        error_msg("NULL returned by get_node()", "Invalid Path");
        return NULL;
    }
    // We will add the directory on this node

    int pathlen = strlen(parent_path) + strlen(name) + 2;
    char *fullpath = (char *)malloc(sizeof(char) * pathlen + 1);
    if(!fullpath){
        perror("Malloc():");
    }
    strcat(fullpath, parent_path);
    strcat(fullpath, "/");
    strcat(fullpath, name);
    if(get_node(fullpath)){
        error_msg("get_node()", "Path already exists.");
        return NULL;
    }

    imsfs_tree_node *new_node = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node) + 1);
    
    parent_node -> num_children++;
    parent_node -> children = realloc(parent_node -> children, sizeof(imsfs_tree_node *) * parent_node -> num_children);
    parent_node -> children[parent_node -> num_children - 1] = new_node;

    new_node -> isfile = 0;
    new_node -> name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node -> name, name);
    new_node -> path = (char *)malloc(pathlen);
    strcpy(new_node -> path, fullpath);
    new_node -> parent = parent_node;
    new_node -> children = NULL;
    new_node -> num_children = 0;
    new_node -> data = NULL;
    new_node -> data_len = 0;
    root -> permissions = DIR_PERM;

    return new_node;
}

