import math
def d(x):
    y = math.log(6-5*math.log(x))
    return y

def s(x):
    y = math.log(7+8*(x))
    return y

def diff_factor(f,g,x):
    y = abs((f(x))-(g(x)))
    return round(y,2)

a = int(input("Enter the initial limit: "))
b = int(input("Enter the final limit: "))

for i in range (a,b+1):    
    x = diff_factor(d,s,i)
    if(x<=0.5):
        print("Equilibrium prize:",x)
        break
else:
    print("No equilibrium found")