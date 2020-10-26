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


void print_node_data(const imsfs_tree_node *node){

    printf("Name of file: %s\n", node.name);

    printf("Path relative to mountpoint: ");
    int i = 0;
    char *next = path[1];
    while(strcmp(curr, "$")){ // $ represents end of string
        printf("%s/", path[i]);
        i++;
        curr = path[i + 1];
    }
    printf("%s\n", path[i]);

    if(node.isfile){
        printf("FILE\n");
    }
    else{
        printf("DIRECTORY\n");
    }

    printf("Parent: %s\n", node.parent);

    printf("Number of children: %d\n", node.num_children);

    for(int i = 0; i < node.num_children){
        printf("Child number %d: %s\n", i + 1, node.children[i]);
    }
    printf("\n");

    printf("Size of file in bytes: %ld\n", node.data_len);

}
