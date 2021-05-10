%% Even odd counting function
%vect = [12, 32, 31, 47, 51, 63, 72, 98, 109, 110, 11, 212];
prompt = 'Enter the vector:  ';
vect = input(prompt);
[even_count , odd_count] = even_odd(vect);
fprintf('The even count is %d\n', even_count);
fprintf('The odd count is %d\n', odd_count);

%% Returns even number vect
prompt = 'Enter the vector:  ';
vect = input(prompt);
resVect = even_vector(vect);
fprintf('The even vector is\n');
disp(resVect);

%% Return even position vectors
prompt = 'Enter the vector:  ';
vect = input(prompt);
resVect = even_posi(vect);
fprintf('The even position vector is\n');
disp(resVect);

%% Return Average height
%heightVect = [145, 187, 175, 165, 174, 180];
prompt = 'Enter the heights of people:  ';
heightVect = input(prompt);
averageHeigh = averageHeight(heightVect);
fprintf('The average height of students is\n');
disp(averageHeigh);

%% Return height in meteres
%height = [1 45;1 87;1 75; 1 65;1 74; 1 80];
prompt = 'Enter the heights of the people:  ';
height = input(prompt);
[m_vect, cm_vect] = returnHeight(height, 6);
fprintf('The height in meteres and cms are\n');
disp(m_vect);
disp(cm_vect);

%% Push Pop from stack
fprintf('============== WELCOME TO MATLAB STACK ===============\n');
stackVect = [];
choice = 1;
while choice ~= 4
    fprintf('1.PUSH\n2.POP\n3.SHOW\n4.EXIT\n');
    prompt = 'Choose any one of the above:   ';
    choice = input(prompt);
    switch choice
        case 1
            val = input('Enter the number to be pushed   :');
            stackVect = push(stackVect, val, 10);
            if length(stackVect) ~= 10
                fprintf('The number is pushed successfully.\n');
            end
        case 2
            [stackVect, value] = pop(stackVect);
            if ~isempty(stackVect)
                fprintf('The value popped is  :  %d \n', value);
            end
        case 3
            if isempty(stackVect)
                fprintf('The stack is empty\n');
            else
                fprintf('The vector is  :\n');
                disp(stackVect);
            end
        case 4
            fprintf('Its exit time.');
            fprintf('At last the vector is  :\n');
            disp(stackVect);
        otherwise
            fprintf('The choice entered is worng.\n');
    end
    fprintf('*****************************************\n');
end

%% Return sum of eigen values
%matrix = [2 1 0; 1 2 1; 0 1 2];
prompt = 'Enter the matrix:   ';
matrix = input(prompt);
fprintf('The matrix is :  \n');
disp(matrix);
sumOfEigen = eigen(matrix);
fprintf('The sum of eigen values of the matrix is  : \n');
disp(sumOfEigen);

%% Finding the names
%vect = {'Mark', 'Simon', 'Juhi', 'Rahul', 'John', 'Roony','Marshmallo'};
vect = {};
prompt = 'Enter the name string:   ';
vect = input(prompt);
prompt = 'Enter the name to be searched:  ';
reqName = input(prompt, 's');
index = findNameInd(vect, reqName);
if index == -1
    fprintf('There is no such name in the vector.\n');
else
    fprintf('The index of the name is %d.\n',index);
end

%% Finding names in the matrix
%vect = {'Mark', 'Simon', 'Juhi',; 
       %'Rahul', 'John','Marshmallo'};
vect = {};
prompt = 'Enter the name string:   ';
vect = input(prompt);
prompt = 'Enter the name to be searched:  ';
reqName = input(prompt, 's');

[x, y] = findNamedMat(vect, reqName);
if x == -1
    fprintf('There is no such name in the vector.\n');
else
    fprintf('X-Index: %d        Y-Index: %d\n',x,y);
end

%% Returning pass or fail of students
%marks = [ 43, 54, 87, 12, 34, 30];
prompt = 'Enter the marks of the students:  ';
marks = input(prompt);
fprintf('The list of marks is : \n');
disp(marks);
fprintf('The pass or fail array is : \n');
resultVect = passOrFail(marks);
disp(resultVect);
