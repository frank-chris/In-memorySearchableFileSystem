#ifndef FFS_OPERATIONS_H
#define FFS_OPERATIONS_H

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

int imsfs_getattr (const char *, struct stat *);

int imsfs_create (const char * , mode_t, struct fuse_file_info *);

int imsfs_mkdir (const char *, mode_t);

int imsfs_open (const char *, struct fuse_file_info *);

int imsfs_read (const char *, char *, size_t, off_t, struct fuse_file_info *);

int imsfs_write (const char *, const char *, size_t, off_t, struct fuse_file_info *);

int imsfs_readdir (const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);

int imsfs_rmdir (const char *);

/** Remove a file */
int imsfs_unlink (const char *);

#endif