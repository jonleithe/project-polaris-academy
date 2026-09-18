---
title       : Column and Null Space
subject     : Linear Algebra
author      : Jon Leithe
date        : 2026-09-18
---

A matrix describes a linear transformation from inputs to outputs. Two
subspaces help us understand that transformation: the **column space** contains
all outputs we can produce, while the **null space** contains all inputs that
produce zero output.

These notes consolidate the handwritten `column-and-null-space.pdf` in
`notes/hand-written/`, including its column-space examples and null-space
proof. Repeated calculations are combined below.

## Subspaces: a short reminder

A subset of a vector space is a subspace if it contains the zero vector and
is closed under addition and scalar multiplication. It inherits the remaining
vector-space properties from the surrounding space.

The first page of the handwritten notes illustrates this with functions.
For a fixed real angular frequency $\omega$, consider

$$
H=\{f:f(t)=c_1\cos(\omega t)+c_2\sin(\omega t),\quad c_1,c_2\in\mathbb{R}\}.
$$

Taking both coefficients to be zero gives the zero function. If
$f(t)=a_1\cos(\omega t)+a_2\sin(\omega t)$ and
$g(t)=b_1\cos(\omega t)+b_2\sin(\omega t)$, then

$$
\begin{aligned}
(f+g)(t)&=(a_1+b_1)\cos(\omega t)+(a_2+b_2)\sin(\omega t),\\
(cf)(t)&=(ca_1)\cos(\omega t)+(ca_2)\sin(\omega t).
\end{aligned}
$$

Both functions remain in $H$, so $H$ is a subspace of the real-valued
functions on $\mathbb{R}$. The same three checks apply to spaces of column
vectors. See also [Subspaces and the Basis for a Subspace](../linear-algebra/courses/khan-academy/04-subspaces-and-the-basis-for-a-subspace.md).

## Column space: all attainable outputs

Let $A\in\mathbb{R}^{m\times n}$ have columns
$\vec{a}_1,\ldots,\vec{a}_n\in\mathbb{R}^m$. Matrix multiplication is a
linear combination of these columns:

$$
A\vec{x}=x_1\vec{a}_1+\cdots+x_n\vec{a}_n.
$$

The **column space** is therefore

$$
\operatorname{Col}(A)
=\operatorname{span}\{\vec{a}_1,\ldots,\vec{a}_n\}
=\{A\vec{x}:\vec{x}\in\mathbb{R}^n\}.
$$

It is a subspace of $\mathbb{R}^m$: zero is obtained with zero coefficients,
and adding or scaling linear combinations produces another linear
combination of the same columns.

::: {.callout-note title="Column space and consistency"}

The system $A\vec{x}=\vec{b}$ is consistent if and only if
$\vec{b}\in\operatorname{Col}(A)$.

:::

This follows directly from the definition: a solution supplies the weights
that combine the columns into $\vec{b}$. To test membership, row-reduce
$[A\mid\vec{b}]$ and check for an inconsistent row.

### Example: an output in two dimensions

Consider

$$
A=\begin{bmatrix}1&3\\4&-6\end{bmatrix},
\qquad
\vec{b}=\begin{bmatrix}-2\\10\end{bmatrix}.
$$

Eliminating with $R_2\leftarrow R_2-4R_1$ gives

$$
\left[\begin{array}{cc|c}1&3&-2\\4&-6&10\end{array}\right]
\sim
\left[\begin{array}{cc|c}1&3&-2\\0&-18&18\end{array}\right].
$$

Thus $x_2=-1$ and $x_1=1$. In column form,

$$
\begin{bmatrix}1\\4\end{bmatrix}
-\begin{bmatrix}3\\-6\end{bmatrix}
=\begin{bmatrix}-2\\10\end{bmatrix}.
$$

There is a pivot in every row, so the columns span $\mathbb{R}^2$.
Every vector in $\mathbb{R}^2$ is an attainable output for this matrix.

### Example: membership with a free variable

The handwritten notes identify this as Section 2.8, Example 4, p.180 of the
textbook. Let

$$
A=\begin{bmatrix}1&-3&-4\\-4&6&-2\\-3&7&6\end{bmatrix},
\qquad
\vec{b}=\begin{bmatrix}3\\3\\-4\end{bmatrix}.
$$

The operations $R_2\leftarrow R_2+4R_1$ and
$R_3\leftarrow R_3+3R_1$ give

$$
\left[\begin{array}{ccc|c}
1&-3&-4&3\\0&-6&-18&15\\0&-2&-6&5
\end{array}\right].
$$

Now apply $R_3\leftarrow R_3-\tfrac13R_2$, scale the second row by
$-\tfrac16$, and use $R_1\leftarrow R_1+3R_2$:

$$
\operatorname{rref}([A\mid\vec{b}])=
\left[\begin{array}{ccc|c}
1&0&5&-9/2\\0&1&3&-5/2\\0&0&0&0
\end{array}\right].
$$

There is no inconsistent row, so $\vec{b}\in\operatorname{Col}(A)$.
Setting the free variable $x_3=0$ gives the explicit check

$$
-\frac92\begin{bmatrix}1\\-4\\-3\end{bmatrix}
-\frac52\begin{bmatrix}-3\\6\\7\end{bmatrix}
=\begin{bmatrix}3\\3\\-4\end{bmatrix}.
$$

The zero row represents $0=0$. It does not by itself establish consistency:
we must check that no other row is inconsistent.

## Finding a basis for the column space

::: {.callout-note title="Pivot columns give a column-space basis"}

Row-reduce $A$ to find its pivot-column indices. The columns at those indices
in the **original matrix** form a basis for $\operatorname{Col}(A)$.

:::

To see why, write the reduced matrix as $R=EA$, where $E$ is invertible.
For any coefficient vector $\vec{c}$,

$$
A\vec{c}=\vec{0}\quad\Longleftrightarrow\quad R\vec{c}=\vec{0}.
$$

Thus row operations preserve the linear dependence relations among columns.
The pivot columns of $R$ are independent and span its column space, so the
corresponding original columns are independent and span $\operatorname{Col}(A)$.
Row operations generally change the column space itself, which is why we
return to the original matrix when selecting the basis vectors.

### Example: three pivot columns

For the matrix from the handwritten notes,

$$
A=\begin{bmatrix}
1&4&0&2&-1\\3&12&1&5&5\\2&8&1&3&2\\5&20&2&8&8
\end{bmatrix},
$$

eliminating below the first pivot gives

$$
\begin{bmatrix}
1&4&0&2&-1\\0&0&1&-1&8\\0&0&1&-1&4\\0&0&2&-2&13
\end{bmatrix}.
$$

Using $R_3\leftarrow R_3-R_2$ and $R_4\leftarrow R_4-2R_2$ gives
last rows $[0,0,0,0,-4]$ and $[0,0,0,0,-3]$. Continuing yields

$$
\operatorname{rref}(A)=\begin{bmatrix}
1&4&0&2&0\\0&0&1&-1&0\\0&0&0&0&1\\0&0&0&0&0
\end{bmatrix}.
$$

The pivot columns are $1$, $3$, and $5$, so a basis is

$$
\left\{
\begin{bmatrix}1\\3\\2\\5\end{bmatrix},
\begin{bmatrix}0\\1\\1\\2\end{bmatrix},
\begin{bmatrix}-1\\5\\2\\8\end{bmatrix}
\right\}.
$$

This is a three-dimensional subspace of $\mathbb{R}^4$.

## Null space: inputs that produce zero output

For $A\in\mathbb{R}^{m\times n}$, the **null space** is

$$
\operatorname{Nul}(A)=\{\vec{x}\in\mathbb{R}^n:A\vec{x}=\vec{0}\}.
$$

It contains input vectors, so it lies in $\mathbb{R}^n$. By comparison,
$\operatorname{Col}(A)$ contains output vectors and lies in $\mathbb{R}^m$.
These ambient spaces need not have the same dimension.

::: {.callout-note title="The null space is a subspace"}

The null space of an $m\times n$ matrix is a subspace of $\mathbb{R}^n$.

:::

**Proof.** First, $A\vec{0}=\vec{0}$, so the zero vector belongs to the
null space. If $A\vec{u}=\vec{0}$ and $A\vec{v}=\vec{0}$, then

$$
A(\vec{u}+\vec{v})=A\vec{u}+A\vec{v}=\vec{0}.
$$

For any scalar $c\in\mathbb{R}$,

$$
A(c\vec{u})=c(A\vec{u})=\vec{0}.
$$

The null space therefore contains zero and is closed under both operations.

## How to determine Nul(A)

1. Row-reduce $A$ to reduced row-echelon form. The zero right-hand side of
   $A\vec{x}=\vec{0}$ stays zero throughout elimination.
2. Identify the pivot variables and the free variables.
3. Express each pivot variable in terms of the free variables.
4. Write the complete solution in parametric vector form, with one vector
   multiplying each free parameter.
5. Those vectors form a basis; their span is $\operatorname{Nul}(A)$.

The vectors span because the formula describes every solution. They are
independent because each has a $1$ in its own free-variable position and $0$
in the other free-variable positions. If there are no free variables, the
null space is $\{\vec{0}\}$ and its basis is the empty set.

### Worked example: both spaces from one reduction

Let

$$
A=\begin{bmatrix}3&1&1&6\\1&-2&5&-5\\4&1&2&7\end{bmatrix}.
$$

Begin with $R_3\leftarrow R_3-R_1$ and then
$R_2\leftarrow R_2-R_3$:

$$
\begin{bmatrix}3&1&1&6\\0&-2&4&-6\\1&0&1&1\end{bmatrix}.
$$

Scale $R_2$ by $-\tfrac12$ and apply $R_1\leftarrow R_1-3R_3$:

$$
\begin{bmatrix}0&1&-2&3\\0&1&-2&3\\1&0&1&1\end{bmatrix}.
$$

Swap rows $1$ and $3$, then apply $R_3\leftarrow R_3-R_2$ to obtain

$$
R=\operatorname{rref}(A)=
\begin{bmatrix}1&0&1&1\\0&1&-2&3\\0&0&0&0\end{bmatrix}.
$$

The pivot variables are $x_1,x_2$; the free variables are $x_3,x_4$.
The equations $R\vec{x}=\vec{0}$ give

$$
x_1=-x_3-x_4,\qquad x_2=2x_3-3x_4.
$$

Set $x_3=s$ and $x_4=t$. Then

$$
\vec{x}=\begin{bmatrix}-s-t\\2s-3t\\s\\t\end{bmatrix}
=s\underbrace{\begin{bmatrix}-1\\2\\1\\0\end{bmatrix}}_{\vec{u}}
+t\underbrace{\begin{bmatrix}-1\\-3\\0\\1\end{bmatrix}}_{\vec{v}},
\qquad s,t\in\mathbb{R}.
$$

Consequently,

$$
\operatorname{Nul}(A)=\operatorname{span}\{\vec{u},\vec{v}\},
\qquad B_{\mathrm{Nul}}=\{\vec{u},\vec{v}\}.
$$

The **basis** is the set of two independent vectors; the **null space** is
their entire span. Verify each basis vector using the original matrix:

$$
A\vec{u}=\begin{bmatrix}-3+2+1\\-1-4+5\\-4+2+2\end{bmatrix}
=\vec{0},\qquad
A\vec{v}=\begin{bmatrix}-3-3+6\\-1+6-5\\-4-3+7\end{bmatrix}
=\vec{0}.
$$

For the column space, the same reduction identifies pivot columns $1$ and
$2$. Select those columns from $A$:

$$
B_{\mathrm{Col}}=\left\{
\begin{bmatrix}3\\1\\4\end{bmatrix},
\begin{bmatrix}1\\-2\\1\end{bmatrix}
\right\}.
$$

Here $\operatorname{Col}(A)\subseteq\mathbb{R}^3$ and
$\operatorname{Nul}(A)\subseteq\mathbb{R}^4$, though both have dimension $2$.
The rank is $2$ and the nullity is $2$, agreeing with
$\operatorname{rank}(A)+\dim(\operatorname{Nul}(A))=4$.
The next note, [Dimension and Rank](2-9-dimension-and-rank.md), develops this
relationship further.

## Engineering interpretation

If $A$ maps actuator commands to a resulting force, its column space describes
the forces those actuators can generate. A null-space vector describes a
combination of commands whose resulting force is zero within that linear model.

More generally, if $\vec{x}_p$ is one solution of $A\vec{x}=\vec{b}$, then
every solution has the form

$$
\vec{x}=\vec{x}_p+\vec{z},\qquad \vec{z}\in\operatorname{Nul}(A).
$$

Adding $\vec{z}$ leaves the output unchanged because $A\vec{z}=\vec{0}$.
Conversely, the difference between any two solutions lies in the null space.
Column space therefore answers whether an output is attainable; null space
describes the freedom in choosing an input that produces it.

## Summary

| Question | Method |
|---|---|
| Is $\vec{b}$ in $\operatorname{Col}(A)$? | Check whether $A\vec{x}=\vec{b}$ is consistent. |
| Find a basis for $\operatorname{Col}(A)$ | Locate pivots by row reduction; take the corresponding original columns. |
| Find a basis for $\operatorname{Nul}(A)$ | Solve $A\vec{x}=\vec{0}$ in parametric vector form. |
| Find the nullity | Count the free variables. |

## Practice

For the $4\times5$ matrix in the three-pivot-column example, use its reduced
form to find a null-space basis and verify that rank plus nullity equals $5$.

**Answer:** The free variables are $x_2=s$ and $x_4=t$, giving

$$
\vec{x}=s\begin{bmatrix}-4\\1\\0\\0\\0\end{bmatrix}
+t\begin{bmatrix}-2\\0\\1\\1\\0\end{bmatrix}.
$$

The two displayed vectors form a basis. The rank is $3$, the nullity is $2$,
and $3+2=5$.
