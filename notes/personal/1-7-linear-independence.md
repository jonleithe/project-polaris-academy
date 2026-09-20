---
title       : Linear Independence
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition, [Khan Academy — Linear Dependence and Independence](https://www.khanacademy.org/math/linear-algebra)
author      : Jon Leithe
date        : 2026-09-20
---

Linear independence tells us whether a set of vectors contains genuinely new
directions or redundant ones. A dependent set has at least one vector that can
be reconstructed from the others; an independent set does not.

These notes are based on the handwritten note
[`1-7-linear-independence.pdf`](../hand-written/1-7-linear-independence.pdf).

## Definition

::: {.callout-note title="Linear independence and dependence"}

**Textbook reference:** p.84

An indexed set $S=\{\vec{v}_1,\ldots,\vec{v}_p\}$ in
$\mathbb{R}^n$ is **linearly independent** if the vector equation

$$
x_1\vec{v}_1+x_2\vec{v}_2+\cdots+x_p\vec{v}_p=\vec{0}
$$

has only the **trivial solution**

$$
x_1=x_2=\cdots=x_p=0.
$$

The set is **linearly dependent** if there are scalars
$c_1,\ldots,c_p$, not all zero, such that

$$
c_1\vec{v}_1+c_2\vec{v}_2+\cdots+c_p\vec{v}_p=\vec{0}.
$$

This last equation is a **linear dependence relation** among the vectors.

:::

## Recognizing dependent sets

::: {.callout-note title="Theorem 7 — Characterization of linearly dependent sets"}

**Textbook reference:** p.86

An indexed set $S=\{\vec{v}_1,\ldots,\vec{v}_p\}$ of two or more vectors
is linearly dependent if and only if at least one vector in $S$ is a linear
combination of the others. Moreover, if $S$ is linearly dependent and
$\vec{v}_1\ne\vec{0}$, then some $\vec{v}_j$ with $j>1$ is a linear
combination of the preceding vectors
$\vec{v}_1,\ldots,\vec{v}_{j-1}$.

:::

::: {.callout-note title="Theorem 8 — Too many vectors imply dependence"}

**Textbook reference:** p.87

Any set $\{\vec{v}_1,\ldots,\vec{v}_p\}$ in $\mathbb{R}^n$ is linearly
dependent if $p>n$.

:::

::: {.callout-note title="Theorem 9 — The zero vector implies dependence"}

**Textbook reference:** p.87

If a set $S=\{\vec{v}_1,\ldots,\vec{v}_p\}$ in $\mathbb{R}^n$ contains
the zero vector, then $S$ is linearly dependent.

:::

## Matrix interpretation

Let $A=[\vec{a}_1\ \cdots\ \vec{a}_n]$. Its columns are linearly
independent if and only if the homogeneous equation

$$
A\vec{x}=\vec{0}
$$

has only the trivial solution. This follows directly from the column form of
matrix-vector multiplication:

$$
A\vec{x}=x_1\vec{a}_1+\cdots+x_n\vec{a}_n.
$$

## Examples

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

### Independent set

As an example of a linearly independent set, suppose we have:

$$
\vec{a}
=
\begin{bmatrix}
1 \\ 0
\end{bmatrix}
,
\vec{b}
=
\begin{bmatrix}
0 \\ 1
\end{bmatrix}
$$

$$
U
=
\left\{
\vec{a},
\vec{b}
\right\}
$$

To determine whether $U$ is linearly independent, we set a linear combination of its vectors equal to the zero vector:

$$
c_1\vec{a}+c_2\vec{b}=\vec{0}
$$

Substituting the vectors gives:

$$
c_1
\begin{bmatrix}
1 \\ 0
\end{bmatrix}
+
c_2
\begin{bmatrix}
0 \\ 1
\end{bmatrix}
=
\begin{bmatrix}
c_1 \\ c_2
\end{bmatrix}
=
\begin{bmatrix}
0 \\ 0
\end{bmatrix}
$$

The only solution is $c_1=c_2=0$. Therefore, the set $U$ is linearly independent.
