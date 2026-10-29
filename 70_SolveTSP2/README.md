# SolveTSP2

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 最佳化
- **狀態：** 尚未作答（僅收錄題目）

## 題目

Traveling Salesman Problem (TSP) is an important problem in computer science. The TSP aims at finding a route passed all cities exactly once with minimum traveling distance. There are two representations for TSP problems: using the coordinates of all cities or using the distance (cost) matrix for the distance between all pairs of the cities. To solve a TSP problem, we can first express a route by a permutation, which defines the traversal order of the cities. For optimizing a given permutation, we can inverse a sub-route between any two cities to see if the route distance is reduced. A simple strategy is given as follows:

1. Find the two cities 𝑖, 𝑗 which can minimize the route distance over all pairs of two cities.
2. If the route distance becomes shorter after inversing the sub-route between 𝑖, 𝑗 then inverse them. Go to step 1.

Your goal is to write a program to solve a TSP problem defined by the coordinates of all cities and an initial permutation using above strategy. You have to provide suitable class definition and implementation for the following classes: Class TravelingSalesmanProblem

1. Private data members for expressing a TSP problem.
2. A copy constructor, destructor, and assignment operator for the dynamically allocated memory.
3. Overloading parentheses operator with two arguments of size_t as the index of two cities to get the cost between the two cities.
4. Overloading stream insertion and extraction operators (cf. sample input and output).
5. Proper accessor, mutation and utility functions.

Class Permutation

1. Two private data members include the length and the numbers without any limitation on the length.
2. Overloading stream insertion and extraction operators (cf. sample input and output).
3. A copy constructor, destructor, and assignment operator for the dynamically allocated memory.
4. Proper accessors, mutators and utility functions.
5. Overloading bracket operator to access the permutation.

Class SolveTSP

1. Three private data members include a route distance, a TSP problem, and a permutation.
2. Overloading stream insertion and extraction operators (cf. sample input and output).
3. Proper accessors, mutators and utility functions.
4. A member function solve to optimize the given TSP problem with the initial permutation.
5. Applicable to the sample main file.

**Input**

Each case contains an integer n, representing the number of cities, and 3n integers follow. The first 2n integers denote the coordinates of the n cities, and the last n integers is the permutation. The input ends with n = 0.

**Output**

For each case, output the distance matrix, where the element m at ith row and jth column is the Manhattan distance i,j between ith city and jth city according to the input order. For each distance value, please set the field width to 4. Any two adjacent columns are separated by a space, and any two adjacent rows are separated by an end line stream manipulator. Also output the route and route distance before and after optimization. Two consecutive cases are also separated by an end line stream manipulator.

**Sample Input**

```
5
-1 2
3 1
4 3
5 -4
-5 0
3 0 4 1 2
0
```

**Sample Output**

```
Route before optimization: 3 0 4 1 2 = 38
Route after optimization : 3 4 0 1 2 = 36
Cost matrix:
    0    5    6   12    6
    5    0    3    7    9
    6    3    0    8   12
   12    7    8    0   14
    6    9   12   14    0
Current route: 3 4 0 1 2 = 36
```

