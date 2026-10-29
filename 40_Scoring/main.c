#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll, a, p, e;
    double f;
    int a1, p1, e1, f1;
    int flag=0;

    while(scanf("%d", &roll))
    {
        a1=0;
        p1=0;
        e1=0;
        f1=0;
        if(roll==0)
        {
            break;
        }
        if(flag>0)
        {
            printf("\n");
        }
        printf("==================================================\n");
        printf("Index   Attendance   Practice   Exam   Final Score\n");
        printf("==================================================\n");
        for(int i=1; i<=roll; ++i)
        {
            scanf("%d %d %d", &a, &p, &e);
            if(i<10)
            {
                f=(double)a/10+((double)p/10)*3+((double)e/10)*6;
                printf("0000%d%13d%11d%7d%14d", i, a, p, e, (int)f );
                if(i<roll)
                {
                    printf("\n");
                }
                a1 += a;
                p1 += p;
                e1 += e;
                f1 += f;
            }
            else if(i<100)
            {
                f=(double)a/10+((double)p/10)*3+((double)e/10)*6;
                printf("000%d%13d%11d%7d%14d", i, a, p, e, (int)f );
                if(i<roll)
                {
                    printf("\n");
                }
                a1 += a;
                p1 += p;
                e1 += e;
                f1 += f;
            }
            else
            {
                f=(double)a/10+((double)p/10)*3+((double)e/10)*6;
                printf("00100%13d%11d%7d%14d", a, p, e, (int)f );
                if(i<roll)
                {
                    printf("\n");
                }
                a1 += a;
                p1 += p;
                e1 += e;
                f1 += f;
            }
        }
        a1 = (double)a1/roll;
        p1 = (double)p1/roll;
        e1 = (double)e1/roll;
        f1 = (double)f1/roll;
        printf("\n");

        printf("==================================================\n");
        printf("Mean%14d%11d%7d%14d\n", a1, p1, e1, f1);
        printf("==================================================\n");
        flag += 1;

    }
    return 0;
}
