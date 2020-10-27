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


imsfs_tree_node *add_file_node(const char *parent_path, const char *name){
    printf("call to function: ADD_FILE_NODE, parent_path: %s, child_name: %s\n",parent_path, name);

    imsfs_tree_node *parent_node = get_node(parent_path);
    if(!parent_node){
        error_msg("NULL returned by get_node()", "Invalid Path");
        return NULL;
    }
    // We will add the file/directory on this node

    int pathlen = strlen(parent_path) + strlen(name) + 2;
    char *fullpath = (char *)malloc(sizeof(char) * pathlen + 1);
    if(!fullpath){
        perror("Malloc():");
    }
    strcat(fullpath, parent_path);
    strcat(fullpath, "/");
    strcat(fullpath, name);
    if(get_node(fullpath)){
        free(fullpath);
        fullpath = NULL;
        error_msg("get_node()", "Path already exists.");
        return NULL;
    }

    imsfs_tree_node *new_node = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node) + 1);
    
    int cur_mex = parent_node -> mex;
    if(cur_mex == (parent_node -> end_of_children)){
        parent_node -> end_of_children++;
        parent_node -> children = realloc(parent_node -> children, sizeof(imsfs_tree_node *) * parent_node -> end_of_children);
    }
    parent_node -> children[cur_mex] = new_node;
    assign_mex(parent_node);

    new_node -> isfile = 1;
    new_node -> name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node -> name, name);
    new_node -> path = (char *)malloc(pathlen);
    strcpy(new_node -> path, fullpath);
    new_node -> parent = parent_node;
    new_node -> children = NULL;
    new_node -> end_of_children = 0;
    new_node -> data = NULL;
    new_node -> data_len = 0;
    root -> permissions = FILE_PERM;

    free(fullpath);
    fullpath = NULL;

    printf("New file node pointer: %p\n",new_node);
    printf("Returning from ADD_FILE_NODE\n");

    return new_node;
}

