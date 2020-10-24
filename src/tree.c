#include "tree.h"

// typedef struct imsfs_tree_node {
//     uint8_t type;                       //type of node
//     char name[256];                         //name of node
//     char *fullname;                     //full path of node
    
//     uint32_t uid, gid;              // user ID and group IP
//     uint32_t perms;                 // file permissions (supposed to be similar to Ubuntu)
//     uint8_t nlinks;             // number of links to this
    
//     struct fs_tree_node *parent;        //link to parent
//     struct fs_tree_node **children;      //links to children
//     uint32_t len;                       //number of children
//     uint64_t *ch_inodes;            // inode_no of children

//     uint8_t *data;						//data for read and write
//     uint64_t data_size;						//size of data
//     uint64_t block_count;               // number of blocks
//     uint64_t inode_no;                  // the inode number, i.e, the block containing first part of data

//     struct timespec st_atim;            /* time of last access */
//     struct timespec st_mtim;            /* time of last modification */
//     struct timespec st_ctim;            /* time of last status change */
// }


imsfs_tree_node* root;

void initialize_imsfs(){
    root=(imsfs_tree_node*)malloc(sizeof(imsfs_tree_node));
    root->type=2;
    strcpy(root->name,"/");
    root->fullname=malloc((strlen("/")+1)*sizeof(char));
    strcpy(root->fullname,"/");
    // root->uid=getuid();
    // root->gid=getgid();
    root->nlinks=2;
    // root->perms=S_IFDIR;
    root->parent=NULL;
    root->children=NULL;
    root->num_children=0;
    root->ch_inodes=NULL;
    root->data=NULL;
    root->data_size=0;
    root->block_count=0;
    // root->inode_no=
    // root->st_atim=time(NULL);
    // root->st_mtim=time(NULL);
    // root->st_ctim=time(NULL);
}


imsfs_tree_node *get_node(const char *path){
    if (!strcmp(path,"/")) return root;
    imsfs_tree_node* temp=root;
    int start=1,end=1,path_len=strlen(path),valid=0;
    while(end<=path_len){
        for (end=start;path[end]!='/'&&end<path_len;end++);
        int substr_len=end-start+1; 
        char* substr=malloc(substr_len*sizeof(char));
        substr[substr_len-1]='\0';
        for (int i=start,j=0;i<end;i++,j++) substr[j]=path[i];
        
    }
    return root;
}
