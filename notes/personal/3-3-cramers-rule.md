---
title       : "Cramer's Rule"
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition
author      : Jon Leithe
date        : 2026-09-14
---

Cramer's rule expresses each component of the solution to a linear system as
a ratio of determinants. It connects solving systems with the determinant
properties developed in [Properties of Determinants](3-2-properties-of-determinants.md),
and leads to a formula for the inverse of a matrix.

This note follows the first five pages of the handwritten section 3.3 notes
and covers Cramer's rule and the inverse formula. The next pages develop the
geometric interpretation in [Determinants as Area or Volume](3-3-determinants-as-area-or-volume.md).
They continue in [Determinants and Linear Transformations](3-3-determinants-and-linear-transformations.md).

## Replacing one column

Write an $n\times n$ matrix in terms of its columns:

$$
A=[\vec{a}_1\ \cdots\ \vec{a}_n].
$$

For $\vec{b}\in\mathbb{R}^n$, define $A_i(\vec{b})$ to be the matrix
obtained by replacing column $i$ of $A$ with $\vec{b}$:

$$
A_i(\vec{b})=
[\vec{a}_1\ \cdots\ \vec{a}_{i-1}\ \vec{b}\ \vec{a}_{i+1}\ \cdots\ \vec{a}_n].
$$

All other columns retain their original positions. For example,

$$
A=\begin{bmatrix}a_{11}&a_{12}\\a_{21}&a_{22}\end{bmatrix},
\qquad
\vec{b}=\begin{bmatrix}b_1\\b_2\end{bmatrix}
$$

give

$$
A_1(\vec{b})=\begin{bmatrix}b_1&a_{12}\\b_2&a_{22}\end{bmatrix},
\qquad
A_2(\vec{b})=\begin{bmatrix}a_{11}&b_1\\a_{21}&b_2\end{bmatrix}.
$$

## Cramer's rule

The equation $A\vec{x}=\vec{b}$ says that
$\vec{b}=x_1\vec{a}_1+\cdots+x_n\vec{a}_n$. If we substitute this
combination into column $i$ of a determinant, linearity in that column
separates it into $n$ terms. Every term except the one containing
$x_i\vec{a}_i$ has two equal columns and vanishes. Thus,
$\det(A_i(\vec{b}))=x_i\det(A)$.

::: {#nte-cramers-rule .callout-note title="Theorem 7: Cramer's Rule"}

Let $A$ be an invertible $n\times n$ matrix. For every
$\vec{b}\in\mathbb{R}^n$, the unique solution of $A\vec{x}=\vec{b}$ has
entries

$$
x_i=\frac{\det(A_i(\vec{b}))}{\det(A)},
\qquad i=1,2,\ldots,n.
$$

:::

### Proof using the determinant of a product

Let $\vec{e}_1,\ldots,\vec{e}_n$ be the columns of the identity matrix
$I$, and let $I_i(\vec{x})$ denote $I$ with column $i$ replaced by
$\vec{x}$. Since $A\vec{e}_j=\vec{a}_j$ and $A\vec{x}=\vec{b}$,

$$
\begin{aligned}
A I_i(\vec{x})
&=A[\vec{e}_1\ \cdots\ \vec{e}_{i-1}\ \vec{x}\ \vec{e}_{i+1}\ \cdots\ \vec{e}_n]\\
&=[\vec{a}_1\ \cdots\ \vec{a}_{i-1}\ \vec{b}\ \vec{a}_{i+1}\ \cdots\ \vec{a}_n]\\
&=A_i(\vec{b}).
\end{aligned}
$$

Taking determinants and using the product rule gives

$$
\det(A)\det(I_i(\vec{x}))=\det(A_i(\vec{b})).
$$

Row $i$ of $I_i(\vec{x})$ is zero except for its diagonal entry $x_i$.
Expanding along this row gives $\det(I_i(\vec{x}))=x_i$: the remaining
minor matrix is an identity matrix and the cofactor sign is positive.
Consequently,

$$
\det(A)x_i=\det(A_i(\vec{b})).
$$

Invertibility ensures that $\det(A)\ne0$, so division proves the formula.

::: {.callout-warning title="Check the denominator first"}

Cramer's rule in this form requires $\det(A)\ne0$. If $\det(A)=0$, the
system has either no solution or infinitely many solutions. Row reduction
of the augmented matrix distinguishes these cases; division by zero does
not give a solution.

:::

### Example 1: a two-by-two system

Solve

$$
\begin{aligned}
3x_1-2x_2&=6,\\
-5x_1+4x_2&=8.
\end{aligned}
$$

The coefficient matrix and replacement matrices are

$$
A=\begin{bmatrix}3&-2\\-5&4\end{bmatrix},
\qquad
A_1(\vec{b})=\begin{bmatrix}6&-2\\8&4\end{bmatrix},
\qquad
A_2(\vec{b})=\begin{bmatrix}3&6\\-5&8\end{bmatrix}.
$$

Their determinants are

$$
\begin{aligned}
\det(A)&=12-10=2,\\
\det(A_1(\vec{b}))&=24+16=40,\\
\det(A_2(\vec{b}))&=24+30=54.
\end{aligned}
$$

Since $\det(A)\ne0$, there is exactly one solution:

$$
x_1=\frac{40}{2}=20,
\qquad
x_2=\frac{54}{2}=27.
$$

Substitution checks both equations:
$3(20)-2(27)=6$ and $-5(20)+4(27)=8$.

## Application to engineering: a parameter-dependent system

Laplace transforms can turn systems of linear differential equations with
constant coefficients into algebraic systems involving a parameter $s$.
Cramer's rule makes the dependence of the solution on that parameter
explicit. The following example illustrates the algebra without requiring
the transform itself.

### Example 2: determine when the solution is unique

Consider

$$
\begin{aligned}
3s x_1-2x_2&=4,\\
-6x_1+s x_2&=1.
\end{aligned}
$$

Here,

$$
A=\begin{bmatrix}3s&-2\\-6&s\end{bmatrix},
\qquad
A_1(\vec{b})=\begin{bmatrix}4&-2\\1&s\end{bmatrix},
\qquad
A_2(\vec{b})=\begin{bmatrix}3s&4\\-6&1\end{bmatrix}.
$$

The determinant is

$$
\det(A)=3s^2-12=3(s+2)(s-2).
$$

Therefore, the system has a unique solution exactly when $s\ne\pm2$.
For these values,

$$
\begin{aligned}
x_1&=\frac{4s+2}{3(s+2)(s-2)},\\
x_2&=\frac{3s+24}{3(s+2)(s-2)}
=\frac{s+8}{(s+2)(s-2)}.
\end{aligned}
$$

At the excluded values, inspect the original equations. When $s=2$, adding
the two equations gives $0=5$. When $s=-2$, subtracting the second equation
from the first gives $0=3$. Thus, neither excluded value gives a solution.

The determinant identifies where uniqueness fails, while the original
equations establish what happens there. This distinction matters when a
parameter represents part of an engineering model.

## A formula for the inverse

The columns of $A^{-1}$ solve a particular collection of linear systems:
column $j$ is the vector $\vec{x}$ satisfying $A\vec{x}=\vec{e}_j$.
Applying Cramer's rule gives

$$
(A^{-1})_{ij}=\frac{\det(A_i(\vec{e}_j))}{\det(A)}.
$$

Column $i$ of $A_i(\vec{e}_j)$ has just one nonzero entry, a $1$ in row
$j$. Cofactor expansion down that column yields

$$
\det(A_i(\vec{e}_j))=(-1)^{j+i}\det(A_{ji})=C_{ji},
$$

where $A_{ji}$ is obtained by deleting row $j$ and column $i$ of $A$, and
$C_{ji}$ is its corresponding cofactor. These are the minor and cofactor
definitions from [Introduction to Determinants](3-1-introduction-to-determinants.md).
Hence,

$$
(A^{-1})_{ij}=\frac{C_{ji}}{\det(A)}.
$$

Notice the reversed indices: entry $(i,j)$ of the inverse uses cofactor
$C_{ji}$. This is why the cofactor matrix must be transposed.

The **adjugate** of $A$ is the transpose of its cofactor matrix:

$$
\operatorname{adj}(A)=[C_{ij}]^T=
\begin{bmatrix}
C_{11}&C_{21}&\cdots&C_{n1}\\
C_{12}&C_{22}&\cdots&C_{n2}\\
\vdots&\vdots&\ddots&\vdots\\
C_{1n}&C_{2n}&\cdots&C_{nn}
\end{bmatrix}.
$$

::: {#nte-adjugate-inverse .callout-note title="Theorem 8: An Inverse Formula"}

If $A$ is an invertible $n\times n$ matrix, then

$$
A^{-1}=\frac{1}{\det(A)}\operatorname{adj}(A).
$$

:::

For a two-by-two matrix this recovers the familiar formula from
[The Inverse of a Matrix](2-2-the-inverse-of-a-matrix.md):

$$
\begin{bmatrix}a&b\\c&d\end{bmatrix}^{-1}
=\frac{1}{ad-bc}\begin{bmatrix}d&-b\\-c&a\end{bmatrix},
\qquad ad-bc\ne0.
$$

### Example 3: a three-by-three inverse

Find the inverse of

$$
A=\begin{bmatrix}2&1&3\\1&-1&1\\1&4&-2\end{bmatrix}.
$$

Compute the nine cofactors, retaining the alternating signs:

$$
\begin{aligned}
C_{11}&=\begin{vmatrix}-1&1\\4&-2\end{vmatrix}=-2,
&C_{12}&=-\begin{vmatrix}1&1\\1&-2\end{vmatrix}=3,
&C_{13}&=\begin{vmatrix}1&-1\\1&4\end{vmatrix}=5,\\
C_{21}&=-\begin{vmatrix}1&3\\4&-2\end{vmatrix}=14,
&C_{22}&=\begin{vmatrix}2&3\\1&-2\end{vmatrix}=-7,
&C_{23}&=-\begin{vmatrix}2&1\\1&4\end{vmatrix}=-7,\\
C_{31}&=\begin{vmatrix}1&3\\-1&1\end{vmatrix}=4,
&C_{32}&=-\begin{vmatrix}2&3\\1&1\end{vmatrix}=1,
&C_{33}&=\begin{vmatrix}2&1\\1&-1\end{vmatrix}=-3.
\end{aligned}
$$

The cofactor matrix and its transpose are

$$
C=\begin{bmatrix}-2&3&5\\14&-7&-7\\4&1&-3\end{bmatrix},
\qquad
\operatorname{adj}(A)=C^T=
\begin{bmatrix}-2&14&4\\3&-7&1\\5&-7&-3\end{bmatrix}.
$$

Expanding $\det(A)$ along the first row gives

$$
\det(A)=2C_{11}+C_{12}+3C_{13}=2(-2)+3+3(5)=14.
$$

Since this is nonzero, the inverse exists and is

$$
A^{-1}=\frac{1}{14}
\begin{bmatrix}-2&14&4\\3&-7&1\\5&-7&-3\end{bmatrix}.
$$

As a check on the cofactor calculations and transpose,

$$
\operatorname{adj}(A)A=
\begin{bmatrix}-2&14&4\\3&-7&1\\5&-7&-3\end{bmatrix}
\begin{bmatrix}2&1&3\\1&-1&1\\1&4&-2\end{bmatrix}
=\begin{bmatrix}14&0&0\\0&14&0\\0&0&14\end{bmatrix}=14I.
$$

Dividing by $14$ therefore gives $A^{-1}A=I$, as required.

## Summary

Cramer's rule finds $x_i$ by replacing column $i$ with the right-hand side
and dividing the resulting determinant by $\det(A)$. It applies when $A$
is square and invertible. Applying the same rule to the columns of the
identity matrix gives the adjugate formula for $A^{-1}$.

Both formulas expose useful algebraic structure, especially in small systems
and symbolic calculations involving parameters. Computing many determinants
by hand quickly becomes cumbersome; elimination is generally the more
practical approach for larger systems.
