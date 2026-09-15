clear
close all
clc

syms a b c d k;

A = sym([6 1; 3 2]);
B = sym([4 3; 1 2]);


disp(A);
disp(B);

disp(A*B);

det(A)*det(B)
det(A*B)