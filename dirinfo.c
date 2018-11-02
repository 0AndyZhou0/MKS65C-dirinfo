#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
  DIR* file = opendir("~/LivingInTheC/MKS65C-dirinfo");
  
  closedir(file);
  return 0;
}
