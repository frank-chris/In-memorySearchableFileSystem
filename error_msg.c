#include "tree.h"


void user_error(char * msg, char * reason){
    fputs(msg, stderr);
    fputs(": ", stderr);
    fputs(reason, stderr);
    fputs("\n", stderr);
    exit(1);
}
