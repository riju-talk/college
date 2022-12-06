import math
def velocity(t):
    v = 2000*math.log(140000/140000-2100*t) - 9.8*t
    return v
def integrate(a,b,f,dx):
    summ=f(a)
    dist=0
    dxfact=0
    for i in range(a+1,b+1,dx):
        dxfact+=dx
        summ+=f(a+dxfact)
        dist+=(summ*dx)
    return dist
x=int(input())
