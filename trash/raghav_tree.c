#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char name[MAX_NAME_SIZE];                         //name of node
//     char *path[MAX_PATH_DEPTH];                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int num_children;                       //number of children
// 
//     char *data;						//data for read and write
//     long int data_len;
// 
// } imsfs_tree_node;

void initialise_imsfs(){
    root = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node)); // Malloc the root. Now we can enter data.
    // printf("Root node at location %p\n", root);

    root -> isfile = 0;
    strcpy(root->name,"/");
    // root -> name = NULL; // Root has no file name or directory name

    // root -> path[0] = (char *) malloc(sizeof(char));
    // strcpy(root -> path[0], "/");
    // root -> path[1] = (char *) malloc(sizeof(char));
    // strcpy(root -> path[1], "$");

    root -> path = (char*)malloc(sizeof(char)*2);
    strcpy(root->path,"/");

    root -> parent = NULL;
    root -> children = NULL;
    root -> num_children = 0;

    root -> data = NULL;
    root ->data_len = 0;

    //root->last_access_time=time(NULL);
    //root->last_modification_time=time(NULL);
}



/* Raghav
imsfs_tree_node* get_node_from_path(const char* path){
    //base case
    if (!strcmp(path,"/")) return root;
    if (path[0]!='/') return NULL;

    //setup
    int path_len=strlen(path);
    char* path_name=malloc((strlen(path)+5)*sizeof(char));
    strcpy(path_name,path);
    if (path[path_len-1]=='/') path_name[path_len-1]='\0';
    path_name++;

    //start searching
    imsfs_tree_node* cur_node=root;
    char* index=strchr(path_name,'/');
    char cur_name[MAX_NAME_SIZE+1];
    while(index!=NULL){
        strncpy(cur_name,path_name,index-path_name);
        cur_name[index-path_name]='\0';
        int valid_name=0;
        for (int i=0;i<cur_node->num_children;i++){
            if (!strcmp(cur_node->children[i]->name,cur_name)){
                cur_node=cur_node->children[i];
                valid_name=1;
                break;
            }
        }
        if (!valid_name) return NULL;
        path_name=index+1;
        index=strchr(path_name,'/');
    }
    strcpy(cur_name,path_name);
    for (int i=0;i<cur_node->num_children;i++){
        if (!strcmp(cur_node->children[i]->name,cur_name)){
            cur_node=cur_node->children[i];
            break;
        }
    }
    free(path_name);
    free(cur_name);
    return NULL;
}
*/

// void initialise_imsfs(){

//     root = (imsfs_tree_node *)malloc(sizeof(imsfs_tree_node)); // Malloc the root. Now we can enter data.
//     // printf("Root node at location %p\n", root);

//     root -> isfile = 0;

//     root -> name = NULL; // Root has no file name or directory name

//     root -> path[0] = (char *) malloc(sizeof(char));
//     strcpy(root -> path[0], "/");

//     root -> parent = NULL;
//     root -> children = NULL;
//     root -> num_children = 0;

//     root -> data = NULL;
//     root ->data_len = 0;
// }