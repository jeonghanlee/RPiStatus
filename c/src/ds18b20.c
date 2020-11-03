#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
 
int
main(int argc, char *argv[])
{

  char path1[50] = "/sys/bus/w1/devices/";
  char path2[50] = "/sys/bus/w1/devices/";
  char rom[2][40];
  char buf[2][100];
  DIR *dirp;

  struct dirent *direntp;

  int fd1 =-1;
  int fd2 =-1;
  
  char *temp[2];
  float value[2];
  // Check if /sys/bus/w1/devices/ exists.

  if( (dirp = opendir(path1)) == NULL) {
    printf("opendir error\n");
    return 1;
  }

  int i=0;
  // Reads the directories or files in the current directory.
  while((direntp = readdir(dirp)) != NULL) {
    // If 28-00000 is the substring of d_name,
    // then copy d_name to rom and print rom.
  
    if(strstr(direntp->d_name,"28-")) {
      strcpy(rom[i],direntp->d_name);
      printf(" rom[%d]: %s\n",i,rom[i]);
      i++;
    }
  }

  closedir(dirp);
  // Append the String rom and "/w1_slave" to path
  // path becomes to "/sys/bus/w1/devices/28-00000xxxx/w1_slave"

  strcat(path1,rom[0]);
  strcat(path1,"/w1_slave");
  strcat(path2,rom[1]);
  strcat(path2,"/w1_slave");

  time_t clk;
  int count=0;
  
  while(1) {
    clk = time(NULL);
    if((fd1 = open(path1,O_RDONLY)) < 0){
      printf("open error %s\n", path1);
      return 1;
    }
    if(read(fd1,buf[0],sizeof(buf[0])) < 0) {
      printf("read error\n");
      return 1;
    }
    if((fd2 = open(path2,O_RDONLY)) < 0){
      printf("open error %s\n", path2);
      return 1;
    }
    if(read(fd2,buf[1],sizeof(buf[1])) < 0) {
      printf("read error\n");
      return 1;
    }
    for (int i=0; i<2; i++) {
      temp[i] = strchr(buf[i],'t');
      sscanf(temp[i],"t=%s",temp[i]);
      value[i] = atof(temp[i])/1000;
    }
    printf (">> %s", ctime(&clk));
    for (int i=0; i<2; i++) {
      printf(">> %8d Sensor %s temperature [%d] : %3.3f °C\n", count, rom[i], i, value[i]);
    }
    count++;
  }
  return 0;
}
