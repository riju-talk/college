def profit(x1,x2,m,i):#profit equation
    if(i<=m):
        p=x1*90+x2*25
        return p
    else:
        p=x1*100+x2*30
        return p
print(profit(10,10,10,19))