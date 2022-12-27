t=list(map(int, input().split()))
ls=[]
ind=[]
for i in range(len(t)):
    for j in range(len(t)):
        if(i!=j):
            if(t[i]>=t[j]):
                ls.append(t[j]*(abs(i-j)-1))
            elif(t[i]<=t[j]):
                ls.append(t[i]*(abs(i-j)-1))
            ind.append([i,j])
mx=max(ls)
f=ind[ls.index(max(ls))]
t=t[f[0]+1:f[1]]
for i in t:
    mx-=i
if(mx<0):
    mx=0
else:
    mx=mx
print(mx)