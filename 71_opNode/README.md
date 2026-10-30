# opNode

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：類別 / 運算式
- **狀態**：尚未作答(僅收錄題目)

## 題目

Expression tree (ET) can be used to express formula. In an ET, the internal nodes are usually composed of unary and binary operators. To accomplish different types of operators, one way is to use the switch logic. However, the switch logic may make the code hard to maintain and to debug. This can be overcome by one of the fascinating features in C++: the polymorphism. Your goal is to write a program handling different operators using dynamic binding. You have to provide a general node class OpNode, and several specific node classes, including AddNode for addition, SubNode for subtraction, MulNode for multiplication, DivNode for division, ModNode for modulo, AndNode for logical and, OrNode for logical Or, NotNode for negation, and NegNode for negative sign. These classes must contain the following capabilities:

1. Two private data members for operands.
2. Appropriate constructors and destructors.
3. Appropriate accessors, mutators, and utility function.
4. Input member function for input operands.
5. Output member function for output result.
6. Applicable to sample main file.

**Input**

The input contains 1000 cases. The first 1000 numbers denote the types of the operators. Specifically, 0 ~ 8 represent addition, subtraction, multiplication, division, modulo, logical and, logical or, negation, and negative sign, respectively. The numbers going after the first 1000 numbers are the operands for the operators.

**Output**

For each case, output the results according to the types of operators, and the contents of operands.

**Sample Input**

```
0 1 2 3 4 5 6 7 8
1 2
3 4
6 5
7 2
8 3
0 0
1 0
5
6
```

**Sample Output**

```
1 + 2 = 3
3 - 4 = -1
6 * 5 = 30
7 / 2 = 3
8 % 3 = 2
0 && 0 = 0
1 || 0 = 1
!5 = 0
-6 = -6
```

