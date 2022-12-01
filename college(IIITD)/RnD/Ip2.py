def sum_digits(n):
    s=0
    while(n!=0):
        s+=n%10
        n//=10
    return s
def if_div(n,s):
    if(n%s==0):
        return True
    else:
        return False
x=int(input())
print(if_div(x,sum_digits(x)))