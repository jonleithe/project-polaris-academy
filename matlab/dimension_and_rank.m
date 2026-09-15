% Matrices in Matlab
clear
clc
close all

% Define some matrices

v1 = [3; 1; 4];
v2 = [1; -2; 1];
v3 = [1; 5;2];
v4 = [6; -5; 7];

A = [v1 v2 v3 v4];

disp(A);

rref(A)