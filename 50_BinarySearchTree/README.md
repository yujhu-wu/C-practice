# BinarySearchTree

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 二元搜尋樹
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Trees are dynamic nonlinear data structure. A special type of trees is binary tree that each node contains at most two children. A famous variation of binary tree is the binary search tree (BST). Every node in a BST follows the BST rule that the keys of all nodes in the left subtree are less than such node, and the keys of all nodes in the right subtree are greater than such node. The construction of a BST bases on the insertion of nodes from an empty binary tree. The insertion procedure finds an appropriate leaf node according to the BST rule to insert. A good property for BST is that the inorder traversal results in a sorted sequence. Your goal is to write a program to construct a BST by insertion, print the contents of the BST by preorder, inorder, and postorder traversals, and delete the BST by postorder traversal. Requirement: Use self-referential structure to build a BST. Reclaim the memory properly. Prohibited: Static as well as dynamic array, any sorting methods for array.

**Input**

Each line contains a set of integers to be inputted, and input ends with an EOF marker.

**Output**

For each case, build the BST according to the input sequence without considering the duplicate values, and output the results of preorder, inorder, and postorder traversals.

**Sample Input**

```
1 3 2 4
```

**Sample Output**

```
Preorder:
1
3
2
4

Inorder:
1
2
3
4

Postorder:
2
4
3
1
```

## 程式碼

### main.c

```c
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
```

