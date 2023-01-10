t=int(input())
for i in range(t):
    t1,n,s=list(map(int, input().split()))
    summ=s
    result=0
    for i in range(t1):
        if(summ>0 and summ<n):
            result+=summ**2
            break
        elif(summ==0):
            break
        summ-=n
        result+=n**2
    print(result)