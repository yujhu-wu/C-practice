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
