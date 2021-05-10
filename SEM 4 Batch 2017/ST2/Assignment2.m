%% Find Whether the number is positive negetive or zero
a = input('Enter a number:');
if a > 0
    disp('Number is greater than 0');
elseif a < 0
    disp('Number is less than 0');   
else 
    disp('Number is equal to 0');
end


%% Table of 5 using while loops
disp('Table of 5 using while loops');
a = 1;
while a<= 10
       fprintf('%d ',5*a);
       a = a + 1;
end
fprintf('\n\n');

%% Table of 5 using for loops
disp('Table of 5 using for loops');
for a = 1:10
    fprintf('%d ',5*a);
end
fprintf('\n\n');

%% Transpose of matrix using loop
A = [1 2 3; 4 5 6; 7 8 9];
disp('Before transpose the matrix is:');
disp(A);

disp('Transpose of the matrix is:');
B = zeros(3,3);  % Pre-allocating
for i = 1:3
    for j = 1:3
        B(i,j) = A(j,i); 
    end
end
disp(B);

A = [1 2 3; 4 5 6; 7 8 9];
B = [1 2 3; 4 5 6; 7 8 9];
C = zeros(3,3);

%% Addition of two matrix using loops
for i = 1:3
    for j = 1:3
        C(i,j) = A(i,j) + B(i,j);
    end
end
disp('The addition of two matrix:');
disp(C);

%% Multiplication of two matrix using loops
disp('The multiplication of two matrix:');
for i = 1:3
    for j = 1:3
        sum = 0;
        for k = 1:3
           sum = sum + A(i,k) * B(k,j);
        end
        C(i,j) = sum;
    end
end
disp(C);

%% Reverse of a given number
a = input('Enter the number: ');
rev = 0;
rem = 0;
while a > 0
    rem = mod(a,10);
    rev = rev * 10 + rem;
    a = (a - rem)/10;
end
disp('Reverse of the given number is: ');
disp(rev);

%% Sum of first and last digit of given number
a = input('Enter the number: ');
i = 0;
sum = 0;
while a > 0
    rem = mod(a,10);
    a = (a - rem)/10;
    if(i == 0)
        sum = sum + rem;
        i = i +1;
    elseif(a == 0)
        sum = sum + rem;
    end
end
disp('The sum of first and last digit of the number is: ');
disp(sum);
        
%% Largest digit in a given number
a = input('Enter the number: ');
rem = 0;
max = -1;
while a > 0
    rem = mod(a,10);
    if rem > max
        max = rem;
    end
    a = (a - rem)/10;
end
disp('The largest of the two numbers is : ');
disp(max);

%% Sum of two column/rows of matrix
A = [1 2 3;4 5 6; 7 8 9]; 
choice = input('Enter 1 for row 2 for column:');
if choice == 1
    row1 = input('Enter row number 1:');
    row2 = input('Enter row number 2:');
    sum = [0 0 0];
    for i = 1:3
        sum(i) = sum(i) + A(row1,i) + A(row2, i);
    end
    fprintf('The sum of two rows is\n');
    disp(sum);
elseif choice == 2
    col1 = input('Enter col number 1:');
    col2 = input('Enter col number 2:');
    sum = [0; 0; 0];
    for i = 1:3
        sum(i,1) = sum(i) + A(i,col1) + A(i, col2);
    end
    fprintf('The sum of two columns is\n');
    disp(sum);
else 
    fprintf('Wrong choice entered\n');
end

%% Positions of matrix which are divisible by 5 and 7
A = [1 2 3 4; 23 11 34 20; 12 14 35 70; 140 12 11 10];
disp('The positions which are divisible by 5 and 7 are:');
for i = 1:4
    for j = 1:4
        if mod(A(i,j),5) == 0 || mod(A(i,j),7) == 0
            fprintf('%d %d\n', i,j);
        end
    end
end

%% Positions of matrix which are prime numbers
disp('The positions which are prime numbers:');
for i = 1:4
    for j = 1:4
        count = 0;
        for k = 1:A(i,j)
            if mod(A(i,j),k) == 0
               count = count + 1;
            end
        end
        if count == 2
            fprintf('Number: %d  Index: %d %d\n', A(i,j),i,j);
        end
    end
end

%% Delete duplicate elements from a array
a = randi(10,[1,10]);
fprintf('The Array is :\n');
disp(a);
b = unique(a);
fprintf('The array after the deletion is :\n');
disp(b)

%% Check if a given number is perfect or not
sum = 0;
a = input('Enter a number: ');
for i = 1:a/2
    if mod(a,i) == 0
        sum = sum + i;
    end
end

if sum == a
    disp('The Number is a perfect number.');
else 
    disp('The Number is not a perfect Number');
end

%% Faabonacci series
fprintf('1 1 ');
n = 1;
m = 1;
temp = 0;
for i = 1:8
    temp = m;
    m = m + n;
    n = temp;
    fprintf('%d ',m);
end
fprintf('\n');

%% Check if a matrix is magic square or not
A = [1 1 1; 1 1 1; 1 1 1];
% For Diagonal
sum = 0;
flag = 0;
for i = 1:3
    for j = 1:3
        if i == j
            sum = sum + A(i,j);
        end
    end
end

% For Rows
for i = 1:3
    sum1 = 0;
    for j = 1:3
        sum1 = sum1 + A(i,j);
    end
    if sum == sum1
        flag = 1;
    else
        flag = 0;
        break;
    end
end

% For columns
for i = 1:3
    sum2 = 0;
    for j = 1:3
        sum2 = sum2 + A(j,i);
    end
    if sum == sum2
        flag = 1;
    else
        flag = 0;
        break;
    end
end

if flag == 1
    fprintf('The matrix is a MAGIC SQUARE\n');
else
    fprintf('The matrix is not a magic square\n');
end

%% Patterns
fprintf('\nThe pattern number 1 is:\n');
for i = 1:4
    for j = 3:-1:i
        fprintf(' ');
    end
    for j = 1:i
        fprintf('* ');
    end
    fprintf('\n');
end

fprintf('\nThe pattern number 2 is:\n');
A = 5;
for i = 1:5
    for j = 4:-1:i
        fprintf(' ');
    end
    for j = 1:i
        fprintf('%d ',A);
    end
    fprintf('\n');
    A = A - 1;
end

fprintf('\nThe pattern number 3 is:\n');
A = 'A';
for i = 1:4
    for j = 3:-1:i
        fprintf(' ');
    end
    for j = 1:i
        fprintf('%c ',A);
        A = A + 1;
    end
    fprintf('\n');
end
%% LAB patterns for evalution.
for i = 1:4
    for j = 3:-1:i
        fprintf(' ');
    end
    for j = 1:i
        fprintf('* ');
    end
    fprintf('\n');
end
for i = 1:3
    for j = 1:i
        fprintf(' ');
    end
    for j = 3:-1:i
        fprintf('* ');
    end
    fprintf('\n');
end
