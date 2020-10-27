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
    printf("WRITE TO FILE\n");
    imsfs_tree_node* cur_node = get_node(path);
    if (!cur_node) return -ENOENT;

    if (cur_node->isfile==0) return -EISDIR; //is a directory

    unsigned long int data_len = cur_node->data_len;

    long int end = offset + (int)size;
    
    if (end>data_len){
        cur_node->data=realloc(cur_node->data,(data_len+end-data_len)*sizeof(char));
        if (!cur_node->data) return -ENOMEM;
        else{
            cur_node->data_len=end;
            cur_node->data[end]='\0';
        }
    }

    strncpy(cur_node->data+offset,buf,size);

    return (int)size;
}