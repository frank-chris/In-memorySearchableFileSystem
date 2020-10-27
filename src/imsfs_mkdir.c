
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

int imsfs_mkdir (const char *path, mode_t mode){
    printf("CREATE DIRECTORY\n");
    imsfs_tree_node* existing_node = get_node(path);
    if (!existing_node) return 	-EEXIST;
    imsfs_tree_node* added_directory_node=add_dir_node(parent_from_path(path),name_from_path(path));
    if (!added_directory_node) return -ENOENT;
    return 0;
}