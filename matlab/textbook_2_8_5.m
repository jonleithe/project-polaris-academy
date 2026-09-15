% Matrices in Matlab
clear
clc
close all

% Define some matrices

A=sym([1, 4, 0, 2, -1; ...
       3, 12, 1, 5, 5; ...
       2, 8, 1, 3, 2; ...
       5, 20, 2, 8, 8]);

disp('rref A:')
disp(rref(A));
