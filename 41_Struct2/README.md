# Struct2

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：結構陣列
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

![題目原文](problem.png)

A common method to store records in a file is the comma-separated values (CSV), where all values are separated by the comma symbol (,) and every two consecutive records are separated by a newline. However, CSV files are often hard to read by human, so the presentation of data in a CSV file should be carefully considered. To help store records in memory, we have to define a structure. Your goal is to write a program to store each record in a file to an array of structure and present them in appropriate format. Requirement: Use standard library functions defined in “string.h” to tokenize your input. Use array of structure to store the records.

**Input**

The input has several records and ends with the EOF. Each record contains the following fields: First Name, Last Name, Nick Name, Age, Gender, University, and Department. All the field values are separated by the comma symbol.

**Output**

Store the records in a structure with proper members. Output the records according to the format shown in the sample output. Two consecutive fields are separated by three spaces, except the fields university and department, where they are separated by 20 spaces. Each dashed line is composed of 112 dashes. All the field values are aligned left except Age (aligned right), and Gender (aligned to the character 'n’ in the filed name).

**Sample Input**

```
Michael,Bryant,Spider,32,Female,Fu Jen Catholic,Electrical Engineering
Cris,Bryant,Scarlet,33,Male,Northwestern,Psychology
Tom,Stockton,Mamba,36,Female,Princton,Electrical Engineering
Lebron,Bryant,Bishop,20,Female,Yale,Psychology
```

**Sample Output**

```

```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct people
{
    char *fn;
    char *ln;
    char *nn;
    char *a;
    char *g;
    char *u;
    char *d;
};

int main()
{
    char c [ 1000 ] ;
    struct people s [ 1000 ];
    int flag;

    printf ( "First Name   Last Name   Nick Name   Age   Gender   University                    Department\n" );
    printf ( "----------------------------------------------------------------------------------------------------------------\n" );

    for ( int i = 0; i < 484; ++i )
    {
        gets ( c );
        s [ i ].fn = strtok (  c, "," );
        s [ i ].ln = strtok ( NULL, "," );
        s [ i ].nn = strtok ( NULL, "," );
        s [ i ].a = strtok ( NULL, "," );
        s [ i ].g = strtok ( NULL, "," );
        s [ i ].u = strtok ( NULL, "," );
        s [ i ].d = strtok ( NULL, "," );

        printf ( "%-13s", s [ i ].fn );
        printf ( "%-12s", s [ i ].ln );
        printf ( "%-12s", s [ i ].nn );

        int n = atoi ( s [ i ].a );
        printf ( "%3d", n );

        flag = strcmp ( s [ i ].g ,"Female" );

        if ( flag == 0 )
        {
            strcpy ( s [ i ].g, "F" );
            printf ( "%6s      ", s [ i ].g );
        }
        else
        {
            strcpy ( s [ i ].g, "M" );
            printf ( "%6s      ", s [ i ].g );
        }

        printf ( "%-30s", s [ i ].u );
        printf ( "%s", s [ i ].d );
        printf ( "\n" );

    }
    printf ( "----------------------------------------------------------------------------------------------------------------\n" );
    return 0;
}
```

