//sine function
x=0:0.1:10;
subplot(5,1,1);
y=sin(x);
xlabel('x');
ylabel('sin(x)');
plot(x,y);

//cosine function
z=cos(x);
subplot(5,1,2);
xlabel('x');
ylabel('cos(x)');
plot(x,z);

//tangent function
x=0:0.01:10
k=tan(x);
subplot(5,1,3);
xlabel('x');
ylabel('tan(x)');
plot(x,k);

//unit step function
i=1;
x=-20:0.01:20;
for k=-20:0.01:20
    if k>=0 then
        y(1,i)=1;
    else
        y(1,i)=0;
    end
    i=i+1;
end
square(-20,-0.5,20,1.5);
subplot(5,1,4);
xlabel('x');
ylabel('u(x)');
plot(x,y);

//unit ramp function
t=-20:0.01:20;
y=t;
subplot(5,1,5);
xlabel('t');
ylabel('r(t)');
plot(t,y);
        

