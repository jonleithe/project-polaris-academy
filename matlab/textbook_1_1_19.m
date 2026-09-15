% Matrices in Matlab
clear
clc
close all

% Define some matrices

A=[1 0 3 0;
    0 1 0 -3;
    0 -2 3 2;
    3 0 0 7];
% b=[2; 3; 1; -5];
b=[0; 0; 0; 0];

disp('Matrix A:')
disp(A)

disp('Matrix b:')
disp(b)

disp('rref A:')
disp(rref(A));

disp('Solution A \ b:')
x = A \ b;

disp(x)