cost=int(input("Enter the cost of Laptop: "))
def count_months(cost,r,allowence,sf):
    netamout=0
    count=0
    while(netamout<cost):
        count+=1
        netamout+=netamout*(r)
        netamout+=allowence*(sf)
    return count
print("The time required is",count_months(cost,0.5,20000,0.1),"months")