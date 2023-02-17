n=int(input())
x = 2*n-1
for i in range(0,int(x/2)):
    y=n
    for j in range(0,i):
        print(y,end="")
        y-=1
    for k in range(0,x-2*i):
        print(n-i,end="")
        y=n-i+1

    for l in range(0,i):
        print(y,end="")
        y+=1
    print("")
   
for i in range(int(x/2),-1,-1):
    y=n
    for j in range(0,i):
        print(y,end="")
        y-=1
    for k in range(0,x-2*i):
        print(n-i,end="")
    y=n-i+1
    for l in range(0,i):
        print(y,end="")
        y+=1
    print("")