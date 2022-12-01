x=eval(input())
emp1=list()
for i in range(x):
    j=int(input())
    emp1.append(j)
y=int(input())
emp2=list()
for i in range(y):
    j=int(input())
    emp2.append(j)
emp=[]
emp+=emp1
emp+=emp2
emp.sort()
