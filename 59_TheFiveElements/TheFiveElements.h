#include <iostream>
#ifndef TheFiveElements_H
#define TheFiveElements_H
class TheFiveElements
{
    friend std::ostream &operator << (std::ostream &, const TheFiveElements &);
    friend std::istream &operator >> (std::istream &,TheFiveElements &);
    friend bool operator> (const TheFiveElements &, const TheFiveElements &);
    friend bool operator< (const TheFiveElements &, const TheFiveElements &);
    public:
    TheFiveElements (int = 0);
    TheFiveElements &operator++ ();
    TheFiveElements operator++ (int);
    TheFiveElements &operator-- ();
    TheFiveElements operator-- (int);
    static std::string getelelment ();
    private:
    int nown;
    void helpIncrement();
    void helpDecrement();
};
#endif
