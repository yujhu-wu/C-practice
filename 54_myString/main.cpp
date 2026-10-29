#include <iostream>
#include <string>
#include "myString.h"

using namespace std;

int main()
{
    string input("");
    MyString mystring(input);

    while ( getline(cin, input).good() )
    {
        mystring.set_string(input);
        cout << "\"" << mystring.get_string() << "\"" << " gets " << mystring.compact_sum() << "." << endl;
    }

    return 0;
}
