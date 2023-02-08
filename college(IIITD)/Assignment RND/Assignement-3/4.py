class Course:
    def __init__(self, cn, cr, a, policy):
        self.cname = cn
        self.credits = cr
        self.assessments = a
        self.policy = policy
        self.students = {}
    def cutoff(self):
        cut_off=[]
        with open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\marks.txt", "r") as f:
            dump=f.read()
            joc=dump.split("\n")
    
            marks=[list(map(int,(i.split(":")[1]).split(", "))) for i in joc]
            ls_of_marks=[sum(i) for i in marks]
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
    
    #marks is list we are taking from outside from marks.txt
    
    def add_student(self, rollno, marks):
        self.students[rollno] = Student(rollno, marks, course.cutoff())

    def generate_summary(self):
        print("Course name:", self.cname)
        print("Credits:", self.credits)
        print("Assessments:", self.assessments)
        print("Grading policy:", self.policy)
        grades = {'A': 0, 'B': 0,'C': 0,'D': 0, 'E': 0,'F': 0}
        for student in self.students.values():
            a=student.get_grade()
            grades[a] += 1
        print("Grading summary:", grades)

    def print_grades(self):
        with open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\grades.txt", "w") as f:
            for student in self.students.values():
                grade = student.get_grade()
                f.write(f"{student.rollno}, {student.total_marks}, {grade}\n")

    def search_student(self, rollno):
        if rollno in self.students:
            student = self.students[rollno]
            print(f"Rollno: {student.rollno}")
            print(f"Marks: {student.marks}")
            print(f"Total marks: {student.total_marks}")
            d=student.get_grade()
            print(f"Grade: {d}")
        else:
            print("Student not found.")
class Student:
    def __init__(self, rollno, marks, ls):
        self.rollno = rollno
        self.marks = marks
        self.total_marks=sum(marks)
        if(ls[0]<self.total_marks):
            self.grades="A"
        elif(ls[0]<self.total_marks<ls[1]):
            self.grades="B"
        elif(ls[1]<self.total_marks<ls[2]):
            self.grades="C"
        elif(ls[2]<self.total_marks<ls[3]):
            self.grades="D"
        else:
            self.grades="F"
    def get_grade(self):
        return self.grades

            
cname, credits = "IP", 4
assessments = [("labs", 30), ("midsem", 15), ("assignments", 30), ("endsem", 25)] 
policy = [80, 65, 50, 40]
course = Course(cname, credits, assessments, policy)

# Upload marks data
with open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\marks.txt", "r") as f:
    dump=f.read()
    split_ls=dump.split("\n")
    for line in split_ls:
        temp=line.split(":")
        rollno, marks = int(temp[0]),list(map(int,temp[1].split(", ")))
        course.add_student(rollno, marks)

while True:
    try:
        operation = int(input("Enter prompt (1, 2, 3, or enter to quit):"))
        if operation == 1:
            print()
            course.generate_summary()
            print()
        elif operation == 2:
            print()
            course.print_grades()
        elif operation == 3:
            print()
            rol=int(input("Enter the Roll Number:"))
            course.search_student(rol)
    except:
        break
    