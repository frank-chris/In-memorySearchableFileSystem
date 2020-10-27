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

int imsfs_write (const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi){
    imsfs_tree_node* cur_node = get_node(path);
    if (!cur_node) return -ENOENT;

    if (cur_node->isfile==0) return -EISDIR; //is a directory

    unsigned long int data_len = cur_node->data_len;

    long int end = offset + (int)size;
    
    if (end>)
}