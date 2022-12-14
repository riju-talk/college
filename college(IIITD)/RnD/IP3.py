import math
def velocity(t):
    v = 2000*(math.log(140000/(140000-2100*t))) - 9.8*t
    return v
def integrate(a,b,f,dx):
    summ=0
    dist=0
    j=a
    while(j<=b):
        dist+=(summ*dx)
        summ=f(j)
        j+=dx
    return dist
a = int(input("Enter the starting point: "))
b = int(input("Enter the final time: "))
c = integrate(a,b,velocity,0.25)
print(c)
