import math
x=int(input())
binlst=0
i=0
while(x!=0):
    binlst+=x%2*(10**i)
    x//=2
    i+=1
one=0
for j in list(str(binlst)):
    if(j=="1"):
        one=one+1
zero=5-one
if(one<3):   
    prime = math.factorial(5)/(math.factorial(5-one)*one)
else:
    prime = math.factorial(5)/(math.factorial(5-zero)*zero)
print(int(prime)) 