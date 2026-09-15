% Matrices in Matlab
clear
clc
close all

% Define some symbols
syms a b c d e f g h i j k l

% wrapping the matrix in sym(), symbolic, allows for matlab to
% display the matrix as fractions
P_B=sym([1 5; -2 -6]);



disp(['Matrix P_B:'])
disp(P_B);

disp(['Inverse of P_B = inv(P_B):'])
disp(inv(P_B));

X_S=sym([4; 0]);

disp(X_S);

disp(inv(P_B) * X_S);
