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

int cmpeverything (const void * a, const void * b)
{
    struct data *A = (struct data *)a;
    struct data *B = (struct data *)b;
    int i;

    i = A->Cost.white - B->Cost.white;
    if (i != 0) return -i;

    i = A->Cost.red - B->Cost.red;
    if (i != 0) return -i;

    i = A->Cost.green - B->Cost.green;
    if (i != 0) return -i;

    i = A->Cost.blue - B->Cost.blue;
    if (i != 0) return -i;

    i = A->Cost.black - B->Cost.black;
    if (i != 0) return -i;

    i = A->Cost.colorless - B->Cost.colorless;
    if (i != 0) return -i;

    i = A->Power - B->Power;
    if (i != 0) return -i;

    i = A->Toughness - B->Toughness;
    if (i != 0) return -i;

    i = strcmp(A->Type, B->Type);
    if (i != 0) return -i;

    return strcmp(A->Name, B->Name);
}

int main()
{
    FILE *instream, *outstream;
    int N;
    struct data *Entry;
    char string[200], temps[10], *s;

    if ((instream = fopen("test_input_SortStructure.txt", "rt")) != NULL) {
        if ((outstream = fopen("my_output_SortStructure.txt", "wt")) != NULL) {
            while (fscanf(instream, "%d ", &N) == 1) {
                if ((Entry = malloc(sizeof (struct data) * N)) == NULL) {
                    printf("Cannot malloc enough memory for %d entries\n", N);
                    break;
                }
                if (N == 0)
                    break;
                memset(Entry, 0, sizeof (struct data) * N); // fill in with zero
                for (int i = 0; i < N; i++) {
                    if (fgets(string, sizeof(string), instream) == NULL) {
                        printf("Cannot read input file\n");
                        return 0;
                    }
                    if (strlen(string) < 117) {
                        printf("string not long enough\n");
                        return 0;
                    }
                    memcpy(Entry[i].Name, string, 35);
                    s = string + 35;
                    sscanf(s, "%s%d%d%d%d%d", temps, &(Entry[i].Cost.white), &(Entry[i].Cost.red), &(Entry[i].Cost.green),
                        &(Entry[i].Cost.blue), &(Entry[i].Cost.black));
                    s = string + 77;
                    memcpy(Entry[i].Type, s, 22);
                    s += 25;
                    sscanf(s, "%d%d", &(Entry[i].Power), &(Entry[i].Toughness));
                    if (sscanf(temps, "%d", &(Entry[i].Cost.colorless)) == 0)
                         Entry[i].Cost.colorless = 99;
                }

                qsort (Entry, N, sizeof(struct data), cmpeverything);

                for (int i = 0; i < N; i++) {
                    fprintf(outstream, "%-35s", Entry[i].Name);

                    if (Entry[i].Cost.colorless == 99)
                        fprintf(outstream, " x");
                    else
                        fprintf(outstream, "%2d", Entry[i].Cost.colorless);
                    fprintf(outstream, "%8d%6d%8d%7d%8d   %-24s%3d%12d\n", Entry[i].Cost.white, Entry[i].Cost.red, Entry[i].Cost.green, Entry[i].Cost.blue, Entry[i].Cost.black, Entry[i].Type, Entry[i].Power, Entry[i].Toughness);
                }
                fprintf(outstream, "\n");
            }
        }
    }
}
