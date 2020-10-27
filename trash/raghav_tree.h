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
    char *path;                                  //full path of node, stored as an array of directories
    
    struct imsfs_tree_node *parent;        //link to parent
    struct imsfs_tree_node **children;      //links to children
    int num_children;                       //number of children

    char *data;						//data for read and write
    unsigned long int data_len;
    //time_t last_access_time;
    //time_t last_modification_time;

} imsfs_tree_node;

// Root
imsfs_tree_node *root;

// // Initialise
// void initialise_imsfs();

// imsfs_tree_node* get_node_from_path(const char* path);


//Amey
void initialise_imsfs(); //Initialises the data structure. Defines a root node and current node that keeps track of where we are

void print_node_data(imsfs_tree_node *node); //Prints node data

imsfs_tree_node *get_node(char *path); //Takes path string, resolves it into an existing node from the tree and returns that. Otherwise NULL

// void add_node(char *parent_path, char *name, bool file); //Adds node named “name” at parent_path

char *name_from_path(char *path); //Extracts name from entire path (everything after last ‘/’)

char *parent_from_path(char *path); //Extracts parent address from entire path (everything before last ‘/’)

imsfs_tree_node *parent_node_from_path(char *path); //Returns parent node from the given path, NULL if invalid path

imsfs_tree_node *add_file_node(char *parent_path, char *name); //Adds node named “name” at parent_path

imsfs_tree_node *add_dir_node(const char *parent_path, const char *name); //Adds node named “name” at parent_path

imsfs_tree_node* get_file_node(char *path); //Takes path as argument and return the pointer to the node only if it is a file node, return NULL if the node is a directory node or if the path is invalid

imsfs_tree_node* get_dir_node(char *path); //Takes path as argument and return the pointer to the node only if it is a directory node, return NULL if the node is a file node or if the path is invalid

int remove_empty_dir(char *path); //Return -2 if file exists on path, -1 if path invalid, 0 if path valid but directory not empty. 1 if path exists and directory is empty

int recursive_remove_dir(char *path); //Return -2 if file exists on path, -1 if path invalid, 1 if path exists and directory node

#endif