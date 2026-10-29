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
