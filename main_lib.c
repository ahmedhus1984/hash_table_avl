//library for main
#include "header.h"

//declarations
//variables
int main_option=0;
char *main_subject_input;
char *main_explanation_input;
char main_filename=0;
//functions
char main_read_filename(){
    FILE *blah=fopen("filename", "r");
    if(blah==NULL){
        printf("unable to open the file, \'filename\' for reading the filename to open\n");
        exit(1);
    }
    char a[2]="";
    fscanf(blah, "%s", a);
    printf("filname content a[0]: %c\n", a[0]);
    fclose(blah);
    printf("filname content a[0]: %c\n", a[0]);
    return a[0];
}
