"""
This program takes input to scale a shape of n-points. for this program 5 of them The points given below form a pentogon
and with the help of this program we will scale this pentagon.
"""
#this is the list of coordinates that map out the shape.
ls_of_cord=[(50,20),(40,10),(40,30),(30,16),(30,24)]
shape=[]
#this will store the final 2-d shape using these coordinates.
print("\nThe Orignal cooridinates are: ")
for i in ls_of_cord:
    print(i,end=" ")
print("\n\nOriginal shape")
for i in shape:
    for j in i:
        print(j,end=" ")
    print()
"""
The 2-d shape will be represented as
| x1 y1 1 |
| x2 y2 1 |
| x3 y3 1 |
| x4 y4 1 |
| x5 y5 1 |
here x1,y1 x2,y2 x3,y3 x4,y4 x5,y5 are list of coordinates 
"""
cx=int(input())#This is where the user inputs the first scaler
cy=int(input())#This is where the user inputs the second scaler
#the user input is then sent to the matrix which will be used to scale it.
scale=[[cx,0,0],[0,cy,0],[0,0,1]]
for i in range(len(ls_of_cord)):
    shape.append([ls_of_cord[i][0],ls_of_cord[i][1],1])
#matrix is a zero matrix of the same dimension as the matrix the will be after multiplication
matrix=[[0 for i in range(len(scale[0]))] for j in range(len(shape))]
"""
Here the matrix multiplication takes place
"""
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        summ=0
        for k in range(len(scale)):
            summ+=shape[i][k]*scale[k][j]
        matrix[i][j]=summ
ls_of_new=list()
#This is the list of all the scaled coordinates.
for i in matrix:
    ls_of_new.append((i[0],i[1]))
"""
Here scaled coordinates are printed along with the scaled shape.
"""
print("\nScaled shape")
for i in matrix:
    for j in i:
        print(j,end=" ")
    print()
print("")
print("The new cooridinates are: ")
for i in ls_of_new:
    print(i,end=" ")
print("\n")