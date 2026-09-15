clear
close all
clc

% Horizontal shear: (x, y) -> (x + k*y, y)
k =  .1;
A = [1 k;
    0 1];

% Square vertices: each column is one point.
square = [-1  1  1 -1 -1;
    -1 -1  1  1 -1];

shearedSquare = A * square;

figure("Color", "w")
tiledlayout(1, 2, "TileSpacing", "compact")

% Original grid and square
ax1 = nexttile;
hold(ax1, "on")

for s = -1:0.25:1
    plot(ax1, [s s], [-1 1], "Color", [0.75 0.75 0.75])
    plot(ax1, [-1 1], [s s], "Color", [0.75 0.75 0.75])
end

fill(ax1, square(1,:), square(2,:), ...
    [0.3 0.6 1], "FaceAlpha", 0.35, "LineWidth", 2)

quiver(ax1, 0, 0, 1, 0, 0, "k", "LineWidth", 1.5)
quiver(ax1, 0, 0, 0, 1, 0, "k", "LineWidth", 1.5)

axis(ax1, "equal")
xlim(ax1, [-3 3])
ylim(ax1, [-2 2])
grid(ax1, "on")
title(ax1, "Original square")
xlabel(ax1, "x")
ylabel(ax1, "y")

% Sheared grid and square
ax2 = nexttile;
hold(ax2, "on")

for s = -1:0.25:1
    verticalLine = [s s; -1 1];
    horizontalLine = [-1 1; s s];

    transformedVertical = A * verticalLine;
    transformedHorizontal = A * horizontalLine;

    plot(ax2, transformedVertical(1,:), transformedVertical(2,:), ...
        "Color", [0.75 0.75 0.75])
    plot(ax2, transformedHorizontal(1,:), transformedHorizontal(2,:), ...
        "Color", [0.75 0.75 0.75])
end

fill(ax2, shearedSquare(1,:), shearedSquare(2,:), ...
    [1 0.55 0.2], "FaceAlpha", 0.35, "LineWidth", 2)

quiver(ax2, 0, 0, A(1,1), A(2,1), 0, "k", "LineWidth", 1.5)
quiver(ax2, 0, 0, A(1,2), A(2,2), 0, "k", "LineWidth", 1.5)

axis(ax2, "equal")
xlim(ax2, [-3 3])
ylim(ax2, [-2 2])
grid(ax2, "on")
title(ax2, sprintf("Horizontal shear, k = %.1f", k))
xlabel(ax2, "x'")
ylabel(ax2, "y'")

sgtitle("T(\mathbf{x}) = A\mathbf{x}")