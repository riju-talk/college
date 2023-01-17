

g="This is another page (page is represented as a line in this). This has reference to URL05, URL04, and URL00"
f="This is page zero, and has references to URL01, URL09, and also to URL08. It may have repeated references - so there are two references to URL09."
"""def capnum(x):
    if(x.isalnum()):
        ls1=[]
        ls2=[]
        for i in x:
            if(i.isupper()):
                ls1.append(i)
            elif(i.isnumeric()):
                ls2.append(i)
        if(len(ls2)+len(ls1)==len(x)):
            return True
        else:
            return False
        return True
    else:
        return False
ls1=[]
for i in g.split():
    if(capnum(i)):
        ls1.append(i)
print()
print(ls1)

ls2=[]
for i in f.split():
    if(capnum(i)):
        ls2.append(i)
print()
print(ls2)"""


