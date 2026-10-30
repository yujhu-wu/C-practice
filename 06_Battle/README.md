# Battle

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：條件判斷
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

Card game is a famous type of board game in past decades. As time goes by, we can now play lots of different card games on computers. A well-known and ancient card game is Magic: The Gathering (MTG). In MTG, cards are of different types, including creature, artifact, enchantment, instant, … etc. A special type of cards is creature, which has power and life. If the power of attacking creature is greater than the defending creature, the surplus power can damage the player’s life, which is 20 at the beginning of a game. Now consider we want to build a platform on computer to compute the result of a battle. Your goal is to write a program to help such calculation.

**Input**

The input begins with an integer 𝑛 indicating the number of cases, followed by 𝑛 lines, each of which denotes the attacking creature’s power and defending creature’s life.

**Output**

For each case, output the difference mentioned above. Each output should be in separate line.

**Sample Input**

```
3
1 3
6 2
3 3
```

**Sample Output**

```
Defending creature survived. No damage caused.
Defending creature vanished. Attacker caused 4 damages to opponent player.
Defending creature vanished. No damage caused.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a, b;

    scanf("%d", &n);

    n = 1;
    while(scanf("%d %d", &a, &b)!=EOF){
        if(a<b){
            printf("Defending creature survived. No damage caused.\n");
        }
        else if(a>b, a-b>1){
            printf("Defending creature vanished. Attacker caused %d damages to opponent player.\n", a - b);
        }
        else if(a>b, a-b==1){
            printf("Defending creature vanished. Attacker caused %d damage to opponent player.\n", a - b);
        }
        else if(a==b){
            printf("Defending creature vanished. No damage caused.\n");
        }
        n++;
    }

    return 0;
}
```

