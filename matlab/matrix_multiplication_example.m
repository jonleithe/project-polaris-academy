% Matrices in Matlab
clear
clc
close all

% Define some matrices
syms a b c d e f g h i j k l

A_1=[a; c; e];
A_2=[b; d; f];

B_1=[1 6];
B_2=[2 7];

disp('Matrix A:')
disp(A_1)
disp(A_2)

disp('Matrix B:')
disp(B_1)
disp(B_2)

C = A_1*B_1 + A_2*B_2

%disp('rref [A b]:')
%disp(rref([A b]));


%disp('rref A:')
%disp(rref(A));

%disp('Solution A \ b:')
%x = A \ b;
%format rat
%disp(x)
