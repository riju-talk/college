f=open("trust.txt","r")
dump=f.read()
star=dump.split("\n")
f.close()
print()
ls=[i.split(", ") for i in star]
ds=[]
for i in ls:
    if(i[0] not in ds):
        ds.append(i[0])
main_dic={}
for i in ls:
    if i[0] not in main_dic.keys():
        main_dic[i[0]]={"Gate Number":[int(i[2])],"Crossing Type":[i[1]],"Time":[i[3]]}
    else:
        get=main_dic.get(i[0])
        if(get["Crossing Type"][-1]==i[1] and i[1]=="ENTER"):
            continue
        elif(get["Crossing Type"][-1]==i[1] and i[1]=="EXIT"):
            get["Gate Number"][-1]=int(i[2])
            get["Crossing Type"][-1]=i[1]
            get["Time"][-1]=i[3]
            main_dic[i[0]]=get
        else:
            get["Gate Number"]+=[int(i[2])]
            get["Crossing Type"]+=[i[1]]
            get["Time"]+=[i[3]]
            main_dic[i[0]]=get
print(ds)
print(len(ds))
print(main_dic)