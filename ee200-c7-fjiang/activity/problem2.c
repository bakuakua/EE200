/* problem2.c - Activity summary */
#include <stdio.h>
#include <string.h>
#include <time.h>
int main(int argc, char* argv[])
{

  // You're on your own!
  FILE *fp = fopen("activity.tsv", "r");
  if (fp==NULL){
      printf("error: file none-exist or corrupted\n");
      return 0;
  }
  //parse input string first
  
  if (argc <2){
      printf("usage: please enter number of years, weeks or days, i.e 1w for 1 week\n");
      return 0;
  }
  char *in = argv[1];
  char unit = in[strlen(in)-1];
  char num[strlen(in)];
  strncpy(num, in, strlen(in)-1);
  num[strlen(in)] = '\0';
  int number = atoi(num);
  //check valid input
  if (number == 0){
     printf("usage: please enter number of years, weeks or days, i.e 1w for 1 week\n");
     return 0;
  }
  //calculate time range
  int secs;
  if (unit == 'd') secs = number*86400;
  else if (unit == 'y') secs = number*86400*365;
  else if (unit == 'w') secs = number*86400*7;
  else{
      printf("usage: please enter number of years, weeks or days, i.e 1w for 1 week\n");
      return 0;
  }
  int sec_curr = time(NULL);
  int sec_past = sec_curr - secs;
  //initialize tab-delimited fields
  char buff[1024];
  char* t_sec[100];
  char* act[100];
  char* dur[100];
  char* note[100];
  int sum = 0;
  //read file input and parse each line to calculate total time  
  while ((fgets(buff,1024,fp))!=NULL){
      sscanf(buff, "%s\t%s\t%s\t%s", t_sec, act, dur, note);
      if (atoi(t_sec)>=sec_past) sum+=atoi(dur);
  }
  printf("Total exercise: %d minutes\n", sum);
  return(0);
}

