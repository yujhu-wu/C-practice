# LinkedList

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：鏈結串列
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

Magic: The Gathering (MTG) is a famous card game designed by Richard Garfield and released by Wizards of the Coast (WoC). In recent years, WoC has dedicated to develop a platform for playing MTG on computers and mobile devices. To accomplish this, WoC tries to store their cards in a file. To ease the computation of the cards in computer, we need to prepare data structures as a container to store the cards with the following members:

1. Name: a string of maximum 50 characters (including the null character)
2. Cost: a user defined data structures with six integers, representing the cost of colorless, White, Red,

Green, Blue and Black mana

3. Type: a string of maximum 50 characters (including the null character)
4. Power: an integer
5. Toughness: an integer

Try to write a program with above structures to read from a random access file with 285 records of MTG cards, insert them into a linked list, and output the contents by linked-list traversal. Requirement: Input from the random access file “test_input_LinkedList.txt” rather than standard input stream, use a linked list to store and sort the data, and output the sorted card set to a sequential access file “my_output_LinkedList.txt” rather than standard output stream. Prepare a function to insert an item into a linked list, a function to traverse a linked list and a function to destroy a linked list by releasing all the allocated memory. You are prohibited to use an array of structures for storing the input.

**Input**

The input named as “test_input_LinkedList.txt” is a random access file with 285 records. Each record is defined as the data structure described above.

**Output**

Prepare a linked list to store and sort the input. Sort the input records according to their cost of White mana, cost of Red mana, cost of Green mana, cost of Blue mana, cost of Black mana, cost of Colorless mana, power, toughness, Type, and Name. The first nine features should be sorted in descending order, and the last feature should be sorted in ascending order. These features should be compared as the above order. Output the records to a sequential access file named as “my_output_LinkedList.txt” according to the following format. Output the ten fields in the same order of the input. Two consecutive fields are separated by three spaces, except the fields Name and Type, where they are followed by 24 and 18 spaces, respectively. All the field values are aligned right except Name and Type which are aligned right.

**Sample Input**

```
Unavailable.
```

**Sample Output**

```
Unavailable.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct mana {
    int colorless;
    int white;
    int red;
    int green;
    int blue;
    int black;
};

struct data {
    char Name[50];
    struct mana Cost;
    char Type[50];
    int Power;
    int Toughness;
};

struct listnode{
    struct data Value;
    struct listnode *nextPtr;
};
typedef struct data Data;
typedef Data *dataPtr;
typedef struct listnode *listnodePtr;

void insert(listnodePtr *sPtr, Data Entry){
    listnodePtr newPtr = malloc(sizeof(struct listnode));

    if(newPtr != NULL){
        newPtr -> Value = Entry;
        newPtr -> nextPtr = NULL;

        listnodePtr previousPtr = NULL;
        listnodePtr currentPtr = *sPtr;

        while(currentPtr != NULL){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
}

int main()
{
    FILE *instream, *outstream;
    listnodePtr startPtr  = NULL;

    if(((instream = fopen("test_input_LinkedList.txt", "rb")) != NULL) && ((outstream = fopen("my_output_LinkedList.txt", "w")) != NULL)){

        fprintf(outstream, "--------------------------------------------------------------------------------------------------------------------\n");
        fprintf(outstream, "Name                        Colorless   White   Red   Green   Blue   Black   Type                  Power   Toughness\n");
        fprintf(outstream, "--------------------------------------------------------------------------------------------------------------------\n");

        while(!feof(instream)) {
            Data Entry;
            fread(&Entry, sizeof(Data), 1, instream);
            insert(&startPtr, Entry);
        }


        listnodePtr head = startPtr;
        listnodePtr index = NULL;
        Data temp;

        while(head->nextPtr != NULL){
            index = head->nextPtr;
            while(index->nextPtr != NULL){
                if((strcmp(head->Value.Name,index->Value.Name)) > 0){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if((strcmp(head->Value.Type,index->Value.Type)) < 0){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Toughness < index->Value.Toughness){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Power < index->Value.Power){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Cost.colorless < index->Value.Cost.colorless){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Cost.black < index->Value.Cost.black){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Cost.blue < index->Value.Cost.blue){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Cost.green < index->Value.Cost.green){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Cost.red < index->Value.Cost.red){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                if(head->Value.Cost.white < index->Value.Cost.white){
                    temp = head->Value;
                    head->Value = index->Value;
                    index->Value = temp;
                }
                    index = index->nextPtr;
            }
                head = head->nextPtr;
        }


        while(startPtr->nextPtr != NULL){
            fprintf(outstream, "%-35s", startPtr->Value.Name);

            if (startPtr->Value.Cost.colorless == 120)
                fprintf(outstream, " x");
            else
                fprintf(outstream, "%2d", startPtr->Value.Cost.colorless);
            fprintf(outstream, "%8d%6d%8d%7d%8d   %-24s%3d%12d\n", startPtr->Value.Cost.white, startPtr->Value.Cost.red, startPtr->Value.Cost.green, startPtr->Value.Cost.blue, startPtr->Value.Cost.black, startPtr->Value.Type, startPtr->Value.Power, startPtr->Value.Toughness);
            startPtr = startPtr -> nextPtr;
        }
        fprintf(outstream, "--------------------------------------------------------------------------------------------------------------------\n");
        printf("im here\n");
    }
    else{
        fprintf(outstream, "no \n");
    }
    fclose(instream);
    fclose(outstream);
    return 0;
}
```

