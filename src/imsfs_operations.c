#include "imsfs_operations.h"
#include "tree.h"
#include "utils.h"

int imsfs_getattr(const char *path, struct stat *s) {
    imsfs_tree_node* temp=get_node(path);
    if (temp==NULL){
        return -ENOENT;
    }
    memset(s,0,sizeof(s));
    // s->st_dev = 666;
    s->st_ino=temp->inode_no;
    switch(temp->type) {
        case 1:
            s->st_mode = S_IFREG | temp->perms;
            s->st_nlink = 1;
            break;

        case 2:
            s->st_mode = S_IFDIR | temp->perms;
            s->st_nlink = 2;
            break;

        default:
            printf("Type not supported : %d", temp->type);
            return -ENOTSUP;
    }
    s->st_nlink += temp->num_children;
    s->st_uid = temp->uid;
    s->st_gid = temp->gid;
    s->st_size = temp->data_size;
    s->st_blocks = ((temp->data_size+NODE_SIZE)/4096)+1;
    s->st_blocks *= 8;
    s->st_atime = (temp->st_atim).tv_sec;
    s->st_mtime = (temp->st_mtim).tv_sec;
    s->st_ctime = (temp->st_ctim).tv_sec;
    return 0;
}
