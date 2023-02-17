def print_pattern1(n, current_state, i=0):
    if n == 0 or i==n: 
        return 
    print(n*current_state,end="")
    print((2*i)*"  ",end="")
    print(n*current_state,end="")
    if(n!=1):
        print()
    print_pattern1(n-1, current_state,i+1)
def print_pattern2(n, current_state, i=1):
    if n == 0: 
        return 
    print(i*current_state,end="")
    print((2*(n-1))*"  ",end="")
    print(i*current_state,end="")
    print()
    print_pattern2(n-1, current_state,i+1)
print_pattern1(5, "* ")
print()
print_pattern2(5, "* ")
