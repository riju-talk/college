"""

"""
ls_of_cord=[(50,20),(40,10),(40,30),(30,16),(30,24)]
shape=[]
cx=int(input())
cy=int(input())
scale=[[cx,0,0],[0,cy,0],[0,0,1]]
for i in range(len(ls_of_cord)):
    shape.append([ls_of_cord[i][0],ls_of_cord[i][1],1])
matrix=[[0 for i in range(len(scale[0]))] for j in range(len(shape))]

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        summ=0
        for k in range(len(scale)):
            summ+=shape[i][k]*scale[k][j]
        matrix[i][j]=summ
ls_of_new=list()
