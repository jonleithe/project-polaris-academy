clear
close all
clc

syms a b c d e f g h i;

A = sym([a b c; d e f; g h i]);

disp(A);

E_1 = sym([1 0 0; 0 1 0; -4 0 1]);
E_2 = sym([0 1 0; 1 0 0; 0 0 1]);
E_3 = sym([1 0 0; 0 1 0; 0 0 5]);

disp(E_1);
disp(E_2);
disp(E_3);

B = E_1 * A
C = E_2 * B

E = E_2 * E_1

D = E * A