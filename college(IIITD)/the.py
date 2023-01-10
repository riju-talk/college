def chocolateFeast(n, c, m):
    no_choc=n//c
    count=0
    while(True):
        count+=no_choc
        if(no_choc<m):
            break
        no_choc=(no_choc%m)+(no_choc//m)
    # Write your code here
    return count
print(chocolateFeast(6,2,2))