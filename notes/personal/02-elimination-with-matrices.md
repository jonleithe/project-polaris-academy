---
title       : Elimination With Matrices
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-08-16
---

Gaussian elimination provides a systematic way to analyze and solve a system
of linear equations. If the system is consistent, elimination reveals one or
more solutions; if it is inconsistent, elimination exposes the contradiction.

Consider the system

$$
\begin{aligned}
x+2y+z &= 2 \\
3x+8y+z &= 12 \\
4y+z &= 2
\end{aligned}
$$

We can write it compactly as

$$
A\vec{x}=\vec{b}
$$

where $A$ is the **coefficient matrix**, $\vec{x}$ contains the unknowns, and
$\vec{b}$ contains the constants on the right-hand side:

$$
\underbrace{
\begin{bmatrix}
1 & 2 & 1 \\
3 & 8 & 1 \\
0 & 4 & 1
\end{bmatrix}
}_{A}
\underbrace{
\begin{bmatrix}
x \\
y \\
z
\end{bmatrix}
}_{\vec{x}}
=
\underbrace{
\begin{bmatrix}
2 \\
12 \\
2
\end{bmatrix}
}_{\vec{b}}
$$

More generally, for $A\in\mathbb{R}^{n\times m}$,
$\vec{x}\in\mathbb{R}^{m}$, and $\vec{b}\in\mathbb{R}^{n}$,

$$
\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1m} \\
a_{21} & a_{22} & \cdots & a_{2m} \\
\vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & \cdots & a_{nm}
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_m
\end{bmatrix}
=
\begin{bmatrix}
b_1 \\
b_2 \\
\vdots \\
b_n
\end{bmatrix}
$$

The system is consistent precisely when there is at least one vector
$\vec{x}$ for which $A\vec{x}=\vec{b}$.

<!-- pagebreak -->

## Augmented matrix and elimination

To perform elimination, place the coefficient matrix and right-hand-side
vector into the augmented matrix

$$
\left[A\mid\vec{b}\right]
=
\left[
\begin{array}{ccc|c}
1 & 2 & 1 & 2 \\
3 & 8 & 1 & 12 \\
0 & 4 & 1 & 2
\end{array}
\right]
$$

First eliminate the $3$ below the leading entry in column one:

$$
R_2\leftarrow R_2-3R_1
$$

which gives

$$
\left[
\begin{array}{ccc|c}
1 & 2 & 1 & 2 \\
0 & 2 & -2 & 6 \\
0 & 4 & 1 & 2
\end{array}
\right]
$$

Next eliminate the $4$ below the leading entry in column two:

$$
R_3\leftarrow R_3-2R_2
$$

The augmented matrix is now in upper-triangular form:

$$
\left[U\mid\vec{c}\right]
=
\left[
\begin{array}{ccc|c}
\boxed{1} & 2 & 1 & 2 \\
0 & \boxed{2} & -2 & 6 \\
0 & 0 & \boxed{5} & -10
\end{array}
\right]
$$

The boxed entries $1$, $2$, and $5$ are the three pivots. Each pivot lies to
the right of the pivot in the row above, and every entry below a pivot is zero.

<!-- pagebreak -->

## Pivots, determinant, and consistency

Only row-replacement operations were used, so the determinant was not changed
during elimination. Because $U$ is triangular, its determinant is the product
of its diagonal entries:

$$
\det(A)=\det(U)=1\cdot 2\cdot 5=10\neq 0
$$

Therefore, $A$ is invertible. Equivalently, there is a pivot in every row and
every column, so this square system has exactly one solution.

Elimination also shows how inconsistency would appear. Suppose, for example,
that the final equation reduced to

$$
\left[
\begin{array}{ccc|c}
0 & 0 & 0 & -10
\end{array}
\right]
$$

This row represents the impossible equation $0=-10$. Any augmented matrix
containing a row of the form

$$
\left[
\begin{array}{cccc|c}
0 & 0 & \cdots & 0 & d
\end{array}
\right]
\qquad d\neq 0
$$

describes an inconsistent system.

<!-- pagebreak -->

## Back-substitution

The transformed right-hand side is

$$
\vec{c}=
\begin{bmatrix}
2 \\
6 \\
-10
\end{bmatrix}
$$

We can now solve $U\vec{x}=\vec{c}$ from the bottom row upward:

$$
\begin{aligned}
5z&=-10
&&\Longrightarrow& z&=-2 \\
2y-2z&=6
&&\Longrightarrow& y&=1 \\
x+2y+z&=2
&&\Longrightarrow& x&=2
\end{aligned}
$$

Thus the unique solution is

$$
\vec{x}=
\begin{bmatrix}
2 \\
1 \\
-2
\end{bmatrix}
$$

We can verify the solution by substituting it into the original matrix
equation:

$$
A\vec{x}
=
\begin{bmatrix}
1 & 2 & 1 \\
3 & 8 & 1 \\
0 & 4 & 1
\end{bmatrix}
\begin{bmatrix}
2 \\
1 \\
-2
\end{bmatrix}
=
\begin{bmatrix}
1\cdot 2+2\cdot 1+1\cdot(-2) \\
3\cdot 2+8\cdot 1+1\cdot(-2) \\
0\cdot 2+4\cdot 1+1\cdot(-2)
\end{bmatrix}
=
\begin{bmatrix}
2 \\
12 \\
2
\end{bmatrix}
=\vec{b}
$$

## Column-space interpretation

Matrix multiplication gives another interpretation of the solution. The
entries of $\vec{x}$ are the weights in a linear combination of the columns of
$A$:

$$
2
\begin{bmatrix}
1 \\
3 \\
0
\end{bmatrix}
+
1
\begin{bmatrix}
2 \\
8 \\
4
\end{bmatrix}
-
2
\begin{bmatrix}
1 \\
1 \\
1
\end{bmatrix}
=
\begin{bmatrix}
2 \\
12 \\
2
\end{bmatrix}
=\vec{b}
$$

Finding a solution to $A\vec{x}=\vec{b}$ is therefore equivalent to finding
weights that combine the columns of $A$ to produce $\vec{b}$. In this example,
$\vec{b}$ lies in the column space of $A$, as it must for the system to be
consistent.
