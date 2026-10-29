#include <stdio.h>
#include <stdlib.h>

struct stackNode{
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void check(StackNodePtr topPtr);


int main(void)
{
    char item;

    while(scanf("%c", &item) != EOF){
        StackNodePtr startPtr = NULL;
        int flag = 0;
        push(&startPtr, item);

        while(scanf("%c", &item) && item != '\n'){
            push(&startPtr, item);
            if(startPtr->data == ')'){
                while(startPtr != NULL && startPtr->data != '('){
                    pop(&startPtr);
                }
                if(startPtr == NULL){
                    flag = 1;
                }
                else{
                    pop(&startPtr);
                }
            }
        }
        while(startPtr != NULL){
            if(startPtr->data== '(' || startPtr->data== ')'){
                flag = 1;
            }
            pop(&startPtr);
        }
        if(flag == 1 || startPtr != NULL){
            printf("Illegal formula.\n");
        }
        else if(flag == 0 || startPtr == NULL){
            printf("Legal formula.\n");
        }
    }
}

void push(StackNodePtr *topPtr, char info)
{
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if(newPtr !=  NULL){
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else{
        printf("%d not inserted. No memory available.\n", info);
    }
}

int pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr = *topPtr;
    int popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);

    return popValue;
}

int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}
