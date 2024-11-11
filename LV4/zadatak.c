#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct SLOVO {
    char c;
    struct SLOVO* left;
    struct SLOVO* right;
}slovo;

slovo* root = NULL, * parent = NULL;

int nadji_p(char c) {
    int flag = 0;
    slovo* slovo_t = root;
    parent = NULL;
    if (slovo_t == NULL) {
        return -1;
    }
    while (1) {
        if (slovo_t->c == c) {
            flag = 1;
        }
        else {
            parent = slovo_t;
            if (slovo_t->c > c)
            {
                if (slovo_t->left != NULL)slovo_t = slovo_t->left;
                else flag = -1;
            }
            else
                if (slovo_t->right != NULL)slovo_t = slovo_t->right;
                else flag = -1;
        }
        if (flag == 1 || flag == -1)break;
    }
    return flag;
}

void dodaj_p(char c) {
    slovo* novi;
    int flag = 0;
    flag = nadji_p(c);
    if (flag == 1) {
        return;
    }
    else {
        novi = (slovo*)malloc(sizeof(slovo));
        novi->c = c;
        novi->left = novi->right = NULL;
        if (parent == NULL) {
            root = novi;
        }
        else {
            if (parent->c > novi->c) {
                parent->left = novi;
            }
            else {
                parent->right = novi;
            }
        }
    }
}

void preOrder(slovo* root) {
    if (root == NULL) {
        return;
    }
    else {
        printf("%c", root->c);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(slovo* root) {
    if (root == NULL) {
        return;
    }
    else {
        inOrder(root->left);
        printf("%c", root->c);
        inOrder(root->right);
    }
}

void postOrder(slovo* root) {
    if (root == NULL) {
        return;
    }
    else {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c", root->c);
    }
}

int main() {
    char ime_prez[] = { 'P','E','T','R','A','P','E','R','K','O','V','I','C','\0' };
    for (int i = 0; ime_prez[i] != '\0'; i++) {
        dodaj_p(ime_prez[i]);
    }
    printf("PreOrder: ");
    preOrder(root);
    printf("\n\n");
    printf("InOrder: ");
    inOrder(root);
    printf("\n\n");
    printf("PostOrder: ");
    postOrder(root);
    printf("\n\n");
}