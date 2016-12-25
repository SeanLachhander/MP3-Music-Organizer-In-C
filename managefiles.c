#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h> 
#include <dirent.h> 
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "managefiles.h"
#include "split_file_name.h"
#include "copy_file.h"


void manage(char* filename, char* directory_name){

    char ch[5][70];
    splitname(filename, ch);
    int i =0;
    int dirlen = strlen(directory_name);
    
    mkdir(ch[1], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    chdir(ch[1]);
    mkdir(ch[2], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    chdir(ch[2]);
    mkdir(ch[3], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    chdir(ch[3]);
   
   strcat(ch[0]," - ");
   strcat(ch[0],ch[4]);
   
   char sourcefile[500];
   for(i=0;i< dirlen; i++){
       sourcefile[i] = directory_name[i];
   }
   sourcefile[i] = '\0';
   strcat(sourcefile, "/");
   strcat(sourcefile, filename);
   copyfile(sourcefile,ch[0]);
    
   chdir("..");
   chdir("..");
   chdir("..");
   unlink(filename);
   
   mkdir(ch[2], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
   chdir(ch[2]);
   
   char linkname[200];
   
   
   for(i=0; i<dirlen;i++){
       linkname[i] = directory_name[i];
   }
   linkname[i] = '\0';
   strcat(linkname,"/");
   strcat(linkname,ch[1]);
   strcat(linkname,"/");
   strcat(linkname,ch[2]);
   strcat(linkname,"/");
   strcat(linkname,ch[3]);

   strcat(ch[1]," - ");
   strcat(ch[1], ch[3]);
   int q = symlink(linkname, ch[1]);
   
   chdir("..");
}