class term:
    def __init__(self,num,coef):
        self.num=abs(num)
        self.cf="x"+str(coef)
        if(num>0):
            self.sign="+"
        else:
            self.sign="-"
        self.index=coef-1
    def __str__(self):
        if(self.num!=0 and self.num!=1 and self.num!=-1):
            return f"{self.sign}{abs(self.num)}{self.cf}"
        elif(self.num==1 or self.num==-1):
            if(self.num>0):
                return f"{self.cf}"
            else:
                return f"{self.sign}{self.cf}"
        elif(self.num==0):
            return "0"
    def invert(self):
        self.num=self.num*-1
        if(self.sign=="+"):
            self.sign="-"
        else:
            self.sign="+"
        return self
    def index(self):
        return self.index
class expression:
    def __init__(self,ls):
        self.exp=ls
    def __str__(self):
        st=""
        for i in self.exp:
            d=str(i)
            if(d!="0"):
                st+=str(i.invert())
        try:
            if(st[0:2]=="0+"):
                st=st[2:]
            elif(st[0]=="+" or st[0]=="0"):
                st=st[1:]
        except:
            st+="0"
        return st
class solution:
    def __init__(self,rhs,lhs):
        self.rhs=rhs
        self.lhs=lhs
    def __str__(self):
        return f"{self.rhs} = {self.lhs}"
print("rows")
rows=int(input())
print("collums")
colums=int(input())
A=[]
#A=[[0,2,0,7,0],[0,0,8,9,7],[-1,0,5,4,3]]
for i in range(rows):
    ls=list(map(int,input().split()))
    A.append(ls)
print()
print("-----Original Matrix-----")
for i in A:
    print(i)
print()
#for finding the rref of the matrix that is given
rows=len(A)
colums=len(A[0])
for i in range(rows):
    for j in range(i, rows):
        if A[j][i] != 0:
            break
    if A[j][i] == 0:
        continue
    if j != i:
        temp = A[i]
        A[i]=A[j]
        A[j]=temp
for i in range(rows):
    for l in range(colums):
        if(A[i][l]!=0):
            fact=A[i][l]
            break
    try:
        d=[x/fact for x in A[i]]
    except:
        continue
    for j in range(rows):
        for l in range(colums):
            if(d[l]!=0):
                fact=A[j][l]
                break
        if(j!=i):
            for k in range(colums):
                A[j][k]-=d[k]*fact
    A[i]=d
for i in range(rows):
    for j in range(colums):
        if round(A[i][j],10)==int(A[i][j]):
            A[i][j]=int(A[i][j])
print("------RREF of the Matrix---------")
for i in A:
    print(i)
print()
print("---------General solution---------")
rows=len(A)
colums=len(A[0])
tot_terms=[]
pivot={}
for i in range(colums):
    tot_terms.append(str(term(1,i+1)))
for i in range(rows):
    flg=False
    m=colums
    for j in range(colums):
        if(A[i][j]!=0):
            flg=True
            m=j
            break
    if(not flg):
        break
    pivot[str(term(A[i][j],j+1))]=i
free=[x for x in tot_terms if x not in pivot.keys()]
gen=[]
for i in range(colums):
    if(tot_terms[i] in free):
        gen.append(str(solution(rhs=tot_terms[i],lhs=tot_terms[i])))
    else:
        k=pivot[tot_terms[i]]
        d=A[k]
        for l in range(len(d)):
            if(d[l]!=0):
                break
        ls=[]
        for j in range(l+1,colums):
            ls.append(term(A[k][j],j+1))
        gen.append(str(solution(rhs=tot_terms[i],lhs=(expression(ls)))))
for i in gen:
    print(i)
print()
print("-----parameteric form--------")
"""
This whole code creates a dictionary called parm_form wich will represent the parametric form of the solution
"""
parm_form={}
def split_string(x):
    new_dic={}
    lhs,rhs=x.split("=")
    lhs=lhs.strip()
    rhs=rhs.strip()
    ls={}
    if(rhs=="0"):
        new_dic[lhs]=0
    else:
        while(len(rhs)!=0):
            i=0
            while(i<=len(rhs)):
                if(rhs[i]=="x"):
                    try:
                        if(float(rhs[:i])%1==0):
                            cf=int(rhs[:i])
                        else:
                            cf=float(rhs[:i])
                    except:
                        g=rhs[:i]
                        if(g=="-"):
                            cf=-1
                        else:
                            cf=1
                    var=rhs[i:i+2]
                    ls[var]=cf
                    rhs=rhs[i+2:]
                    i=0
                i+=1
        new_dic[lhs]=ls
    return new_dic
new_parm=[]
for i in range(len(gen)):
    new_parm+=[split_string(gen[i])]
if(len(free)==0):
    print("no parameters present")
try:
    for i in free:
        ls=[]
        for j in new_parm:
            k=list(j.values())
            h=k[0]
            try:
                if(i in h.keys()):
                        val=h[i]
                        ls.append(val)
                else:
                        ls.append(0)
            except:
                ls.append(0)
        parm_form["+"+i]=ls
    st=list(parm_form.keys())[0]
    def change_first_key(d, new_key):
        e={}
        first_key = list(d.keys())[0]
        e[new_key] = d.pop(first_key)
        for i,j in d.items():
            e[i]=j
        return e
    parm_form=change_first_key(parm_form,st[1:])
    for i in parm_form:
        print(f"{i}{parm_form[i]}",end="")
    print("\n")
except:
    print("No parameters available")