x = linspace(0,2,15);
y = sqrt(x);
p = polyfit(x,y,14);
x1 = linspace(0,2);
y1 = polyval(p,x1);
y2 = sqrt(x1);

figure(1)
plot (x1,y2,'LineWidth',3)
hold on 
plot(x1,y1)
legend('f(x)','p(x)')
set(gca,'ytick', 0:1:10.45)
xlabel("x"); ylabel("y")
hold off

figure(2) 
grid on 
diff = abs(y1-y2);
semilogy(x1,diff);
hold on 
legend('log(abs(f(x)-p(x)))')

xlabel("x"); ylabel("log(abs(f(x)-p(x)))")
hold off 

figure(3) 
yy = spline(x,y,x1);
plot(x1,y2,x1,yy)
hold on 
legend('f(x)','p(x)')
ylim([0,1.45]);
xlabel("x"); ylabel("y")
hold off

figure(4) 

diff = abs(yy-y2);
semilogy(x1,diff);
hold on 
legend('log(abs(f(x)-p(x)))')

xlabel("x"); ylabel("log(abs(f(x)-p(x)))")
hold off 

figure(5) 

n = 14;
a = linspace(0,2,15);
p2 = 1+cos(((2.*a+1)/(2.*(14)+2)).*pi);
%for i=0:14
    %p2(i+1) = (1 * cos(((pi/(n+1))*(0.5+i)))); %compute chebyshev points
 %end
p3 = spline(x,y,p2)
a2 = linspace(0,2);
y3 = polyval(p3,a)

plot(x1,y2,x1,y3)




%{
n = 8; 
count = 1;
while n<=32,    
    resolution = 100; 
    for i=0:n
        X(1,i+1) = -1 * cos(((pi/(n+1))*(0.5+i))); %compute chebyshev points
    end
    clear i;
    for i=0:n
        Y(1,i+1) = sign(X(1,i+1)); %find actual points using sign(x) eq.
    end
    [P,S] = polyfit(X,Y,n); %perform actual fit
    clear i
    for step=0:2*resolution
        clear Q;
        for i=n:-1:0
            temp = 1;
            for j=0:i-1
                temp = temp * (step/resolution-1); %performing looping X^n
            end
            Q(1,n-i+1) = P(1,n-i+1) * temp;
        end
        total = 0;
        for i=0:n
            total = total + Q(1,i+1);
        end
        Xapp(1,step+1) = step/resolution - 1;
        Yapp(1,step+1) = total; %assign polynomial value on Y @ X step
    end
    subplot(3,1,count), plot(X,Y);
    hold on;
    subplot(3,1,count), plot(Xapp,Yapp,'color',[.6 0 0]);
    n = n * 2;
    count = count + 1;
    clear Xapp Yapp Q X Y step i j
end
%}
