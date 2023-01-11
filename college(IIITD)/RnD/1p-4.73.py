x=input()
st=""
i=0
while(i<len(x)-1):
    st+=x[i]
    if(x[i]==x[i+1]):
        i+=2
    else:
        i+=1
if(len(st)==0):
    print("Empty String")
else:
    print(st)