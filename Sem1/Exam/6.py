def sq(x):
    y=[]
    for i in range(len(x)):
        y.append(str(x[i]*x[i]))
    return y
f=open(r"D:\college\college(IIITD)\Exam\in.txt","r")
dump=f.readlines()
f.close()
mat=[]
for i in dump:
    temp=i[:len(i)]
    ls=temp.split()
    n_ls=list(map(int,ls))
    mat.append(" ".join(sq(n_ls)))
f=open(r"D:\college\college(IIITD)\Exam\out.txt","w")
for i in mat:
    f.write(i+"\n")
f.close()