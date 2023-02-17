"""
here i have hardcoded the strings from which i am taking refernce for all my functions  
    """


cap="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
sml="abcdefghijklmnopqrstuvwxyz"
spec="@#$%&"
num="1234567890"
def is_cap(x):
    flg=False
    for i in x:
        if(i in cap):
            flg=True
            break
    return flg

def is_sml(x):
    flg=False
    for i in x:
        if(i in sml):
            flg=True
            break
    return flg

def is_num(x):
    flg=False
    for i in x:
        if(i in num):
            flg=True
            break
    return flg

def is_spec(x):
    flg=False
    for i in x:
        if(i in spec):
            flg=True
            break
    return flg

x=input()
if(len(x)>=8 and is_cap(x) and is_num(x) and is_sml(x) and is_spec(x)):
    print(True)
else:
    print(False)