#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

typedef struct node Node;

struct node {
    char *name;
    char *tea;
    Node *left;
    Node *right;
    
};
int depthr(Node *ptr){
    if(ptr==NULL){
        return 0;
    }else{
        int lb=depthr(ptr->left);
        int rb=depthr(ptr->right);
        if (lb>rb) {
            return lb+1;
        }else{
            return rb+1;
        }
        
    }
}
int depth(Node *root) {
    Node* ptr=root;
    
    return depthr(ptr);
}
int count;
int found;

int dfsr(Node *ptr,char *name) {
    
    if (ptr == NULL) {
        return 0;
    }
    count++;
    if (ptr->name==name){
       found=1;
       return count;
       
    }
    printf("%s",ptr->name);
    int lb=dfsr(ptr->left,name);
    int rb=dfsr(ptr->right,name);

}

int dfs(Node *root,char *name) {
    Node* ptr=root;
    count=0;
    found=0;
    dfsr(ptr,name);
    if (found==1) {
        return count;
    } else {
        return -1;
    }

    
}
int main() {
    // Testing code ^_^
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
}