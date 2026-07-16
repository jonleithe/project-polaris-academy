Let's talk a bit about parametric representation.
From what I've understood so far, or just to be frank: I understand how the equations work, and a list as set of all vectors that desribes points through the same line. What I want to discuss is the application.
To me, it's like this: Say we have two position vectors, and their end points describes a line. Now, imagine this to be a path travelled by some vessel, and assuming a linear path (like Newton's law, an object in motion, balh blah), how can we predict the vessels location over time? This is where I see the application of parametric representation. By creating the list as a set of vectors, one of the location vectors + some constant t times (b-a), we can describe all possible vessel locations along that same path of travel.


Yes—your understanding is essentially right. The important refinement is that a parametric representation describes both a geometric path and, if we interpret the parameter appropriately, motion along that path.

Suppose the vessel is at position vector $\mathbf{a}$ at time $t_0$, and at $\mathbf{b}$ at time $t_1$.

Assuming constant velocity, its position at time $t$ is

$$
\mathbf{r(t)}
=
\mathbf{a+}
\frac{t-t_0}{t_1-t_0}(\mathbf{b-}\mathbf{a})
$$

Here,

$$
\mathbf v=\frac{\mathbf b-\mathbf a}{t_1-t_0}
$$

is the vessel’s velocity vector, so the same equation can be written more familiarly as

$$
\mathbf r(t)=\mathbf a+(t-t_0)\mathbf v.
$$

There is a subtle distinction worth making:

$$
\mathbf r(s)=\mathbf a+s(\mathbf b-\mathbf a)
$$

describes the line geometrically, but \(s\) is initially just a dimensionless parameter—not necessarily physical time.

$s=0$ gives $\mathbf{a}$.

$s=1$ gives $\mathbf{b}$.

$0<s<1$ gives positions between them.

$s>1$ continues past $\mathbf{b}$.

$s<0$ goes backward past $\mathbf{a}$.

To turn $s$ into a prediction about time, we need timing information. If the vessel moves from $\mathbf{a}$ at 10:00 to $\mathbf{b}$ at 11:00, then $s=0.5$ corresponds to 10:30 under the constant-velocity assumption.

This gives a useful conceptual division:
The set of generated points is the vessel’s geometric path.
The parametrization tells us where the vessel is at each parameter value.
When the parameter represents time, the parametrization becomes a model of the vessel’s motion—a trajectory.
Two endpoints alone determine the line of travel, but they do not determine the vessel’s speed. The associated times are what let us convert that line into a time-based prediction. And, naturally, predictions beyond the two observations rely on the vessel maintaining the same speed and direction.

$\mathbf v=\frac{\mathbf b-\mathbf a}{t_1-t_0}$
isn't this a vector divided by a scalar?

Exactly. It is a vector divided by a scalar, which is defined as multiplying the vector by the scalar’s reciprocal:
$$
\frac{\mathbf b-\mathbf a}{t_1-t_0}
=
\frac{1}{t_1-t_0}(\mathbf b-\mathbf a).
$$

For example, suppose

$$
\mathbf a=(2,3),\qquad \mathbf b=(8,9)
$$
and the journey takes $3$ seconds. Then

$$
\mathbf b-\mathbf a=(6,6),
$$

so

$$
\mathbf v=\frac{(6,6)}{3}=(2,2).
$$

This says that each second, the vessel moves $2$ units in the $x$-direction and $2$ units in the $y$-direction.
The units also reveal what is happening:

$$
\frac{\text{displacement}}{\text{time}}
=
\text{velocity}.
$$

If position is measured in metres and time in seconds, then

$$
\mathbf v=(2,2)\ \mathrm{m/s}.
$$

So yes, it’s vector–scalar division. We divide every component of the displacement vector by the elapsed time. What generally isn’t defined in ordinary vector algebra is division by another vector.


Of course, I should have thought of that, thanks

You’re welcome—and it was a good thing to question. Vector notation can conceal ordinary component-wise arithmetic. The dimensional interpretation is often the quickest check:
$$
\frac{\text{position vector}}{\text{time scalar}}
=\text{velocity vector}.
$$

Your original picture of parametric representation as a model for a vessel’s possible positions is solid. The parameter becomes physically meaningful once we connect it to time.