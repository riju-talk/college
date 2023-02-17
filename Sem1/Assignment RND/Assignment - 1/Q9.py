import math
e=math.e
def D(x,a,b):# Demand Function
    return e**(a-b*x)

def S(x,c,d):# Supply Function
    return e**(c+d*x)
# Intial Price
x=float(input())
i=0
while(i<80):
    y1=D(x,10,1.05)
    y2=S(x,1,1.06)
    z=abs(y1-y2)
    if round(z/100,1)<=(0.5):
        break
    x=x+x/20  
    i+=1
if(i==80):
    print("No price found")  
else:
    print(x)
