#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

void printSize(int size){
  printf("File Size: ");
  if(size % 1073741824 / 10000000 > 0){
    printf("%d GB ",size % 1073741824 / 10000000);
  }
  if(size % 1048576 / 1000 > 0){
    printf("%d MB ",size % 1048576 / 1000);
  }
  if(size % 1024 > 0){
    printf("%d B",size % 1024);
  }
  printf("\n");
}

int main(){
  DIR *d;
  char directory[100] ="../MKS65C-dirinfo/";
  int total;
  if(d = opendir(directory)){
    printf("owo\n");
  }else{
    printf("%d\n",errno);
  }
  struct dirent *file;
  while(file = readdir(d)){
    if(file -> d_type == 4){
      printf("Directory: ");
      printf("%s\n",file -> d_name);
    }else if(file -> d_type == 8){
      printf("File: ");
      printf("%s\n",file -> d_name);
      char dummy[100];
      strcpy(dummy,directory);
      strcat(dummy,file->d_name);
      struct stat stuff;
      stat(dummy,&stuff);
      printSize(stuff.st_size);
      total+=stuff.st_size;
    }else{
      printf("%d: ",file -> d_type);
      printf("%s\n",file -> d_name);
    }
  }
  closedir(d);
  printf("Total File Size: ");
  if(total % 1073741824 / 10000000 > 0){
    printf("%d GB ",total % 1073741824 / 10000000);
  }
  if(total % 1048576 / 1000 > 0){
    printf("%d MB ",total % 1048576 / 1000);
  }
  if(total % 1024 > 0){
    printf("%d B",total % 1024);
  }
  printf("\n");
  return 0;
}
