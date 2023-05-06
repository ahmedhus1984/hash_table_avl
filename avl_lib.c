//library for avl
#include "header.h"

card* avl_create(char *subject, char *explanation){
    card *a=malloc(sizeof(card));
    if (a==NULL){
        printf("unable to allocate memory for the card for %s\n", subject);
    }
    else{
        a->subject=malloc(strlen(subject)+1);
        if (a->subject==NULL){
            printf("unable to allocate memory for subject portion for the card %s\n", subject);
            free(a);
            a=NULL;
        }
        else{
            strcpy(a->subject, subject);
            a->explanation=malloc(strlen(explanation)+1);
            if (a->explanation==NULL){
                printf("unable to allocate memory for explanation portion for the card %s\n", subject);
                free(a->subject);
                free(a);
                a=NULL;
        }   
            else{
                strcpy(a->explanation, explanation);
                a->left=a->right=NULL;   
            }
        }
    }
    return a;
}
card* avl_insert_node_avl(card *root, char *subject, char *explanation){
  if(root==NULL){
    card *temp=avl_create(subject, explanation);
    if(temp==NULL){
        printf("unable to insert %s\n", subject);
    }
    else{
      printf("%s inserted to tree\n", temp->subject);
    }
    return temp;
  }
  else if(strcmp(subject, root->subject)<0){
    root->left=avl_insert_node_avl(root->left, subject, explanation);
  }
  else if(strcmp(subject, root->subject)>0){
    root->right=avl_insert_node_avl(root->right, subject, explanation);
  }
  else{
    printf("unable to insert %s. %s already exists in dictionary\n", subject, subject);
    return root;
  }

/*code for avl balance factor checks and subsequent rotations if necessary after node insertion begins*/
    int balance = avl_node_balance_factor(root);
    //case of right-right imbalance requiring a left rotation on the root to correct imbalance
    if(balance==-2 && avl_node_balance_factor(root->right)<=0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("right-right imbalance of %d for node %s\n", balance, root->subject);
        printf("performing left rotation on node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root = avl_leftRotate(root);
    }
    //case of right-left imbalance requiring a right rotation on the root's right node then a left rotation on the root to correct imbalance
    if(balance==-2 && avl_node_balance_factor(root->right)>0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("right-left imbalance of %d for node %s\n", balance, root->subject);
        printf("performing step 1/2: right rotation on node %s to correct this imbalance...\n", (root->right)->subject);
        root->right = avl_rightRotate(root->right);
        printf("performing step 2/2: left rotation on root node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root=avl_leftRotate(root);
    }
    //case of left-left imbalance requiring a right rotation on the root to correct imbalance
    if(balance==2 && avl_node_balance_factor(root->left)>=0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("left-left imbalance of %d for node %s\n", balance, root->subject);
        printf("performing right rotation on node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root = avl_rightRotate(root);
    }
    //case of left-right imbalance requiring a left rotation on the root's left node then a right rotation on the root to correct imbalance
    if(balance==2 && avl_node_balance_factor(root->left)<0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("left-right imbalance of %d for node %s\n", balance, root->subject);
        printf("performing step 1/2: left rotation on node %s to correct this imbalance...\n", (root->left)->subject);
        root->left = avl_leftRotate(root->left);
        printf("performing step 2/2: right rotation on root node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root=avl_rightRotate(root);
    }
/*code for avl balance factor checks and subsequent rotations if necessary after node insertion ends*/

    return root;
}

card* avl_read_card(card *root, char *subject){
   //base 1 + work
   if (root==NULL){
      printf("%s does not exist in tree\n", subject);
      return root;
   }
   //base 2 + work
   else if(strcmp(subject, root->subject)==0){
      return root;
   }
   //recursions
   else if(strcmp(subject, root->subject)<0){
      return avl_read_card(root->left, subject);
   }
   else{
      return avl_read_card(root->right, subject);
   }
}

card* avl_lookup_card(card *root, char *subject){
   //base 1 + work
   if (root==NULL){
      printf("%s does not exist in tree\n", subject);
      return root;
   }
   //base 2 + work
   else if(strcmp(subject, root->subject)==0){
      printf("\n");
      printf("###############################################\n");
      printf("subject:\n%s\n", root->subject);
      printf("\n");
      printf("explanation:\n%s\n", root->explanation);
      printf("###############################################\n");
      printf("\n");
      return root;
   }
   //recursions
   else if(strcmp(subject, root->subject)<0){
      return avl_lookup_card(root->left, subject);
   }
   else{
      return avl_lookup_card(root->right, subject);
   }
}

void avl_pattern_search(card *root, char *pattern){
  //base 1 + work
  if (root==NULL){
    return;
  }
  //base 2 + work
  else if(avl_pattern_check(pattern, root->subject)==true || avl_pattern_check(pattern, root->explanation)==true){
    printf("\n");
    printf("###############################################\n");
    printf("subject:\n%s\n", root->subject);
    printf("\n");
    printf("explanation:\n%s\n", root->explanation);
    printf("###############################################\n");
    printf("\n");
  }
  //recursions
  avl_pattern_search(root->left, pattern);
  avl_pattern_search(root->right, pattern);
}

bool avl_pattern_check(char *pattern, char *text){
  int c, d, e, text_length, pattern_length, position = -1;

  text_length=strlen(text);
  pattern_length=strlen(pattern);

  if (pattern_length>text_length) {
    return false;
  }

  for (c=0; c<=text_length-pattern_length; c++) {
    position=e=c;

    for (d=0; d<pattern_length; d++) {
      if (pattern[d]==text[e]) {
        e++;
      }
      else {
        break;
      }
    }
    if (d==pattern_length) {
      printf("match for pattern begins at character %d of the string\n", position+1);
      return true;
    }
  }
  return false;
}

card* avl_delete_node_avl(card *root, char *subject){
  if(root==NULL){
    printf("unable to delete %s as it does not exist in dictionary\n", subject);
  }
  else if(strcmp(subject, root->subject)<0){
    root->left=avl_delete_node_avl(root->left, subject);
  }
  else if(strcmp(subject, root->subject)>0){
    root->right=avl_delete_node_avl(root->right, subject);
  }
  else{
    if(root->left==NULL){
      card *temp=root->right;
      free(root->explanation);
      free(root->subject);
      free(root);
      printf("%s has been deleted from the tree\n", subject);
      return temp;
    }
    else if(root->right==NULL){
      card *temp=root->left;
      free(root->explanation);
      free(root->subject);
      free(root);
      printf("%s has been deleted from the tree\n", subject);
      return temp;
    }
    else{
      card *temp=avl_minValueNode(root->right);
      root->subject=temp->subject;
      root->explanation=temp->explanation;
      printf("%s has replaced double-child node %s, the original node %s is ready to be deleted from the tree\n", temp->subject, subject, temp->subject);
      root->right=avl_delete_node_avl(root->right, temp->subject);
    }
  }

/*code for avl balance factor checks and subsequent rotations if necessary after node deletion begins*/
    int balance = avl_node_balance_factor(root);
    //case of right-right imbalance requiring a left rotation on the root to correct imbalance
    if(balance==-2 && avl_node_balance_factor(root->right)<=0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("right-right imbalance of %d for node %s\n", balance, root->subject);
        printf("performing left rotation on node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root = avl_leftRotate(root);
    }
    //case of right-left imbalance requiring a right rotation on the root's right node then a left rotation on the root to correct imbalance
    if(balance==-2 && avl_node_balance_factor(root->right)>0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("right-left imbalance of %d for node %s\n", balance, root->subject);
        printf("performing step 1/2: right rotation on node %s to correct this imbalance...\n", (root->right)->subject);
        root->right = avl_rightRotate(root->right);
        printf("performing step 2/2: left rotation on root node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root=avl_leftRotate(root);
    }
    //case of left-left imbalance requiring a right rotation on the root to correct imbalance
    if(balance==2 && avl_node_balance_factor(root->left)>=0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("left-left imbalance of %d for node %s\n", balance, root->subject);
        printf("performing right rotation on node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root = avl_rightRotate(root);
    }
    //case of left-right imbalance requiring a left rotation on the root's left node then a right rotation on the root to correct imbalance
    if(balance==2 && avl_node_balance_factor(root->left)<0){
        printf("\n");
        printf("root value: %s\n", root->subject);
        printf("left-right imbalance of %d for node %s\n", balance, root->subject);
        printf("performing step 1/2: left rotation on node %s to correct this imbalance...\n", (root->left)->subject);
        root->left = avl_leftRotate(root->left);
        printf("performing step 2/2: right rotation on root node %s to correct this imbalance...\n", root->subject);
        printf("\n");
        root=avl_rightRotate(root);
    }
/*code for avl balance factor checks and subsequent rotations if necessary after node deletion ends*/

  return root;
}

//barebone version
card* avl_update_card(card *root, char *subject_old, char *subject_new, char *explanation){
  root=avl_delete_node_avl(root, subject_old);
  root=avl_insert_node_avl(root, subject_new, explanation);
  return root;
}

int avl_node_height(card* root){
    if (root==NULL){
        return -1;
    }
    else {
        // Find the height of left, right subtrees, adding 1 to include the current node's height
        int left_height=avl_node_height(root->left)+1;
        int right_height=avl_node_height(root->right)+1;
        // Find max(sub tree's height) + 1 to get the height of the tree
        return (left_height>right_height) ? left_height:right_height;
    }
}

int avl_node_balance_factor(card* root){
    // Find the height of left, right subtrees
    int left=avl_node_height(root->left);
    int right=avl_node_height(root->right);
    int balance_factor = left-right;
    return balance_factor;
}

struct card* avl_minValueNode(card* root){
    card *current = root;
    /* loop down to find the left-most leaf */
    while(current->left!=NULL){
        current=current->left;
  }
    return current;
}

struct card* avl_maxValueNode(card* root){
    card *current = root;
    /* loop down to find the right-most leaf */
    while(current->right!=NULL){
        current=current->right;
  }
    return current;
}

// A utility function to correct Right-Right cases by doing a left rotate on a given root of a tree/subtree
// See the diagram given above.
card* avl_leftRotate(card* root){
    card *y = root->right;
    card *T2 = y->left;

    // Perform rotation
    y->left = root;
    root->right = T2;

    return y;
}

// A utility function to correct Left-Left cases by doing a right rotate on a given root of a tree/subtree
card* avl_rightRotate(card* root){
    card *y = root->left;
    card *T2 = y->right;

    // Perform rotation
    y->right = root;
    root->left = T2;

    return y;
}

void avl_print_tree_inorder(card* root){
  if (root==NULL){
      return;
  }
  avl_print_tree_inorder(root->left);
  printf("%s\n", root->subject);
  avl_print_tree_inorder(root->right);
}

void avl_print_tree_inorder_full(card* root){
  if (root==NULL){
      return;
  }
  avl_print_tree_inorder_full(root->left);
  printf("\n");
  printf("###############################################\n");
  printf("subject:\n%s\n", root->subject);
  printf("\n");
  printf("explanation:\n%s\n", root->explanation);
  printf("###############################################\n");
  printf("\n"); 
  avl_print_tree_inorder_full(root->right);
}

int avl_count_subjects_per_index_avl(card* root){
  if (root==NULL){
      return 0;
  }
  int l=0;
  int r=0;
  l=avl_count_subjects_per_index_avl(root->left);
  r=avl_count_subjects_per_index_avl(root->right);
  return l+r+1;
}

//levelorder traversal print
/* Function to print level order traversal a tree*/
void avl_printLevelOrder(card *root){
  int a=avl_node_height(root);
  for (int i = 0; i <= a; i++){
    avl_printCurrentLevel(root, i);
    printf("\n");
  }
}

/* Print nodes at a current level */
void avl_printCurrentLevel(card *root, int level){
  if (root == NULL){
    return;
  }
  if(level == 0){
    printf("%s ", root->subject);
  }
  avl_printCurrentLevel(root->left, level-1);
  avl_printCurrentLevel(root->right, level-1);
}

void avl_save_tree(FILE *p1, card* root){
  if (root==NULL){
    return;
  }
  avl_save_tree(p1, root->left);
  int new_size=avl_save_mem_alloc(root->subject);
  char *avl_save_buffer_1=calloc(1, new_size);
  if(avl_save_buffer_1==NULL){
    printf("unable to allocate memory for extension to accommodate quotations for the subject string for the subject %s\n", root->subject);
    return;
  }
  avl_save_quotation_rectification(root->subject, avl_save_buffer_1);
  new_size=avl_save_mem_alloc(root->explanation);
  char *avl_save_buffer_2=calloc(1, new_size);
  if(avl_save_buffer_2==NULL){
    printf("unable to allocate memory for extension to accommodate quotations for the explanation string for the subject %s\n", root->explanation);
    return;
  }
  avl_save_quotation_rectification(root->explanation, avl_save_buffer_2);
  avl_save_write_to_file(p1, avl_save_buffer_1, avl_save_buffer_2);
  free(avl_save_buffer_1);
  free(avl_save_buffer_2);
  avl_save_tree(p1, root->right);
}

int avl_save_quotation_checker(char* p1){
  int count=0;
  while(*p1!='\0'){
    if(*p1=='\"'){
      count++;
    }
    p1++;
  }
  return count;
}

int avl_save_mem_alloc(char* p1){
  int new_sz=(strlen(p1))+1;
  printf("original size for %s is %d\n", p1, new_sz);
  int count=avl_save_quotation_checker(p1);
  if(count>0){
    new_sz+=count;
  }
  printf("resized size for %s is %d\n", p1, new_sz);
  return new_sz;
}

void avl_save_quotation_rectification(char* p1, char *p2){
  while(*p1!='\0'){
    if(*p1=='\"'){
      *p2=*p1;
      p2++;
    }
    *p2=*p1;
    p2++;
    p1++;
  }
}

void avl_save_write_to_file(FILE* p1, char* p2, char* p3){
  fprintf(p1, "%s", "\"");
  fprintf(p1, "%s", p2);
  fprintf(p1, "%s", "\"");
  fprintf(p1, "%s", ",");
  fprintf(p1, "%s", "\"");
  fprintf(p1, "%s", p3);
  fprintf(p1, "%s", "\"");
  fprintf(p1, "%s", "\n");
  }

void avl_free_tree(card* root){
  if (root==NULL){
    return;
  }
  avl_free_tree(root->left);
  avl_free_tree(root->right);
  free(root->explanation);
  free(root->subject);
  free(root);
}