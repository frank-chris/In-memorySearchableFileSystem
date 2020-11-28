#include <stdio.h> 
#include <dirent.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define WORKLOAD_SIZE 1000

int main()
{   
    struct timeval start, end;

    long elapsed_time;

    FILE* fp;

	fp = fopen("comparison/ondisk_2.csv", "w");

	if(fp == NULL){
        fprintf(stderr, "\nFile open error\n");
        exit(EXIT_FAILURE);
    }
	
	fprintf(fp, "system_call,time(us)\n");

    char* dirname = malloc(sizeof(char)*50);
    
    strcpy(dirname, "comparison/disk/");

    char* filename = malloc(sizeof(char)*50);

    for (int i = 1; i <= WORKLOAD_SIZE; i++)
    {
        sprintf(filename, "%d", i);
        
        strcat(dirname, filename);

        if (mkdir(dirname, 0777) == -1) 
            printf("Error");
        
        free(dirname);
        dirname = malloc(sizeof(char)*50);
        strcpy(dirname, "comparison/disk/");
    }
    
    gettimeofday(&start, NULL);

    for (int i = 1; i <= WORKLOAD_SIZE; i++)
    {
        // open source file
        int fd1 = open("comparison/sample", O_RDONLY );

        sprintf(filename, "%d/%d", i, i);
        
        strcat(dirname, filename);

        // open destination file
        int fd2 = open(dirname, O_WRONLY | O_CREAT, 0777);
        int buf;
        
        // check if files were opened
        if(fd1 < 0) { 
            perror("open error"); 
            return 1;
        }
        if(fd2 < 0) { 
            perror("open error"); 
            return 1;
        }

        // reading contents of source file and writing it into destination file
        while(read(fd1, &buf, 1)){
            write(fd2, &buf, 1);
        }
        
        // close files
        close(fd1);
        close(fd2);

        free(dirname);
        dirname = malloc(sizeof(char)*50);
        strcpy(dirname, "comparison/disk/");
    }

    gettimeofday(&end, NULL);
    elapsed_time = ((end.tv_sec*1000000 + end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec));

    fprintf(fp, "open_read_write_close,%ld\n", elapsed_time);

    gettimeofday(&start, NULL);
    
    for (int i = 1; i <= WORKLOAD_SIZE; i++)
    {   
        sprintf(filename, "%d", i);
        
        strcat(dirname, filename);

        struct dirent *de;
        DIR *dr = opendir(dirname);

        if (dr == NULL)
        {
            printf("Could not open directory" );
            return 0;
        }

        while ((de = readdir(dr)) != NULL)
            ;

        closedir(dr);

        free(dirname);
        dirname = malloc(sizeof(char)*50);
        strcpy(dirname, "comparison/disk/");
    }

    gettimeofday(&end, NULL);
    elapsed_time = ((end.tv_sec*1000000 + end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec));
    
    fprintf(fp, "opendir_readdir_closedir,%ld\n", elapsed_time);

    fclose(fp);

    system("rm -rvf comparison/disk");

    free(filename);
    free(dirname);    
    return 0;
}

