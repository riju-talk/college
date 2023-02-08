ls1=[1,2,3,4,5,6,7,8]
ls2=ls1.copy()
ls3=[ls1[i] for i in range(len(ls1)-2,-1,-1)]
ls2+=ls3
print(ls2)