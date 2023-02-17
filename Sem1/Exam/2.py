ls=[10000,20000,50000,100000,40000,18000]
def fun(ls):
    nls=sorted(ls)
    n=len(nls)
    if(len(nls)%2==0):    
        md=(nls[(n//2)-1]+nls[n//2])/2
    else:
        md=nls[n//2]
    sal1=0
    count1=0
    for i in nls:
        if(i<md):
            sal1+=i
            count1+=1
    av1=sal1/count1
    
    sal2=0
    count2=0
    for i in nls:
        if(i>=md):
            sal2+=i
            count2+=1
    av2=sal2/count1
    return [av1,av2]
d = fun(ls)
print("average value of salaries for students under median salary",d[0],"\naverage value of salaries for students above or equal to median salary",d[1])