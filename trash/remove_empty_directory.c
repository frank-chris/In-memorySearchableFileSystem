#include "tree.h"

/**
-> int remove_empty_dir(char *path);
* Return -2 if file exists on path
* -1 if path invalid, 
* 0 if path valid but directory not empty. 
* 1 if path exists and directory is empty
*/

int remove_empty_dir(char *path);

int free_empty_dir_node(imsfs_tree_node* node);

int remove_empty_dir(char *path){
    imsfs_tree_node* cur_node = get_node(path);

    return remove_empty_dir(cur_node);

}

/*
-> int free_empty_dir_node(imsfs_tree_node* node);
* -2 if file node
* -1 if node null
* 0 if directory not empty
* 1 if success
*/

int free_empty_dir_node(imsfs_tree_node* node){
    if (!node) return -1; // null node
    else if (node->isfile) return -2; // not a directory
    else if (node->num_children) return 0; // not empty
    else {
        imsfs_tree_node* parent_node = node->parent; //get parent node
    
        for (int i=0; i<parent_node->num_children; i++){
            if (!strcmp(parent_node->children[i]->name,cur_node->name)){
                
                imsfs_tree_node* to_free = parent_node->children[i];
                parent_node->children[i] = NULL;

                free(to_free -> name);
                free(to_free -> path);
                free(to_free -> parent);
                free(to_free -> data);
                free(to_free -> children);

                break;
            }
        }
        return 1; //success
    }
}