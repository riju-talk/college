t=int(input())
for i in range(t):
    g=int(input())
    ls=list(map(int,input().split()))
    count=0
    i=0
    for i in range(g-1):
        if(ls[i]%ls[i+1]==0):
            ls[i]+=1
    for i in range(g-1):
        if(ls[i+1]%ls[i]==0):
            ls[i]+=1
    for i in range(len(ls)):
        print(ls[i],end=" ")