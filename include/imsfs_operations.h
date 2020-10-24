#ifndef IMSFS_OPERATIONS
#define IMSFS_OPERATIONS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <fuse.h>

int imsfs_getattr(const char *path, struct stat *s);

#endif