---
title       : Determinants as Area or Volume
subject     : Linear Algebra
source      : Linear Algebra and Its Applications, 6th edition
author      : Jon Leithe
date        : 2026-09-17
---

Besides testing invertibility and solving systems, a determinant has a direct
geometric meaning. The columns of a two-by-two matrix determine a
parallelogram; the columns of a three-by-three matrix determine a
parallelepiped. The magnitude of the determinant gives the corresponding
area or volume.

The absolute value is essential. A negative determinant records an orientation
reversal, not a negative physical area or volume.

## Determinants as area or volume

::: {#nte-determinant-area-volume .callout-note title="Theorem 9: Determinants as Area or Volume"}

If $A$ is a $2\times2$ matrix, the area of the parallelogram determined by
the columns of $A$ is $|\det(A)|$. If $A$ is a $3\times3$ matrix, the volume
of the parallelepiped determined by the columns of $A$ is $|\det(A)|$.

:::

For a diagonal matrix, the result is immediate. The columns of

$$
D=\begin{bmatrix}a&0\\0&d\end{bmatrix}
$$

are perpendicular side vectors of a rectangle with side lengths $|a|$ and
$|d|$. Its area is therefore $|a||d|=|ad|=|\det(D)|$. Similarly, the columns
of

$$
D=\begin{bmatrix}a&0&0\\0&b&0\\0&0&c\end{bmatrix}
$$

determine a rectangular parallelepiped with volume
$|a||b||c|=|abc|=|\det(D)|$.

This gives the main idea of the general proof. Adding a multiple of one column
to another is a shear: it changes the shape of the parallelogram or
parallelepiped without changing its area or volume. The same column operation
leaves the determinant unchanged. Rigid motions preserve geometric size, and
column interchanges reverse orientation but do not change that size. These
operations reduce the geometric argument to the diagonal case, where the
formula is immediate.

### Example 1: area of a parallelogram from its vertices

Calculate the area of the parallelogram with vertices

$$
(-2,-2),\qquad (0,3),\qquad (4,-1),\qquad (6,4).
$$

First translate the parallelogram so that $(-2,-2)$ becomes the origin.
Translation does not change area. Subtracting $(-2,-2)$ from every vertex
gives

$$
(0,0),\qquad (2,5),\qquad (6,1),\qquad (8,6).
$$

The two edge vectors from the origin are

$$
\vec{u}=\begin{bmatrix}2\\5\end{bmatrix},
\qquad
\vec{v}=\begin{bmatrix}6\\1\end{bmatrix}.
$$

The fourth translated vertex satisfies
$\vec{u}+\vec{v}=(8,6)^T$, confirming that these are adjacent sides of the
parallelogram. Put the edge vectors into the columns of a matrix:

$$
A=\begin{bmatrix}2&6\\5&1\end{bmatrix}.
$$

Then

$$
\det(A)=2(1)-6(5)=-28.
$$

The negative sign says that the ordered pair $(\vec{u},\vec{v})$ has the
opposite orientation from the standard coordinate axes. The area is the
magnitude:

$$
\operatorname{area}=|\det(A)|=|-28|=28.
$$

## Summary

For two-dimensional column vectors, $|\det(A)|$ is the area of their
parallelogram. For three-dimensional column vectors, it is the volume of their
parallelepiped. The sign of $\det(A)$ carries orientation information, whereas
the absolute value is the geometric size.

The next section applies this interpretation to the area and volume changes
caused by a matrix: [Determinants and Linear Transformations](3-3-determinants-and-linear-transformations.md).
