//main program: hash_table with avl trees
#include "header.h"

int main(int argc, char *argv[]){
    hash_table_init_hash_table();
    while(main_option!=10){
        main_option=0;
        user_interface_option();
    }
    hash_table_free();
    printf("bye!\n\n");
    return 0;
}