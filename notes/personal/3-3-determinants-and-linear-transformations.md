---
title       : Determinants and Linear Transformations
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition
author      : Jon Leithe
date        : 2026-09-17
---

A determinant does more than measure the area of one particular
parallelogram or the volume of one particular parallelepiped. It gives the
scale factor for the area or volume of every suitable region under the linear
transformation $\vec{x}\mapsto A\vec{x}$.

This is the geometric role of a determinant: $|\det(A)|$ measures how much a
linear transformation stretches, compresses, or collapses space. The sign of
$\det(A)$ still records orientation, but geometric area and volume use its
absolute value.

## Area and volume scale factors

::: {#nte-linear-transformation-area-volume .callout-note title="Theorem 10: Area and Volume Under Linear Transformations"}

Let $T\colon\mathbb{R}^2\to\mathbb{R}^2$ be the linear transformation
determined by a $2\times2$ matrix $A$. If $S$ is a parallelogram in
$\mathbb{R}^2$, then

$$
\operatorname{area}(T(S))=|\det(A)|\operatorname{area}(S).
$$

Let $T\colon\mathbb{R}^3\to\mathbb{R}^3$ be determined by a $3\times3$
matrix $A$. If $S$ is a parallelepiped in $\mathbb{R}^3$, then

$$
\operatorname{volume}(T(S))=|\det(A)|\operatorname{volume}(S).
$$

:::

If $|\det(A)|>1$, the transformation enlarges every such area or volume. If
$0<|\det(A)|<1$, it compresses them. When $\det(A)=0$, the transformation
collapses the relevant dimension, so every two-dimensional area or
three-dimensional volume becomes zero.

### Proof for a parallelogram at the origin

First consider a parallelogram at the origin with edge vectors
$\vec{b}_1$ and $\vec{b}_2$:

$$
S=
\left\{
s_1\vec{b}_1+s_2\vec{b}_2
\mathrel{}\middle|\mathrel{}
0\le s_1\le1,\ 0\le s_2\le1
\right\}.
$$

Let

$$
B=[\vec{b}_1\ \vec{b}_2].
$$

By linearity, every point of the image has the form

$$
\begin{aligned}
T(s_1\vec{b}_1+s_2\vec{b}_2)
&=s_1T(\vec{b}_1)+s_2T(\vec{b}_2)\\
&=s_1A\vec{b}_1+s_2A\vec{b}_2.
\end{aligned}
$$

Thus, $T(S)$ is the parallelogram determined by the columns of

$$
[A\vec{b}_1\ A\vec{b}_2]=AB.
$$

By [Determinants as Area or Volume](3-3-determinants-as-area-or-volume.md),

$$
\begin{aligned}
\operatorname{area}(T(S))
&=|\det(AB)|\\
&=|\det(A)|\,|\det(B)|\\
&=|\det(A)|\operatorname{area}(S).
\end{aligned}
$$

The same argument in $\mathbb{R}^3$ gives the volume formula for a
parallelepiped.

### Parallelograms away from the origin

An arbitrary parallelogram is a translation of one at the origin. Write it
as $\vec{p}+S$, where $S$ is a parallelogram at the origin. Linearity gives

$$
T(\vec{p}+S)=T(\vec{p})+T(S).
$$

The right-hand side is a translation of $T(S)$, and translation does not
change area. Therefore the formula holds for every parallelogram, not only
for those with a vertex at the origin.

## Example: area of an ellipse

Let $a$ and $b$ be positive numbers. Find the area of the region $E$ bounded
by the ellipse

$$
\frac{x_1^2}{a^2}+\frac{x_2^2}{b^2}=1.
$$

Start with the unit disk

$$
D=
\left\{
\begin{bmatrix}u_1\\u_2\end{bmatrix}
\mathrel{}\middle|\mathrel{}
u_1^2+u_2^2\le1
\right\},
$$

whose area is $\pi$. Define

$$
A=
\begin{bmatrix}a&0\\0&b\end{bmatrix},
\qquad
T(\vec{u})=A\vec{u}.
$$

For $\vec{x}=A\vec{u}$,

$$
x_1=au_1,
\qquad
x_2=bu_2.
$$

Since $a,b>0$,

$$
u_1^2+u_2^2\le1
\quad\Longleftrightarrow\quad
\frac{x_1^2}{a^2}+\frac{x_2^2}{b^2}\le1.
$$

Thus, $E=T(D)$. The determinant is $\det(A)=ab$, so Theorem 10 gives

$$
\operatorname{area}(E)
=|\det(A)|\operatorname{area}(D)
=ab\pi.
$$

The familiar ellipse-area formula $\pi ab$ is therefore a direct consequence
of determinant scaling.

## Summary

For a linear transformation determined by $A$, the magnitude $|\det(A)|$ is
the area or volume scale factor. This result extends the geometric meaning of
determinants from individual parallelograms and parallelepipeds to the effect
of a transformation on entire regions.

For the definition and elementary properties of linear transformations, see
[Linear Transformations](1-8-linear-transformations.md).
