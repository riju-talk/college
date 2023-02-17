import time
import random
f=open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\6.txt","w")

f.write("Advantages of using OO\n")
f.write("1. Easy to gather smaller data.\n")
f.write("2. Easy to manipulate data by creating methods.\n\n")

f.write("Advantages of using Dictionaries\n")
f.write("1. Easy to organise data in a large amount.\n")
f.write("2. Less time taking in traversing due to hashing.\n\n")

f.write("Disadvantages of using OO\n")
f.write("1. Difficult to add attributes and data associated to it.\n")
f.write("2. This appraoch is quite abstract, considering that we can't know the state of object but we can print a dictionary to know the state.\n\n")

f.write("Disadvantages of using Dictionaries\n")
f.write("1. Initializing a dictioanry \n")
f.write("2. Easy to gather smaller data\n\n")
f.close()

cname="IP"
credit=4
assesment= [("labs", 30), ("midsem", 15), ("assignments", 30), ("endsem", 25)]
policy= [80, 65, 50, 40]
stud={22400: 81.5,
 22401: 65.5,
 22411: 92.8,
 22296: 83.2,
 22593: 32.0,
 22212: 90.3,
 22264: 33.5,
 22149: 94.5,
 22472: 89.1,
 22129: 0.3,
 22129: 31.2,
 22277: 32.3,
 22221: 60.1,
 22551: 60.2,
 22573: 18.5,
 22551: 17.9,
 22507: 68.1,
 22126: 75.2,
 22075: 39.9,
 22095: 19.1,
 22107: 50.1,
 22507: 74.3,
 22296: 74.2,
 22033: 65.3,
 22059: 15.2,
 22250: 86.3,
 22292: 86.8,
 22102: 18.9,
 22279: 21.8,
 22177: 98.1,
 22166: 70.8,
 22121: 53.2,
 22054: 64.5,
 22393: 33.5,
 22312: 65.2,
 22086: 57.8,
 22345: 49.3,
 22348: 33.8,
 22388: 14.5,
 22390: 80.8,
 22347: 47.0,
 22310: 58.8,
 22377: 47.3,
 22321: 69.8,
 22345: 98.2,
 22293: 36.8,
 22286: 94.0,
 22236: 48.9,
 22282: 93.3,
 22183: 83.3,
 22239: 96.0,}

#------------------testing object------------------
class Course:
    def __init__(self, cn, cr, a, policy, stud):
        self.cname = cn
        self.credits = cr
        self.assessments = a
        self.policy = policy
        self.students = stud
    def cutoff(self):
        cut_off=[]
        ls_of_marks=[i.get_marks() for i in self.students]
        k=0
        ls_of_marks=list(reversed(sorted(ls_of_marks)))
        for j in self.policy:
            range_cut=list([j-2,j+2])
            for i in range(len(ls_of_marks)-1):
                if(k<(ls_of_marks[i+1]-ls_of_marks[i]) and range_cut[0] <= ls_of_marks[i+1] <=range_cut[1] and range_cut[0] <= ls_of_marks[i] <=range_cut[1]):
                    k=ls_of_marks[i+1]-ls_of_marks[i]
                    l=(ls_of_marks[i+1]+ls_of_marks[i])/2
            if(k==0):
                cut_off.append(j)
            else:
                cut_off.append(l)
        self.policy=cut_off
        return cut_off
    
    def grading(self):
        ls_for_grading=self.cutoff()
        for j in range(len(self.students)):
            marks=self.students[j].get_marks()
            if(marks>ls_for_grading[0]):
                    self.students[j].set_grades("A")
            elif(marks<ls_for_grading[-1]):
                self.students[j].set_grades("F")
            else:
                for i in range(len(ls_for_grading)-1):
                    if(ls_for_grading[i]<=marks<=ls_for_grading[i+1]):
                        self.students[j].set_grades(chr(ord("A")+i+1))
   
    def search_student(self, rollno):
        for i in self.students:
            if rollno == i.get_rollno():
                return ("Found")
            else:
                return ("Student not found.")
    
class Student:
    def __init__(self,roll,maxmarks):
        self.rollno=roll
        self.marks=maxmarks
    def set_grades(self,f):
        self.grades=f
    def get_rollno(self):
        return self.rollno
    def get_marks(self):
        return self.marks

ls_of_stud=[]
for i,j in stud.items():
    ls_of_stud.append(Student(i,j))
course=Course(cname,credit,assesment,policy,ls_of_stud)
start0=time.time()
for i in range(1000):
    course.grading()
end0=time.time()

time_for_searching_object=end0-start0

start0=time.time()
for i in range(1000):
    f=random.randint(0,len(ls_of_stud)-1)
    course.search_student(ls_of_stud[f].get_rollno())
end0=time.time()

time_for_grading_object=end0-start0

#------------------testing dictionary------------------

def create_course(cname, credits, assessments, policy, stud):
    course = {}
    course["name"] = cname
    course["credits"] = credits
    course["assessments"] = assessments
    course["policy"] = policy
    course["students"]= stud
    return course

def new_policy(course):
    old_policy=course["policy"]
    cut_off=[]
    ls_of_marks=[i["marks"] for i in course["students"].values()]
    ls_of_marks=list(reversed(sorted(ls_of_marks)))
    for j in old_policy:
        range_cut=list([j-2,j+2])
        k=0
        for i in range(len(ls_of_marks)-1):
            if(k<(ls_of_marks[i+1]-ls_of_marks[i]) and range_cut[0] <= ls_of_marks[i+1] <=range_cut[1] and range_cut[0] <= ls_of_marks[i] <=range_cut[1]):
                k=ls_of_marks[i+1]-ls_of_marks[i]
                l=(ls_of_marks[i+1]+ls_of_marks[i])/2
        if(k==0):
            cut_off.append(j)
        else:
            cut_off.append(l)
    course["policy"]=cut_off
    return cut_off

def get_grade(course):
    ls=course["students"]
    policy=list(reversed(sorted(new_policy(course))))
    for i in ls.values():
        if(policy[0]<i["marks"]):
            i["grades"]="A"
        elif(policy[0]<i["marks"]<policy[1]):
            i["grades"]="B"
        elif(policy[1]<i["marks"]<policy[2]):
            i["grades"]="C"
        elif(policy[2]<i["marks"]<policy[3]):
            i["grades"]="D"
        else:
            i["grades"]="F"
    
def find_student(course, rollno):
    students=course["students"]
    if rollno in students.keys():
        return (f"Student Found")
    else:
        return (f"No student found with roll number")
for i, j in stud.items():
    stud[i] = {"marks": j}
course=create_course(cname, credits, assesment, policy,stud)
start1=time.time()
for i in range(1000):
    f=random.randint(22000,22699)
    find_student(course,f)
end1=time.time()
time_for_searching_dict=end0-start0

start1=time.time()

for i in range(1000):
    get_grade(course)
end1=time.time()

time_for_grading_dict=end0-start0

if(time_for_searching_dict>time_for_searching_object):
    g=(time_for_searching_dict-time_for_searching_object)/time_for_searching_dict
else:
    g=(time_for_searching_object-time_for_searching_dict)/time_for_searching_object
    
if(time_for_grading_dict>time_for_grading_object):
    h=(time_for_grading_dict-time_for_grading_object)/time_for_grading_dict
else:
    h=(time_for_grading_object-time_for_grading_dict)/time_for_grading_object
f=open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\6.txt","a")
f.write("Performance comparison for grading operation (give in each line: value of N; time taken by two approaches in seconds, and which is faster and by how much).\n")
f.write(f"1. N: {1000}\n\
2. Time by OO: {time_for_grading_object} \n\
3. Time by dictionary: {time_for_grading_dict} \n\
4. X is faster; fraction of time x took is: {h}\n\n") 

f.write("Performance comparison for search operation (give in each line: value of N; time taken by two approaches in seconds, and which is faster and by how much).\n")
f.write(f"1. N: {1000}\n\
2. Time by OO: {time_for_searching_object} \n\
3. Time by dictionary: {time_for_searching_dict} \n\
4. X is faster; fraction of time x took is: {g}")
f.close()