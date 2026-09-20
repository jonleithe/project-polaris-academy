---
title       : The Matrix Equation $A\vec{x}=\vec{b}$
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-09-20
---

The equation $A\vec{x}=\vec{b}$ connects three views of the same problem:
a system of scalar equations, a vector equation, and a matrix equation. Its
most useful interpretation is that the entries of $\vec{x}$ are weights for
the columns of $A$. Solving the equation therefore asks whether those columns
can be combined to produce $\vec{b}$.

These notes are based on the handwritten note
[`1-4-the-matrix-equation.pdf`](../hand-written/1-4-the-matrix-equation.pdf).

## Matrix-vector multiplication

Let $A\in\mathbb{R}^{m\times n}$ have columns
$\vec{a}_1,\ldots,\vec{a}_n$, and let
$\vec{x}\in\mathbb{R}^n$. The product $A\vec{x}$ is defined by

$$
A\vec{x}
=
\begin{bmatrix}
\vec{a}_1 & \vec{a}_2 & \cdots & \vec{a}_n
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}
=x_1\vec{a}_1+x_2\vec{a}_2+\cdots+x_n\vec{a}_n.
$$

Thus, $A\vec{x}$ is a linear combination of the columns of $A$, with the
corresponding entries of $\vec{x}$ as coefficients. The number of columns in
$A$ must equal the number of entries in $\vec{x}$; equivalently, an
$m\times n$ matrix can multiply only a vector in $\mathbb{R}^n$. The result
is a vector in $\mathbb{R}^m$.

For example, if

$$
A=
\begin{bmatrix}
2 & 3 & 4 \\
-1 & 5 & -3 \\
6 & -2 & 8
\end{bmatrix},
\qquad
\vec{x}=
\begin{bmatrix}x_1\\x_2\\x_3\end{bmatrix},
$$

then the column interpretation gives

$$
\begin{aligned}
A\vec{x}
&=
x_1\begin{bmatrix}2\\-1\\6\end{bmatrix}
+x_2\begin{bmatrix}3\\5\\-2\end{bmatrix}
+x_3\begin{bmatrix}4\\-3\\8\end{bmatrix} \\
&=
\begin{bmatrix}
2x_1+3x_2+4x_3 \\
-x_1+5x_2-3x_3 \\
6x_1-2x_2+8x_3
\end{bmatrix}.
\end{aligned}
$$

The second line is the **row-vector rule**: the $i$th entry of $A\vec{x}$ is
the sum of the products of corresponding entries in row $i$ of $A$ and in
$\vec{x}$. The column and row views are not competing definitions; they are
two useful ways to read the same product.

## The matrix equation and its equivalent forms

Suppose $A=[\vec{a}_1\ \cdots\ \vec{a}_n]$ is an $m\times n$ matrix and
$\vec{b}\in\mathbb{R}^m$. The matrix equation

$$
A\vec{x}=\vec{b}
$$

means exactly that

$$
x_1\vec{a}_1+x_2\vec{a}_2+\cdots+x_n\vec{a}_n=\vec{b}.
$$

Writing the columns and right-hand side by their entries turns this vector
equation into the usual system of $m$ linear equations. Therefore all three
forms have the same solution set.

::: {.callout-note title="Theorem 3 — Matrix, vector, and system equivalence"}

If $A$ is an $m\times n$ matrix with columns
$\vec{a}_1,\ldots,\vec{a}_n$, and $\vec{b}\in\mathbb{R}^m$, then the
following have the same solution set:

$$
A\vec{x}=\vec{b},
\qquad
x_1\vec{a}_1+\cdots+x_n\vec{a}_n=\vec{b},
\qquad
\left[\begin{array}{cccc|c}
\vec{a}_1 & \vec{a}_2 & \cdots & \vec{a}_n & \vec{b}
\end{array}\right].
$$

:::

This equivalence is valuable because it allows us to choose the most useful
view. Use the augmented matrix to row-reduce and solve; use the vector view to
reason about span and attainable outputs.

## Consistency and the column space

The equation $A\vec{x}=\vec{b}$ has a solution if and only if $\vec{b}$ is a
linear combination of the columns of $A$. In other words,

$$
A\vec{x}=\vec{b}
\text{ is consistent}
\quad\Longleftrightarrow\quad
\vec{b}\in\operatorname{Col}(A).
$$

This is the direct bridge from solving a system to understanding the column
space.

### Example: can every right-hand side be reached?

Let

$$
A=
\begin{bmatrix}
1 & 3 & 4 \\
-4 & 2 & -6 \\
-3 & -2 & -7
\end{bmatrix},
\qquad
\vec{b}=
\begin{bmatrix}b_1\\b_2\\b_3\end{bmatrix}.
$$

To determine whether $A\vec{x}=\vec{b}$ is consistent for *every*
$\vec{b}\in\mathbb{R}^3$, row-reduce its augmented matrix symbolically:

$$
\begin{aligned}
\left[\begin{array}{ccc|c}
1&3&4&b_1\\
-4&2&-6&b_2\\
-3&-2&-7&b_3
\end{array}\right]
&\xrightarrow[\displaystyle R_3\leftarrow R_3+3R_1]
{\displaystyle R_2\leftarrow R_2+4R_1}
\left[\begin{array}{ccc|c}
1&3&4&b_1\\
0&14&10&b_2+4b_1\\
0&7&5&b_3+3b_1
\end{array}\right] \\
&\xrightarrow{\displaystyle R_2\leftarrow \tfrac12R_2}
\left[\begin{array}{ccc|c}
1&3&4&b_1\\
0&7&5&\tfrac12b_2+2b_1\\
0&7&5&b_3+3b_1
\end{array}\right] \\
&\xrightarrow{\displaystyle R_3\leftarrow R_3-R_2}
\left[\begin{array}{ccc|c}
1&3&4&b_1\\
0&7&5&\tfrac12b_2+2b_1\\
0&0&0&b_1-\tfrac12b_2+b_3
\end{array}\right].
\end{aligned}
$$

The system is consistent precisely when the final entry is zero:

$$
b_1-\frac12b_2+b_3=0.
$$

Consequently, this matrix cannot produce every vector in $\mathbb{R}^3$.
Its columns span a plane through the origin, and only vectors on that plane
can be right-hand sides of a consistent equation.

::: {.callout-note title="Theorem 1.4.2 — When the columns span the output space"}

For an $m\times n$ matrix $A$, the following statements are equivalent:

1. For every $\vec{b}\in\mathbb{R}^m$, the equation $A\vec{x}=\vec{b}$ has a solution.
2. Every vector in $\mathbb{R}^m$ is a linear combination of the columns of $A$.
3. The columns of $A$ span $\mathbb{R}^m$.
4. $A$ has a pivot position in every row.

:::

The pivot criterion makes the geometric statement about spanning practical:
row-reduce $A$ and check whether every row contains a pivot.

<!-- pagebreak -->

## Computing products

The row-vector rule makes numerical multiplication routine. For instance,

$$
\begin{aligned}
\begin{bmatrix}
1&2&-1\\
0&-5&3
\end{bmatrix}
\begin{bmatrix}4\\3\\7\end{bmatrix}
&=
\begin{bmatrix}
1\cdot4+2\cdot3-1\cdot7\\
0\cdot4-5\cdot3+3\cdot7
\end{bmatrix}
=
\begin{bmatrix}3\\6\end{bmatrix}, \\
\begin{bmatrix}
2&-3\\
8&0\\
-5&2
\end{bmatrix}
\begin{bmatrix}4\\7\end{bmatrix}
&=
\begin{bmatrix}
2\cdot4-3\cdot7\\
8\cdot4+0\cdot7\\
-5\cdot4+2\cdot7
\end{bmatrix}
=
\begin{bmatrix}-13\\32\\-6\end{bmatrix}.
\end{aligned}
$$

The identity matrix leaves every compatible vector unchanged. In particular,

$$
I_3\begin{bmatrix}r\\s\\t\end{bmatrix}
=
\begin{bmatrix}r\\s\\t\end{bmatrix}.
$$

## Linearity of matrix-vector multiplication

Matrix-vector multiplication respects addition and scalar multiplication.

::: {.callout-note title="Theorem 1.4.3 — Linearity of matrix-vector multiplication"}

Let $A$ be an $m\times n$ matrix, let $\vec{u},\vec{v}\in\mathbb{R}^n$,
and let $c$ be a scalar. Then

$$
A(\vec{u}+\vec{v})=A\vec{u}+A\vec{v},
\qquad
A(c\vec{u})=c(A\vec{u}).
$$

:::

To see the first property, write $A=[\vec{a}_1\ \vec{a}_2\ \vec{a}_3]$
and let $\vec{u},\vec{v}\in\mathbb{R}^3$. Then

$$
\begin{aligned}
A(\vec{u}+\vec{v})
&=\vec{a}_1(u_1+v_1)+\vec{a}_2(u_2+v_2)+\vec{a}_3(u_3+v_3) \\
&=(u_1\vec{a}_1+u_2\vec{a}_2+u_3\vec{a}_3)
+(v_1\vec{a}_1+v_2\vec{a}_2+v_3\vec{a}_3) \\
&=A\vec{u}+A\vec{v}.
\end{aligned}
$$

The same column interpretation gives

$$
\begin{aligned}
A(c\vec{u})
&=(cu_1)\vec{a}_1+(cu_2)\vec{a}_2+(cu_3)\vec{a}_3 \\
&=c(u_1\vec{a}_1+u_2\vec{a}_2+u_3\vec{a}_3) \\
&=c(A\vec{u}).
\end{aligned}
$$

These two rules are why multiplication by a matrix represents a linear map:
it preserves both vector addition and scalar multiplication.

## Engineering interpretation

Suppose $\vec{x}$ contains actuator commands and the columns of $A$ describe
the output produced by each unit command. Then $A\vec{x}$ is the total output
predicted by the linear model. The column space is the set of outputs the
actuators can achieve. A right-hand side outside that space is not a failure
of the solution method; it is a request the model cannot satisfy.

## Summary

- $A\vec{x}$ is a linear combination of the columns of $A$.
- $A\vec{x}=\vec{b}$ is consistent exactly when $\vec{b}$ lies in $\operatorname{Col}(A)$.
- The columns of $A$ span $\mathbb{R}^m$ exactly when $A$ has a pivot in every row.
- Matrix-vector multiplication is linear.

The relation between consistency and the column space is developed further in
[Subspaces of $\mathbb{R}^n$](2-8-subspaces-of-Rn.md). For the row-reduction
technique used here, see [Elimination With Matrices](1-2-row-reduction-and-echelon-forms.md).
