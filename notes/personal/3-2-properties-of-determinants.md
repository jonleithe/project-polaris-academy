---
title       : Properties of Determinants
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition
author      : Jon Leithe
date        : 2026-09-13
---

The determinant is especially useful when a matrix is simplified by row
operations.  The matrix entries may change substantially, but the effect on
the determinant is predictable.  This makes it possible to reduce a matrix to
triangular form and then use the product of its diagonal entries.

## Row operations and determinants

::: {#nte-row-operations-determinant .callout-note title="Theorem 3: Effects of Row Operations"}

Let $A$ be a square matrix, and let $B$ be obtained from $A$ by one row
operation.

1. If a multiple of one row is added to another row, then
   $\det(B)=\det(A)$.
2. If two rows are interchanged, then $\det(B)=-\det(A)$.
3. If one row is multiplied by a scalar $k$, then
   $\det(B)=k\det(A)$.

:::

The first operation is particularly valuable in calculations because it
creates zeros without changing the determinant.  A row interchange changes
only the sign, while scaling a row requires its scale factor to be tracked.

### Example 1: reducing to triangular form

Compute the determinant of

$$
A=
\begin{bmatrix}
1 & -4 & 2 \\
-2 & 8 & -9 \\
-1 & 7 & 0
\end{bmatrix}.
$$

Use row replacements to create zeros below the first pivot:

$$
\begin{aligned}
R_2&\leftarrow R_2+2R_1, \\
R_3&\leftarrow R_3+R_1.
\end{aligned}
$$

These operations leave the determinant unchanged and give

$$
\begin{bmatrix}
1 & -4 & 2 \\
0 & 0 & -5 \\
0 & 3 & 2
\end{bmatrix}.
$$

Interchange rows $2$ and $3$ to obtain an upper-triangular matrix:

$$
U=
\begin{bmatrix}
1 & -4 & 2 \\
0 & 3 & 2 \\
0 & 0 & -5
\end{bmatrix}.
$$

One row interchange was used, so $\det(A)=-\det(U)$.  Therefore,

$$
\det(A)=-(1)(3)(-5)=15.
$$

### Example 2: tracking a factored row

Compute the determinant of

$$
A=
\begin{bmatrix}
2 & -8 & 6 & 8 \\
3 & -9 & 5 & 10 \\
-3 & 0 & 1 & -2 \\
1 & -4 & 0 & 6
\end{bmatrix}.
$$

Factoring $2$ out of the first row avoids a row interchange and produces a
leading entry of $1$:

$$
\det(A)=2
\begin{vmatrix}
1 & -4 & 3 & 4 \\
3 & -9 & 5 & 10 \\
-3 & 0 & 1 & -2 \\
1 & -4 & 0 & 6
\end{vmatrix}.
$$

Now use only row replacements:

$$
\begin{aligned}
R_2&\leftarrow R_2-3R_1, &
R_3&\leftarrow R_3+3R_1, &
R_4&\leftarrow R_4-R_1, \\
R_3&\leftarrow R_3+4R_2, &
R_4&\leftarrow R_4-\tfrac12R_3.
\end{aligned}
$$

The resulting triangular matrix is

$$
\begin{bmatrix}
1 & -4 & 3 & 4 \\
0 & 3 & -4 & -2 \\
0 & 0 & -6 & 2 \\
0 & 0 & 0 & 1
\end{bmatrix}.
$$

Hence,

$$
\det(A)=2(1)(3)(-6)(1)=-36.
$$

::: {.callout-tip title="Determinant bookkeeping during elimination"}

If $U$ is obtained from $A$ using row replacements and $r$ row interchanges,
with no row scaling, then

$$
\det(A)=(-1)^r\det(U).
$$

If rows are also scaled, include every scale factor.  For example, factoring
$k$ out of a row gives $\det(A)=k\det(B)$, where $B$ is the matrix with that
row divided by $k$.

:::

## Zero determinants and invertibility

::: {#nte-invertible-determinant .callout-note title="Theorem 4: Invertibility Test"}

A square matrix $A$ is invertible if and only if

$$
\det(A)\ne0.
$$

:::

This theorem links determinant calculations to solving linear systems.  A
zero row or column makes the determinant zero.  Likewise, if two rows or two
columns are equal, the determinant is zero: interchanging the equal rows or
columns leaves the matrix unchanged but must reverse the determinant's sign.

### Example 3: detecting equal rows

Compute the determinant of

$$
A=
\begin{bmatrix}
3 & -1 & 2 & -5 \\
0 & 5 & -3 & -6 \\
-6 & 7 & -7 & 4 \\
-5 & -8 & 0 & 9
\end{bmatrix}.
$$

Apply the determinant-preserving replacement

$$
R_3\leftarrow R_3+2R_1.
$$

This gives

$$
\begin{bmatrix}
3 & -1 & 2 & -5 \\
0 & 5 & -3 & -6 \\
0 & 5 & -3 & -6 \\
-5 & -8 & 0 & 9
\end{bmatrix}.
$$

Rows $2$ and $3$ are now equal, so $\det(A)=0$.  Consequently, $A$ is not
invertible.

### Example 4: combine row operations and cofactor expansion

Compute the determinant of

$$
A=
\begin{bmatrix}
0 & 1 & 2 & -1 \\
2 & 5 & -7 & 3 \\
0 & 3 & 6 & 2 \\
-2 & -5 & 4 & -2
\end{bmatrix}.
$$

First use $R_4\leftarrow R_4+R_2$.  This does not change the determinant and
creates a single nonzero entry in the first column:

$$
\det(A)=
\begin{vmatrix}
0 & 1 & 2 & -1 \\
2 & 5 & -7 & 3 \\
0 & 3 & 6 & 2 \\
0 & 0 & -3 & 1
\end{vmatrix}.
$$

Expanding along the first column, the only contribution is $a_{21}=2$.  Its
cofactor sign is $(-1)^{2+1}=-1$, so

$$
\det(A)=-2
\begin{vmatrix}
1 & 2 & -1 \\
3 & 6 & 2 \\
0 & -3 & 1
\end{vmatrix}.
$$

Use $R_2\leftarrow R_2-3R_1$ inside the remaining determinant:

$$
\begin{aligned}
\det(A)
&=-2
\begin{vmatrix}
1 & 2 & -1 \\
0 & 0 & 5 \\
0 & -3 & 1
\end{vmatrix} \\
&=-2\bigl(0-(-15)\bigr) \\
&=-30.
\end{aligned}
$$

The first row operation creates a sparse column; cofactor expansion then
reduces the calculation to a three-by-three determinant.

## More determinant properties

::: {#nte-transpose-determinant .callout-note title="Theorem 5: Transpose Invariance"}

If $A$ is an $n\times n$ matrix, then

$$
\det(A)=\det(A^T).
$$

:::

This allows every row-based determinant property to be stated equally for
columns.

::: {#nte-product-determinant .callout-note title="Theorem 6: Determinant of a Product"}

If $A$ and $B$ are $n\times n$ matrices, then

$$
\det(AB)=\det(A)\det(B).
$$

:::

For

$$
A=
\begin{bmatrix}
6 & 1 \\
3 & 2
\end{bmatrix},
\qquad
B=
\begin{bmatrix}
4 & 3 \\
1 & 2
\end{bmatrix},
$$

we have

$$
AB=
\begin{bmatrix}
25 & 20 \\
14 & 13
\end{bmatrix}.
$$

The three determinants are

$$
\det(A)=9,
\qquad
\det(B)=5,
\qquad
\det(AB)=45,
$$

so $\det(AB)=45=9\cdot5=\det(A)\det(B)$, as expected.  In
$\mathbb{R}^2$, $|\det[\vec{a}\ \vec{b}]|$ is the area of the parallelogram
spanned by the column vectors $\vec{a}$ and $\vec{b}$.  The product rule says
that the area-scaling effects of two linear transformations multiply.

## Linearity in one column

The determinant is **linear in each column separately** when all other
columns are held fixed.  For example, if the $j$th column is allowed to vary,
define

$$
T(\vec{x})=
\det\left[
\vec{a}_1\ \cdots\ \vec{a}_{j-1}\ \vec{x}\ \vec{a}_{j+1}\ \cdots\ \vec{a}_n
\right].
$$

Then $T\colon\mathbb{R}^n\to\mathbb{R}$ is a linear transformation:

$$
T(c\vec{x})=cT(\vec{x}),
\qquad
T(\vec{u}+\vec{v})=T(\vec{u})+T(\vec{v}).
$$

To see this for a two-by-two matrix, fix the first column and let the second
column vary:

$$
\vec{a}_1=
\begin{bmatrix}2\\3\end{bmatrix},
\qquad
\vec{x}=
\begin{bmatrix}x_1\\x_2\end{bmatrix},
\qquad
T(\vec{x})=
\det
\begin{bmatrix}
2 & x_1 \\
3 & x_2
\end{bmatrix}
=2x_2-3x_1.
$$

Let

$$
\vec{u}=
\begin{bmatrix}1\\4\end{bmatrix},
\qquad
\vec{v}=
\begin{bmatrix}2\\5\end{bmatrix}.
$$

Then

$$
T(\vec{u})=5,
\qquad
T(\vec{v})=4,
\qquad
T(\vec{u}+\vec{v})=T
\begin{bmatrix}3\\9\end{bmatrix}=9,
$$

so $T(\vec{u}+\vec{v})=T(\vec{u})+T(\vec{v})$.  Similarly,

$$
T(3\vec{u})=15=3T(\vec{u}).
$$

::: {.callout-warning title="Linearity is column by column"}

For matrices of size greater than one, the determinant is not generally a
linear function of the entire matrix.  In particular,

$$
\det(A+B)\ne\det(A)+\det(B)
$$

in general.  The determinant is linear in **one column at a time** while all
the other columns remain fixed.

:::

## Summary

Row replacements preserve a determinant, row interchanges change its sign,
and row scaling changes its magnitude by the same factor.  These rules make
elimination an efficient determinant method when every interchange and scale
factor is recorded.  A determinant also detects invertibility, is unchanged
by transposition, multiplies across matrix products, and is linear in each
column separately.
