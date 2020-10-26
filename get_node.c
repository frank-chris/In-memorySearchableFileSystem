#include "tree.h"

// typedef struct imsfs_tree_node {
//     bool isfile;                        
//     char name[MAX_NAME_SIZE];                         //name of node
//     char *path;                     //full path of node, stored as an array of directories
//     
//     struct imsfs_tree_node *parent;        //link to parent
//     struct imsfs_tree_node **children;      //links to children
//     int num_children;                       //number of children
// 
//     char *data;						//data for read and write
//     long int data_len;
// 
// } imsfs_tree_node;


imsfs_tree_node *get_node(const char *path){
    // Format for path is "/directory/sub1/sub2/..."
    //
    // Algorithm for finding node-
    // 1) Store 2 pointers, curptr for cur '/', nxtptr for next '/'
    // 2) nxtptr will point to end of string (nullptr) at the end
    // 3) Generate string from characters in between
    // 4) Current string should be a child current node. If so make this new current node and loop.
    
    imsfs_tree_node *cur = root;

    if(strcmp(path, "/") == 0){
        return curr;
    }

    int curptr = 0, nxtptr = 1;
    int pathlen = strlen(path);
    char *sub_dir = NULL;
    bool resolved = 0;

    do{
        bool found = 0;
        while(path[nxtptr] != '/'){
            nxtptr++;
            if(nxtptr >= pathlen)
                break;
        }
        curptr++;

        int subdir_len = nxtptr - curptr;
        if(nxtptr == pathlen)
            subdir_len++;
        if(subdir_len <= 0){
            error_msg("Node not found", "Invalid path");
            return 0;
        }
        sub_dir = (char *)malloc(sizeof(char) * pathlen);
        for(int i = curptr; i < nxtptr; i++){
            sub_dir[i - curptr] = path[i];
        }

        for(int i = 0; i < (cur -> num_children); i++){
            if(!(cur ->children[num_children]))
                continue;
            char *tmp_name = (cur -> children[num_children]) -> name;
            if(strcmp(tmp_name, sub_dir) == 0){
                cur = cur -> children[num_children];
                found = 1;
                break;
            }
        }
        if(!found)
            break;

        free(sub_dir);
        sub_dir = NULL;
        curptr = nxtptr;
        nxtptr++;
        if(nxtptr >= pathlen)
            resolved = 1;
    }while(nxtptr < pathlen);

    if(!resolved){
            error_msg("Node not found", "Invalid path");
            return 0;
    }

    return cur;
}

