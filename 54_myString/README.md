# myString

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：類別
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[myString.h](myString.h)

## 題目

Class is a fundamental programming unit in C++. The data members and member function provide good example of information hiding. With appropriate constructor, the declaration and initialization of objects are very easy to handle. Your goal is to provide a class with five class members, including

1. a constructor with one argument of type string,
2. a private data member of type string,
3. a public member function for setting the private data member,
4. a public member function for getting the private data member, and
5. a public member function for calculating the compaction sum of the private data member.

The constructor uses the string parameter to initialize the class data member. The compaction sum is defined as follows: First sum all the characters, where ‘a’ or ‘A’ equals to 1, ‘b’ or ‘B’ equals to 2, …, and ‘z’ or ‘Z’ equals to 26. While the value of sum is greater than or equal to ten, replace the sum by the summation of sum’s all digits. Requirement: Your class should be applicable to the given main file.

**Input**

The input contains several lines (cases) and ends with EOF.

**Output**

For each line of input 𝑠, output in the following format: “”𝑠“ gets 𝑑.”, where 𝑑 is the compaction sum of 𝑠. Each output is ended by an end line stream manipulator.

**Sample Input**

```
A
AB
abc
abcd
ABCDef
```

**Sample Output**

```
"A" gets 1.
"AB" gets 3.
"abc" gets 6.
"abcd" gets 1.
"ABCDef" gets 3.
```

## 程式碼

### main.cpp

```cpp
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
```

### myString.h

```cpp
#include <iostream>
#include <string>

class MyString
{
public:
    explicit MyString ( std::string input )
        : s ( input )
    {

    }

    void set_string ( std::string input )
    {
        s = input;
    }
    std::string get_string ()
    {
        return s;
    }
    int compact_sum()
    {
        int sum;
        for ( int i = 0; i < s.length(); ++i )
        {
            if ( s [ i ] >= 'a' )
            {
                sum += s [ i ] - 'a' + 1;
            }
            else
            {
                sum += s [ i ] - 'A' + 1;
            }
        }
        while ( sum >= 10 )
        {
            int p1, p2, p3, p4;
            int sum2 = sum;
            if ( sum >= 1000 )
            {
                p1 = sum2 / 1000;
                sum2 -= p1 * 1000;
                p2 = sum2 / 100;
                sum2 -= p2 * 100;
                p3 = sum2 / 10;
                sum2 -= p3 * 10;
                p4 = sum2;
                sum2 -= p4;
                sum = p1 + p2 + p3 + p4;
                sum2 = sum;
            }
            if ( sum >= 100 && sum < 1000)
            {
                p1 = sum2 / 100;
                sum2 -= p1 * 100;
                p2 = sum2 / 10;
                sum2 -= p2 * 10;
                p3 = sum2;
                sum2 -= p3;
                sum = p1 + p2 + p3;
                sum2 = sum;
            }
            if ( sum >= 10 && sum < 100 )
            {
                p1 = sum2 / 10;
                sum2 -= p1 * 10;
                p2 = sum2;
                sum2 -= p2;
                sum = p1 + p2;
                sum2 = sum;
            }
        }
        return sum;
    }
private:
    std::string s;
};
```

