t=[-2,-3,4,-1,-2,1,5,-3]
ls=list()
emp=list()
for k in range(0,len(t)-1):
    for i in range(len(t)-k):
        sum=0
        for j in range(i,len(t)-k):
            sum+=t[j]
        emp.append(sum)
print(max(emp))