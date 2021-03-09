#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
pNode createTree(FILE *input) {
    char c;
    fscanf(input, "%c", &c);
    pNode node = (pNode)malloc(sizeof(Node));
    if(c == '*')
        return NULL;
    else {
        if(node == NULL){
            printf("No memory in createTree");
            exit(0);
        }
        node->id = c;
        node->left = createTree(input);
        node->right = createTree(input);
    }
    return node;
}
int maxHeight(pNode root) {
    if(root == NULL)
        return -1;
    else {
        int heightleft = maxHeight(root->left);
        int heightright = maxHeight(root->right);
        if(heightleft > heightright)
            return heightleft + 1;
        else
            return heightright + 1;
    }
}
void preorder(FILE *output, pNode root, int cur_height) {
    if(root!=NULL) {
        int i;
        for(i = 0; i < cur_height; i++) {
            fprintf(output, " ");
        }
        fprintf(output, "%c\n", root->id);
        preorder(output, root->left, cur_height+1);
        preorder(output, root->right, cur_height+1);
    }
}
void inorder(FILE *output, pNode root, int cur_height) {
    if(root!=NULL) {
        int i;
        inorder(output, root->left, cur_height + 1);
        for(i = 0; i <= cur_height; i++) {
            fprintf(output, " ");
        }
        fprintf(output, "%c\n", root->id);
        inorder(output, root->right, cur_height + 1);
    }
}
void postorder(FILE *output, pNode root, int cur_height) {
    if(root!=NULL) {
        int i;
        postorder(output, root->left, cur_height+1);
        postorder(output, root->right, cur_height+1);
        for(i = 0; i <= cur_height; i++) {
            fprintf(output, " ");
        }
        fprintf(output, "%c\n", root->id);
    }
}
int leaves(pNode root) {
    if(root == NULL)
        return 0;
    if(root -> left == NULL && root->right ==NULL)
        return 1;
    else {
        return (leaves(root->left) + leaves(root->right));
    }
}
void swapp(char key, pNode root) {
    if(root != NULL){
        printf("%c %c\n", key, root->id);
        if(key == root->id) {
            pNode right = root->right;
            root->right = root->left;
            root->left = right;
            return;
        }
        else {
            swapp(key, root->left);
            swapp(key, root->right);
        }
    }

}
