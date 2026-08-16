---
title       : Elimination Matrices
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-08-16
---

Row reduction can be understood as matrix multiplication. Each elementary row
operation corresponds to an **elementary matrix**, and multiplying a matrix on
the left by that elementary matrix performs the row operation

An elementary matrix is produced by applying a single row operation to an
identity matrix. This connects the computational steps of elimination with
ordinary matrix multiplication

Consider

$$
A=
\begin{bmatrix}
1 & 3 \\
2 & 7
\end{bmatrix}
$$

We want to find $A^{-1}$ by reducing $A$ to the identity. This is the same idea
used in the augmented-matrix method

$$
\left[A\mid I_2\right]
\longrightarrow
\left[I_2\mid A^{-1}\right]
$$

Here, however, we will write each row operation explicitly as a matrix
multiplication

## The first elimination matrix

The first row operation eliminates the $2$ below the leading entry in the
first column

$$
R_2\leftarrow R_2-2R_1
$$

Apply this operation to the identity matrix to obtain the first elimination
matrix

$$
E_1=
\begin{bmatrix}
1 & 0 \\
-2 & 1
\end{bmatrix}
$$

The first row of $E_1$ leaves row one unchanged. Its second row forms
$-2R_1+R_2$, exactly reproducing the desired row operation when $E_1$ is
multiplied by $A$

$$
\begin{aligned}
E_1A
&=
\begin{bmatrix}
1 & 0 \\
-2 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 3 \\
2 & 7
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
1 & 3 \\
-2+2 & -6+7
\end{bmatrix}
=
\begin{bmatrix}
1 & 3 \\
0 & 1
\end{bmatrix}
\end{aligned}
$$

## The second elimination matrix

The next operation eliminates the $3$ above the second pivot

$$
R_1\leftarrow R_1-3R_2
$$

Applying this operation to $I_2$ gives

$$
E_2=
\begin{bmatrix}
1 & -3 \\
0 & 1
\end{bmatrix}
$$

Multiplying the partially reduced matrix by $E_2$ completes the reduction

$$
\begin{aligned}
E_2(E_1A)
&=
\begin{bmatrix}
1 & -3 \\
0 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 3 \\
0 & 1
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
=I_2
\end{aligned}
$$

## Recovering the inverse

The two elimination steps give

$$
E_2E_1A=I_2
$$

By the definition of an inverse, the matrix multiplying $A$ on the left must
be $A^{-1}$. Therefore

$$
\begin{aligned}
A^{-1}
&=E_2E_1 \\
&=
\begin{bmatrix}
1 & -3 \\
0 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 0 \\
-2 & 1
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
7 & -3 \\
-2 & 1
\end{bmatrix}
\end{aligned}
$$

The multiplication order is important. Since $E_1$ acts on $A$ first and
$E_2$ acts second, the combined transformation is $E_2E_1A$. The most recent
operation appears closest to the left

As a check

$$
\begin{aligned}
A^{-1}A
&=
\begin{bmatrix}
7 & -3 \\
-2 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 3 \\
2 & 7
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
=I_2
\end{aligned}
$$
