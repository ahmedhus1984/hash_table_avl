//library for user interface
#include "header.h"

void user_interface_menu(){
    printf("\n");
    printf("1. lookup a subject in dictionary\n");
    printf("2. add a word to dictionary\n"); //data modification occurs
    printf("3. inorder display of all subjects in an index's tree\n");
    printf("4. levelorder display of of all subjects in an index's tree\n");
    printf("5. delete a word from dictionary\n"); //data modification occurs
    printf("6. edit a word\n"); //data modification occurs
    printf("7. save dictionary changes\n");
    printf("8. display all the first words of indexes which are not NULL\n");
    printf("9. compare words\n");
    printf("10. exit dictionary\n");
    printf("11. inorder display of all subjects and their explanations from all the trees in the hash-table \n");
    printf("12. inorder display of all subjects and their respective explanations in an index's tree\n");
    printf("13. display number of subjects in an index\n");
    printf("14. display number of subjects in the entire dictionary\n");
    printf("15. search dictionary for a text pattern and display all records which contain that text pattern\n");   
    printf("\nenter the respective number from the given options you would like to choose: ");
}

char* user_interface_init_subject(){
    char *a=(char*)calloc(1,sizeof(char));
    int i=0, j=0;
    while(*(a+j)!='\n'){
        scanf("%c", a+i);
        j=i;
        i++;
        a=realloc(a, ((i + 1) * sizeof(char)));
        *(a+(j+1))='\0';
    }
    int str_len=strlen(a);
    a[str_len-1]='\0';
    return a;
}

void user_interface_option(){
    user_interface_menu();
    scanf("%d", &main_option);
    while((getchar())!='\n');
    user_interface_choice(main_option);
}

void user_interface_char_inorder_single_tree_subject(){
    char a;
    printf("enter an alphabet: ");
    scanf("%c", &a);
    while((getchar())!='\n');
    hash_table_print_an_index_tree_subjects_inorder(a);
}

void user_interface_char_inorder_single_tree_subject_and_explanation(){
    char a;
    printf("enter an alphabet: ");
    scanf("%c", &a);
    while((getchar())!='\n');
    hash_table_print_an_index_tree_subjects_and_explanations_inorder(a);
}

void user_interface_char_levelorder(){
    char a;
    printf("enter an alphabet: ");
    scanf("%c", &a);
    while((getchar())!='\n');
    hash_table_print_an_index_tree_levelorder(a);
}

void user_interface_choice(int option){
    switch (option){
        case 1:
            user_interface_lookup();
            break;
        case 2:
            user_interface_add();
            break;
        case 3:
            user_interface_char_inorder_single_tree_subject();
            break;
        case 4:
            user_interface_char_levelorder();
            break;
        case 5:
            user_interface_delete();
            break;
        case 6:
            user_interface_update();
            break;
        case 7:
            user_interface_save();
            break;
        case 8:
            hash_table_print_first_non_null_indexes();
            break;
        case 9:
            user_interface_compare_words();
            break;
        case 10:
            printf("\nexiting application...\n");
            break;
        case 11:
            hash_table_print_inorder_entire_dictionary();
            break;
        case 12:
            user_interface_char_inorder_single_tree_subject_and_explanation();
            break;
        case 13:
            user_interface_count_subjects_per_index();
            break;
        case 14:
            hash_table_count_subjects_entire_dictionary();
            break;
        case 15:
            user_interface_pattern_search();
            break;
        default:
            printf("you have entered, %d which is an invalid option, please try again\n", option);
            break;
    }
}

void user_interface_lookup(){
    printf("enter the subject you would like to lookup in the dictionary: ");
    char *a=user_interface_init_subject();
    printf("subject input for lookup: %s\n", a);
    hash_table_lookup(a);
    free(a);
}

void user_interface_pattern_search(){
    printf("\nenter the text you would like to search the dictionary for: ");
    char *a=user_interface_init_subject();
    printf("\ntext input for lookup: %s\n", a);
    hash_table_pattern_search(a);
    free(a);
}


void user_interface_add(){
    unsigned int size=0;
    printf("enter the subject you would like to add in the dictionary: ");
    char *a=user_interface_init_subject();
    printf("subject entered for adding: %s\n", a);
    size=strlen(a)+1;
    printf("size of subject entered: %u\n", size);
    printf("enter the explanation you would like to associate with the subject: ");
    char *b=user_interface_init_subject();
    size=strlen(b)+1;
    printf("subject explanation for adding: %s\n", b);
    printf("size of subject explanation: %u\n", size);
    hash_table_insert(a, b);
    free(a);
    free(b);
}

void user_interface_delete(){
    printf("enter the subject you would like to delete from the dictionary: ");
    char *a=user_interface_init_subject();
    printf("subject entered for deletion: %s\n", a);
    hash_table_delete(a);
    free(a);
}

void user_interface_update(){
    printf("enter the subject you would like to edit in the dictionary: ");
    char *a=user_interface_init_subject();
    printf("subject's current information:\n");
    hash_table_lookup(a);
    printf("enter the new subject you would like to update %s to in the dictionary: ", a);
    char *b=user_interface_init_subject();
    printf("enter the new explanation you would like to update %s with in the dictionary: ", a);
    char *c=user_interface_init_subject();
    hash_table_update(a, b, c);
    printf("subject's updated information:\n");
    hash_table_lookup(b);
    free(a);
    free(b);
    free(c);
}

void user_interface_count_subjects_per_index(){
    char a;
    printf("enter an alphabet: ");
    scanf("%c", &a);
    while((getchar())!='\n');
    hash_table_count_subjects_per_index(a);
}

void user_interface_save(){
    main_filename=main_read_filename();
    printf("main_filename@user_interface_save(): %c\n", main_filename);
    hash_table_save_tree(main_filename);
}

void user_interface_compare_words(){
    unsigned int length=0;
    unsigned int size=0;
    printf("enter first word: ");
    char *a=user_interface_init_subject();
    length=strlen(a);
    size=strlen(a)+1;
    printf("no. of characters in first word, %s: %u\n", a, length);
    printf("size of first word, %s: %u\n", a, size);
    printf("enter second word: ");
    char *b=user_interface_init_subject();
    length=strlen(b);
    size=strlen(b)+1;
    printf("no. of characters in second word, %s: %u\n", b, length);
    printf("size of second word, %s: %u\n", b, size);
    if(strcmp(a, b)>0){
        printf("%s is greater than %s\n", a, b);
    }
    else if(strcmp(a, b)<0){
        printf("%s is smaller than %s\n", a, b);
    }
    else{
        printf("%s is equal to %s\n", a, b);
    }
    free(a);
    free(b);
}