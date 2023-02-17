def profit(x1,x2,m):#profit equation
    if(x1>m and x2<=m):
        p=(x1-m)*100+x2*30+m*90
        return p
    elif(x2>m and x1<=m):
        p=x1*90+(x2-m)*30+m*25
        return p
    elif(x2>m and x1>m):
        p=(x1-m)*100+(x2-m)*30+m*25+m*90
        return p
    else:
        p=x2*25+x1*90
        return p
#main program
maine=[]
main2=[]
m=10 #if m's value ranges from 0, 20 the maximum profit will be constant
for j in range(1,121):
    for i in range(1,61):
        if(8*i+2*j<=400 and 2*i+j<=120):
            maine.append(profit(i,j,m))
            main2.append([i,j])
#prints maximum profit
print(max(maine))
print(main2[maine.index(max(maine))])