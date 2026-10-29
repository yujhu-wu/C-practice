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
