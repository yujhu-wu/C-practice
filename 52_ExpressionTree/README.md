# ExpressionTree

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：運算式樹
- **狀態**：尚未作答(僅收錄題目)

## 題目

There are plenty of applications depending on the use of tree structure. One famous application is to use tree to represent expression (formula) known as expression tree. An expression is composed of operators as internal nodes and operands as leaf nodes. To establish an expression tree from an expression, a common method starts from its prefix. For example, the following prefix expression + +-*abba can be expressed as: - a (((a * b) – b) + a) Note that we add a pair of parentheses for each operator to prevent from the influence of * b operator precedence. a b The corresponding expression tree is given in the right figure. The tree construction can be done recursively in the preorder manner. For instance, we first create the root as ‘+’ and recursively call the tree construction process with the left child of the root as arguments, and so on. After the left subtree is established, the recursion starts from the right child of the root. Note that an operand has no children. From the expression tree, it is quite simple to get the above expression by an inorder traversal. The expression can also be used to help the calculation of the corresponding expression. This can be done by a postorder traversal and can also be implemented in a recursive manner. Write a program to establish an expression through a prefix expression, show the expressions through a inorder traversal, and calculate the result of the expression through a postorder traversal. Requirement: Write a tree node data structure with corresponding functions for constructing a tree from prefix expression, expressing the tree, and calculating the result of the tree.

**Input**

The input contains several cases and ends with EOF. Each case in a line is a prefix expression, composed of variables (1~9) and operators (+, -, *, /).

**Output**

For each case, output the corresponding expression with proper parentheses and the result under the format: Expression = Result, where Expression is an infix expression with a pair of parentheses for each operator outside the two operands, and Result is a number. Two consecutive cases should be separated by a newline character.

**Sample Input**

```
/5+13
-//*1718+6**52*74
+/++78-5372
*51
```

**Sample Output**

```
(5 / (1 + 3)) = 1
((((1 * 7) / 1) / 8) - (6 + ((5 * 2) * (7 * 4)))) = -286
((((7 + 8) + (5 - 3)) / 7) + 2) = 4
(5 * 1) = 5
```

