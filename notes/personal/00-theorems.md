---
title       : Theorems
subject     : Linear Algebra
source      : Linear aglebra and Its Applications, 6th edition
isbn        : 1-292-35121-7 / 978-1-292-35121-6
author      : Jon Leithe
date        : 2026-08-16
language:
    callout-note-title: "Theorem"
    crossref-nte-title: "Theorem"
    crossref-nte-prefix: "Theorem"
format:
  html:
    number-sections: false
---

This chapter serves as an index to all the theorems found in the textbook, *6th edition of linear algebra and its applications*. Some of them have explanations, whenever I found it necessary.

![6th edition of linear algebra and its applications](../../images/textbook-cover.png){#fig-vectors-example width=25% fig-pos="H" fig-align="left"}

## Chapter 1.2 – Row Reduction and Echelon Forms

::: {#theorem-1-2-1 .callout-note title="Theorem 1.2.1 — Uniqueness of the Reduced Echelon Form"}

**Textbook reference:** p.38

Each matrix is row equivalent to one and only one reduced echelon matrix.

:::

::: {#theorem-1-2-2 .callout-note title="Theorem 1.2.2 — Existence and Uniqueness Theorem"}

**Textbook reference:** p.46

A linear system is consistent if and only if the rightmost column of the augmented matrix is *not* a pivot column - that is, if and only if an echelon form of the augmented matrix has *no* row on the form

$$
\left[
0 \; \cdots \; 0 \mid b
\right]
\qquad
\text{where } b \ne 0
$$

If a linear system is consistent, then the solution set contains either:

(i) A unique solution, when there are no free variables
(ii) Infinitely many solutions, when there are at least one free variable

::: {.content-visible when-format="html"}

***

:::

::: {.content-visible when-format="pdf"}

\noindent\rule{\linewidth}{0.5pt}

:::

A system of linear equations is said to be **homogeneous** if it can be written on the form $A\vec{x}=\vec{0}$, where $A$ is an $m \times n$ matrix and $\vec{0}$ is the zero vector in $\mathbb{R}^n$. Such a system $A\vec{x}=\vec{0}$ *always* has at least one solution, namely $\vec{x}=\vec{0}$ (the zero vector in $\mathbb{R}^n$). This zero solution is usually called the **trivial solution**. For a given equation $A\vec{x}=\vec{0}$, the important question is whether there exists a **nontrivial solution**, that is, a nonzero vector $\vec{x}$ that satisfies $A\vec{x}=\vec{0}$. [Theorem 1.2.2](#theorem-1-2-2) leads to the following fact:

> The homogeneous equation $A\vec{x}=\vec{0}$ has a nontrivial solution if and only if the equation has at least one free variable.

An indexed set of vectors $\{\vec{v}_1, \cdots, \vec{v}_p\}$ in $\mathbb{R}^n$ are said to be **linearly independent** if the vector equation

$$
x_1\vec{v}_1
+
x_2\vec{v}_2
+
\cdots
+
x_p\vec{v}_p
=
0
$$

has only the trivial solution. The set $\{\vec{v}_1, \cdots, \vec{v}_p\}$ is said to be **linearly dependent** if there exists weights $c_1, \cdots, c_p$, not all zeros, such that

$$
c_1\vec{v}_1
+
c_2\vec{v}_2
+
\cdots
+
c_p\vec{v}_p
=
0
$$

:::

## Chapter 1.4 – The Matrix Equation $A\vec{x}=\vec{b}$

::: {#theorem-1-4-1 .callout-note title="Theorem 1.4.1 — Matrix, Vector, and System Equivalence"}

**Textbook reference:** p.62

If $A$ is an $m \times n$ matrix, with columns $\vec{a}_1, \cdots \vec{a}_n$, and if $\vec{b}$ is in $\mathbb{R}^m$, the matrix equation

$$
A
\vec{x}
=
\vec{b}
$$

has the same solution set as the vector equation

$$
x_1\vec{a}_1
+
x_2\vec{a}_2
+
\cdots
+
x_n\vec{a}_n
=
\vec{b}
$$

which, in turn, has the same solution set as the system of linear equations whose augmented matrix is

$$
\begin{bmatrix}
\vec{a}_1 &
\vec{a}_2 &
\cdots
&
\vec{a}_n
\mid
\vec{b}
\end{bmatrix}
$$

:::

::: {#theorem-1-4-2 .callout-note title="Theorem 1.4.2 — Equivalent Conditions for Spanning $\mathbb{R}^m$"}

**Textbook reference:** p.63

Let $A$ be an $m \times n$ matrix. Then the following statements are logically equivalent. That is, for for a particula $A$, either they are all true statements or they are all false.

a. For each $\vec{b}$ in $\mathbb{R}^m$, the equation $A\vec{x}=\vec{b}$ has a solution.
b. Each $\vec{b}$ in $\mathbb{R}^m$ is a linear combination of the columns of $A$.
c. The columns of $A$ span $\mathbb{R}^m$.
d. $A$ has a pivot position in every row.

:::

::: {#theorem-1-4-3 .callout-note title="Theorem 1.4.3 — Linearity of Matrix-Vector Multiplication"}

**Textbook reference:** p.65

If $A$ is an $m \times n$ matrix, $\vec{u}$ and $\vec{v}$ are vectors in $\mathbb{R}^m$, and $c$ is a scalar, then:

a. $A(\vec{u}+\vec{v}) = A\vec{u}+A\vec{v}$
b. $A(c\vec{u}) = c(A\vec{u})$

:::

## Chapter 1.5 – Solution Sets of Linear Systems

::: {#theorem-1-5-1 .callout-note title="Theorem 1.5.1 — Solution Set of a Consistent Linear System"}

**Textbook reference:** p.73

Suppose the equation $A\vec{x}=\vec{b}$ is consistent for some given $\vec{b}$, and let $\vec{p}$ be a solution. Then the solution set of $A\vec{x}=\vec{b}$ is the set of all vectors of the form $\vec{w}=\vec{p}+\vec{v}_h$, where $\vec{v}_h$ is any solution of the homogenous equation $A\vec{x}=0$.

:::

## Chapter 1.7 – Linear Independence

::: {#theorem-1-7-1 .callout-note title="Theorem 1.7.1 — Characterization of Linearly Dependent Sets"}

**Textbook reference:** p.86

An indexed set $S= \{ \vec{v}_1, \cdots, \vec{v}_p \}$ of two or more vectors is linearly dependent if and only if at least one of the vectors in $S$ is a linear combination of the others. In fact, if $S$ is linearly dependent and $\vec{v}_1 \ne 0$, then some $\vec{v}_j \text{ ( with }j > 1)$ is a linear combination of the preceding vectors, $\vec{v}_1, \cdots, \vec{v}_{j-1}$.

:::

::: {#theorem-1-7-2 .callout-note title="Theorem 1.7.2"}

**Textbook reference:** p.87

If a set contains more vectors than there are entries in each vector, then the set is linearly dependent. That is, any set $\{ \vec{v}_1, \cdots, \vec{v}_p\}$ in $\mathbb{R}^n$ is linearly dependent if $p>n$.

:::

::: {#theorem-1-7-3 .callout-note title="Theorem 1.7.3"}

**Textbook reference:** p.87

 If a set $\{ \vec{v}_1, \cdots, \vec{v}_p\}$ in $\mathbb{R}^n$ contains the zero vector, then the set is linearly dependent.

::: {.content-visible when-format="html"}

***

:::

::: {.content-visible when-format="pdf"}

\noindent\rule{\linewidth}{0.5pt}

:::

 Suppose we have:

 $$
\vec{v}_1
=
\begin{bmatrix}
1 \\
2
\end{bmatrix}
,
\quad
\vec{v}_2
=
\begin{bmatrix}
0 \\
0
\end{bmatrix}
$$

We could write:

$$
0\vec{v}_1
+
1\vec{v}_2
=
\vec{0}
$$

Because one coefficient is nonzero, this is a nontrivial (see [Theorem 1.2.2](#theorem-1-2-2)) linear combination that equals $\vec{0}$. Therefore the set is linearly dependent.

:::

## Chapter 2.2 – The Inverse of a Matrix

::: {#theorem-2-2-4 .callout-note title="Theorem 2.2.4 — Inverse of a Two-by-Two Matrix"}

**Textbook reference:** p.135

**Source note:** [The Inverse of a Matrix](2-2-the-inverse-of-a-matrix.md)

Let

$$
A=
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}.
$$

If $ad-bc\ne0$, then $A$ is invertible and

$$
A^{-1}=
\frac{1}{ad-bc}
\begin{bmatrix}
d & -b \\
-c & a
\end{bmatrix}.
$$

If $ad-bc=0$, then $A$ is not invertible.

:::

::: {#theorem-2-2-5 .callout-note title="Theorem 2.2.5 — Solving a System with an Inverse"}

**Textbook reference:** p.136

**Source note:** [The Inverse of a Matrix](2-2-the-inverse-of-a-matrix.md)

If $A$ is an invertible $n\times n$ matrix, then for every
$\vec{b}\in\mathbb{R}^n$, the equation

$$
A\vec{x}=\vec{b}
$$

has the unique solution

$$
\vec{x}=A^{-1}\vec{b}.
$$

:::

::: {#theorem-2-2-6 .callout-note title="Theorem 2.2.6 — Properties of Inverse Matrices"}

**Textbook reference:** p.137

**Source note:** [The Inverse of a Matrix](2-2-the-inverse-of-a-matrix.md)

If $A$ and $B$ are invertible $n\times n$ matrices, then

$$
\left(A^{-1}\right)^{-1}=A,
\qquad
(AB)^{-1}=B^{-1}A^{-1},
\qquad
\left(A^T\right)^{-1}=\left(A^{-1}\right)^T.
$$

:::

::: {#theorem-2-2-7 .callout-note title="Theorem 2.2.7 — Row-Equivalence Criterion for Invertibility"}

**Textbook reference:** p.140

**Source note:** [The Inverse of a Matrix](2-2-the-inverse-of-a-matrix.md)

An $n\times n$ matrix $A$ is invertible if and only if $A$ is row equivalent
to $I_n$. In that case, every sequence of elementary row operations that
reduces $A$ to $I_n$ also transforms $I_n$ into $A^{-1}$.

:::

## Chapter 2.3 – Characterizations of Invertible Matrices

::: {#theorem-2-3-8 .callout-note title="Theorem 2.3.8 — Invertible Matrix Theorem"}

**Textbook reference:** p.145; points m-q, p.189

**Source note:** [Characterizations of Invertible Matrices](2-3-characterizations-of-invertible-matrices.md)

Let $A$ be an $n\times n$ matrix. The following statements are equivalent:
for a given $A$, either they are all true or they are all false.

a. $A$ is invertible.
b. $A$ is row equivalent to the $n\times n$ identity matrix.
c. $A$ has $n$ pivot positions.
d. The equation $A\vec{x}=\vec{0}$ has only the trivial solution.
e. The columns of $A$ form a linearly independent set.
f. The linear transformation $\vec{x}\mapsto A\vec{x}$ is one-to-one.
g. For every $\vec{b}\in\mathbb{R}^n$, the equation
   $A\vec{x}=\vec{b}$ has at least one solution.
h. The columns of $A$ span $\mathbb{R}^n$.
i. The linear transformation $\vec{x}\mapsto A\vec{x}$ maps
   $\mathbb{R}^n$ onto $\mathbb{R}^n$.
j. There is an $n\times n$ matrix $C$ such that $CA=I$.
k. There is an $n\times n$ matrix $D$ such that $AD=I$.
l. $A^T$ is invertible.
m. The columns of $A$ form a basis for $\mathbb{R}^n$.
n. $\operatorname{Col}(A)=\mathbb{R}^n$.
o. $\operatorname{rank}(A)=n$.
p. $\dim\bigl(\operatorname{Nul}(A)\bigr)=0$.
q. $\operatorname{Nul}(A)=\{\vec{0}\}$.

:::

## Chapter 2.8 – Subspaces of $\mathbb{R}^n$

**Source note:** [Subspaces of $\mathbb{R}^n$](2-8-subspaces-of-Rn.md)

::: {#definition-2-8-1 .callout-note title="Definition 2.8.1 — Subspace"}

**Textbook reference:** p.179

A subset $H\subseteq\mathbb{R}^n$ is a subspace if it contains
$\vec{0}$ and is closed under vector addition and scalar multiplication.

:::

::: {#definition-2-8-2 .callout-note title="Definition 2.8.2 — Column Space"}

**Textbook reference:** p.180

For an $m\times n$ matrix $A=[\vec{a}_1\ \cdots\ \vec{a}_n]$,

$$
\operatorname{Col}(A)=
\operatorname{span}\{\vec{a}_1,\ldots,\vec{a}_n\}.
$$

It is a subspace of $\mathbb{R}^m$.

:::

::: {#definition-2-8-3 .callout-note title="Definition 2.8.3 — Null Space"}

**Textbook reference:** p.181

For $A\in\mathbb{R}^{m\times n}$,

$$
\operatorname{Nul}(A)=
\{\vec{x}\in\mathbb{R}^n:A\vec{x}=\vec{0}\}.
$$

:::

::: {#theorem-2-8-12 .callout-note title="Theorem 2.8.12 — The Null Space Is a Subspace"}

**Textbook reference:** p.181

For every $m\times n$ matrix $A$, the null space of $A$ is a subspace of
$\mathbb{R}^n$. Equivalently, the solution set of every homogeneous system
$A\vec{x}=\vec{0}$ is a subspace of $\mathbb{R}^n$.

:::

::: {#definition-2-8-4 .callout-note title="Definition 2.8.4 — Basis for a Subspace"}

**Textbook reference:** p.181

A basis for a subspace $H$ is a linearly independent set in $H$ that spans
$H$.

:::

::: {#theorem-2-8-13 .callout-note title="Theorem 2.8.13 — Pivot Columns Form a Column-Space Basis"}

**Textbook reference:** p.183

The pivot columns of a matrix $A$ form a basis for $\operatorname{Col}(A)$.
Determine their indices by row-reducing $A$, then take the columns with those
indices from the original matrix.

:::

## Chapter 2.9 – Dimension and Rank

::: {#theorem-2-9-1 .callout-note title="Theorem 2.9.1 — Rank Theorem"}

**Source note:** [Dimension and Rank](2-9-dimension-and-rank.md)

If a matrix $A$ has $n$ columns, then

$$
\operatorname{rank}(A)+\dim\bigl(\operatorname{Nul}(A)\bigr)=n.
$$

:::

::: {#theorem-2-9-2 .callout-note title="Theorem 2.9.2 — Basis Theorem"}

**Source note:** [Dimension and Rank](2-9-dimension-and-rank.md)

Let $H$ be a $p$-dimensional subspace of $\mathbb{R}^n$.

- Any linearly independent set of exactly $p$ vectors in $H$ is a basis for
  $H$.
- Any set of exactly $p$ vectors that spans $H$ is a basis for $H$.

:::

## Chapter 3.1 – Introduction to Determinants

::: {#theorem-3-1-1 .callout-note title="Theorem 3.1.1 — Cofactor Expansion"}

**Source note:** [Introduction to Determinants](3-1-introduction-to-determinants.md)

The determinant of an $n\times n$ matrix can be computed by expanding along
any row $i$ or any column $j$:

$$
\det(A)=\sum_{k=1}^{n}a_{ik}C_{ik}
\qquad\text{or}\qquad
\det(A)=\sum_{k=1}^{n}a_{kj}C_{kj}.
$$

Here, $C_{ij}=(-1)^{i+j}\det(A_{ij})$ is the cofactor of $a_{ij}$.

:::

::: {#theorem-3-1-2 .callout-note title="Theorem 3.1.2 — Triangular-Matrix Determinant"}

**Source note:** [Introduction to Determinants](3-1-introduction-to-determinants.md)

If $A$ is an upper- or lower-triangular matrix, then its determinant is the
product of the entries on its main diagonal:

$$
\det(A)=a_{11}a_{22}\cdots a_{nn}.
$$

:::

## Chapter 3.2 – Properties of Determinants

::: {#theorem-3-2-3 .callout-note title="Theorem 3.2.3 — Effects of Row Operations"}

**Source note:** [Properties of Determinants](3-2-properties-of-determinants.md)

Let $A$ be a square matrix, and let $B$ be obtained from $A$ by one row
operation.

1. Adding a multiple of one row to another row leaves the determinant
   unchanged: $\det(B)=\det(A)$.
2. Interchanging two rows reverses the sign: $\det(B)=-\det(A)$.
3. Multiplying one row by $k$ multiplies the determinant by $k$:
   $\det(B)=k\det(A)$.

:::

::: {#theorem-3-2-4 .callout-note title="Theorem 3.2.4 — Invertibility Test"}

**Source note:** [Properties of Determinants](3-2-properties-of-determinants.md)

A square matrix $A$ is invertible if and only if

$$
\det(A)\ne0.
$$

:::

::: {#theorem-3-2-5 .callout-note title="Theorem 3.2.5 — Transpose Invariance"}

**Source note:** [Properties of Determinants](3-2-properties-of-determinants.md)

If $A$ is an $n\times n$ matrix, then

$$
\det(A)=\det(A^T).
$$

:::

::: {#theorem-3-2-6 .callout-note title="Theorem 3.2.6 — Determinant of a Product"}

**Source note:** [Properties of Determinants](3-2-properties-of-determinants.md)

If $A$ and $B$ are $n\times n$ matrices, then

$$
\det(AB)=\det(A)\det(B).
$$

:::

## Chapter 3.3 – Cramer's Rule

::: {#theorem-3-3-7 .callout-note title="Theorem 3.3.7 — Cramer's Rule"}

**Source note:** [Cramer's Rule](3-3-cramers-rule.md)

Let $A$ be an invertible $n\times n$ matrix. For every
$\vec{b}\in\mathbb{R}^n$, the unique solution of $A\vec{x}=\vec{b}$ has
entries

$$
x_i=\frac{\det(A_i(\vec{b}))}{\det(A)},
\qquad i=1,2,\ldots,n,
$$

where $A_i(\vec{b})$ is obtained by replacing column $i$ of $A$ with
$\vec{b}$.

:::

::: {#theorem-3-3-8 .callout-note title="Theorem 3.3.8 — An Inverse Formula"}

**Source note:** [Cramer's Rule](3-3-cramers-rule.md)

If $A$ is an invertible $n\times n$ matrix, then

$$
A^{-1}=\frac{1}{\det(A)}\operatorname{adj}(A),
$$

where $\operatorname{adj}(A)=[C_{ij}]^T$ is the transpose of the cofactor
matrix of $A$.

:::

::: {#theorem-3-3-9 .callout-note title="Theorem 3.3.9 — Determinants as Area or Volume"}

**Source note:** [Determinants as Area or Volume](3-3-determinants-as-area-or-volume.md)

If $A$ is a $2\times2$ matrix, the area of the parallelogram determined by
the columns of $A$ is $|\det(A)|$. If $A$ is a $3\times3$ matrix, the volume
of the parallelepiped determined by the columns of $A$ is $|\det(A)|$.

:::

::: {#theorem-3-3-10 .callout-note title="Theorem 3.3.10 — Area and Volume Under Linear Transformations"}

**Source note:** [Determinants and Linear Transformations](3-3-determinants-and-linear-transformations.md)

Let $T\colon\mathbb{R}^2\to\mathbb{R}^2$ be determined by a $2\times2$
matrix $A$. For every parallelogram $S$ in $\mathbb{R}^2$,

$$
\operatorname{area}(T(S))=|\det(A)|\operatorname{area}(S).
$$

Let $T\colon\mathbb{R}^3\to\mathbb{R}^3$ be determined by a $3\times3$
matrix $A$. For every parallelepiped $S$ in $\mathbb{R}^3$,

$$
\operatorname{volume}(T(S))=|\det(A)|\operatorname{volume}(S).
$$

:::

## Chapter 4.1 – Vector Spaces and Subspaces

::: {#theorem-4-1-1 .callout-note title="Theorem 4.1.1 — Every Span Is a Subspace"}

**Source note:** [Vector Spaces and Subspaces](4-1-vector-spaces-and-subspaces.md)

If $\vec{v}_1,\ldots,\vec{v}_p$ belong to a vector space $V$, then

$$
\operatorname{span}\{\vec{v}_1,\ldots,\vec{v}_p\}
$$

is a subspace of $V$.

:::
