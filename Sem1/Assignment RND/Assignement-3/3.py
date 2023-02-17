from random import randint
from functions_3 import *


files=["297.txt", "316.txt", "230.txt", "205.txt","325.txt","328.txt","397.txt","390.txt"]
path=r"D:\college\college(IIITD)\Assignment RND\Assignement-3\3correct"
for file in files:
    plandic=[]
    f=open(path+r"\\"+file,"r")
    dump=f.read()
    f.close()
    dump=dump.split("\n")
    filter_st=" ".join(dump)
    var1=f1(filter_st)
    var2=f2(filter_st)
    csum=0
    for i,j in var2.items():
        csum+=int(j)
        plandic.append(i)
    csum/=len(split_sp(filter_st))
    var3=f3(filter_st)
    var4=f4(filter_st)
    var5=f5(filter_st)
    net_score = 4 + var1*6 + csum*6 -var3 - var4 - var5

    f=open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\scores.txt","a")
    f.write(f"{file}\n")
    f.write(f"Score: {net_score}")
    f.write("\nThe most used words:\n")
    for i in plandic:
        f.write("\t"+i+"\n")
    f.write("\n5 Random words from submission:\n")
    for i in range(5):
        k=randint(0,len(split_sp(filter_st)))
        temp=split_sp(filter_st)
        f.write("\t"+temp[k]+"\n")
    f.write("-----------------\n")
    f.close()