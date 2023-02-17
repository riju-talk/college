def grade(x): #this function calculates grades for a percentage
    if(x>80):
        return "A"
    elif(x>=70 and x<=80):
        return "A-"
    elif(x>=60 and x<70):
        return "B"
    elif(x>=50 and x<60):
        return "B-"
    elif(x>=40 and x<50):
        return "C"
    elif(x>=35 and x<40):
        return "C-"
    elif(x>=30 and x<35):
        return "D"
    elif(x<30):
        return "F"
#Here IPmarks.txt is being opened
f=open(r"Assignment RND\Assignnment-2\IPmarks.txt","r")
#here the file is being read
fil=f.read()
f.close()
n_ls=[]
roll_no=[]
dump=fil.split("\n")
#here a dump is being created from where data will be taken to do operations
for i in dump:
    j=i.split(", ")
    n_ls.append(list(map(float,j[1:])))
    roll_no.append(int(j[0]))
wts = [(10,20), (20,30), (100,35), (40,15)]
proces_ls=[]
tot_marks=[]
for i in n_ls:
    ls=[]
    #this is calculating percetnage and storing it in a list ls 
    #then this list is getting further stored in a bigger list proces_ls
    for j in range(len(i)):
        vr=(int(i[j])/int(wts[j][0]))*wts[j][1]
        ls.append(vr)
    proces_ls.append(ls)
    summ=0
    #this is adding all the marks by a student and storing it in a list tot_marks
    for k in range(len(i)):
        summ+=float(i[k])
    tot_marks.append(summ)
total=[]
for i in proces_ls:
    summ=0
    for j in i:
        summ+=j
    total.append(summ)
#the processed data is stored in list named
#Here IPgrades.txt is being opened 
f=open(r"Assignment RND\Assignnment-2\IPgrades.txt","w")
#Here the file is being written
for i in range(len(total)):
    d=", ".join([str(roll_no[i]),str(tot_marks[i]),str(grade(total[i]))])
    d+="\n"
    f.write(d)
f.close()