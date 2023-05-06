//header files for the project

#ifndef myheader

//include statements
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//general declarations
struct card{
    char *subject;
    char *explanation;
    struct card *left;
    struct card *right;
    // add other stuff later, maybe
};

typedef struct card card;


//main lib declarations
//variables
extern int main_option;
extern bool main_data_modification;
extern char main_filename;
//functions
char main_read_filename();

//hash_table lib declarations
//variables
#define TABLE_SIZE 26
card *hash_table[TABLE_SIZE];
//functions
unsigned int hash_table_hash(char *name);
void hash_table_init_hash_table();
void hash_table_insert(char *name, char *explanation);
void hash_table_read(char *subject);
void hash_table_lookup(char *subject);
void hash_table_save_tree(char p1);
void hash_table_pattern_search(char *subject);
void hash_table_delete(char *subject);
void hash_table_update(char *subject_old, char *subject_new, char *explanation);
void hash_table_print_an_index_tree_subjects_inorder(char alphabet);
void hash_table_print_an_index_tree_subjects_and_explanations_inorder(char alphabet);
void hash_table_print_an_index_tree_levelorder(char alphabet);
void hash_table_count_subjects_per_index(char alphabet);
void hash_table_count_subjects_entire_dictionary();
void hash_table_print_first_non_null_indexes();
void hash_table_print_inorder_entire_dictionary();
void hash_table_free();



//avl_lib declarations
//functions
card* avl_create(char *subject, char *explanation);
card* avl_insert_node_avl(card *root, char *subject, char *explanation);
card* avl_read_card(card *root, char *subject); //7
card* avl_lookup_card(card *root, char *subject);
void avl_pattern_search(card *root, char *pattern);
bool avl_pattern_check(char *pattern, char *text);
card* avl_delete_node_avl(card *root, char *subject);
card* avl_update_card(card *root, char *subject_old, char *subject_new, char *explanation);
int avl_node_height(card*); //9
int avl_node_balance_factor(card*); //10
card* avl_minValueNode(card*); //8
card* avl_maxValueNode(card*); //8
card* avl_leftRotate(card*);//15
card* avl_rightRotate(card*);//15
void avl_print_tree_inorder(card *root);
void avl_print_tree_inorder_full(card *root);
int avl_count_subjects_per_index_avl(card *root);
void avl_printLevelOrder(card *root);
void avl_printCurrentLevel(card *root, int level);
void avl_save_tree(FILE *p1, card *root);
void avl_save_quotation_manager(char* p1, char *p2);
int avl_save_quotation_checker(char * p1);
int avl_save_mem_alloc(char* p1);
void avl_save_quotation_rectification(char* p1, char* p2);
void avl_save_write_to_file(FILE* p1, char* p2, char* p3);
void avl_free_tree(card *root);

//user_interface lib declaration
//functions
void user_interface_menu();
void user_interface_option();
void user_interface_char_inorder_single_tree_subject();
void user_interface_char_inorder_single_tree_subject_and_explanation();
void user_interface_count_subjects_per_index();
void user_interface_char_levelorder();
void user_interface_choice(int option);
void user_interface_lookup();
void user_interface_pattern_search();
void user_interface_add();
void user_interface_delete();
void user_interface_update();
void user_interface_save();
void user_interface_compare_words(); //test function

#define myheader
#endif