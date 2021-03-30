#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
int main(int argc, char **argv)
{
    if(argc <= 1) {
        printf("not enough command line arguments");
        exit(0);
    }
    if(argv[1]==NULL || argv[2]==NULL || argv[3]==NULL) {
        printf("not enough command line arguments");
        exit(0);
    }
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    if(input == NULL || output == NULL) {
        printf("Missing input/output file(s)");
        exit(0);
    }
    pNode root = createTree(input);
    if(!strcmp(argv[3], "height")) {
        fprintf(output, "Height of the tree is: %d\n", maxHeight(root) + 1);
    }
    else if(!strcmp(argv[3], "preorder")) {
        preorder(output, root, 0);
    }
    else if(!strcmp(argv[3], "inorder")) {
        inorder(output, root, 0);
    }
    else if(!strcmp(argv[3], "postorder")) {
        postorder(output, root, 0);
    }
    else if(!strcmp(argv[3], "leaves")) {
        fprintf(output, "%d", leaves(root));
    }
    else if(!strcmp(argv[3], "swap")) {
        char key;
        fscanf(input, "%c", &key);
        fscanf(input, "%c", &key);
        swapp(key, root);
        inorder(output, root, 0);
    }
    else if(!strcmp(argv[3], "list")) {
        pNode head = NULL;
        ///printf("%c ", root->id);
        btlConstruct(root, &head, output);
    }
    deleteTree(root);
    fclose(input);
    fclose(output);
    return 0;
}
