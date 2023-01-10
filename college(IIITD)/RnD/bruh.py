x=list(input().split())
c={}
for i in x:
    c[i.lower()]=c.get(i.lower(),0)+1
factor2=list(c.keys())
for i in range(len(factor2)):
    for j in range(len(factor2)-1-i):
        if(c[factor2[j]]<c[factor2[j+1]]):
            factor2[j],factor2[j+1]=factor2[j+1],factor2[j]
        elif(c[factor2[j]]==c[factor2[j+1]]):
            if(factor2[j]<factor2[j+1]):
                factor2[j],factor2[j+1]=factor2[j+1],factor2[j]
for i in factor2:
    print(i,end=" ")
"""count=0
for i in range(len(c)):
    flag=True
    for j in range(len(c)):
        if(c[i]==c[j] and i!=j):
            flag=False
            break
    if(flag):
        count+=1
print(count)"""