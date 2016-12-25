#include <string.h>
#include <stdio.h>
#include "split_file_name.h"

void splitname(char* filename, char ch[5][70]){
    
    int t = 0,t1 =0;
    int i =0,j=strlen(filename);
    for(i=0;i<j;i++){
        if(filename[i] != '-'){
       ch[t][t1] = filename[i];
       t1++;
        }else{
            ch[t][t1] = '\0';
            t++;
            t1 = 0;
        }
    }
    ch[t][t1] = '\0';
}