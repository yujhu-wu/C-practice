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
