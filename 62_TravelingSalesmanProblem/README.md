# TravelingSalesmanProblem

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 類別
- **狀態：** 尚未作答（僅收錄題目）

## 題目

Traveling Salesman Problem (TSP) is an important problem in computer science. The TSP aims at finding a route passed all cities exactly once with minimum traveling distance. There are two representations for TSP problems: using the coordinates of all cities or using the distance matrix for the distance between all pairs of the cities. Your goal is to write a program with a classes City with the following capabilities:

1. Two private data members as the x and y coordinates of a city.
2. A default constructor.
3. Overloading stream insertion and extraction operators.
4. Proper accessor and mutator functions.
5. Applicable to the sample main file. and a class TravelingSalesmanProblem with the following capabilities:
1. Three private data members include the number of cities as an unsigned integer, the cities as a pointer of city (City*), the cost between each pair of cities as an double pointer of unsigned integer

(unsigned int**)

2. A default constructor to initialize the members to zero or null pointer
3. A constructor with two arguments as cities (City*) and the number of cities (unsigned int).
4. A copy constructor, destructor, and assignment operator for the dynamically allocated memory.
5. Overloading parentheses with two arguments of size_t as the index of the two cities to get the cost between the two cities.
6. Overloading bracket operator with one argument of size_t as the city index to get the corresponding city
7. Overloading stream insertion and extraction operators (cf. sample input and output).
8. Proper accessor, mutation and utility functions.
9. A member function badAlloc to check the validity of the three members.
10. Applicable to the sample main file.

**Input**

Each case contains an integer n, representing the number of cities, and 2n integers, denoting the coordinates of the n cities. The input ends with n = 0.

**Output**

For each case, output the distance matrix, where the element m at ith row and jth column is the Manhattan i,j distance between ith city and jth city according to the input order. For each distance value, please truncate it to an integer and set the field width to 4. Any two adjacent columns are separated by a space, and any two adjacent rows are separated by an end line stream manipulator. Two consecutive cases are also separated by an end line stream manipulator.

**Sample Input**

```
5
-1 2
3 1
4 3
5 -4
-5 0

0
```

**Sample Output**

```
   0      5      6   12      6
   5      0      3      7      9
   6      3      0      8   12
12      7      8      0   14
   6      9   12   14       0
```

