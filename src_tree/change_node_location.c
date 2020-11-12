#include "tree.h"
#include "search_use_query.h"

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
 * Changes location of the node at oldpath to newpath. 
 * Return -2 if oldpath a directory, 
 * -1 if oldpath invalid, 
 * 0 if newpath invalid, 
 * 1 for success. 
 * Also, return -3 if newpath already exists but it points to a directory
*/


int change_filenode_location(const char *oldpath, const char *newpath){
    imsfs_tree_node *cur = get_node(oldpath);

    //Remove from search buffer if it exists there
    remove_node_from_search_buffer(cur);

    if(!cur){
        return -1; // Invalid old path
    }

    if((cur -> isfile) == false){
        return -2; // We need oldpath to point to a file
    }

    
    imsfs_tree_node *cur_parent = parent_node_from_path(oldpath);
    imsfs_tree_node *parent_node = parent_node_from_path(newpath);
    
    if(!parent_node){
        return 0;
    }

    imsfs_tree_node *existing = get_node(newpath);

    if(existing){ // If a node at that location already exists
        if((existing -> isfile) == false){
            return -3;
        }
        free_file_node(existing);
    }
    int pos = find_pos(cur, cur_parent);
    cur_parent -> children[pos] = NULL;
    if(pos < (cur_parent -> mex)){
        cur_parent -> mex = pos;
    }
    int cur_mex = parent_node -> mex;
    if(cur_mex == (parent_node -> end_of_children)){
        parent_node -> end_of_children++;
        parent_node -> children = realloc(parent_node -> children, sizeof(imsfs_tree_node *) * parent_node -> end_of_children);
    }
    parent_node -> children[cur_mex] = cur;
    assign_mex(parent_node);
    cur -> parent = parent_node;

    // Changing the name and path of cur
    free (cur->name);
    cur->name = name_from_path(newpath);

    free(cur->path);
    cur->path = (char*)malloc(sizeof(char)*strlen(newpath)+1);
    strcpy(cur->path, newpath);

    return 1;
}

