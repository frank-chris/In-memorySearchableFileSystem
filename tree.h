#ifndef IMSFS_TREE_H
#define IMSFS_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 256
#define MAX_PATH_DEPTH 20
// size in bytes = 1 + 256 + 8 + 8 + 8 + 4 + 8 + 8 = 301
#define NODE_SIZE 301



typedef struct imsfs_tree_node {
    bool isfile;                        
    char name[MAX_NAME_SIZE];                         //name of node, file/directory
    char *path[MAX_PATH_DEPTH];                     //full path of node, stored as an array of directories
    
    struct imsfs_tree_node *parent;        //link to parent
    struct imsfs_tree_node **children;      //links to children
    int num_children;                       //number of children

    char *data;						//data for read and write
    long int data_len;

} imsfs_tree_node;

// Root
fs_tree_node *root;

// Initialise
void initialise_imsfs();


#endif
