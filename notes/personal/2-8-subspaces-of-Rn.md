---
title       : Subspaces of $\mathbb{R}^n$
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-09-19
---

Subspaces are vector spaces sitting inside a larger vector space. They provide
the language for describing important sets associated with a matrix: the
**column space** contains its attainable outputs, while the **null space**
contains the input directions that it maps to zero.

These notes are based primarily on the handwritten note
[`2-8-subspaces-of-Rn.pdf`](../hand-written/2-8-subspaces-of-Rn.pdf). The
earlier [`column-and-null-space.pdf`](../hand-written/column-and-null-space.pdf)
contributes the sine-and-cosine example and the engineering interpretation.

## What makes a set a subspace?

::: {.callout-note title="Definition — Subspace"}

**Textbook reference:** p.179

Let $H\subseteq\mathbb{R}^n$. Then $H$ is a **subspace of
$\mathbb{R}^n$** if all three conditions hold:

1. $\vec{0}\in H$;
2. if $\vec{u},\vec{v}\in H$, then $\vec{u}+\vec{v}\in H$;
3. if $\vec{u}\in H$ and $c\in\mathbb{R}$, then $c\vec{u}\in H$.

:::

In other words, a subspace contains the zero vector and is closed under vector
addition and scalar multiplication. The other vector-space properties are
already inherited from $\mathbb{R}^n$.

::: {.callout-note title="Example 2 — A line missing the origin"}

A line or plane through the origin is a subspace of $\mathbb{R}^n$. A line or
plane shifted away from the origin is not: it does not contain $\vec{0}$.

:::

### Example 1: every span is a subspace

Let $\vec{v}_1,\ldots,\vec{v}_p\in\mathbb{R}^n$ and define

$$
H=\operatorname{span}\{\vec{v}_1,\ldots,\vec{v}_p\}.
$$

Then $H$ is a subspace of $\mathbb{R}^n$. Indeed, zero coefficients produce
$\vec{0}$. If

$$
\vec{u}=s_1\vec{v}_1+\cdots+s_p\vec{v}_p,
\qquad
\vec{v}=t_1\vec{v}_1+\cdots+t_p\vec{v}_p,
$$

belong to $H$, then

$$
\vec{u}+\vec{v}
=(s_1+t_1)\vec{v}_1+\cdots+(s_p+t_p)\vec{v}_p\in H.
$$

Similarly, for $c\in\mathbb{R}$,

$$
c\vec{u}=(cs_1)\vec{v}_1+\cdots+(cs_p)\vec{v}_p\in H.
$$

This observation is useful throughout linear algebra: whenever a set is
defined as the span of vectors, it is automatically a subspace.

### Example 3: span notation for several vectors

For vectors $\vec{v}_1,\ldots,\vec{v}_p\in\mathbb{R}^n$, the set of all
their linear combinations is written

$$
\operatorname{span}\{\vec{v}_1,\ldots,\vec{v}_p\}.
$$

Example 1 proves the case of two vectors; the same coefficient argument shows
that this span is a subspace for any finite number of vectors.

### Example: a subspace of functions

The same test works in vector spaces other than $\mathbb{R}^n$. For a fixed
angular frequency $\omega$, consider

$$
H=\{f:f(t)=c_1\cos(\omega t)+c_2\sin(\omega t),
\quad c_1,c_2\in\mathbb{R}\}.
$$

The zero function occurs when $c_1=c_2=0$. If $f$ and $g$ have coefficients
$(a_1,a_2)$ and $(b_1,b_2)$, respectively, then

$$
\begin{aligned}
(f+g)(t)&=(a_1+b_1)\cos(\omega t)+(a_2+b_2)\sin(\omega t),\\
(cf)(t)&=(ca_1)\cos(\omega t)+(ca_2)\sin(\omega t).
\end{aligned}
$$

Both results remain in $H$, so $H$ is a subspace of the real-valued functions
on $\mathbb{R}$. In signal terms, adding or scaling sinusoidal signals of one
frequency cannot create a different frequency.

## Bases for subspaces

::: {.callout-note title="Definition — Basis for a subspace"}

**Textbook reference:** p.181

A **basis** for a subspace $H\subseteq\mathbb{R}^n$ is a linearly independent
set in $H$ that spans $H$.

:::

Thus a basis gives exactly the directions needed to construct every vector in
the subspace, with no redundant direction.

The standard basis for $\mathbb{R}^n$ is

$$
\{\vec{e}_1,\ldots,\vec{e}_n\},
$$

where $\vec{e}_i$ has a $1$ in position $i$ and zeros elsewhere.

### Example 5: the standard basis for $\mathbb{R}^3$

$$
\vec{e}_1=\begin{bmatrix}1\\0\\0\end{bmatrix},\qquad
\vec{e}_2=\begin{bmatrix}0\\1\\0\end{bmatrix},\qquad
\vec{e}_3=\begin{bmatrix}0\\0\\1\end{bmatrix}
$$

form a basis for $\mathbb{R}^3$. The columns of an invertible $n\times n$
matrix likewise form a basis for $\mathbb{R}^n$.

## Column space: all attainable outputs

Let $A\in\mathbb{R}^{m\times n}$ have columns
$\vec{a}_1,\ldots,\vec{a}_n\in\mathbb{R}^m$. Matrix multiplication is a
linear combination of its columns:

$$
A\vec{x}=x_1\vec{a}_1+\cdots+x_n\vec{a}_n.
$$

::: {.callout-note title="Definition — Column space"}

**Textbook reference:** p.180

The **column space** of $A$ is

$$
\operatorname{Col}(A)
=\operatorname{span}\{\vec{a}_1,\ldots,\vec{a}_n\}
=\{A\vec{x}:\vec{x}\in\mathbb{R}^n\}.
$$

:::

It is a subspace of $\mathbb{R}^m$, because it is the span of the columns of
$A$. Notice the ambient space: an $m\times n$ matrix produces vectors with
$m$ entries, so its column space lies in $\mathbb{R}^m$.

::: {.callout-note title="Column space and consistency"}

The system $A\vec{x}=\vec{b}$ is consistent if and only if
$\vec{b}\in\operatorname{Col}(A)$.

:::

A solution supplies the weights that combine the columns of $A$ into
$\vec{b}$. To test membership, row-reduce the augmented matrix
$[A\mid\vec{b}]$ and check for an inconsistent row.

### Example 4: testing whether an output is attainable

Let

$$
A=\begin{bmatrix}1&-3&-4\\-4&6&-2\\-3&7&6\end{bmatrix},
\qquad
\vec{b}=\begin{bmatrix}3\\3\\-4\end{bmatrix}.
$$

Row reduction gives

$$
\operatorname{rref}([A\mid\vec{b}])=
\left[\begin{array}{ccc|c}
1&0&5&-9/2\\
0&1&3&-5/2\\
0&0&0&0
\end{array}\right].
$$

There is no inconsistent row, so $\vec{b}\in\operatorname{Col}(A)$. Taking
the free variable $x_3=0$ gives one explicit combination:

$$
-\frac92\begin{bmatrix}1\\-4\\-3\end{bmatrix}
-\frac52\begin{bmatrix}-3\\6\\7\end{bmatrix}
=\begin{bmatrix}3\\3\\-4\end{bmatrix}.
$$

### Example 8: finding a basis for the column space

::: {.callout-note title="Theorem 13 — Pivot columns form a column-space basis"}

**Textbook reference:** p.183

Find the pivot-column indices by row-reducing $A$. The columns with those
indices in the **original matrix** form a basis for $\operatorname{Col}(A)$.

:::

Row operations preserve linear dependence relations among the columns, so
they correctly reveal the pivot indices. They generally change the column
space itself, however; this is why the basis vectors must be taken from the
original matrix rather than its reduced form.

For example, let

$$
A=\begin{bmatrix}
1&3&3&2&-9\\
-2&-2&2&-8&2\\
2&3&0&7&1\\
3&4&-1&11&-8
\end{bmatrix}.
$$

Its reduced row-echelon form is

$$
\operatorname{rref}(A)=
\begin{bmatrix}
1&0&-3&5&0\\
0&1&2&-1&0\\
0&0&0&0&1\\
0&0&0&0&0
\end{bmatrix}.
$$

The pivot columns are $1$, $2$, and $5$. Therefore,

$$
\left\{
\begin{bmatrix}1\\-2\\2\\3\end{bmatrix},
\begin{bmatrix}3\\-2\\3\\4\end{bmatrix},
\begin{bmatrix}-9\\2\\1\\-8\end{bmatrix}
\right\}
$$

is a basis for $\operatorname{Col}(A)$.

## Null space: inputs sent to zero

::: {.callout-note title="Definition — Null space"}

**Textbook reference:** p.181

For $A\in\mathbb{R}^{m\times n}$, the **null space** is

$$
\operatorname{Nul}(A)=\{\vec{x}\in\mathbb{R}^n:A\vec{x}=\vec{0}\}.
$$

:::

It contains input vectors, so $\operatorname{Nul}(A)\subseteq\mathbb{R}^n$.
In contrast, $\operatorname{Col}(A)\subseteq\mathbb{R}^m$. These spaces need
not even have the same ambient dimension.

::: {.callout-note title="Theorem 12 — The null space is a subspace"}

**Textbook reference:** p.181

For every $m\times n$ matrix $A$, $\operatorname{Nul}(A)$ is a subspace of
$\mathbb{R}^n$.

:::

**Proof.** We have $A\vec{0}=\vec{0}$, so the zero vector is in the null
space. If $A\vec{u}=\vec{0}$ and $A\vec{v}=\vec{0}$, then

$$
A(\vec{u}+\vec{v})=A\vec{u}+A\vec{v}=\vec{0}.
$$

For a scalar $c$,

$$
A(c\vec{u})=c(A\vec{u})=\vec{0}.
$$

The three subspace conditions hold.

### Example 6: finding a null-space basis

To determine $\operatorname{Nul}(A)$, row-reduce $A$, identify the free
variables, and write the solution of $A\vec{x}=\vec{0}$ in parametric vector
form. The vectors multiplying the free parameters form a basis for the null
space. If there are no free variables, the null space is $\{\vec{0}\}$ and
its basis is the empty set.

Consider

$$
A=\begin{bmatrix}
-3&6&-1&1&-7\\
1&-2&2&3&-1\\
2&-4&5&8&-4
\end{bmatrix}.
$$

Row reduction gives

$$
\operatorname{rref}(A)=
\begin{bmatrix}
1&-2&0&-1&3\\
0&0&1&2&-2\\
0&0&0&0&0
\end{bmatrix}.
$$

The pivot variables are $x_1$ and $x_3$. Set the free variables to
$x_2=r$, $x_4=s$, and $x_5=t$. Then

$$
x_1=2r+s-3t,
\qquad
x_3=-2s+2t,
$$

so

$$
\vec{x}
=r\begin{bmatrix}2\\1\\0\\0\\0\end{bmatrix}
+s\begin{bmatrix}1\\0\\-2\\1\\0\end{bmatrix}
+t\begin{bmatrix}-3\\0\\2\\0\\1\end{bmatrix}.
$$

Consequently,

$$
\operatorname{Nul}(A)=
\operatorname{span}\left\{
\begin{bmatrix}2\\1\\0\\0\\0\end{bmatrix},
\begin{bmatrix}1\\0\\-2\\1\\0\end{bmatrix},
\begin{bmatrix}-3\\0\\2\\0\\1\end{bmatrix}
\right\}.
$$

## Engineering interpretation

If $A$ maps actuator commands to a resulting force, its column space is the
set of forces the actuators can generate. A null-space vector is a combination
of commands whose resulting force is zero within that linear model.

More generally, if $\vec{x}_p$ is one solution of $A\vec{x}=\vec{b}$, then
every solution has the form

$$
\vec{x}=\vec{x}_p+\vec{z},
\qquad \vec{z}\in\operatorname{Nul}(A).
$$

Adding $\vec{z}$ leaves the output unchanged, because $A\vec{z}=\vec{0}$.
Thus the column space answers whether an output is attainable, while the null
space describes the freedom in choosing an input that produces it.

The next note, [Dimension and Rank](2-9-dimension-and-rank.md), develops how
the dimensions of these two spaces account for all input directions.

## Summary

| Question | Method |
|---|---|
| Is a set a subspace? | Check zero, closure under addition, and closure under scalar multiplication. |
| Find a basis for $\operatorname{Col}(A)$ | Find pivot indices; select the corresponding columns of the original $A$. |
| Is $\vec{b}\in\operatorname{Col}(A)$? | Check whether $A\vec{x}=\vec{b}$ is consistent. |
| Find a basis for $\operatorname{Nul}(A)$ | Solve $A\vec{x}=\vec{0}$ in parametric vector form. |
