#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define NONE "\e[0m"
#define RED  "\e[0;31m"
#define BLUE "\e[0;34m"

int main()
{
  int i = 0;
  char bar[102];
  memset(bar, 0 ,sizeof(bar));
  const char *lable="|/-\\";
  while(i <= 100){
    if(i % 2){
      printf(RED"[%-100s][%d%%][%c]\r" NONE, bar , i , lable[i%4]);
    }
else 
      printf(BLUE"[%-100s][%d%%][%c]\r"NONE, bar , i , lable[i%4]);  
       fflush(stdout);
    bar[i++] = '#';
    usleep(100000);
    }
  printf("\n");
  return 0;

}
