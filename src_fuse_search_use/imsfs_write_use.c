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
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char *name;                         //name of node
//     char *path;                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int end_of_children;                       //number of children
//     int mex;                                 // lowest unfilled location
// 
//     char *data;						//data for read and write
//     unsigned long int data_len;
//
//     unsigned int permissions;        // Permissions
// 
// } imsfs_tree_node;

int imsfs_write_use (const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi){

    printf("***************************************\n");
    printf("WRITE USE FILE\n");

    printf("path passed to imsfs_write_use: %s\n",path);

    char* file_name = get_file_name_use(path);

    if (!file_name) return -ENOENT;

    imsfs_tree_node* cur_node = get_node_from_search_buffer(file_name);
    
    if (!cur_node){
        free(file_name);    
        return -ENOENT;
    }

    printf("data length of file before write: %lu\n",cur_node->data_len);
    
    unsigned long int data_len = cur_node->data_len;

    long int end = offset + (long int)size;
    
    if (end>data_len){
        cur_node->data = realloc (cur_node->data, sizeof(char)*end + 1);
        if (!cur_node->data) return -ENOMEM;
        else{
            cur_node->data_len=end;
        }
    }

    strncpy(cur_node->data + offset, buf, size);
    cur_node->data[end]='\0';

    printf("data length of file after write: %lu\n",cur_node->data_len);
    int ret_val = size;
    printf("returning from imsfs_write with return value: %d\n",ret_val);

    printf("***************************************\n");
    
    free(file_name);
    return size;
}