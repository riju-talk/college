def only_zero(x):
    flg=True
    for i in x:
        if(type(i)==float):
            if(float(i)!=0.0):
                flg=False
                break
        else:
            if(str(i)!="0"):
                flg=False
                break
    return flg
def pivot(x):
    if(only_zero(x)):
        return len(x)
    tag=0
    for i in x:
        if(float(i)!=0.0):
            tag=x.index(i)
            break
    return tag

A=[[1, 0, -1.3333333333333333, 0, 0],
[0, 1, 0, 0, 0],
[0, 0, 0, 0, 1],
[0, 0, 0, 1, 3.051282051282051],
[0, 0, 0, 0, 0]]

for i in A:
    print(pivot(i))