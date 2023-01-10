w="angel"
for i in range(0,6):
    x=input()
    wr_index=[]
    rt_places=[]
    count=0
    for j in range(len(x)):
        if(x[j] in w and x[j]!=w[j]):
            if(x[j]not in wr_index):
                wr_index.append(x[j])
            rt_places.append("-")
        elif(x[j] in w and x[j]==w[j]):
            count+=1
            rt_places.append(x[j])
        elif(x[j] not in w):
            rt_places.append("-")
            count+=0
    print("\n")
    if(count==5):
        print("Hurray you guessed right")
        print(f"{w}")
        break
    elif(i==5):
        print("Sorry, out of luck")
        print(f"The word was {w}")
        break
    if(len(wr_index)!=0):
        for i in wr_index:
            print(i,end=" ")
        print("exist in word but at wrong positions\n")
    if(len(rt_places)!=0 and count!=5 or len(rt_places)==5):
        print("Words in right places are:")
        for i in rt_places:
            print(i,end="")
        print("\n")
    else:
        print("No correct words found\n")