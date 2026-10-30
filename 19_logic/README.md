# logic

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：邏輯推理
- **狀態**：尚未作答(僅收錄題目)

## 題目

Logical expressions are important in decision making. A common form of logical expressions is represented by clauses and logical operators: 𝑐 ∙ 𝑐 ∙ … 𝑐 ∙ 𝑐 , 1 1 2 2 𝑛−1 𝑛−1 𝑛 where 𝑐 is the i-th clause and ∙ is the i-th logical operator. A clause can be expressed as a comparison: 𝑖 𝑖 𝑐 = ¬ 𝑢 ° 𝑣 , 𝑖 where 𝑢 and 𝑣 are two variables, ° is relational operators (>, =, <), and ¬ is the optional negation operators. Write a program to determine the partial result of each clause and the final result of a logical expression.

**Input**

The input contains several cases and end with EOF. Each case consist of two lines. The first line is five integer values for variables 𝑎, 𝑏, 𝑐, 𝑑, and 𝑒. The second line is a logical expression which associates from left to right as aforementioned.

**Output**

For each case, output the partial result of each clause and the connecting logical operators in turn, and output the final result of the whole expression. The result of each case should be in a separate line.

**Sample Input**

```
2 5 8 6 2
(a > e) & (b = c) | -(e > b) & -(a = d) | -(d > e) | -(c > a)
```

**Sample Output**

```
False && False || True && True || False || False = True
```

