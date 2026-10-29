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
