def kangaroo(x1, v1, x2, v2):
    d1=x1+v1
    d2=x2+v2
    if(d1%2==0 and d2%2==0):
        return "YES"
    elif(d1%2!=0 and d2%2!=0):
        return "YES"
    else:
        return "NO"
b=kangaroo(21,6,47,3)
print(b)