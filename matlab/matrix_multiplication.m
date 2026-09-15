% Matrices in Matlab
clear
clc
close all

% Define some symbols
syms a b c d e f g h i j k l

% wrapping the matrix in sym(), symbolic, allows for matlab to
% display the matrix as fractions
A=sym([1 2; 3 4; 5 6])
B=sym([a b c; d e f])



disp(['Matrices A and B:'])
disp(A);
disp(B);

C=A*B