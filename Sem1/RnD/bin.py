def sign(x):
    if(x<0):
        return "-"
    else:
        return "+"

class term:
    def __init__(self,num,coef,sign=sign(1)):
        self.num=abs(num)
        self.cf="x"+str(coef)
        self.sign=sign
    def __str__(self):
        if(self.sign=="-" and self.num!=0 and self.num!=1 and self.num!=-1):
            return f"{self.sign}{self.num}{self.cf}"
        elif(self.num==1 or self.num==-1):
            if(self.num>0):
                return f"{self.cf}"
            else:
                return f"{self.sign}{self.cf}"
        elif(self.num==0):
            return "0"
        else:
            return f"{self.num}{self.cf}"

class solution:
    def __init__(self,rhs,lhs,free=0):
        self.rhs=rhs
        self.lhs=lhs
        self.free=free
    def __str__(self):
        if(self.free==0):
            return f"{self.rhs} = {self.lhs}"
        else:
            return f"{self.rhs} is free"
gen=[]
for i in range(len(z)):
    if(1 in z[i]):
        ls=[]
        for k in range(len(z[0])):
            if(z[i][k]!=1):
                ls.append(str(term(z[i][k],(k+1),sign(z[i][k]))))
        gen.append(str(solution(rhs=term(1,i+1),lhs=ls)))
    elif(z[i]==[0]*len(z[i])):
        gen.append(str(solution(rhs=term(1,i+1),lhs=term(1,i+1))))
print(gen)