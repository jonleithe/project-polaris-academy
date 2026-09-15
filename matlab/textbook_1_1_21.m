% Matrices in Matlab
clear
clc
close all

% Define some matrices

A=sym([1 -4;
    2 -1
   -1 -3]);
b=sym([1; -3; 4]);

disp('Matrix A:')
disp(A)

disp('Matrix b:')
disp(b)

disp('rref A:')
disp(rref(A));

disp('Solution A \ b:')
x = A \ b;
format rat
disp(x)
