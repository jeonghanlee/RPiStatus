#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

float C2F(float degC)
{
  return degC*9.0/5.0 + 32.0;
}

int
main(int argc, char *argv[])
{

  static char statfile[] = "/sys/class/thermal/thermal_zone0/temp";
  int temp = 0;
  FILE *fp;
  
  time_t clk;
  int count=0;
  float valueC=0.0;
  float valueF=0.0;
  
  while(1) {
    clk = time(NULL);
    fp = fopen(statfile, "r");
    if (fp) {
      fscanf(fp, "%d", &temp);
      fclose(fp);
    }
    else {
      printf("open error %s\n", statfile);
      return 1;
    }
    /* temp is millidegree Celsius */
    valueC=temp/1000.;
    valueF=C2F(valueC);
        
    printf (">> %s", ctime(&clk));
    printf(">> %8d Thermal Zone temperature : %3.3f °C %3.3f F\n", count, valueC, valueF);
    count++;
    sleep(1);
  }
  return 0;
}



