syms x y z
res3 = solve('2*x + y + z = 2','-x + y - z = 3','x + 2*y +3*z = -10');
disp(res3.x);
disp(res3.y);
disp(res3.z);

%%
vect = input('Enter a vector');
max = Maxnum(vect);
fprintf('The maximum of the array is: ');
disp(max);