---
title       : Linear Dependence and Independence
course      : Linear Algebra
unit        : 1
provider    : Khan Academy
author      : Jon Leithe
date        : 2026
---

# Linear Dependence and Independence

Source: [Khan Academy — Linear Dependence and Independence](https://www.khanacademy.org/math/linear-algebra)

A set of vectors is linearly dependent if some linear combination of its vectors equals the zero vector using coefficients that are not all zero. It is linearly independent if the only such linear combination uses zero for every coefficient.

The set

$$
S
=
\left\{
\vec v_1, \vec v_2 , \dotsb, \vec v_n
\right\}
$$

is linearly dependent if and only if

$$
c_1\vec v_1+c_2\vec v_2+\dotsb+c_n\vec v_n=\vec{0}
$$

for some $c_1,\dotsc,c_n\in \mathbb{R}$, not all zero. (At least one of the coefficients has to be non-zero).

Suppose we have:

$$
\vec{v}
=
\begin{bmatrix}
2 \\ 3
\end{bmatrix}
,
\vec{w}
=
\begin{bmatrix}
4 \\ 6
\end{bmatrix}
$$

$$
S
=
\left\{
\vec{v}
,
\vec{w}
\right\}
$$

Because $\vec{w}=2\vec{v}$, we have $2\vec{v}-\vec{w}=\vec{0}$. Therefore, the set $S$ is linearly dependent.

Another example would be:

$$
\vec{p}
=
\begin{bmatrix}
2 \\ 3
\end{bmatrix}
,
\vec{q}
=
\begin{bmatrix}
7 \\ 2
\end{bmatrix}
,
\vec{r}
=
\begin{bmatrix}
9 \\ 5
\end{bmatrix}
$$

$$
T
=
\left\{
\vec{p},
\vec{q},
\vec{r}
\right\}
$$

This set is also linearly dependent because $\vec{r}-\vec{q}-\vec{p}=\vec{0}$.

\newpage
