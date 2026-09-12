---
title       : Introduction to Determinants
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition
author      : Jon Leithe
date        : 2026-09-12
---

The determinant is a single number associated with a square matrix. It is an
important test for invertibility: a square matrix is invertible exactly when
its determinant is nonzero. This note introduces a general method for
calculating determinants by reducing them to determinants of smaller matrices.

## Minors and cofactors

Let $A=[a_{ij}]$ be an $n\times n$ matrix. The **minor matrix** $A_{ij}$ is
formed by deleting row $i$ and column $j$ from $A$. Its determinant,

$$
M_{ij}=\det(A_{ij}),
$$

is called the **minor** of the entry $a_{ij}$.

The **cofactor** of $a_{ij}$ includes a sign that depends on its position:

$$
C_{ij}=(-1)^{i+j}\det(A_{ij}).
$$

The signs therefore follow a checkerboard pattern:

$$
\begin{bmatrix}
+ & - & + & \cdots \\
- & + & - & \cdots \\
+ & - & + & \cdots \\
\vdots & \vdots & \vdots & \ddots
\end{bmatrix}.
$$

For a one-by-one matrix, the determinant is its only entry:

$$
\det\begin{bmatrix}a\end{bmatrix}=a.
$$

This base case makes the following recursive definition complete.

::: {.callout-note title="Cofactor expansion"}

The determinant of an $n\times n$ matrix can be computed by expanding along
any row $i$ or any column $j$:

$$
\det(A)=\sum_{k=1}^{n}a_{ik}C_{ik}
\qquad\text{or}\qquad
\det(A)=\sum_{k=1}^{n}a_{kj}C_{kj}.
$$

:::

For example, expanding along the first row gives

$$
\det(A)=a_{11}\det(A_{11})-a_{12}\det(A_{12})+\cdots
+(-1)^{1+n}a_{1n}\det(A_{1n}).
$$

The freedom to choose the row or column is useful: selecting one that contains
many zero entries avoids unnecessary calculations.

## A three-by-three example

Consider

$$
A=
\begin{bmatrix}
1 & 5 & 0 \\
2 & 4 & -1 \\
0 & -2 & 0
\end{bmatrix}.
$$

Expanding along the first row gives

$$
\begin{aligned}
\det(A)
&=1
\begin{vmatrix}
4 & -1 \\
-2 & 0
\end{vmatrix}
-5
\begin{vmatrix}
2 & -1 \\
0 & 0
\end{vmatrix}
+0
\begin{vmatrix}
2 & 4 \\
0 & -2
\end{vmatrix} \\
&=1(0-2)-5(0)+0 \\
&=-2.
\end{aligned}
$$

The same result follows more efficiently by expanding along the third row,
which has two zero entries:

$$
\begin{aligned}
\det(A)
&=0C_{31}+(-2)C_{32}+0C_{33} \\
&=-(-2)
\begin{vmatrix}
1 & 0 \\
2 & -1
\end{vmatrix} \\
&=2(-1)=-2.
\end{aligned}
$$

## Repeated cofactor expansion

For larger matrices, expand repeatedly along sparse rows or columns. Consider

$$
A=
\begin{bmatrix}
3 & -7 & 8 & 9 & -6 \\
0 & 2 & -5 & 7 & 3 \\
0 & 0 & 1 & 5 & 0 \\
0 & 0 & 2 & 4 & -1 \\
0 & 0 & 0 & -2 & 0
\end{bmatrix}.
$$

Only the first entry in the first column is nonzero. Expanding down that
column, and then down the first column of the resulting matrix, gives

$$
\begin{aligned}
\det(A)
&=3\begin{vmatrix}
2 & -5 & 7 & 3 \\
0 & 1 & 5 & 0 \\
0 & 2 & 4 & -1 \\
0 & 0 & -2 & 0
\end{vmatrix} \\
&=3(2)
\begin{vmatrix}
1 & 5 & 0 \\
2 & 4 & -1 \\
0 & -2 & 0
\end{vmatrix}.
\end{aligned}
$$

Expanding the remaining determinant along its third row yields

$$
\begin{aligned}
\det(A)
&=6\left[-(-2)
\begin{vmatrix}
1 & 0 \\
2 & -1
\end{vmatrix}\right] \\
&=6(0-2+0) \\
&=-12.
\end{aligned}
$$

## Determinants of triangular matrices

::: {.callout-note title="Triangular-matrix determinant"}

If $A$ is an upper- or lower-triangular matrix, then its determinant is the
product of the entries on its main diagonal:

$$
\det(A)=a_{11}a_{22}\cdots a_{nn}.
$$

:::

This result follows naturally from cofactor expansion: at each step, a row or
column contains only one nonzero entry. It provides a much faster calculation
than expanding all cofactors of a triangular matrix.

## Worked practice problem

Compute the determinant of

$$
A=
\begin{bmatrix}
5 & -7 & 2 & 2 \\
0 & 3 & 0 & -4 \\
-5 & -8 & 0 & 3 \\
0 & 5 & 0 & -6
\end{bmatrix}.
$$

Column $3$ has only one nonzero entry, so cofactor expansion down that column
immediately reduces the problem to a three-by-three determinant:

$$
\det(A)
=2
\begin{vmatrix}
0 & 3 & -4 \\
-5 & -8 & 3 \\
0 & 5 & -6
\end{vmatrix}.
$$

Next, expand down the first column. Again, only one term remains:

$$
\begin{aligned}
\det(A)
&=2(-1)(-5)
\begin{vmatrix}
3 & -4 \\
5 & -6
\end{vmatrix} \\
&=10\bigl(3(-6)-5(-4)\bigr) \\
&=10(-18+20) \\
&=20.
\end{aligned}
$$

The calculation illustrates the practical rule for cofactor expansion: choose
the row or column with the most zeros, while carefully retaining the alternating
cofactor signs.
