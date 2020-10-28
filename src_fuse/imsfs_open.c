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


int imsfs_open (const char *path, struct fuse_file_info *fi){
    
    printf("OPEN FILE\n");
    printf("open file called at path: %s\n",path);

    imsfs_tree_node* cur_node = get_node(path);

    printf("pointer to the node: %p\n", cur_node);

    if (!cur_node) return -ENOENT;
    else if (cur_node->isfile == 0){
        return -EISDIR;
    }
    else return 0;
}