def fact(x):
    if(x==0):
        return 1
    else:
        multiplier=1
        for i in range(x,0,-1):
            multiplier*=i
        return multiplier
 
def rad(x):
    y = (3.14/180)*x
    return y
 
def sin(x):
    x = rad(x)
    flag=True
    add_factor=0
    for i in range(1,101,2):
        if(flag):
            add_factor+=(x**i)/fact(i)
        else:
            add_factor-=(x**i)/fact(i)
        flag=not flag
    return add_factor        
 
def cos(x):
    x = rad(x)
    flag=False
    add_factor=0
    for i in range(0,100,2):
        if(flag):
            add_factor-=(x**i)/fact(i)
        else:
            add_factor+=(x**i)/fact(i)
        flag=not flag
    return add_factor
 
def tan(x):
    return sin(x)/cos(x)
 
 
a=float(input())
d=float(input())
print("The Height of the pole is",tan(a)*d)
print("The length of the line from observer to top of the pole is",d/cos(a))