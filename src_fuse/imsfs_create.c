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

/** Create and open a file **/

int imsfs_create (const char * path, mode_t mode, struct fuse_file_info *fi){

    printf("******************\n");
    printf("CREATE FILE\n");
    printf("create file called at path: %s\n",path);

    imsfs_tree_node* existing_node = get_node(path); // checking if entry already exists

    //printf("existing node pointer check: %p\n",existing_node);

    if (existing_node!=NULL) return -EEXIST; //

    //printf("Node doesn't exist, creating new\n");

    imsfs_tree_node* added_file_node=add_file_node(parent_from_path(path),name_from_path(path));

    //printf("new node pointer check: %p\n",added_file_node);

    if (!added_file_node) return -ENOENT; //parent path invalid
    
    printf("returning from create file\n");
    printf("******************\n");
    
    return 0;
}

// char* index = strrchr(path,'/');
//     char* parent_path;
//     strncpy(parent_path,path,index-path+1);
//     imsfs_tree_node* parent_node = get_node_from_path(parent_path);
//     if (!parent_node) return -ENOENT;
//     parent_node -> children=(imsfs_tree_node**)realloc(parent_node->children,(parent_node->num_children+1)*sizeof(imsfs_tree_node*));
//     if (!parent_node->children) return -ENOMEM;
//     parent_node->num_children++;
//     parent_node->children[parent_node->num_children-1]=(imsfs_tree_node*)malloc(sizeof(imsfs_tree_node));
//     if (!(parent_node->children[parent_node->num_children-1])) return -ENOMEM;
//     imsfs_tree_node* cur_node=parent_node->children[parent_node->num_children-1];
    
//     cur_node->isfile=1;
//     strcpy(cur_node->name,index+1);
//     strcpy(cur_node->path,path);
//     cur_node->parent=parent_node;
//     cur_node