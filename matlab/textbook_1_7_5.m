% Matrices in Matlab
clear
clc
close all

% Define some matrices

A=sym([2, 3, -5; ...
      -4, -5, 8]);

disp('rref A:')
disp(rref(A));

B=sym([8, 2, -9])
