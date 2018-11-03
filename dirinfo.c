#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

int main(){
  DIR *d;
  if(d = opendir("../MKS65C-dirinfo/")){
    printf("owo\n");
  }else{
    printf("%d\n",errno);
  }
  struct dirent *file;
  while(file = readdir(d)){
    if(file -> d_type == 4){
      printf("Directory: ");
    }else if(file -> d_type == 8){
      printf("File: ");
    }else{
      printf("%d: ",file -> d_type);
    }
    printf("%s\n",file -> d_name);
  }
  closedir(d);
  return 0;
}
