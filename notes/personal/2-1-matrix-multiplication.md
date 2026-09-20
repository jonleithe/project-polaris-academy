---
title       : Matrix Multiplication
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-08-16
---

::: {.hidden}
$$
\def\maroonD#1{{\color{maroon}#1}}
\def\greenD#1{{\color{green}#1}}
\def\redD#1{{\color{red}#1}}
\def\goldD#1{{\color{orange}#1}}
$$
:::

Matrices are multiplied by multiplying corresponding elements from the row of the first matrix by the elements from the column of the second matrix, adding the products together.

Suppose we have the matrices:

$$
A (\maroonD{m} \times \greenD{n}) =
\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\greenD{a_{31}} & \greenD{a_{32}} & \greenD{\cdots} & \greenD{a_{3n}} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn}
\end{bmatrix}
,\qquad
B (\greenD{n} \times \goldD{p}) =
\begin{bmatrix}
b_{11} & \greenD{b_{12}} & \cdots & b_{1p} \\
b_{21} & \greenD{b_{22}} & \cdots & b_{2p} \\
b_{31} & \greenD{b_{32}} & \cdots & b_{3p} \\
\vdots & \greenD{\vdots} & \ddots & \vdots \\
b_{n1} & \greenD{b_{n2}} & \cdots & b_{np}
\end{bmatrix}
$$

Leaning on the example matrices, let's multiply row 3 from A by column 2 from B:

$$
\greenD{a_{31}} \cdot \greenD{b_{12}}
+
\cdots
+
\greenD{a_{3n}} \cdot \greenD{b_{n2}}
$$

Matrix multiplication is only defined when the number of columns in $A$ equals
the number of rows in $B$. Using the convention that $A$ is an
$\maroonD{m} \times \greenD{n}$ matrix and $B$ is an
$\greenD{n} \times \goldD{p}$ matrix, the $\greenD{n}$'s have to match. The
resulting matrix has dimensions $\maroonD{m} \times \goldD{p}$.

For a full size example, suppose we have:

$$
A =
\begin{bmatrix}
1 & 2 \\
3 & 4 \\
5 & 6
\end{bmatrix}
,\qquad
B =
\begin{bmatrix}
a & b & c \\
d & e & f
\end{bmatrix}
$$

their resulting product matrix will be:

$$
AB =
\begin{bmatrix}
1a+2d & 1b+2e & 1c+2f \\
3a+4d & 3b+4e & 3c+4f \\
5a+6d & 5b+6e & 5c+6f
\end{bmatrix}
$$

<!-- pagebreak -->

## Column view

The product can also be understood one column at a time. Consider the same matrices, with the columns of $A$ distinguished by colour:

$$
A =
\begin{bmatrix}
\greenD{1} & \redD{2} \\
\greenD{3} & \redD{4} \\
\greenD{5} & \redD{6}
\end{bmatrix}
,\qquad
B =
\begin{bmatrix}
a & c & e \\
b & d & f
\end{bmatrix}
$$

Each column of $AB$ is a linear combination of the columns of $A$. The
coefficients come from the corresponding column of $B$:

$$
\begin{aligned}
\vec{c}_1
&=
A\begin{bmatrix}a \\ b\end{bmatrix}
=
\begin{bmatrix}
\greenD{1}a + \redD{2}b \\
\greenD{3}a + \redD{4}b \\
\greenD{5}a + \redD{6}b
\end{bmatrix}
\\[1em]
\vec{c}_2
&=
A\begin{bmatrix}c \\ d\end{bmatrix}
=
\begin{bmatrix}
\greenD{1}c + \redD{2}d \\
\greenD{3}c + \redD{4}d \\
\greenD{5}c + \redD{6}d
\end{bmatrix}
\\[1em]
\vec{c}_3
&=
A\begin{bmatrix}e \\ f\end{bmatrix}
=
\begin{bmatrix}
\greenD{1}e + \redD{2}f \\
\greenD{3}e + \redD{4}f \\
\greenD{5}e + \redD{6}f
\end{bmatrix}
\end{aligned}
$$

The three resulting column vectors form the product matrix:

$$
AB =
\begin{bmatrix}
\vert & \vert & \vert \\
\vec{c}_1 & \vec{c}_2 & \vec{c}_3 \\
\vert & \vert & \vert
\end{bmatrix}
=
\begin{bmatrix}
\greenD{1}a + \redD{2}b & \greenD{1}c + \redD{2}d & \greenD{1}e + \redD{2}f \\
\greenD{3}a + \redD{4}b & \greenD{3}c + \redD{4}d & \greenD{3}e + \redD{4}f \\
\greenD{5}a + \redD{6}b & \greenD{5}c + \redD{6}d & \greenD{5}e + \redD{6}f
\end{bmatrix}
$$

<!-- pagebreak -->

## Row view

We can shift the focus by $90^\circ$ and understand the product one row at a time. Consider the same matrices, now with the rows of $A$ distinguished by
colour:

$$
A =
\begin{bmatrix}
\goldD{1} & \goldD{2} \\
\redD{3} & \redD{4} \\
\greenD{5} & \greenD{6}
\end{bmatrix}
,\qquad
B =
\begin{bmatrix}
a & c & e \\
b & d & f
\end{bmatrix}
$$

Each row of $C=AB$ is a linear combination of the rows of $B$. The
coefficients come from the corresponding row of $A$:

$$
\begin{aligned}
\mathbf{r}_1(C)
&=
\begin{bmatrix}1 & 2\end{bmatrix}B
=
\begin{bmatrix}
\goldD{1}a + \goldD{2}b &
\goldD{1}c + \goldD{2}d &
\goldD{1}e + \goldD{2}f
\end{bmatrix},
\\[1em]
\mathbf{r}_2(C)
&=
\begin{bmatrix}3 & 4\end{bmatrix}B
=
\begin{bmatrix}
\redD{3}a + \redD{4}b &
\redD{3}c + \redD{4}d &
\redD{3}e + \redD{4}f
\end{bmatrix},
\\[1em]
\mathbf{r}_3(C)
&=
\begin{bmatrix}5 & 6\end{bmatrix}B
=
\begin{bmatrix}
\greenD{5}a + \greenD{6}b &
\greenD{5}c + \greenD{6}d &
\greenD{5}e + \greenD{6}f
\end{bmatrix}.
\end{aligned}
$$

For example, the third row can be recognized directly as a linear combination
of the two rows of $B$:

$$
\mathbf{r}_3(C)
=
\greenD{5}\begin{bmatrix}a & c & e\end{bmatrix}
+
\greenD{6}\begin{bmatrix}b & d & f\end{bmatrix}.
$$

In general, if $A$ is an $m \times n$ matrix and $B$ is an $n \times p$
matrix, row $i$ of their product is

$$
\mathbf{r}_i(C)
=
a_{i1}\,\mathbf{r}_1(B)
+
a_{i2}\,\mathbf{r}_2(B)
+
\cdots
+
a_{in}\,\mathbf{r}_n(B),
\qquad C=AB.
$$

The same relationship can be written compactly using summation notation:

$$
\mathbf{r}_i(AB)
=
\sum_{k=1}^{n} a_{ik}\,\mathbf{r}_k(B).
$$

<!-- pagebreak -->

## Row $\times$ column vs. column $\times$ row

Multiplying a row by a column produces a single number. For example,

$$
\underbrace{\begin{bmatrix}a & b\end{bmatrix}}_{1 \times 2}
\underbrace{\begin{bmatrix}1 \\ 2\end{bmatrix}}_{2 \times 1}
=
\underbrace{\begin{bmatrix}a+2b\end{bmatrix}}_{1 \times 1}.
$$

The result is formally a $1 \times 1$ matrix, which we usually identify with
the scalar $a+2b$.

Reversing the order has a very different effect. A column multiplied by a row
produces a matrix:

$$
\underbrace{\begin{bmatrix}2 \\ 3 \\ 4\end{bmatrix}}_{3 \times 1}
\underbrace{\begin{bmatrix}1 & 7\end{bmatrix}}_{1 \times 2}
=
\underbrace{
\begin{bmatrix}
2 & 14 \\
3 & 21 \\
4 & 28
\end{bmatrix}
}_{3 \times 2}
$$

This can be understood using the row view. Each entry of the column scales the
entire row:

$$
\begin{aligned}
\mathbf{r}_1(C) &= 2\begin{bmatrix}1 & 7\end{bmatrix}
                 = \begin{bmatrix}2 & 14\end{bmatrix} \\
\mathbf{r}_2(C) &= 3\begin{bmatrix}1 & 7\end{bmatrix}
                 = \begin{bmatrix}3 & 21\end{bmatrix} \\
\mathbf{r}_3(C) &= 4\begin{bmatrix}1 & 7\end{bmatrix}
                 = \begin{bmatrix}4 & 28\end{bmatrix}
\end{aligned}
$$

Stacking these rows gives the $3 \times 2$ product matrix. Multiplication in
this order is commonly called an **outer product**.

<!-- pagebreak -->

## Outer-product view

The previous result gives another way to understand matrix multiplication:
$AB$ is the sum of the columns of $A$ multiplied by the corresponding rows of
$B$.

Consider

$$
A =
\begin{bmatrix}
1 & 7 \\
2 & 8 \\
3 & 9
\end{bmatrix}
\in \mathbb{R}^{3 \times 2},
\qquad
B =
\begin{bmatrix}
1 & 6 \\
2 & 7
\end{bmatrix}
\in \mathbb{R}^{2 \times 2}
$$

Pairing the first column of $A$ with the first row of $B$, and then the second
column of $A$ with the second row of $B$, gives

$$
\begin{aligned}
AB
&=
\begin{bmatrix}1 \\ 2 \\ 3\end{bmatrix}
\begin{bmatrix}1 & 6\end{bmatrix}
+
\begin{bmatrix}7 \\ 8 \\ 9\end{bmatrix}
\begin{bmatrix}2 & 7\end{bmatrix}
\\[1em]
&=
\begin{bmatrix}
1 & 6 \\
2 & 12 \\
3 & 18
\end{bmatrix}
+
\begin{bmatrix}
14 & 49 \\
16 & 56 \\
18 & 63
\end{bmatrix}
\\[1em]
&=
\begin{bmatrix}
15 & 55 \\
18 & 68 \\
21 & 81
\end{bmatrix}
\end{aligned}
$$

More generally, let $\mathbf{a}_k$ denote column $k$ of $A$ and let
$\mathbf{r}_k(B)$ denote row $k$ of $B$. If $A$ is an $m \times n$ matrix and
$B$ is an $n \times p$ matrix, then

$$
AB
=
\mathbf{a}_1\mathbf{r}_1(B)
+
\mathbf{a}_2\mathbf{r}_2(B)
+
\cdots
+
\mathbf{a}_n\mathbf{r}_n(B)
=
\sum_{k=1}^{n}\mathbf{a}_k\mathbf{r}_k(B)
$$

Each term $\mathbf{a}_k\mathbf{r}_k(B)$ is an $m \times p$ outer-product
matrix, and adding those matrices produces $AB$.
