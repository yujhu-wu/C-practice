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
