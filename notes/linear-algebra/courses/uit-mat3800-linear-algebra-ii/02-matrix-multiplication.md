---
title       : Matrix Multiplication
subject     : Linear Algebra
course      : MAT3800 Linear Algebra II
unit        : 1
provider    : UiT Narvik
author      : Jon Leithe
date        : 2026-08-10
---

::: {.math-definitions style="position: absolute; width: 1px; height: 1px; overflow: hidden; clip-path: inset(50%);" aria-hidden="true"}
$$
\def\eqMatrixProduct{c_{ij}=\sum_{k=1}^{n}a_{ik}b_{kj}}
$$
:::

$$
\eqMatrixProduct
$$

Matrix multiplication combines the rows of one matrix with the columns of another. Each entry in the product is found by multiplying corresponding entries from a row of matrix $A$ and a column of matrix $B$, then adding the resulting products. If $A$ is an $m \times n$ matrix and $B$ is an $n \times p$ matrix, then the product $AB$ is defined and has dimensions $m \times p$. Therefore, the number of columns in $A$ must equal the number of rows in $B$.

Let $A$ be an $m \times n$ matrix and $B$ an $n \times p$ matrix.

The product $C=AB$ has entries

$$
c_{ij} = \sum_{k=1}^{n} a_{ik}b_{kj}.
$$

$$
A =
\begin{bmatrix}
a_{11} & a_{12} \\
a_{21} & a_{22}
\end{bmatrix}.
$$

$$
\begin{aligned}
c_{11} &= a_{11}b_{11} + a_{12}b_{21}, \\
c_{12} &= a_{11}b_{12} + a_{12}b_{22}.
\end{aligned}
$$

$$
\begin{aligned}
AB
&=
\begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}
\begin{bmatrix}
5 & 6 \\
7 & 8
\end{bmatrix} \\[0.5em]
&=
\begin{bmatrix}
1(5)+2(7) & 1(6)+2(8) \\
3(5)+4(7) & 3(6)+4(8)
\end{bmatrix} \\[0.5em]
&=
\begin{bmatrix}
19 & 22 \\
43 & 50
\end{bmatrix}.
\end{aligned}
$$
