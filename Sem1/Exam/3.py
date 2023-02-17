"""
program to find numbers between 1 and n(1 and n inclusive)    
"""

def is_div(x):
    if(x%3==0 or x%5==0 or x%7==0 or x%9==0):
        return True
    else:
        return False

n=int(input())
f=[i for i in range(1,n+1) if is_div(i)]
print(f)