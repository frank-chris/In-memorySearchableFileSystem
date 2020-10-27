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

#include <fuse.h>

#define MAX_NAME_SIZE 256
#define MAX_PATH_DEPTH 20
// size in bytes = 1 + 8 + 8 + 8 + 8 + 4 + 8 + 8 = 301
#define NODE_SIZE 53

void error_msg(const char *msg, const char *reason);


typedef struct imsfs_tree_node {
    bool isfile;                        
    char *name;                         //name of node, file/directory
    char *path;                     //full path of node, stored as an array of directories
    
    struct imsfs_tree_node *parent;        //link to parent
    struct imsfs_tree_node **children;      //links to children
    int num_children;                       //number of children

    char *data;						//data for read and write
    unsigned long int data_len;

} imsfs_tree_node;

// Root
imsfs_tree_node *root;

// Current Node we are on
imsfs_tree_node *cur_node;

// Initialise
void initialise_imsfs();

void print_node_data(imsfs_tree_node *node);
imsfs_tree_node *get_node(const char *path);
imsfs_tree_node *add_file_node(const char *parent_path, const char *name);
imsfs_tree_node *add_dir_node(const char *parent_path, const char *name);
char *name_from_path(const char *path);
char *parent_from_path(const char *path);
imsfs_tree_node *parent_node_from_path(const char *path);
#endif
