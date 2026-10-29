# ComplexNumber

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 運算子多載
- **狀態：** 尚未作答（僅收錄題目）

## 題目

Complex numbers are a set of numbers which can be expressed as a+bi, where a is known as real part, b is known as imaginary part, and both of a and b are real numbers. To improve the efficiency of calculation, the real numbers can be exchanged as rational numbers, and the complex number can be referred to as complex rational number. Four basic operations on complex numbers are addition, subtraction, multiplication, and division. It is quite easy and common for human to perform these operations on complex numbers. For computers, it is not straightforward to represent complex numbers as well as to perform the four operations on them. In fact, complex number is not a built-in type of C++. Nevertheless, you can build your own class with overloaded operators for complex numbers. Your goal is to write a program to deal with the operations of complex numbers through a user-defined class ComplexNumber with the following capabilities:

1. Two private data members for a and b as two objects of rational numbers.
2. A constructor with two arguments for a and b with default values a = 0, and b = 0.
3. Overloaded stream extraction operator for inputting a complex number.
4. Overloaded stream insertion operator for outputting a complex number.
5. Overloaded addition (+), subtraction (-), multiplication (*), and division (/) operators.
6. Applicable to the sample main file.

**Input**

Each case contains eight integers, representing the four rational numbers 𝑎 , 𝑏 , 𝑎 , and 𝑏 , respectively. 1 1 2 2

**Output**

For each case, output the results of 𝑐 {+,-,*,/} 𝑐 . 1 2

**Sample Input**

```
1 2 -3 -4
5 -6 -7 8
```

**Sample Output**

```
(1/2 + 3/4i) + (-5/6 - 7/8i) = -1/3 - 1/8i
(1/2 + 3/4i) - (-5/6 - 7/8i) = 4/3 + 13/8i
(1/2 + 3/4i) * (-5/6 - 7/8i) = 23/96 - 17/16i
(1/2 + 3/4i) / (-5/6 - 7/8i) = -618/841 - 108/841i
```

