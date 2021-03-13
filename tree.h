#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
struct node {
    char id;
    struct node *left, *right;
};
typedef struct node Node;
typedef struct node* pNode;
pNode createTree(FILE *input);
int maxHeight(pNode root);
void preorder(FILE *output, pNode root, int cur_height);
void inorder(FILE *output, pNode root, int cur_height);
void postorder(FILE *output, pNode root, int cur_height);
int leaves(pNode root);
void swapp(char key, pNode root);
void deleteTree(pNode root);
void btlConstruct(pNode root, pNode * head, FILE *output);
#endif // TREE_H_INCLUDED
