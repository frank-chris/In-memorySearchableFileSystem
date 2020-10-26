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


// in bits = 8 + (256*8) + 32 + 32 + 32 + 32 + 8 + 64 + (16*8) + (16*8) + (16*8) + 64 + 64 = 2768 = 346 bytes
// size in bytes = 1 + 256 + 8 + 8 + 8 + 4 + 8 + 8 = 301
#define NODE_SIZE 301


typedef struct imsfs_tree_node {
    bool isfile;                        
    char name[256];                         //name of node, file/directory
    char *path;                     //full path of node
    
    struct imsfs_tree_node *parent;        //link to parent
    struct imsfs_tree_node **children;      //links to children
    int num_children;                       //number of children

    char **data;						//data for read and write
    long int data_len;

} imsfs_tree_node;

#endif
