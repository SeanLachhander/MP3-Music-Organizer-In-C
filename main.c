#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h> 
#include <dirent.h> 
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include "managefiles.h"


int check_mp3(char* filename){
    
    char secname[5];
    int i=strlen(filename) - 1;
    int j =1;
    for(j=0; j<3; j++){
        secname[j] = filename[i];
        i--;
    }
    
    secname[j] = '\0';
    int q = strcmp("3pm",secname);
    return q;
}



void findfile(char* directory_name){
    
     struct dirent *directory_read;
             DIR *open_directory = opendir((const char*)directory_name);
             struct stat s;
             if(open_directory != NULL){
             while(NULL != (directory_read = readdir(open_directory))) 
                    { 
                        char* name = directory_read->d_name;
                                char path[PATH_MAX];
                                stat(name,&s);
                        if(name[0] != '.' && S_ISDIR(s.st_mode) == 0) 
                            {
                                
                                if(check_mp3(name) == 0){
                                    manage(name, directory_name);
                            }
                    }
                        
            }
            
             }else{
                 fprintf(stderr, "%d: %s\n", errno ,"Directory cannot be accessed");
             }

    }
    

int main(int argc, char **argv)
{
    if(argc == 2){
	int e = chdir(argv[1]);
    if(e==0){
        findfile(argv[1]);
    }else{
        fprintf(stderr, "%s: directory doesn’t exist \n",argv[1]);
    }
    
    }else{
        if(argc == 1){
            findfile(getenv("PWD"));
        }else{
            fprintf(stderr, "%d: number of arguments more than one \n",argc-1);
                return 0; 
        }
    }
}
