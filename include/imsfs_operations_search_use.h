#ifndef IMSFS_OPERATIONS_SEARCH_USE_H
#define IMSFS_OPERATIONS_SEARCH_USE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <fuse.h>
#include "tree.h"
#include "search_use_query.h"

//search
int imsfs_getattr_search(const char *path, struct stat *s);
int imsfs_readdir_search(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi );

//use
int imsfs_getattr_use(const char *path, struct stat *s);
int imsfs_read_use (const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi);
int imsfs_write_use (const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi);
int imsfs_open_use (const char *path, struct fuse_file_info *fi);
int imsfs_unlink_use(const char *path);

#endif