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

/* Rename a file or folder */

int imsfs_rename (const char *old_path, const char *new_path){

    imsfs_tree_node *cur = get_node(old_path);

    printf("rename %s to %s\n",old_path,new_path);
    if((cur -> isfile)){
        printf("***************************************\n");
        printf("RENAME FILE\n");

        int ret = change_node_location(old_path, new_path);
        switch(ret) {
            case -3:
                return -EISDIR;
                break;
            case -2: 
                return -EISDIR;
                break;
            case -1:
                return -ENOENT;
                break;
            case 0:
                return -ENOENT;
                break;
            case 1:
                return 0;
                break;
        }
    }
    
    else{
        printf("***************************************\n");
        printf("RENAME FOLDER\n");

        imsfs_tree_node *new = get_node(new_path);

        if(!new){
            int ret = rename_node(old_path, new_path);
            if(ret == 1)
                return 0;
        }

        if((new -> isfile)){
            printf("Target location is a file\n");
            return -EISDIR;
        }
        else{
            int ret = change_node_location(old_path, new_path);
            if(ret == 1)
                return 0;
        }

    }

    printf("***************************************\n");
    return 0;
}

/*
Cases:
Note: This function is for renaming files
1) old path is invalid
--> return exception
2) old path is a directory
--> return exception
3) old path exists
3a) new path invalid
-> return exception
3b) new path already exists
-> as per the working of bash terminal
-> remove the file node at the current new path
-> remove the file node from the current old path and place it in place vacated by the earlier node at the new path
3c) new path not present
-> remove the file node from the current old path and place it in the new path
*/
