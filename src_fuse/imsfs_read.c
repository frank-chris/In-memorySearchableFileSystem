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

//data_len -> length of string (excluding NULL character)

int imsfs_read (const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi){
    printf("READ FILE\n");
    imsfs_tree_node* cur_node = get_node(path);
    if (!cur_node) return -ENOENT;

    if (cur_node->isfile==0) return -EISDIR; //is a directory

    unsigned long int data_len = cur_node->data_len;

    long int start = offset;
    long int end = offset+(int)size; 

    if (start<0) start=0;
    else if (start>=data_len) return 0;

    if (end<=start) return 0;
    else if (end>data_len) end=data_len;

    char* data_pointer=cur_node->data;
    strncpy(buf,data_pointer+start,end-start);

    return end-start;
}