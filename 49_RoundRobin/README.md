# RoundRobin

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：佇列
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

Process scheduling is an important task of operating system. A common process scheduling method is the round-robin, which is basically a first-come-first-served queue but only allows a process to be executed at most 𝑞 unit of time, where 𝑞 is noted as quantum. Write a program to simulate the process scheduling of round-robin by implementing a queue through linked list. Requirement: Define queue node structure, dequeue and enqueue functions. Prohibited: Static as well as dynamic array.

**Input**

The input contains several cases. Each case includes a quantum 𝑞 in milliseconds and several tasks to be executed, representing as pairs of processing time in milliseconds (unsigned integer) and task label (character). Consecutive cases are separated by a newline character. The input ends with zero quantum.

**Output**

For each case, output the simulation results of task processing sequence according to the format shown in sample output. Consecutive cases should be separated by a newline character.

**Sample Input**

```
3
5 A
6 C
4 B
7 R
9 G
4 F
13 H
11 T

0
```

**Sample Output**

```
Serve Task A 3 ms.
Serve Task C 3 ms.
Serve Task B 3 ms.
Serve Task R 3 ms.
Serve Task G 3 ms.
Serve Task F 3 ms.
Serve Task H 3 ms.
Serve Task T 3 ms.
Serve Task A 2 ms. Task A done.
Serve Task C 3 ms. Task C done.
Serve Task B 1 ms. Task B done.
Serve Task R 3 ms.
Serve Task G 3 ms.
Serve Task F 1 ms. Task F done.
Serve Task H 3 ms.
Serve Task T 3 ms.
Serve Task R 1 ms. Task R done.
Serve Task G 3 ms. Task G done.
Serve Task H 3 ms.
Serve Task T 3 ms.
Serve Task H 3 ms.
Serve Task T 2 ms. Task T done.
Serve Task H 1 ms. Task H done.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queueNode{
    int data;
    char letter;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

int main(void)
{

    int std;
    int own;
    char let;
    char space;
    char blank;
    char number;
    char enter;
    int record;
    int cnt = 0;

    while ( scanf ( "%d%c", &std, &blank ) && std != 0 ){
        if ( cnt != 0 ){
            puts ( "" );
        }
        cnt = 1;
        QueueNodePtr headPtr = NULL;
        QueueNodePtr tailPtr = NULL;

        scanf ( "%d %c", &own, &let );
        QueueNodePtr newPtr;
        newPtr = malloc ( sizeof ( QueueNode ) );
        newPtr -> data = own;
        newPtr -> letter = let;
        newPtr -> nextPtr = NULL;
        headPtr = newPtr;
        tailPtr = newPtr;

        while ( scanf ( "%c%c", &enter, &number ) && number != '\n' ){
            QueueNodePtr evaluatePtr;
            evaluatePtr = malloc ( sizeof ( QueueNode ) );
            scanf ( "%c%c", &blank, &let );
            evaluatePtr -> data = number - '0';
            if ( blank != ' ' ){
                evaluatePtr -> data *= 10;
                evaluatePtr -> data += blank - '0';
                scanf ( "%c", &let );
            }

            evaluatePtr -> letter = let;
            evaluatePtr -> nextPtr = NULL;

            tailPtr -> nextPtr = evaluatePtr;
            tailPtr = evaluatePtr;
        }

        while ( headPtr != NULL ){
            QueueNodePtr extendPtr;
            extendPtr = malloc ( sizeof ( QueueNode ) );
            record = headPtr -> data;
            headPtr -> data -= std;

            if ( headPtr -> data > 0 ){
                printf ( "Serve Task %c %d ms.\n", headPtr -> letter, std );
                QueueNodePtr temp;
                temp = headPtr;
                extendPtr -> data = headPtr -> data;
                extendPtr -> letter = headPtr -> letter;
                extendPtr -> nextPtr = NULL;
                tailPtr -> nextPtr = extendPtr;
                tailPtr = extendPtr;
                headPtr = headPtr -> nextPtr;
                free ( temp );
            }
            else{
                printf ( "Serve Task %c %d ms. Task %c done.\n", headPtr -> letter, record, headPtr -> letter );
                QueueNodePtr temp;
                temp = headPtr;
                headPtr = headPtr -> nextPtr;
                free ( temp );
            }
        }
    }
}
```

