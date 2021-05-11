A=[1 2 3;4 5 6;7 8 9];
B=[1 2 3;4 5 6;7 8 9];

% Transpose of A
disp(A');

% Addition of two matrix
C=A+B;
disp(C);

% Multiplication of two matrix
D=A*B;
disp(D);

% Individual multiplication
E=A.*B;
disp(E);

% Square Individual elements of a and b
F=A.*A;
disp(F);
G=B.*B;
disp(G);

% Display First row of matrix A
disp(A(1,:));

% Display last column of matrix B
disp(B(:,3));

% Display det of matrix A
H=det(A);
disp(H);

% Inverse  of matrix A
I=inv(B);
disp(I);

% Random array 
J=randi(5,6);
disp(J);

% String
K='I am an Indian';
disp(K);

% Type of each variable
disp(class(A));
disp(class(B));
disp(class(C));
disp(class(D));

% 3rd to 4th row 2nd to 5th column
L=J([3 4],[2 3 4 5]);
disp(L);

% Exist 
if exist('A') 
    disp('A variable exist');
else 
    disp('A variable does not exist');
end

% Clear a single variable
clear;

A = [ 22 44 36; 52 57 68; 66 53 69; 85 40 86; 15 47 25; 79 72 82];

% Append marks of mechanics
A(:,4) = [36 76 76 72 28 91];

% Scale marks of mechanics to half
B = A;
B(:,4) = B(:,4)./2;
disp(B);

% Extract marks 3 and give it to chetan
B = A(3,:);
S = sum(B);
disp('Marks of chetan:');
disp(B);
disp('Total of chetan:');
disp(S);

% Extract marks of our best students, Deepak and Farah for first three courses
C = A(4,[1 2 3]);
D = A(6,[1 2 3]);
disp('Marks of deepak:');
disp(C);
disp('Marks of farah:');
disp(D);

% Average of each marks
B = A(:,1);
disp(sum(B)/4);
B = A(:,2);
disp(sum(B)/4);
B = A(:,3);
disp(sum(B)/4);
B = A(:,4);
disp(sum(B)/4);

% Display each marks as 10
B = A;
disp(B);
B = B./10;
disp(B);
