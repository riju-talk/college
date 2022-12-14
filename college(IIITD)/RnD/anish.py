n=int(input())
for i in range(1,n):
    
    for k in range(n-i,0,-1):
        print(" ",end="")
    
    for j in range(i*2-1):
        print("*",end="")
    print("")

for i in range(1,n+1):
   
    for k in range(n-i,0,-1):
        print(" ",end="")
    
    for j in range(i*2-1):
        print("*",end="")
    print("")

for i in range(1,n):
    
    for k in range(0,i):
        print(" ",end="")
    
    for j in range((n-i)*2-1,0,-1):
        print("*",end="")
    print("")

for i in range(1,n):
    
    for k in range(0,i):
        print(" ",end="")
    
    for j in range((n-i)*2-1,0,-1):
        print("*",end="")
    print("")