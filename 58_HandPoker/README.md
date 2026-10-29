# HandPoker

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 類別 / 組合
- **語言：** C++
- **程式碼：** [main.cpp](main.cpp)、[HandCards.cpp](HandCards.cpp)、[HandCards.h](HandCards.h)

## 題目

Poker is any of a number of card games in which players wager over which hand is best according to that specific game‘s rules in ways similar to these rankings. The ranking depends on the pattern of hands. A common ranking hierarchy is defined as: High Card < Pair < Two Pairs < Three of a Kind < Straight < Flush < Full House < Four of a Kind < Straight Flush < Royal Flush The patterns bases on five cards. Followings are their definitions: High Card: Five different cards Pair: Two cards with the same face value. Two pairs: Two pairs with different face value Three of a Kind: Three cards with the same face value Straight: Cards with five contiguous face values, including Ten Jack Queen King Ace Flush: Five cards with the same suit color. Full House: Three of a Kind with a Pair Four of a Kind: Four cards with the same face value Straight Flush: A straight with flush Royal Flush: A Straight Flush ends with Ace (Ten Jack Queen King Ace). Any hands which satisfy the requirement of the pattern in the highest hierarchy are regarded as being of that pattern. Your goal is to write a program to determine the patterns of a combination of five cards. In your program, you have to provide a class HandPoker with the following capabilities:

1. A constructor with one argument of array of unsigned integers.
2. A data member of five cards.
3. A static data member representing the possible pattern names.
4. Several utility functions to sort the cards and determine the pattern.
5. A member function to show the hands.
6. Separation of class interface and implementation.
7. Must be applicable to the sample main file.

**Input**

The input contains several cases and ends with EOF. Each case in a single line contains five integers, which represent the indices of the five cards. The thirteen face values are encoded as 0 for Ace, 1 for Two, 2 for Three, …, 10 for Jack, 11 for Queen, and 12 for King. The four suit colors are encoded as 0 for Spades, 1 for Hearts, 2 for Diamonds, and 3 for Clubs. Each card is indexed by first ascending the face value, and then ascending the suit color.

**Output**

For each case, output the string representing the five cards with the format: F of S , F of S , F of S , F of S , and F of S are P 1 1 2 2 3 3 4 4 5 5 , where F and S are the face value and suit color of the ith smallest card in hands, and P is the corresponding pattern. i i

**Sample Input**

```
0 15 30 45 8
0 13 41 3 24
2 16 24 28 50
2 24 47 28 15
10 13 22 24 38
29 26 30 36 38
2 24 28 11 41
10 49 37 36 23
17 21 19 20 18
36 35 26 38 37
```

**Sample Output**

```
Three of Hearts, Five of Diamonds, Seven of Clubs, Nine of Spades, and Ace of Spades are High Card.
Three of Clubs, Four of Spades, Queen of Hearts, Ace of Hearts, and Ace of Spades are Pair.
Three of Diamonds, Three of Spades, Four of Hearts, Queen of Clubs, and Queen of Hearts are Two Pairs.
Three of Diamonds, Three of Hearts, Three of Spades, Nine of Clubs, and Queen of Hearts are Three of a Kind.
Ten of Hearts, Jack of Spades, Queen of Hearts, King of Diamonds, and Ace of Hearts are Straight.
Four of Diamonds, Five of Diamonds, Jack of Diamonds, King of Diamonds, and Ace of Diamonds are Flush.
Three of Clubs, Three of Diamonds, Three of Spades, Queen of Hearts, and Queen of Spades are Full House.
Jack of Clubs, Jack of Diamonds, Jack of Hearts, Jack of Spades, and Queen of Diamonds are Four of a Kind.
Five of Hearts, Six of Hearts, Seven of Hearts, Eight of Hearts, and Nine of Hearts are Straight Flush.
Ten of Diamonds, Jack of Diamonds, Queen of Diamonds, King of Diamonds, and Ace of Diamonds are Royal Flush.
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "HandCards.h"
#include "HandCards.h"

using namespace std;

void input(unsigned int intArray[5]);

int main()
{
    unsigned int value[5] = {0};

    input(value);
    while ( cin.good() )
    {
        const HandCards hand(value);
        hand.show();
        input(value);
    }

    return 0;
}

void input(unsigned int intArray[5])
{
    for ( size_t i = 0; i < 5; ++i )
    {
        cin >> intArray[i];
    }
}
```

### HandCards.cpp

```cpp
#include <iostream>
#include <stdexcept>
#include "HandCards.h"
using namespace std;

HandCards::HandCards ( unsigned int x[5])
{
    for ( int i = 0; i < 5; ++ i ){
        in [i] = x[i];
    }
    setCard();
}
void HandCards::show() const
{
    string thef [14]  = { "", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
    string thes [5]  = { "",  "Clubs", "Diamonds","Hearts", "Spades" };
    string thesituation [10] = { "High Card", "Pair", "Two Pairs", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush" };
    cout << thef [ afterf [0] ] << " of " << thes [ afters [0] ] << ", " << thef [ afterf [1] ] << " of " << thes [ afters [1] ] << ", "<< thef [ afterf [2] ] << " of " << thes [ afters [2] ] << ", "
        << thef [ afterf [3] ] << " of " << thes [ afters [3] ] << ", and " << thef [ afterf [4] ] << " of " << thes [ afters [4] ] << " are " << thesituation [situation] << "." << endl;
}
void HandCards::setCard()
{
    for ( int a=0; a<5; ++a ){
        afters [a] = in [a] / 13;
        afterf [a] = in [a] % 13;
        if ( afterf [a] == 0 ){
            afterf [a] = 13;
        }
        if ( afters [a] == 0 ){
            afters [a] = 4;
        }
        else if ( afters [a] == 1 ){
            afters [a] = 3;
        }
        else if ( afters [a] == 3 ){
            afters [a] = 1;
        }
    }
    for ( size_t b=0; b< 5 - 1 ; ++b ){
        for ( size_t c=0; c< 5 - 1 ; ++c ){

            if ( afterf [c] > afterf [ c+1 ]  ){
                    unsigned int hold = afterf [c];
                    afterf [c] = afterf [c+1];
                    afterf [ c+1 ] = hold;
                    hold = afters [c];
                    afters [c] = afters [c+1];
                    afters [c+1] = hold;
            }
            else if ( afterf [c] == afterf [c+1] )
            {
                if ( afters [c] > afters [c+1] )
                {
                    unsigned int hold = afterf [c];
                    afterf [c] = afterf [c+1];
                    afterf [c+1] = hold;
                    hold = afters [c];
                    afters [c] = afters [c+1];
                    afters [c+1] = hold;
                }
            }
        }
    }
    change();
}
void HandCards::change ()
{
    situation = 0;
    int thevalue, thevalue2 = 60;
    int amount = 0, amount2 = 0;
    thevalue = afterf [0];
    for ( int d= 1; d < 5 ; ++d){
        if ( afterf [d] == thevalue ){
            amount += 1;
        }
        else if ( afterf [d] == thevalue2 ){
            amount2 += 1;
        }
        else if ( amount > 0 ){
            if ( afterf [d] == thevalue2 ){
                amount2 += 1;
            }
            else{
                thevalue2 = afterf [d];
            }
        }
        else{
            thevalue = afterf [d];
        }
    }
    if ( amount==1 || amount2==1){
        if ( amount==1 && amount2==1 ){
            situation=2;
        }
        else if (amount==1){
            if (amount2==3){
                situation=6;
            }
            else{
                situation=1;
            }
        }
        else if (amount2==1){
            if (amount==2){
                situation=6;
            }
            else{
                situation=1;
            }
        }
    }
    else if (amount==2 || amount2==2){
        situation=3;
    }
    else if (amount==3 || amount2==3 ){
        situation=7;
    }
    int flu = 0, straight = 0;
    for ( int e= 0; e< 5 - 1; ++e ){
        if ( afterf[e]==(afterf [e+1]-1) ){
            straight += 1;
        }
    }
    for ( int f= 0; f< 5 - 1; ++f){
        if ( afters[f]==(afters [f+ 1]) ){
            flu += 1;
        }
    }
    if (straight==4 || flu==4 ){
        if (straight==4 && flu==4 ){
            if (afterf [4]==13){
                situation=9;
            }
            else{
                situation=8;
            }
        }
        else if(straight==4){
            situation=4;
        }
        else if (flu==4){
            situation=5;
        }
    }
}
```

### HandCards.h

```cpp
#ifndef PokerCard_H
#define PokerCard_H

class HandCards
{
    public:
    explicit HandCards (unsigned int in [5]);
    void show() const ;
    void setCard();
    void change ();
    private:
    unsigned int in [5];
    int situation = 0;
    int afterf [5];
    int afters [5];
};
#endif
```

