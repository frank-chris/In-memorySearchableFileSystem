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

int imsfs_readdir(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi ){
    printf("READ DIRECTORY\n");
    imsfs_tree_node* dir_node = get_node(path);
    if (!dir_node) return -ENOENT;

    filler(buffer,".",NULL,0);
    filler(buffer,"..",NULL,0);

    for (int i=0; i<(dir_node->num_children); i=i+1){
        filler(buffer,dir_node->children[i]->name,NULL,0);
    }
    return 0;
}   