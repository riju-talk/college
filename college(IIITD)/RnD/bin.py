n=int(input())
bin=0
i=0
while(n!=0):
    bin+=n%2*(10**i)
    n//=2
    i+=1
print(bin)