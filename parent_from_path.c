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


char *parent_from_path(const char *path){
    if(strcmp(path, "/"))
        return path; // Root is the special case

    int pathlen = strlen(path);
    bool found = false;
    int i;
    for(i = pathlen - 1; i >= 0; i--){
        if(path[i] == '/'){
            found = true;
            break;
        }
    }
    if(!found){
        error_msg("name_from_path()", "Invalid path");
        return NULL;
    }
    
    int dir_len = i;
    char *dir = (char *)malloc(sizeof(char) * dir_len + 1);
    int j = 0;
    while(j < dir_len){
        dir[j] = path[j];
        j++;
    }
    return dir;
}

