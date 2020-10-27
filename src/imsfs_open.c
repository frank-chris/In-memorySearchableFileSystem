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
    imsfs_tree_node* existing_node = get_node(path);
    if (!existing_node) return -ENOENT;
    return 0;
}