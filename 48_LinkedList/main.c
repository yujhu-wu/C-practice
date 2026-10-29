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
