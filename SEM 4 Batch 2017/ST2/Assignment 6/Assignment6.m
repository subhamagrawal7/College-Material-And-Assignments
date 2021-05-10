%% This contains the solution of polynomial equations
fprintf('======== FINDING THE ROOTS OF THE EQUATIONS =========\n')
eq1 = 'x^2 + 7*x + 12';
res1 = solve(eq1);
fprintf('The roots of the equation x^2 + 7*x + 12 are :\n');
disp(double(res1));

eq2 = '((x - 3)^2) * (x - 7)';
res2 = solve(eq2);
fprintf('The roots of the equation (x - 3)^2*(x - 7) are :\n');
disp(double(res2));

eq3 = 'x^4 - 7*x^3 + 3*x^2 - 5*x +9';
res3 = solve(eq3);
fprintf('The roots of the equation x^4 - 7*x^3 + 3*x^2 - 5*x +9 are :\n');
disp(double(res3));

eq4 = '6*x^2 + 11*x -35';
res4 = solve(eq4);
fprintf('The roots of the equation 6*x^2 + 11*x -35 are :\n');
disp(double(res4));

eq5 = '((x - 2)^2) - 12';
res5 = solve(eq5);
fprintf('The roots of the equation (x - 2)^2 - 12 are :\n');
disp(double(res5));

%% The solutions of the two equations is:
fprintf('========== SOLVING TWO LINEAR EQUATIONS ===========\n');
res1 = solve('5*x + 9*y = 5','3*x - 6*y = 4');
fprintf('For the equations, 5*x + 9*y = 5 , 3*x - 6*y = 4\n\n');
fprintf('The values of x is:\n ');
disp(res1.x);
fprintf('The values of y is:\n ');
disp(res1.y);

res2 = solve('x + 3*y - 2*z = 5','3*x + 5*y + 6*z = 7','2*x + 4*y + 3*z = 8');
fprintf('For the equations, x + 3*y - 2*z = 5 , 3*x + 5*y + 6*z = 7 , 2*x + 4*y + 3*z = 8\n\n');
fprintf('The values of x is:\n ');
disp(res2.x);
fprintf('The values of y is:\n ');
disp(res2.y);
fprintf('The values of z is:\n ');
disp(res2.z);

res3 = solve('7*x + 5*y - 3*z = 16','3*x - 5*y + 2*z = -8','5*x + 3*y -7*z = 0');
fprintf('For the equations, 7*x + 5*y - 3*z = 16 , 3*x - 5*y + 2*z = -8 , 5*x + 3*y -7*z = 0\n\n');
fprintf('The values of x is:\n ');
disp(res3.x);
fprintf('The values of y is:\n ');
disp(res3.y);
fprintf('The values of z is:\n ');
disp(res3.z);

res4 = solve('3*x + 2*y = 16','7*x + y = 19');
fprintf('For the equations, 3*x + 2*y = 16 , 7*x + y = 19\n\n');
fprintf('The values of x is:\n ');
disp(res4.x);
fprintf('The values of y is:\n ');
disp(res4.y);

res5 = solve('4*x + 3*y = -2','8*x - 2*y = 12');
fprintf('For the equations, 4*x + 3*y = -2 , 8*x - 2*y = 12\n\n');
fprintf('The values of x is:\n ');
disp(res5.x);
fprintf('The values of y is:\n ');
disp(res5.y);

%% Finding factors of the required equations
fprintf('========== FACTORIZATIONS OF EQUATIONS ===========\n');
syms x
syms y

fprintf('The factorization of x^2 - y^2 is: \n');
factor(x^2 - y^2)

fprintf('The factorization of x^3 + y^3 is: \n');
factor(x^3 + y^3)

fprintf('The simplification of (x^4-16)/(x^2-4) is: \n');
simplify((x^4-16)/(x^2-4))

fprintf('The factorization of x^4+ y^4 is: \n');
factor(x^4+ y^4)

fprintf('The factorization of x^5 - y^5 is: \n');
factor(x^5 - y^5)

%% Finding the limits 
fprintf('=========== FINDING THE LIMITS ===========\n');
syms x

fprintf('The limit of the function is (x^3 + 5)/(x^4 + 7) :\n');
limit((x^3 + 5)/(x^4 + 7))

fprintf('The limit of the function is (x - 3)/(x-1) :\n');
limit((x - 3)/(x-1),1)

fprintf('The limit of the function is (1 - x^0.5)/(1 - x) :\n');
limit((1 - x^0.5)/(1 - x),1)

fprintf('The limit of the function is (sin(5*x))/(3*x) :\n');
limit((sin(5*x))/(3*x))

f = (x - 3)/abs(x-3);
ezplot(f,[-1,5])
fprintf('The left limit of the function is :\n');
l = limit(f,x,3,'left')
fprintf('The right limit of the function is :\n');
r = limit(f,x,3,'right')
