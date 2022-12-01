x=input()
y=input()
x = list(x)
y = list(y)
x.reverse()
y.reverse()
x.append("0")
y.append("0")
if(len(x)>len(y)):
    while len(x)>len(y):
        y.append("0")
else:
    while len(y)>len(x):
        x.append("0")

carry=0
sum=[]
for i in range(len(x)):
    if(x[i]=="1" and y[i]=="1"):
        if carry==1:
            sum.append(1)
            carry=1
        else:
            sum.append(0)
            carry=1
    elif(y[i]=="1" or x[i]=="1"):
        if carry==1:
            sum.append(0)
            carry=1
        else:
            sum.append(1)
            carry=0
    else:
        if carry==1:
            sum.append(1)
            carry=0
        else:
            sum.append(0)
            carry=0
if(sum[-1]==0):
    sum.pop(-1)
sum.reverse()
print(sum)