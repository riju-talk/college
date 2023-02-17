#taking Derivative of f(x) using coefficients
def derivative_of_f(ls):
    nls=[]
    for i in range(len(ls)):
        nls.append((len(ls)-(i+1))*ls[i])
        if(nls[i]==0):
            break
    nls.pop()
    return nls
#computing value of f(x) using coefficients and some x
def f(ls,x):
    sum=0
    for i in range(len(ls)):
        sum+=ls[i]*(x**(len(ls)-(i+1)))
    return sum
#computing the root using some value x0 and set of coefficients that indicate a polynomial
def solution(f,ls,x0):
    precision=0.2
    toexit=0
    nl=derivative_of_f(ls)
    while(toexit==0):
        x1=x0-(f(ls,x0)/f(nl,x0))
        x1=round(x1,2)
        if(f(ls,x1)<=precision and f(ls,x1)>=(-precision)):
            toexit=1
            return x1
        else:
            x0=x1   
#main program    
ls=[]
print("Enter the Coeffeciants of the polynomial in descending order then press enter to exit:") 
while(True):
    x=input()
    if(x==""):
        break
    ls.append(x)
y=float(input("Enter an approximate root for the equation: "))
nl=list(map(int,ls))
root=solution(f,nl,y)
print(root)