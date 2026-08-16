---
title       : Inverses
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-08-16
---

An inverse matrix reverses the transformation performed by a matrix. This is
the matrix analogue of multiplying a nonzero scalar by its reciprocal

An $n\times n$ matrix $A$ is **invertible** if there is an $n\times n$ matrix
$C$ such that

$$
CA=I_n
\qquad\text{and}\qquad
AC=I_n
$$

Here, $I_n$ is the $n\times n$ identity matrix. If such a matrix $C$ exists,
it is unique and is denoted by $A^{-1}$. Therefore

$$
A^{-1}A=I_n
\qquad\text{and}\qquad
AA^{-1}=I_n
$$

A matrix that is not invertible is called **singular**. An invertible matrix
is also called **nonsingular**

## Verifying an inverse

Consider the matrices

$$
A=
\begin{bmatrix}
2 & 5 \\
-3 & -7
\end{bmatrix}
\qquad
C=
\begin{bmatrix}
-7 & -5 \\
3 & 2
\end{bmatrix}
$$

To verify that $C$ is the inverse of $A$, both multiplication orders must give
the identity matrix

$$
\begin{aligned}
AC
&=
\begin{bmatrix}
2 & 5 \\
-3 & -7
\end{bmatrix}
\begin{bmatrix}
-7 & -5 \\
3 & 2
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
-14+15 & -10+10 \\
21-21 & 15-14
\end{bmatrix}
=
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
=I_2
\end{aligned}
$$

Similarly

$$
\begin{aligned}
CA
&=
\begin{bmatrix}
-7 & -5 \\
3 & 2
\end{bmatrix}
\begin{bmatrix}
2 & 5 \\
-3 & -7
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
-14+15 & -35+35 \\
6-6 & 15-14
\end{bmatrix}
=
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
=I_2
\end{aligned}
$$

Since $AC=CA=I_2$, it follows that

$$
C=A^{-1}
$$

## Inverse of a two-by-two matrix

For a matrix

$$
A=
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}
$$

the determinant is

$$
\det(A)=ad-bc
$$

If $ad-bc\neq 0$, then $A$ is invertible and

$$
A^{-1}
=
\frac{1}{ad-bc}
\begin{bmatrix}
d & -b \\
-c & a
\end{bmatrix}
$$

If $ad-bc=0$, division by the determinant is impossible and $A$ is singular

<!-- pagebreak -->

## Solving a linear system with an inverse

If $A$ is invertible, then the equation

$$
A\vec{x}=\vec{b}
$$

has a unique solution for every $\vec{b}\in\mathbb{R}^n$. Multiplying both
sides on the left by $A^{-1}$ gives

$$
\begin{aligned}
A^{-1}A\vec{x} &= A^{-1}\vec{b} \\
I_n\vec{x} &= A^{-1}\vec{b} \\
\vec{x} &= A^{-1}\vec{b}
\end{aligned}
$$

Consider the system

$$
\begin{aligned}
3x_1+4x_2 &= 3 \\
5x_1+6x_2 &= 7
\end{aligned}
$$

Its matrix form is

$$
A\vec{x}=\vec{b}
\qquad\text{with}\qquad
A=
\begin{bmatrix}
3 & 4 \\
5 & 6
\end{bmatrix}
\qquad
\vec{b}=
\begin{bmatrix}
3 \\
7
\end{bmatrix}
$$

Using the two-by-two inverse formula

$$
\begin{aligned}
A^{-1}
&=
\frac{1}{3\cdot 6-4\cdot 5}
\begin{bmatrix}
6 & -4 \\
-5 & 3
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
-3 & 2 \\
\frac{5}{2} & -\frac{3}{2}
\end{bmatrix}
\end{aligned}
$$

The solution is therefore

$$
\begin{aligned}
\vec{x}
&=A^{-1}\vec{b} \\
&=
\begin{bmatrix}
-3 & 2 \\
\frac{5}{2} & -\frac{3}{2}
\end{bmatrix}
\begin{bmatrix}
3 \\
7
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
-9+14 \\
\frac{15}{2}-\frac{21}{2}
\end{bmatrix}
=
\begin{bmatrix}
5 \\
-3
\end{bmatrix}
\end{aligned}
$$

## Finding an inverse by row reduction

For larger matrices, an inverse can be found by augmenting $A$ with the
identity matrix

$$
\left[A\mid I_n\right]
$$

Apply row operations until the left side becomes the identity. If this is not
possible, $A$ is singular and has no inverse. If it is possible, the right side
becomes the inverse

$$
\left[A\mid I_n\right]
\longrightarrow
\left[I_n\mid A^{-1}\right]
$$

This works because row operations amount to multiplying by invertible
elementary matrices. If their combined effect changes $A$ into $I_n$, that
same combination is $A^{-1}$

Consider

$$
A=
\begin{bmatrix}
1 & 2 & 0 \\
0 & 1 & 1 \\
1 & 2 & 1
\end{bmatrix}
$$

Begin with the augmented matrix

$$
\left[
\begin{array}{ccc|ccc}
1 & 2 & 0 & 1 & 0 & 0 \\
0 & 1 & 1 & 0 & 1 & 0 \\
1 & 2 & 1 & 0 & 0 & 1
\end{array}
\right]
$$

Eliminate the leading entry in the third row with
$R_3\leftarrow R_3-R_1$

$$
\left[
\begin{array}{ccc|ccc}
1 & 2 & 0 & 1 & 0 & 0 \\
0 & 1 & 1 & 0 & 1 & 0 \\
0 & 0 & 1 & -1 & 0 & 1
\end{array}
\right]
$$

Next use $R_2\leftarrow R_2-R_3$

$$
\left[
\begin{array}{ccc|ccc}
1 & 2 & 0 & 1 & 0 & 0 \\
0 & 1 & 0 & 1 & 1 & -1 \\
0 & 0 & 1 & -1 & 0 & 1
\end{array}
\right]
$$

Finally use $R_1\leftarrow R_1-2R_2$

$$
\left[
\begin{array}{ccc|ccc}
1 & 0 & 0 & -1 & -2 & 2 \\
0 & 1 & 0 & 1 & 1 & -1 \\
0 & 0 & 1 & -1 & 0 & 1
\end{array}
\right]
=
\left[I_3\mid A^{-1}\right]
$$

Therefore

$$
A^{-1}
=
\begin{bmatrix}
-1 & -2 & 2 \\
1 & 1 & -1 \\
-1 & 0 & 1
\end{bmatrix}
$$

As a check

$$
\begin{aligned}
A^{-1}A
&=
\begin{bmatrix}
-1 & -2 & 2 \\
1 & 1 & -1 \\
-1 & 0 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 2 & 0 \\
0 & 1 & 1 \\
1 & 2 & 1
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix}
=I_3
\end{aligned}
$$
