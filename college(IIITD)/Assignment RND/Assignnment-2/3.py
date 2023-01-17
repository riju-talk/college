#this program calculates the maximum numbers of signatures in the given file
#this function will take the processed dictionary and will count the person(key) with the maximum signatures
def sig_count(dic):
    sg_count=[]
    for i,j in dic.items():
        count_of_signatures=0
        for k,l in j.items():
            count_of_signatures+=l
        sg_count.append(count_of_signatures)
    maxx=0
    for i in sg_count:
        if(maxx<i):
            maxx=i
        else:
            maxx=maxx
    ls=[]
    for i in range(len(sg_count)):
        if(maxx==sg_count[i]):
            ls.append(i)
    return ls
d=open("D:\college\college(IIITD)\Assignment RND\Assignnment-2\\test.txt")#This function opens a test file in the local directory
"""
    This program works for file format of.

    bruh: ----1
    hellobruh,0
    bruhhello,1
    ifyoulikepinacolladas,0

    hellobruh: -----2
    bruh,1
    bruhhello,1
    ifyoulikepinacolladas,1

    ifyoulikepinacolladas: ------3
    bruh,1
    bruhhello,1
    hellobruh,0

    bruhhello: ---------4
    bruh,1
    ifyoulikepinacolladas,1
    hellobruh,0
    
    where 1,2,3,4
    are names.
    
"""
dump=d.read() #this is the file dump all the detailes from the files are stored here.
d.close() #this is where the test file is closed.
net=dump.split("\n\n")

basket=[]# this where the newline charcters are removed for ease in conversion
for i in net:
    temp=i.split("\n")
    basket.append(temp)

#this is the main dictionary that will store the data from the dump.
main_dic={}
for i in range(len(basket)):
    dic={}
    for j in range(1,len(basket[i])):
        temp=basket[i][j].split(",")
        dic[temp[0]]=int(temp[1])
    main_dic[basket[i][0][:-1]]=dic

#this stores the most signutures and postion of the key with the most signatures
result=sig_count(main_dic)

#this the list of names or keys of the main dict
names=list(main_dic.keys())

#here the name with maximum signatures is identified and stored in a variable using the index obtained
#from the function and 
max_name=""
for i in result:
    max_name+=names[i]+", "
print(f"{max_name}has the most signatures in all the students")