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


int rename_node(const char *old_path, const char *new_path){
    if(get_node(new_path)){
        // printf("Path at %s already exists.\n", new_path);
        return -1;
    }

    imsfs_tree_node *parent_node = parent_node_from_path(new_path);
    if(!parent_node){
        // printf("Parent at %s does not exist.\n", new_path);
        return -1;
    }

    imsfs_tree_node *cur = get_node(old_path);
    imsfs_tree_node *cur_parent = parent_node_from_path(old_path);
    int pos = find_pos(cur, cur_parent);
    cur_parent -> children[pos] = NULL;
    if(pos < (cur_parent -> mex)){
        cur_parent -> mex = pos;
    }
    // Node disconnected from parent node

    char *new_name = name_from_path(new_path);
    free(cur -> name);
    cur -> name = NULL;
    int new_len = strlen(new_path);
    cur -> name = malloc(sizeof(char) * (new_len + 1));
    for(int i = 0; i < new_len; i++){
        cur -> name[i] = new_name[i];
    }
    cur -> name[new_len] = '\0';

    int cur_mex = parent_node -> mex; // Parent node of new node
    if(cur_mex == (parent_node -> end_of_children)){
        parent_node -> end_of_children++;
        parent_node -> children = realloc(parent_node -> children, sizeof(imsfs_tree_node *) * parent_node -> end_of_children);
    }
    parent_node -> children[cur_mex] = cur;
    assign_mex(parent_node);
    cur -> parent = parent_node;

    // Changing the path of cur

    return recursive_path_update(parent_from_path(new_path), cur);
}

