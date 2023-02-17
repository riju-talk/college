def pop_after_n(n,x,r):# population calculating function
    temp=x.copy()
    summ=0
    for j in range(n):
        y=r
        for i in range(len(temp)):
            temp[i]=temp[i]+(y/100)*temp[i]
            y-=0.4
        r=r-0.1
    for i in range(len(temp)):
        summ+=temp[i]
    return round(summ,2)
pop = [50, 1450, 1400, 1700, 1500, 600, 1200]#current frame of population

#main program
i=0
while(True):
    y1=pop_after_n(i,pop,r=2.5)#keyword argument
    y2=pop_after_n(i+1,pop,r=2.5)#keyword argument
    if(y1>y2):
        break
    i+=1
print("The current popolation of the world",pop_after_n(0,pop,r=2.5))
print("The years until maximum population and The maximum population")
print(i,"and",pop_after_n(i,pop,r=2.5))