/* problem3.c - Word counting */
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    char * file_path;
    char * option;
    FILE *fp;
    if (argc == 3){
        file_path = argv[1];
        fp = fopen(argv[1], "r");
        option = argv[2];
    }
    else if (argc == 2){
        if (argv[1][0] == '-' ){
            char input[1024];
	    FILE *temp = fopen("stdin.txt", "w");
            while (fgets(input, 1024, stdin)!=NULL) fputs(input,temp);
            fclose(temp);
            fp = fopen("stdin.txt", "r");
            file_path = "";
            option = argv[1];
        }
        else{
            file_path = argv[1];
            fp = fopen(file_path, "r");
            option = "";
        }
    }
    else if (argc == 1) {
            char input[1024];
            FILE * tmp = fopen("stdin.txt", "w");
            while(fgets(input, 1024, stdin)!=NULL){
                fputs(input, tmp);
            }
            fclose(tmp);
            file_path = "stdin.txt";
            fp = fopen(file_path,"r");
            file_path = "";
            option = "";
    }
    int lc = 0;
    int wc = 0;
    int cc = 0;
    if (fp){
       char temp_char;
       char prev_char;
       while((temp_char = fgetc(fp))!=EOF){
            cc++;
            if ((temp_char == ' '|| temp_char == '\n' || temp_char == '\t')&&(prev_char!=' '&&prev_char!='\n'&&prev_char!='\t') ){
                wc++;
            }
            if (temp_char =='\n') lc++;
            prev_char = temp_char;
       }
       if (prev_char!='\n'&& prev_char != '\t'&& prev_char != ' '){
           lc++;
           wc++;
       }
       if (!strcmp(option,"-l")) printf("%d %s\n", lc, file_path);
       if (!strcmp(option,"-w")) printf("%d %s\n", wc, file_path);
       if (!strcmp(option,"-c")) printf("%d %s\n", cc, file_path);
       if (!strcmp(option, "")) printf("%d %d %d %s\n",lc, wc, cc, file_path );      
    }
    else return 0;
    remove("temp.txt");
  return(0);
 
}

