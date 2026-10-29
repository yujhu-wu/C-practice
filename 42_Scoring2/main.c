#include <stdio.h>
#include <stdlib.h>


struct scores
{
    int a;
    int b;
    int c;
};

int main()
{
    struct scores score;
    struct scores array[ 10000 ];

    int roll;
    int flag = 0;
    while(scanf("%d", &roll)!=EOF){
        int a1 = 0;
        int b1 = 0;
        int c1 = 0;
        int f1 = 0;
        double f;

        if(roll==0){
            break;
        }
        if(flag>=1){
            printf("\n");
        }
        printf("==================================================\n");
        printf("Index   Attendance   Practice   Exam   Final Score\n");
        printf("==================================================\n");
        for(int i=1; i<=roll; ++i){
            scanf("%d %d %d", &array[i-1].a, &array[i-1].b, &array[i-1].c);
            if(i<10){
                f=((double)array[i-1].a/10)+((double)array[i-1].b/10)*3+((double)array[i-1].c/10)*6;
                printf("0000%d%13d%11d%7d%14d\n", i, array[i-1].a, array[i-1].b, array[i-1].c, (int)f );
                a1 += array[i-1].a;
                b1 += array[i-1].b;
                c1 += array[i-1].c;
                f1 += f;
            }
            else if(i<100){
                f=((double)array[i-1].a/10)+((double)array[i-1].b/10)*3+((double)array[i-1].c/10)*6;
                printf("000%d%13d%11d%7d%14d\n", i, array[i-1].a, array[i-1].b, array[i-1].c, (int)f );
                a1 += array[i-1].a;
                b1 += array[i-1].b;
                c1 += array[i-1].c;
                f1 += f;
            }
            else{
                f=((double)array[i-1].a/10)+((double)array[i-1].b/10)*3+((double)array[i-1].c/10)*6;
                printf("00100%13d%11d%7d%14d\n", array[i-1].a, array[i-1].b, array[i-1].c, (int)f );
                a1 += array[i-1].a;
                b1 += array[i-1].b;
                c1 += array[i-1].c;
                f1 += f;
            }
        }
        a1 = (double)a1/(double)roll;
        b1 = (double)b1/(double)roll;
        c1 = (double)c1/(double)roll;
        f1 = (double)f1/(double)roll;

        printf("==================================================\n");
        printf("Mean%14d%11d%7d%14d\n", a1, b1, c1, f1);
        printf("==================================================\n");
        flag += 1;

    }

    return 0;
}
