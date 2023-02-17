def in_out(x,name,time):
    h=x[name]
    ls=[]
    for i in h["Time"]:
        if(i<time):
            ls.append(i)
    m=h["Time"].index(max(ls))
    if(h["Crossing Type"][m]=="ENTER"):
        return [(h["Crossing Type"][:m+1],h["Time"][:m+1]),"In Campus"]
    else:
        return [(h["Crossing Type"][:m+1],h["Time"][:m+1]),"Not in Campus"]
    


def time_range(x,start,end):
    en=[]
    ex=[]
    for i,j in x.items():
        for k in range(len(j["Time"])):
            if(start<=j["Time"][k]<=end):
                if(j["Crossing Type"][k]=="ENTER" and i not in en):
                    en.append(i)
                elif(j["Crossing Type"][k]=="EXIT" and i not in ex):
                    ex.append(i)
    return [en,ex]

def gate_number(x,y):
    counte=0
    countl=0
    for j in x.values():
        d=j.get("Gate Number")
        e=j.get("Crossing Type")
        for i in range(len(d)): 
            if(d[i]==y):
                if(e[i]=="EXIT"):
                    countl+=1
                else:
                    counte+=1
    return f"the gate number {y} has been used a total of {countl+counte} times {counte} times to enter and {countl} times to exit"

f=open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\sorted_data.txt","r")
dump=f.read()
f.close()
#------------------------------------------
inter=dump.split("\n")
n_inter=[i.split(", ") for i in inter]
one_more_inter=n_inter[1:]
final_f=[i for i in one_more_inter]
final_f=final_f[:-1]
#-------------------------------------------
sorted_f=sorted(final_f,key=lambda x:x[3])
main_dic={}
for i in sorted_f:
    if i[0].lower() not in main_dic.keys():
        main_dic[i[0].lower()]={"Gate Number":[int(i[2])],"Crossing Type":[i[1]],"Time":[i[3]]}
    else:
        get=main_dic.get(i[0].lower())
        if(get["Crossing Type"][-1]==i[1] and i[1]=="ENTER"):
            continue
        elif(get["Crossing Type"][-1]==i[1] and i[1]=="EXIT"):
            get["Gate Number"][-1]=int(i[2])
            get["Crossing Type"][-1]=i[1]
            get["Time"][-1]=i[3]
            main_dic[i[0].lower()]=get
        else:
            get["Gate Number"]+=[int(i[2])]
            get["Crossing Type"]+=[i[1]]
            get["Time"]+=[i[3]]
            main_dic[i[0].lower()]=get
while(True):
    try:
        n=int(input())
        if(n==1):
            x=input()
            y=input()
            c=in_out(main_dic,x,y)
        elif(n==2):
            x=input()
            y=input()
            c=time_range(main_dic,x,y)
        elif(n==3):
            x=int(input())
            c=gate_number(main_dic,x)
            print(c)
    except:
        break
if(n==1):
    part1=list(zip(c[0][0],c[0][1]))
    part1=list(map(str,part1))
    part1+=[c[1]]
    nstr="\n".join(part1)
    f=open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\output.txt","w")
    f.write(nstr)    
    f.close()
elif(n==2):
    c[0]=["Students who Entered the College"]+c[0]
    c[1]=["Students who Exited the College"]+c[1]
    part1=list(zip(c[0],c[1]))
    part1=list(map(list,part1))
    part1=list(map(str,part1))
    nstr="\n".join(part1)
    f=open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\output.txt","w")
    f.write(nstr)   
    f.close()