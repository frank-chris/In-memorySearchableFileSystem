#include "tree.h"


void error_msg(char * msg, char * reason){
    fputs(msg, stderr);
    fputs(": ", stderr);
    fputs(reason, stderr);
    fputs("\n", stderr);
    exit(1);
}
