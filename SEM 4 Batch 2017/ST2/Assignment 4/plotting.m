%% Question 1
x = [1 2 4 2 4 6 2 ];
y = [3 1 3 4 5 2 2 ];
plot(x,y);

%% Question 2
x1 = [1 2 3];
y1 = [1 2 3];
x2 = [2 1 4];
y2 = [1 3 2];
plot(x1, y1, 'g', x2, y2, 'y'), grid on, legend('Plot 1', 'Plot 2'), 
xlabel('X Axis'), ylabel('Y Axis'), title('Question 2');

%% Question 3 Part 1
x = 0 : 0.1 : 4*pi;
y = sin(x);
z = cos(x);
plot(sin(x), 'r'), grid on, xlabel('x'), ylabel('sin(x)'),title('SINE CURVE');

%% Question 3 Part 2
plot(x,z), grid on, xlabel('x'), ylabel('cos(x)'),title('COSINE CURVE');

%% Question 3 Part 3
plot(x, y, 'g', x, z, 'r'), grid on, legend('sin(x)', 'cos(x)'), 
xlabel('x'), title('Question 3');

%% Question 5
x = 0 : 0.1 : 2*pi;
subplot(2,3,1)
plot(x, sin(x)), xlabel('x'), ylabel('sin(x)'), title('SINE GRAPH'), grid on;
subplot(2,3,2)
plot(x, cos(x)), xlabel('x'), ylabel('cos(x)'), title('COSINE GRAPH'), grid on;
subplot(2,3,3)
plot(x, tan(x)), xlabel('x'), ylabel('tan(x)'), title('TANGENT GRAPH'), grid on;
subplot(2,3,4)
plot(x, csc(x)), xlabel('x'), ylabel('cosec(x)'), title('COSECENT GRAPH'), grid on;
subplot(2,3,5)
plot(x, sec(x)), xlabel('x'), ylabel('sec(x)'), title('SECENT GRAPH'), grid on;
subplot(2,3,6)
plot(x, cot(x)), xlabel('x'), ylabel('cot(x)'), title('COTANGET GRAPH'), grid on;

%% Question 6
x = -10 : 0.01: 10;
y = 3*x.^4 + 2*x.^3 + 7*x.^2 + 2*x + 9;
plot(x,y), xlabel('x'), ylabel('f(x)'), title('Question 6'), grid on


%% Question 7
x = -10 : 0.01: 10;
y1 = 2 - (x - 3).^2;
y2 = x/2 + 1;
plot(x, y1, 'g', x, y2, 'r'), grid on, legend('Plot 1', 'Plot 2'), 
xlabel('X Axis'), ylabel('Y Axis'), title('Question 7');

%% Question 8
data = [9, 3, 6, 12];
bar(data);
set(gca, 'xtickLabel',{'Walk', 'Bike', 'Car', 'Bus'});

%% Question 8 Pie Chart
labels = {'Walk', 'Bike', 'Car', 'Bus'};
explode = [0 1 0 1];
pie(data,explode,labels);