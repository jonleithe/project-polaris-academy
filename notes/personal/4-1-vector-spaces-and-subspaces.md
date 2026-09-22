---
title       : Vector Spaces and Subspaces
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition
author      : Jon Leithe
date        : 2026-09-22
---

Linear algebra becomes more useful when its ideas are separated from ordinary
arrows in two or three dimensions. A **vector space** is any collection of
objects that can be added and scaled while obeying the same consistent rules.
The objects may be coordinate vectors, polynomials, signals, or matrices.

These notes are based on the handwritten note
[`4-1-vector-spaces-and-subspaces.pdf`](../hand-written/4-1-vector-spaces-and-subspaces.pdf).

## Vector spaces

::: {.callout-note title="Definition — Vector space"}

**Textbook reference:** pp.226–227

A **vector space** is a nonempty set $V$ of objects, called vectors, on which
vector addition and multiplication by real scalars are defined. For all
$\vec{u},\vec{v},\vec{w}\in V$ and all scalars $c,d\in\mathbb{R}$, the
following ten axioms hold:

1. $\vec{u}+\vec{v}\in V$.
2. $\vec{u}+\vec{v}=\vec{v}+\vec{u}$.
3. $(\vec{u}+\vec{v})+\vec{w}=\vec{u}+(\vec{v}+\vec{w})$.
4. There is a zero vector $\vec{0}\in V$ such that
   $\vec{u}+\vec{0}=\vec{u}$.
5. For every $\vec{u}\in V$, there is a vector $-\vec{u}\in V$ such that
   $\vec{u}+(-\vec{u})=\vec{0}$.
6. $c\vec{u}\in V$.
7. $c(\vec{u}+\vec{v})=c\vec{u}+c\vec{v}$.
8. $(c+d)\vec{u}=c\vec{u}+d\vec{u}$.
9. $c(d\vec{u})=(cd)\vec{u}$.
10. $1\vec{u}=\vec{u}$.

:::

The familiar space $\mathbb{R}^n$ satisfies these axioms. The same reasoning
also applies to less visual spaces, such as sampled signals or polynomials.

## Subspaces

A **subspace** is a vector space contained inside another vector space. The
ambient vector space already supplies the ten axioms, so only three properties
need to be checked.

::: {.callout-note title="Definition — Subspace"}

**Textbook reference:** p.229

A subset $H$ of a vector space $V$ is a **subspace of $V$** if:

1. $\vec{0}\in H$;
2. for every $\vec{u},\vec{v}\in H$, the sum
   $\vec{u}+\vec{v}\in H$;
3. for every $\vec{u}\in H$ and every scalar $c$,
   $c\vec{u}\in H$.

:::

The origin is essential. A plane in $\mathbb{R}^3$ that does not pass through
the origin is not a subspace because it fails the first condition. Likewise, a
line in $\mathbb{R}^2$ that misses the origin is not a subspace.

## A subspace spanned by a set

::: {.callout-note title="Theorem 1 — Every span is a subspace"}

If $\vec{v}_1,\ldots,\vec{v}_p$ belong to a vector space $V$, then

$$
\operatorname{span}\{\vec{v}_1,\ldots,\vec{v}_p\}
$$

is a subspace of $V$.

:::

To see why, first note that zero coefficients produce $\vec{0}$. Let

$$
\vec{u}=s_1\vec{v}_1+\cdots+s_p\vec{v}_p,
\qquad
\vec{w}=t_1\vec{v}_1+\cdots+t_p\vec{v}_p
$$

be vectors in the span. Then

$$
\vec{u}+\vec{w}
=(s_1+t_1)\vec{v}_1+\cdots+(s_p+t_p)\vec{v}_p,
$$

which is another vector in the span. For any scalar $c$,

$$
c\vec{u}=(cs_1)\vec{v}_1+\cdots+(cs_p)\vec{v}_p
$$

is also in the span. Thus all three subspace conditions hold.

### Example 11: a span of two vectors

Let

$$
H=\operatorname{span}\{\vec{v}_1,\vec{v}_2\}.
$$

Every vector in $H$ is a linear combination of $\vec{v}_1$ and
$\vec{v}_2$. The argument above proves that $H$ is a subspace of the ambient
space $V$. Geometrically, if the two vectors are independent in
$\mathbb{R}^3$, their span is a plane through the origin.

### Example 12: recognizing a subspace from its description

Let $H$ be the set of all vectors of the form

$$
H=
\left\{
\begin{bmatrix}
a-3b\\
b-a\\
a\\
b
\end{bmatrix}
:a,b\in\mathbb{R}
\right\}.
$$

Writing a general vector as a linear combination gives

$$
\begin{bmatrix}
a-3b\\
b-a\\
a\\
b
\end{bmatrix}
=
a\begin{bmatrix}1\\-1\\1\\0\end{bmatrix}
+b\begin{bmatrix}-3\\1\\0\\1\end{bmatrix}.
$$

Therefore,

$$
H=
\operatorname{span}\left\{
\begin{bmatrix}1\\-1\\1\\0\end{bmatrix},
\begin{bmatrix}-3\\1\\0\\1\end{bmatrix}
\right\}.
$$

By Theorem 1, $H$ is a subspace of $\mathbb{R}^4$.

## Testing whether a vector lies in a span

To determine whether a vector $\vec{y}$ belongs to
$\operatorname{span}\{\vec{v}_1,\ldots,\vec{v}_p\}$, solve

$$
x_1\vec{v}_1+\cdots+x_p\vec{v}_p=\vec{y}.
$$

Equivalently, row-reduce the augmented matrix

$$
\left[
\begin{array}{cccc|c}
\vec{v}_1 & \vec{v}_2 & \cdots & \vec{v}_p & \vec{y}
\end{array}
\right].
$$

### Example 13: a membership condition

For which values of $h$ is

$$
\vec{y}=
\begin{bmatrix}-4\\3\\h\end{bmatrix}
$$

in the subspace of $\mathbb{R}^3$ spanned by

$$
\vec{v}_1=
\begin{bmatrix}1\\-1\\-2\end{bmatrix},
\qquad
\vec{v}_2=
\begin{bmatrix}5\\-4\\-7\end{bmatrix},
\qquad
\vec{v}_3=
\begin{bmatrix}-3\\1\\0\end{bmatrix}?
$$

Row-reducing the augmented matrix gives

$$
\begin{aligned}
\left[
\begin{array}{ccc|c}
1&5&-3&-4\\
-1&-4&1&3\\
-2&-7&0&h
\end{array}
\right]
&\xrightarrow[\displaystyle R_3\leftarrow R_3+2R_1]
{\displaystyle R_2\leftarrow R_2+R_1}
\left[
\begin{array}{ccc|c}
1&5&-3&-4\\
0&1&-2&-1\\
0&3&-6&h-8
\end{array}
\right] \\
&\xrightarrow{\displaystyle R_3\leftarrow R_3-3R_2}
\left[
\begin{array}{ccc|c}
1&5&-3&-4\\
0&1&-2&-1\\
0&0&0&h-5
\end{array}
\right].
\end{aligned}
$$

The system is consistent precisely when $h-5=0$. Therefore,

$$
\vec{y}\in\operatorname{span}\{\vec{v}_1,\vec{v}_2,\vec{v}_3\}
\qquad\Longleftrightarrow\qquad h=5.
$$

## Engineering interpretation

A vector space describes all allowable signals or states under a chosen linear
model. A subspace describes a restricted family that remains meaningful after
signals are added or scaled. For example, the span of a set of vibration modes
contains every response constructed from those modes, while the membership
test determines whether a measured response can be represented by them.

## Summary

- A vector space is closed under addition and scalar multiplication and
  satisfies the ten vector-space axioms.
- A subspace contains zero and is closed under addition and scalar
  multiplication.
- The span of any finite set of vectors is a subspace.
- Membership in a span is tested by solving a matrix equation or row-reducing
  an augmented matrix.
