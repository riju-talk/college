x=int(input())
def pattern(x):
    for i in range(1,x+1):
        for j in range(0,i):
            print("*",end="")
       
        for k in range((x-i)*2):
            print(" ",end="")
   
        for j in range(0,i):
            print("*",end="")
        print("")
pattern(x)
