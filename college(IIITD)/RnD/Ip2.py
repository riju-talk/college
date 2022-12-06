"""Basically there are two separate loops
    one loop is for 5 to 2 downwards (look at the middle most digits)
    I tried making an hourglass pattern first
    555555555
     4444444
      33333
       222
        1
       222
      33333
     4444444
    555555555
"""
n=int(input())

for i in range(0 , n-1):
    count=0
    for j in range(1 , i+1):
        print(n-j+1,end="")
    #main
    for k in range(0 , 2*(n-i)-1):
        print(n-i,end="")
    
    for l in range((n-i+1) , n+1):
        print(l,end="")
    
    print("")
    
for i in range(1 , n+1):
    count=0
    for j in range(1 , n-i+1):
        print(n-j+1,end="")
    #main
    for k in range(0 , 2*i-1):
        print(i,end="")
    
    for l in range(1 , n-i+1):
        print(l+i,end="")
    
    print("")