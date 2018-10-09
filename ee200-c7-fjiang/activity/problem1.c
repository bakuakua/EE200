/* problem1.c - Activity log */
#include <stdio.h>
#include <time.h>
int main(int argc, char* argv[])
{ 
    //create file if not exist, else open
    FILE *fp = fopen("activity.tsv", "ab+");
    //get time in sec 
    time_t secs;
    secs = time(NULL);
    char* act = argv[1];
    char* dur = argv[2];
    //check if activity or duration is empty 
    if (act[0]=='\0'||dur[0]=='\0'){
        printf("usage: Please enter ./log \"activity\" \"duration\" \"notes\" where activity and durations are not empty\n");
    return 0;
    }
    char* note = argv[3];
    //write input to log file
    fprintf(fp, "%ld	%s	%s	%s\n", secs, act, dur, note);
    return(0);
}

