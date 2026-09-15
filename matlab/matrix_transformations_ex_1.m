% Matrices in Matlab
clear
clc
close all

% Define some symbols
%syms a b c d e f g h i j k l

% wrapping the matrix in sym(), symbolic, allows for matlab to
% display the matrix as fractions
A=sym([1 -3; 3 5; -1 7]);
b=sym([3; 2; -5]);



disp(['Matrices A and B:'])
disp(A);
disp(b);

rref(sym([A b]))