# ParenthesisCheck

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 堆疊
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Stack is a common data structure with a variety of applications. One useful application of stack is to determine the legality of a formula by checking whether each right parenthesis match a left one. To take this check, we can prepare a stack and push every left parenthesis, variable, and operators into a stack. Whenever a right parenthesis is encountered, pop all the items in the stack until a left parenthesis is popped. A formula is illegal if the stack cannot be successfully popped or there remains left parentheses in the stack at the end. Try to write a program to check the legality of input formula through the above method. You have to write a stack node data structure with corresponding push and pop functions and prepare a stack for checking the legality. Requirement: Write a stack node data structure with corresponding push and pop functions and prepare a stack for checking the legality.

**Input**

The input contains several cases and ends with EOF. Each case in a line is a formula, composed of variables (1~9), operators (+, -, *, /), and parentheses.

**Output**

For each case, output “Legal formula.” if it is legal; otherwise, output “Illegal formula.” Two consecutive cases should be separated by a newline character.

**Sample Input**

```
9 * 5 - 2 * 1)
8 / 8 * 4 + (1 + 6 - (5 * (7
(9 / (8) * (3) / 3)
```

**Sample Output**

```
Illegal formula.
Illegal formula.
Legal formula.
```

## 程式碼

### main.c

```c
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
```

