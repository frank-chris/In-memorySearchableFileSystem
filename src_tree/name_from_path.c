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


char *name_from_path(const char *path){
    printf("call to function: NAME_FROM_PATH, parent_path: %s\n",path);

    if(strcmp(path, "/") == 0)
        return NULL;

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
    
    i++;
    int name_len = pathlen - i;
    char *name = (char *)malloc(sizeof(char) * name_len + 1);
    int j = 0;
    while(i < pathlen){
        name[j] = path[i];
        j++;
        i++;
    }

    name[name_len]='\0';
    printf("Extracted name: %s\n",name);
    printf("Returning from NAME_FROM_PATH\n");

    return name;
}

