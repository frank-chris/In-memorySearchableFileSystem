#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char name;                         //name of node
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


void print_node_data(imsfs_tree_node *node){

    printf("Name of file: %s\n", node -> name);

    printf("Path relative to mountpoint: %s\n", node -> path);

    if(node -> isfile){
        printf("FILE\n");
    }
    else{
        printf("DIRECTORY\n");
    }

    printf("Parent: %p\n", node -> parent);

    printf("Number of children: %d\n", node -> num_children);

    for(int i = 0; i < node -> num_children; i++){
        printf("Child number %d: %p\n", i + 1, node -> children[i]);
    }
    printf("\n");

    printf("Size of file in bytes: %ld\n", node -> data_len);

    printf("Permissions of the node: %u\n",node->permissions);

    printf("\n");
}
