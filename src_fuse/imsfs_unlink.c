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

/** Remove a file **/

int imsfs_unlink (const char *path){
    
    printf("REMOVE FILE\n");
    
    int ret = remove_file_node(path);

    switch (ret){
        case -2:
            return -EISDIR;
            break;
        case -1:
            return -ENOENT;
            break;
        case 1:
            return 0;
            break;
    }
    return 0;
}