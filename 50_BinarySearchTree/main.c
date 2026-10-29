#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode{
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
    int data;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main()
{
    TreeNodePtr rootPtr = NULL;
    char string[100];
    int value;

    while((gets(string)) != NULL){
        char *tokenPtr = strtok(string, " ");
        value = atoi(tokenPtr);
        //printf("%d", value);
        insertNode(&rootPtr, value);

        while((tokenPtr = strtok(NULL, " ")) != NULL){
            value = atoi(tokenPtr);
            //printf("%d", value);
            insertNode(&rootPtr, value);
        }

        puts("Preorder:");
        preOrder(rootPtr);
        puts("");

        puts("Inorder:");
        inOrder(rootPtr);
        puts("");

        puts("Postorder:");
        postOrder(rootPtr);
        puts("");

        rootPtr = NULL;

    }
    return 0;
}

void insertNode(TreeNodePtr *treePtr, int value)
{
    if(*treePtr == NULL){
        *treePtr = malloc(sizeof(TreeNode));

        if(*treePtr != NULL){
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else{
            printf("Error.");
        }
    }
    else{
        if(value < (*treePtr)->data){
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else if(value > (*treePtr)->data){
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else{
            return;
        }
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if(treePtr != NULL){
        inOrder(treePtr->leftPtr);
        printf("%d\n", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr)
{
    if(treePtr != NULL){
        printf("%d\n", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TreeNodePtr treePtr)
{
    if(treePtr != NULL){
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%d\n", treePtr->data);
    }
}
