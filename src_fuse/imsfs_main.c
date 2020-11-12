#define FUSE_USE_VERSION 26

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

static struct fuse_operations imsfs_operations = {
    .getattr    = imsfs_getattr,
    // //.readlink = imsfs_readlink,
    .create    = imsfs_create,
    //.mknod     = imsfs_mknod,
    .mkdir      = imsfs_mkdir,
    .unlink     = imsfs_unlink,
	.rmdir	    = imsfs_rmdir,
	// //.symlink	= imsfs_symlink,
	.rename	    = imsfs_rename,
	// //.link	    = imsfs_link,
	// .chmod	    = imsfs_chmod,
	// .chown	    = imsfs_chown,
	// .truncate   = imsfs_truncate,
	.open	    = imsfs_open,
	.read	    = imsfs_read,
	.write	    = imsfs_write,
	// //.statfs	    = imsfs_statfs,
	.flush	    = imsfs_flush,
	// //.release	= imsfs_release,
	// //.fsync	    = imsfs_fsync,
	// //.setxattr	= imsfs_setxattr,
	// //.getxattr	= imsfs_getxattr,
	// //.listxattr	= imsfs_listxattr,
	// //.removexattr = imsfs_removexattr,
	// //.opendir	= imsfs_opendir,
	.readdir	= imsfs_readdir,
	// //.releasedir	= imsfs_releasedir,
	// //.fsyncdir	= imsfs_fsyncdir,
	// .init	    = imsfs_init,
	// .destroy	= imsfs_destroy,
	// .access	    = imsfs_access,
	// .create	    = imsfs_create,
	// .ftruncate	= imsfs_ftruncate,
	// .fgetattr	= imsfs_fgetattr,
	// //.lock	    = imsfs_lock,*/
	// .utime	= imsfs_utimens,
	// /*.bmap	    = imsfs_bmap,
	// //.ioctl	    = imsfs_ioctl,
	// //.poll	    = imsfs_poll,
	// .write_buf	= imsfs_write_buf,
	// //.read_buf	= imsfs_read_buf,
	// //.flock	    = imsfs_flock,
	// //.fallocate	= imsfs_fallocate,
};

int main(int argc, char **argv) {

	printf("Initialising tree\n");
    initialise_imsfs();
	printf("Initialised tree\n");

	printf("Initialising searchability\n");
    initialise_search();
	printf("Initialised searchability\n");

    return fuse_main(argc, argv, &imsfs_operations, NULL);
	// return 0;
}
