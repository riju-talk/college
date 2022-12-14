t=int(input())
for i in range(t):
    l=list(map(int,input().split()))
    count=2
    if(l[0]==l[2] or l[1]==l[2]):
        count-=1
    if(l[0]==l[3] or l[1]==l[3]):
        count-=1
    print(count)