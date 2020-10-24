#ifndef IMSFS_TREE_H
#define IMSFS_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

// #include "disk.h"
// #include "bitmap.h"

#define DEF_DIR_PERM (0775)
#define DEF_FILE_PERM (0664)

// fields = type + name + len + uid + gid + perms + nlinks + data_size + atim + mtim + ctim < + data + > + inode_no + next_block
// in bits = 8 + (256*8) + 32 + 32 + 32 + 32 + 8 + 64 + (16*8) + (16*8) + (16*8) + 64 + 64 = 2768 = 346 bytes
#define NODE_SIZE 346

#define SUPERBLOCKS 1   // number of blocks designated to be part of superblock


typedef struct imsfs_tree_node {
    uint8_t type;                       //type of node
    char name[256];                         //name of node
    char *fullname;                     //full path of node
    
    uint32_t uid, gid;              // user ID and group IP
    uint32_t perms;                 // file permissions (supposed to be similar to Ubuntu)
    uint8_t nlinks;             // number of links to this
    
    struct fs_tree_node *parent;        //link to parent
    struct fs_tree_node **children;      //links to children
    uint32_t num_children;                       //number of children
    uint64_t *ch_inodes;            // inode_no of children

    uint8_t *data;						//data for read and write
    uint64_t data_size;						//size of data
    uint64_t block_count;               // number of blocks
    uint64_t inode_no;                  // the inode number, i.e, the block containing first part of data

    struct timespec st_atim;            /* time of last access */
    struct timespec st_mtim;            /* time of last modification */
    struct timespec st_ctim;            /* time of last status change */

    // time_t st_atim;            /* time of last access */
    // time_t st_mtim;            /* time of last modification */
    // time_t st_ctim;            /* time of last status change */

} imsfs_tree_node;

/*
types:
    1 = file
    2 = directory
*/

#endif