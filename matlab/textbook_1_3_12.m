% Matrices in Matlab
clear
clc
close all

% Define some matrices

A=sym([1 0 2; ...
      -2 5 0; ...
       2 5 8]);

b=sym([-5; 11; -7]);

disp('Matrix A:')
disp(A)

disp('Matrix b:')
disp(b)

disp('rref [A b]:')
disp(rref([A b]));

disp('rref A:')
disp(rref(A));

%disp('Solution A \ b:')
%x = A \ b;
%format rat
%disp(x)
