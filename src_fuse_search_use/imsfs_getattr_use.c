#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "imsfs_operations.h"
#include "imsfs_operations_search_use.h"

int imsfs_getattr_use(const char *path, struct stat *s){

    // printf("imsfs_getattr_use called at path: %s\n",path);

    if (strcmp(path, "/USE") == 0){
        s->st_nlink = 2; //"." and ".."
        s->st_size=0;
        s->st_mode= S_IFDIR | DIR_PERM;
        return 0;
    }
    
    char* file_name = get_file_name_use(path);
    // printf("extracted file name: %s\n", file_name);

    if (!file_name) return -ENOENT;
    
    imsfs_tree_node* cur_node = get_node_from_search_buffer(file_name);
    
    if (!cur_node){
        free(file_name);    
        file_name = NULL;
        return -ENOENT;
    }

    s->st_nlink=1;
    s->st_size=(cur_node->data_len);
    s->st_mode= S_IFREG | cur_node->permissions;

    free(file_name);
    file_name = NULL;

    return 0;
}
