"""
This program takes user input as Course name, credits and grades and the outputs the Coursee and Grades\
"""
#This matrix will store all user input to operate on.
matrix=[]
#This matrix has all mappings of grades and their weightage
dic={
    "A+":10,
    "A":10,
    "A-":9,
    "B":8,
    "B-":7, 
    "C":6, 
    "C-":5, 
    "D":4, 
    "F":2  
}
"""
This is taking user input
"""
while(True):
    ls=list(input().split())
    if(bool(ls)==False):
        break
    matrix.append(ls)
"""
This is where the main processing takes place
"""
course_dic={}
sgpa=0
sum_credits=0
for i in matrix:
    if(i[0].isalnum() and i[1] in ['1','2','4'] and i[2] in dic.keys()):
        course_dic[i[0]]=course_dic.get(i[0],i[2])
        sgpa+=float(i[1])*dic[i[2]]
        sum_credits+=float(int(i[1]))
    else:
        #this is for the expceptional cases
        if(i[0].isalnum()==False):# this is for invalid course
            print(f"Improper Course number {i[0]}",end=" ")
        elif(i[1] not in [1,2,4]):# this is for invalid credit
            print(f"Incorrect Credit {i[0]}",end=" ")
            sum_credits+=0
        elif(i[2] not in dic.keys()):# this is for if invalid grade
            print(f"Incorrect Grade {i[0]}",end=" ")
sgpa/=sum_credits
"""
The represtation is Taken out from here
"""
newkey=list(course_dic.keys())
newkey.sort()
print("\n")
for i in newkey:
    print(i,course_dic[i],sep=": ")
print("....\n")
print("%0.2f"%sgpa)