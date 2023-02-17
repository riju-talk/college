def create_course(cname, credits, assessments, policy):
    course = {}
    course["name"] = cname
    course["credits"] = credits
    course["assessments"] = assessments
    course["policy"] = policy
    course["students"]={}
    return course

def upload_marks(course, filename):
    students = {}
    with open(filename, "r") as file:
        dump=file.read().split("\n")
        for line in dump:
            rollno, marks =  line.split(":")
            rollno=int(rollno.strip())
            marks=list(map(int,marks.split(",")))
            total = sum(marks)
            grade = get_grade(new_policy(course), total)
            students[rollno] = {"marks": marks, "total": total, "grade": grade}
    course["students"]=students
    return students

def new_policy(course):
    old_policy=course["policy"]
    cut_off=[]
    with open(r"D:\college\college(IIITD)\Assignment RND\Assignement-3\marks.txt", "r") as f:
        dump=f.read()
        joc=dump.split("\n")
        marks=[list(map(int,(i.split(":")[1]).split(", "))) for i in joc]
        ls_of_marks=[sum(i) for i in marks]
        k=0
        ls_of_marks=list(reversed(sorted(ls_of_marks)))
        for j in old_policy:
            range_cut=list([j-2,j+2])
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


def get_grade(policy, total):
    
    policy=list(reversed(sorted(policy)))
    if(policy[0]<total):
        return"A"
    elif(policy[0]<total<policy[1]):
        return "B"
    elif(policy[1]<total<policy[2]):
        return "C"
    elif(policy[2]<total<policy[3]):
        return "D"
    else:
        return "F"

def get_summary(course, students):
    grades = [student["grade"] for student in students.values()]
    summary = {"A": grades.count("A"), "B": grades.count("B"), "C": grades.count("C"), "D": grades.count("D"), "F": grades.count("F")}
    print(f"{course['name']} ({course['credits']} credits):\nAssessments: {course['assessments']}\nGrading Policy: {course['policy']}\n" \
           f"Grading Summary: {summary}")

def save_grades(students, filename):
    with open(filename, "w") as file:
        for rollno, value in course[students].items():
            file.write(f"{rollno} {value['total']} {value['grade']}\n")

def find_student(students, rollno):
    if rollno in students:
        student = students[rollno]
        print(f"Roll No: {rollno}\nMarks: {student['marks']}\nTotal: {student['total']}\nGrade: {student['grade']}")
    else:
        print(f"No student found with roll number: {rollno}")


cname, credits = "IP", 4
assessments = [("labs", 30), ("midsem", 15), ("assignments", 30), ("endsem", 25)] 
policy = [80, 65, 50, 40, 30]
course = create_course(cname, credits, assessments, policy)
students = upload_marks(course, f"D:\college\college(IIITD)\Assignment RND\Assignement-3\marks.txt")
updated_policy=new_policy(course)

while True:
    try:
        operation = int(input("Enter prompt (1, 2, 3, or enter to quit):"))
        if operation == 1:
            print()
            get_summary(course,students)
            print()
        elif operation == 2:
            print()
            save_grades(students)
        elif operation == 3:
            print()
            rol=int(input("Enter the Roll Number:"))
            course.search_student(rol)
    except:
        break
    
