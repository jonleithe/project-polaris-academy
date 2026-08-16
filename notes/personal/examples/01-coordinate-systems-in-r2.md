---
title       : Coordinate Systems in R²
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-08-16
---

A vector is a geometric object, while its coordinates depend on the basis used
to describe it. Changing the basis changes the coordinate values, but it does
not change the vector itself

Let

$$
\vec{b}_1=
\begin{bmatrix}
1 \\
-2
\end{bmatrix}
\qquad
\vec{b}_2=
\begin{bmatrix}
5 \\
-6
\end{bmatrix}
\qquad
B=\left\{\vec{b}_1,\vec{b}_2\right\}
$$

The vectors $\vec{b}_1$ and $\vec{b}_2$ are linearly independent, so $B$ is a
basis for $\mathbb{R}^2$

Consider the vector whose coordinates relative to the standard basis
$\mathcal{S}$ are

$$
\left[\vec{x}\right]_{\mathcal{S}}
=
\begin{bmatrix}
4 \\
0
\end{bmatrix}
$$

Because $\mathcal{S}$ is the standard basis, these coordinates describe the
familiar vector from the origin to the point $(4,0)$

Our goal is to find the coordinates of the same vector relative to $B$

$$
\left[\vec{x}\right]_B
=
\begin{bmatrix}
c_1 \\
c_2
\end{bmatrix}
$$

## Coordinates relative to a basis

If $V$ is a vector space and

$$
B=\left\{\vec{b}_1,\vec{b}_2,\ldots,\vec{b}_n\right\}
$$

is a basis for $V$, then every vector $\vec{x}\in V$ has a unique
representation

$$
\vec{x}
=
c_1\vec{b}_1
+
c_2\vec{b}_2
+
\cdots
+
c_n\vec{b}_n
$$

The scalars in this representation form the coordinate vector of $\vec{x}$
relative to $B$

$$
\left[\vec{x}\right]_B
=
\begin{bmatrix}
c_1 \\
c_2 \\
\vdots \\
c_n
\end{bmatrix}
$$

For the present example, we seek $c_1$ and $c_2$ such that

$$
c_1
\begin{bmatrix}
1 \\
-2
\end{bmatrix}
+
c_2
\begin{bmatrix}
5 \\
-6
\end{bmatrix}
=
\begin{bmatrix}
4 \\
0
\end{bmatrix}
$$

## Direct solution by row reduction

The vector equation gives the augmented matrix

$$
\left[
\begin{array}{cc|c}
1 & 5 & 4 \\
-2 & -6 & 0
\end{array}
\right]
$$

First use $R_2\leftarrow R_2+2R_1$

$$
\left[
\begin{array}{cc|c}
1 & 5 & 4 \\
0 & 4 & 8
\end{array}
\right]
$$

Scale the second row with $R_2\leftarrow\frac{1}{4}R_2$

$$
\left[
\begin{array}{cc|c}
1 & 5 & 4 \\
0 & 1 & 2
\end{array}
\right]
$$

Finally use $R_1\leftarrow R_1-5R_2$

$$
\left[
\begin{array}{cc|c}
1 & 0 & -6 \\
0 & 1 & 2
\end{array}
\right]
$$

Therefore, the coordinates of $\vec{x}$ relative to $B$ are

$$
\left[\vec{x}\right]_B
=
\begin{bmatrix}
-6 \\
2
\end{bmatrix}
$$

These coordinates mean that the original vector is

$$
\vec{x}=-6\vec{b}_1+2\vec{b}_2
$$

We can see the geometry by evaluating the two scaled basis vectors

$$
-6\vec{b}_1
=
\begin{bmatrix}
-6 \\
12
\end{bmatrix}
\qquad
2\vec{b}_2
=
\begin{bmatrix}
10 \\
-12
\end{bmatrix}
$$

Their sum returns the vector expressed in standard coordinates

$$
-6\vec{b}_1+2\vec{b}_2
=
\begin{bmatrix}
-6 \\
12
\end{bmatrix}
+
\begin{bmatrix}
10 \\
-12
\end{bmatrix}
=
\begin{bmatrix}
4 \\
0
\end{bmatrix}
=\left[\vec{x}\right]_{\mathcal{S}}
$$

## Change-of-coordinate matrix

The same coordinate problem can be expressed as a matrix transformation. Let
$P_B$ be the matrix whose columns are the basis vectors in $B$, written in
standard coordinates

$$
P_B
=
\begin{bmatrix}
\vert & \vert \\
\vec{b}_1 & \vec{b}_2 \\
\vert & \vert
\end{bmatrix}
=
\begin{bmatrix}
1 & 5 \\
-2 & -6
\end{bmatrix}
$$

Multiplying a $B$-coordinate vector by $P_B$ forms the corresponding linear
combination of the basis vectors. It therefore converts $B$-coordinates into
standard coordinates

$$
\left[\vec{x}\right]_{\mathcal{S}}
=
P_B\left[\vec{x}\right]_B
$$

Since $B$ is a basis, $P_B$ is invertible. Multiplying by $P_B^{-1}$ reverses
the coordinate transformation

$$
\left[\vec{x}\right]_B
=
P_B^{-1}\left[\vec{x}\right]_{\mathcal{S}}
$$

## Finding the inverse of the basis matrix

Use Gauss--Jordan elimination on the augmented matrix

$$
\left[P_B\mid I_2\right]
=
\left[
\begin{array}{cc|cc}
1 & 5 & 1 & 0 \\
-2 & -6 & 0 & 1
\end{array}
\right]
$$

After $R_2\leftarrow R_2+2R_1$ and
$R_2\leftarrow\frac{1}{4}R_2$, we have

$$
\left[
\begin{array}{cc|cc}
1 & 5 & 1 & 0 \\
0 & 1 & \frac{1}{2} & \frac{1}{4}
\end{array}
\right]
$$

Using $R_1\leftarrow R_1-5R_2$ completes the reduction

$$
\left[
\begin{array}{cc|cc}
1 & 0 & -\frac{3}{2} & -\frac{5}{4} \\
0 & 1 & \frac{1}{2} & \frac{1}{4}
\end{array}
\right]
=
\left[I_2\mid P_B^{-1}\right]
$$

Thus

$$
P_B^{-1}
=
\begin{bmatrix}
-\frac{3}{2} & -\frac{5}{4} \\
\frac{1}{2} & \frac{1}{4}
\end{bmatrix}
$$

Applying the inverse to the standard-coordinate vector gives

$$
\begin{aligned}
\left[\vec{x}\right]_B
&=
P_B^{-1}\left[\vec{x}\right]_{\mathcal{S}} \\
&=
\begin{bmatrix}
-\frac{3}{2} & -\frac{5}{4} \\
\frac{1}{2} & \frac{1}{4}
\end{bmatrix}
\begin{bmatrix}
4 \\
0
\end{bmatrix}
\\[0.5em]
&=
\begin{bmatrix}
-6 \\
2
\end{bmatrix}
\end{aligned}
$$
