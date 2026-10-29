#include <stdio.h>
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
 char *Name;
 struct mana Cost;
 char *Type;
 int Power;
 int Toughness;
};

void ParseCost(struct mana *cost, char *string)
{
 int i;

 cost->colorless = 0;
 cost->white = 0;
 cost->red = 0;
 cost->green = 0;
 cost->blue = 0;
 cost->black = 0;

 if (*string == ' ')

  return;

 if ( (strstr(string, "x") == string) ||  (strstr(string, "X") == string) ) {
  cost->colorless = -1;
  string++;

 }
 if (isdigit(*string)) {
  i = *string - '0';
  string++;
  if (isdigit(*string)) {
   i = i * 10 + (*string - '0');
   string++;
  }
  cost->colorless = i;
 }
 while (*string != 0) {
  if (strstr(string, "White") == string) {
   cost->white++;
   string += 5;
  } else if (strstr(string, "Red") == string) {
   cost->red++;
   string += 3;
  } else if (strstr(string, "Green") == string) {
   cost->green++;
   string += 5;
  } else if (strstr(string, "Blue") == string) {
   cost->blue++;
   string += 4;
  } else if (strstr(string, "Black") == string) {
   cost->black++;
   string += 5;
  } else
   break;
 }
}

int main()
{
 FILE *instream, *outstream;
 struct data Entry;
 char string[200];
 char *ptr, *ptr2;

 if ((instream = fopen("test_input_MTG21.txt", "rt")) != NULL) {
  if ((outstream = fopen("my_output_MTG21.txt", "wt")) != NULL) {
   fprintf(outstream, "--------------------------------------------------------------------------------------------------------------------\n");
   fprintf(outstream, "Name                        Colorless   White   Red   Green   Blue   Black   Type                  Power   Toughness\n");
   fprintf(outstream, "--------------------------------------------------------------------------------------------------------------------\n");

   while (fgets(string, sizeof(string), instream) != NULL) {
    Entry.Power = 0;
    Entry.Toughness = 0;
    ptr = strtok(string, ",");

    for (int i = 0; ptr != NULL; i++) {
     switch (i) {
     case 0:
      Entry.Name = ptr;
      break;
     case 1:
      ParseCost(&(Entry.Cost), ptr);
      break;
     case 2:
      ptr2 = strstr(ptr, "-");
      if (ptr2 != NULL)
       *ptr2 = 0;
      Entry.Type = ptr;
      break;
     case 3:
      if (sscanf(ptr, "%d", &Entry.Power) != 1)
       Entry.Power = 0;
      break;
     case 4:
      if (sscanf(ptr, "%d", &Entry.Toughness) != 1)
       Entry.Toughness = 0;
      break;
     default:
      printf("error: too many commas");
      return 0;
     }
     ptr = strtok(NULL, ",");
    }

    fprintf(outstream, "%-28s", Entry.Name);

    if (Entry.Cost.colorless == -1)
     fprintf(outstream, "        x");
    else
     fprintf(outstream, "%9d", Entry.Cost.colorless);
    fprintf(outstream, "%8d%6d%8d%7d%8d   %-22s%5d%12d\n", Entry.Cost.white, Entry.Cost.red, Entry.Cost.green, Entry.Cost.blue, Entry.Cost.black, Entry.Type, Entry.Power, Entry.Toughness);
   }
   fprintf(outstream, "--------------------------------------------------------------------------------------------------------------------\n");
   fclose(outstream);
  }
  fclose(instream);
 }

 return 0;
}
