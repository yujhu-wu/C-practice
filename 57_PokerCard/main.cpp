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
