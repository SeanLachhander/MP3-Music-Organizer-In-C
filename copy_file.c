#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h> 
#include <dirent.h> 
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h> 
#include <dirent.h> 
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

void copyfile(char *source, char *destination){
    FILE  *ptr_old, *ptr_new;
    ptr_old = fopen (source, "rb");
    ptr_new = fopen (destination, "wb");
    off_t file_size;
   char *buffer;
   struct stat s;
   //int y = open (filename, O_RDONLY);
  // fileno(ptr_old);
   fstat(fileno(ptr_old),&s);
   file_size = s.st_size;
   buffer = (char*)malloc(file_size);
   

while(1){
    int bytes_read = fread(buffer,sizeof(buffer),1,ptr_old); 
    if(bytes_read == 1){
        fwrite(buffer,sizeof(buffer),1,ptr_new);
    }else{
        fwrite(buffer,sizeof(buffer),1,ptr_new);
        break;
    }
}

free(buffer);
		fclose(ptr_new);
		fclose(ptr_old);
}