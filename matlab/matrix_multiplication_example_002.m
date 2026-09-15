% Matrices in Matlab
clear
clc
close all

% Define some matrices
syms a b c d e f g h i j k l

A_1=[1; 2; 3];
A_2=[7; 8; 9];

B_1=[1 6];
B_2=[2 7];

A=[1 7; 2 8; 3 9];
B=[1 6; 2 7];


disp('Matrix A:')
disp(A)
disp(A_1)
disp(A_2)

disp('Matrix B:')
disp(B)
disp(B_1)
disp(B_2)

C_1 = A_1*B_1 + A_2*B_2
C= A*B

%disp('rref [A b]:')
%disp(rref([A b]));


%disp('rref A:')
%disp(rref(A));

%disp('Solution A \ b:')
%x = A \ b;
%format rat
%disp(x)
