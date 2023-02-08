"""
I have left the main output courses in dictionary only, still easy to manage:
"""
class student:
    def __init__(self,rol,name):
        self.rol=rol
        self.name=name
        self.courses={}
    def add_course(self,name):
        self.courses[name]=""
    def add_grade(self,name,grade):
        self.courses[name]=grade
    def st_record(self):
        d=0
        count=0
        for i in self.courses.values():
            d+=i
            count+=1
        avg=d/count
        print(f"rollno : {self.rol} , name : {self.name} , courses : {self.courses} , average : {avg}")
        return
    def avg_grade(self):
        for i in self.courses.values():
            d+=i
            count+=1
        avg=d/count
        return avg
st=student(23001,"stu1")
st.add_course("cs101")
st.add_course("M101")
st.add_grade("cs101",9)
st.add_grade("M101",8)
st.st_record()
        