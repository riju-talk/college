"""
The output is coming as a matrix but the final result is a cross product only T.A said it works
"""
ls1=input().split()
ls2=input().split()
ls3=[]
def joint(x,y,z):
    ls=[]
    def f(x,y,z):
        if(len(y)==0):
            return z
        else:
            z+=[(x,y[0])]
            return f(x,y[1:],z)
    if(len(x)==0):
        return z
    else:
        g=f(x[0],y,ls)
        z.append(g)
        return joint(x[1:],y,z)
d=joint(ls1,ls2,ls3)
print(d)