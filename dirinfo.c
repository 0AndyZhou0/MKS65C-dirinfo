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
    printf("%s\n",file -> d_name);
  }
  closedir(d);
  return 0;
}
