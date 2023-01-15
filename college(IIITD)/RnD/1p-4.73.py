x=list(map(int,input().split()))
y=list(map(int,input().split()))
count=0
d={}
ls=[]
for i in range(len(x)):
    d[x[i]]=y[i]
for i in d.keys():
    f=i
    count=1
    for j in d.keys():
        count+=1
        if(d[j]==f):
            break
    ls.append(count)
if(max(ls)>len(ls)):
    print(max(ls)-len(ls))
else:
    print(max(ls))