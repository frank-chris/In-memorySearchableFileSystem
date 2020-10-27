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


char *parent_from_path(const char *path){
    printf("call to function: PARENT_FROM_PATH, parent_path: %s\n",path);

    char *dir = (char *)malloc(sizeof(char) + 1);
    if(!strcmp(path, "/"))
        return dir; // Root is the special case

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

    //Special case -> "/file.txt", extracted parent should be "/"

    if (dir_len==0){
        strcpy(dir,"/");
    }
    else{
        dir = (char *)realloc(dir, sizeof(char) * dir_len + 1);
        int j = 0;
        while(j < dir_len){
            dir[j] = path[j];
            j++;
        }

        dir[dir_len]='\0';
    }

    printf("Extracted parent: %s\n",dir);
    printf("Returning from ADD_FILE_NODE\n");
    return dir;
}

