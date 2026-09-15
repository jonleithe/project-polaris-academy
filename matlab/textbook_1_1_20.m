% Matrices in Matlab
clear
clc
close all

% Define some matrices

A=[1 0 0 -4;
    0 2 2 0;
    0 0 1 3;
    -2 3 2 1];
b=[-3;0;1;5];

disp('Matrix A:')
disp(A)

disp('Matrix b:')
disp(b)

disp('rref A:')
disp(rref(A));

disp('Solution A \ b:')
x = A \ b;

disp(x)