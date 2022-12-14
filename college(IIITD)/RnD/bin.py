ls1=list(map(int, input().split()))
ls2=list(map(int, input().split()))
emp=[]
def unique(emp):
    for i in range(len(emp)):
        for j in range(i+1,len(emp)):
            if(emp[i]==emp[j]):
                for k in range(j+1,len(emp)):
                    emp[k-1]=emp[k]
    for i in range(1,len(emp)):
        if(emp[i-1]==emp[i]):
            emp=emp[:i]
            break
        return emp
ls1=unique(ls1)
ls2=unique(ls2)
emp+=ls1+ls2
emp=unique(emp)
emp.sort()
print(emp)