# PokerCard

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 類別
- **語言：** C++
- **程式碼：** [main.cpp](main.cpp)、[PokerCard.cpp](PokerCard.cpp)、[PokerCard.h](PokerCard.h)

## 題目

C++ provides the possibility of creating any class we need. A simple example is to represent the card in a deck by a class PokerCard with two members face and suit, where the face is an integer value between 0 to 12 (standing for Ace, Two, Three, …, Ten, Jack, Queen, and King), and suit is also an integer value between 0 to 3 (denoting Spades, Hearts, Diamonds, and Clubs). Alternatively, we can represent the value of face and suit by an integer of 0 to 51 as Ace of Spaces to King of Clubs. To show the card, the class must provide a show() method to translate the integer values to a meaningful string. Your goal is to write a program translate each pair of two integer values to a string representing the card’s face value and suit color. Note that you need to use static arrays of strings to store the possible face values and suit colors for encapsulation and saving memory. The declaration of a static member is to add the keyword static before the data type of a class member. To prevent the invalid input, please throw an exception when the face value or suit color of a card is invalid. If the face value is invalid, throw an exception of invalid argument with “Invalid face value”. If the suit value us invalid, throw an exception of invalid argument with “Invalid suit color”. Check the face value first then the suit value. Your goal is to write a class PokerCard as mentioned above with the following capabilities:

1. A constructor with a single argument.
2. A constructor with two arguments as face and suit.
3. Mutators for the private data members with the ability of cascaded function calls.
4. A member function show to present the card.
5. Static arrays of strings as data members to store the possible face values and suit colors.
6. Separation of class interface and implementation.
7. Must be applicable to the sample main file.

**Input**

Each line is an input case starting with a number n indicating the number of input values follow, and the input ends with n = 0.

**Output**

For each case, output the string representing the card with the format: F of S, where F and S are the face value and suit color of the card, respectively.

**Sample Input**

```
2 6 5
1 29
1 18
1 22
1 5
2 13 1
0
```

**Sample Output**

```
Invalid suit color
Four of Diamonds
Six of Hearts
Ten of Hearts
Six of Spades
Invalid face value
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "PokerCard.h"
#include "PokerCard.h"

using namespace std;

int main()
{
    PokerCard pokerCard; //default constructor: set face value and suit color to zero
    pokerCard.show(); // Ace of Spades
    pokerCard.setFace(12).setSuit(1).show(); // King of Hearts

    const PokerCard pokerCard2(13); // constructor with one argument
    pokerCard2.show(); // Ace of Hearts

    const PokerCard pokerCard3(2,3); // constructor with two arguments of face value and suit color
    pokerCard3.show(); // Three of Clubs

    cout << endl;

    int n, number, face, suit;

    cin >> n;
    while ( n > 0 )
    {
        if ( n == 1 )
        {
            cin >> number;
            try
            {
                pokerCard.setCard(number).show();
            }
            catch(invalid_argument& e)
            {
                cout << e.what() << endl;
            }
        }
        else
        {
            cin >> face >> suit;
            try
            {
                pokerCard.setFace(face).setSuit(suit).show();
            }
            catch(invalid_argument& e)
            {
                cout << e.what() << endl;
            }
        }

        cin >> n;
    }

    return 0;
}
```

### PokerCard.cpp

```cpp
#include <iostream>
#include <stdexcept>
#include "PokerCard.h"

using namespace std;

PokerCard::PokerCard (int n){
    setCard(n);
}
PokerCard::PokerCard (unsigned int x, unsigned int y){
    setFace(x).setSuit(y);
}





void PokerCard::show() const{
    cout << face2 << " of " << suit2 << endl;
}

PokerCard &PokerCard::setFace(int a)
{

    string thef [13]  = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    if ( a <= 12 ){
        theo1 = a;
        face2 = thef [a];
    }
    else{
        throw invalid_argument ("Invalid face value");
    }
    return *this;
}

PokerCard &PokerCard::setSuit(int b)
{
    string thes [4]  = {"Spades", "Hearts", "Diamonds", "Clubs"};
    if ( b <= 3 ){
        theo2 = b;
        suit2 = thes [b];
    }
    else{
        throw invalid_argument ("Invalid suit color");
    }
    return *this;
}

PokerCard &PokerCard::setCard(int c)
{
    string thef [13]  = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string thes [4]  = {"Spades", "Hearts", "Diamonds", "Clubs"};

    theorder = c;
    int l = theorder / 13;
    int l2 = theorder % 13;
    setFace(l2).setSuit(l);
    return *this;
}

string PokerCard::getface () const{
    return face2;
}
string PokerCard::getsuit () const{
    return suit2;
}
```

### PokerCard.h

```cpp
#include <iostream>
#ifndef PokerCard_H
#define PokerCard_H

class PokerCard
{
    public:
    PokerCard (int);
    PokerCard (unsigned int = 0, unsigned int = 0 );

    void show() const;
    PokerCard &setFace(int );
    PokerCard &setSuit(int );
    PokerCard &setCard(int );
    std::string getface () const;
    std::string getsuit () const;
    private:
    int theorder;
    int theo1, theo2;
    std::string face2, suit2;
    static const std::string  thef [13] ;
    static const  std ::string thes [4];
};
#endif
```

