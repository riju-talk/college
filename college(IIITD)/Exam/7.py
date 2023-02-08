l = [1, 1, 2, 2, 1, 3, 2, 4, 5, 2, 6, 7, 8, 9]
dic={}
ls=[]
n=int(input())
for i in range(len(l)):
    if(l[i]==n):
        ls.append(str(i))
for i in range(len(l)):
    dic[l[i]]=dic.get(l[i],0)+1
print("frequency is",dic[n])
dt=",".join(ls)
print(dt)