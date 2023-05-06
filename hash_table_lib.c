//library for hash_table
#include "header.h"

//hash function to generate hash number base on alphabetical order for each data entry to the hash table
unsigned int hash_table_hash(char *name){
    unsigned int hash_value=0;
    if (name[0]<91){
        hash_value=name[0]-65;
    }
    else{
        hash_value=name[0]-97;
    }
    return hash_value;
}

//initialize the hash table values to NULL at the beginning of the program
void hash_table_init_hash_table(){
    for (int i=0; i<TABLE_SIZE; i++){
        hash_table[i]=NULL;
    }
}

//function to insert word into hash table
void hash_table_insert(char *subject, char *explanation){
    // check which index to put the new word into
    unsigned int index=hash_table_hash(subject);
    hash_table[index]=avl_insert_node_avl(hash_table[index], subject, explanation);
}

void hash_table_read(char *subject){
    // check which index to put the new word into
    unsigned int index=hash_table_hash(subject);
    avl_read_card(hash_table[index], subject);
}

void hash_table_lookup(char *subject){
    // check which index to put the new word into
    unsigned int index=hash_table_hash(subject);
    avl_lookup_card(hash_table[index], subject);
}

void hash_table_pattern_search(char *pattern){
    printf("\nsearching all matches for, \"%s\" in the entire dictionary:\n\n", pattern);
    for (int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i]!=NULL){
            avl_pattern_search(hash_table[i], pattern);
        }
    }
    printf("\nsearch for all matches for, \"%s\" in the entire dictionary has ended\n", pattern);

}

void hash_table_delete(char *subject){
    // check which index to put the new word into
    unsigned int index=hash_table_hash(subject);
    hash_table[index]=avl_delete_node_avl(hash_table[index], subject);
}

void hash_table_update(char *subject_old, char *subject_new, char *explanation){
    unsigned int index=hash_table_hash(subject_old);
    hash_table[index]=avl_update_card(hash_table[index], subject_old, subject_new, explanation);
}

void hash_table_print_an_index_tree_subjects_inorder(char alphabet){
    char blah[3]="xx";
    blah[0]=alphabet;
    unsigned int a=hash_table_hash(blah);
    avl_print_tree_inorder(hash_table[a]);
}

void hash_table_print_an_index_tree_subjects_and_explanations_inorder(char alphabet){
    char blah[3]="xx";
    blah[0]=alphabet;
    unsigned int a=hash_table_hash(blah);
    avl_print_tree_inorder_full(hash_table[a]);
}

void hash_table_count_subjects_per_index(char alphabet){
    char blah[3]="xx";
    blah[0]=alphabet;
    unsigned int a=hash_table_hash(blah);
    int count=avl_count_subjects_per_index_avl(hash_table[a]);
    printf("number of subjects starting with the letter, '%c' in the dictionary: %d\n", alphabet, count);
}

void hash_table_print_an_index_tree_levelorder(char alphabet){
    char blah[3]="xx";
    blah[0]=alphabet;
    unsigned int a=hash_table_hash(blah);
    avl_printLevelOrder(hash_table[a]);
}

void hash_table_save_tree(char p1){
    char a[6]="";
    a[1]='.';
    a[2]='c';
    a[3]='s';
    a[4]='v';
    printf("p1 (char): %c\n", p1);
    a[0]=p1;
    printf("a (string): %s\n", a);
    printf("attempting to open filename: %s\n", a);
    FILE *blah=fopen(a, "w");
    if(!blah){
        printf("unable to open the file, \'%s\' for saving current data\n", a);
        exit(2);
    }
    printf("saving to file...\n");
    fprintf(blah, "%s", "\"");
    fprintf(blah, "%s", "Subject");
    fprintf(blah, "%s", "\"");
    fprintf(blah, "%s", ",");
    fprintf(blah, "%s", "\"");
    fprintf(blah, "%s", "Explanation");
    fprintf(blah, "%s", "\"");
    fprintf(blah, "%s", "\n");
    for (int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i]!=NULL){
            avl_save_tree(blah, hash_table[i]);
        }
    }
    fclose(blah);
}

void hash_table_count_subjects_entire_dictionary(){
    int count=0;
    for (int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i]!=NULL){
            count+=avl_count_subjects_per_index_avl(hash_table[i]);
        }
        else{
            count+=0;
        }
    }
    printf("total number of subjects in the dictionary: %d\n", count);
}

void hash_table_print_first_non_null_indexes(){
    printf("printing all the first words of indexes which are not NULL...\n");
    for (int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i]!=NULL){
            printf("printing %c...\n", i+97);
            printf("hash_table[%d]: %s\n", i, hash_table[i]->subject);
            printf("######################\n");
        }
    }
}

void hash_table_print_inorder_entire_dictionary(){
    printf("printing the entire dictionary:\n");
    for (int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i]!=NULL){
            avl_print_tree_inorder_full(hash_table[i]);
        }
    }
}

void hash_table_free(){
    printf("\nfreeing dictionary...\n\n");
    for (int i=0; i<TABLE_SIZE; i++){
        printf("freeing %c...\n", i+97);
        avl_free_tree(hash_table[i]);
    }
    printf("\nentire dictionary freed!\n");
}
