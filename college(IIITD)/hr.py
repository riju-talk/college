def round5(x):
    y=x//10
    if((y+1)*10>=x and x>=(y*10)+5):
        return (y+1)*10;
    elif((y*10)<=x and x<=(y*10)+5):
        return (y*10)+5;

def roundif(x):
    y=round5(x)
    if(3>abs(y-x)):
        return y;
    else:
        return x;

print(roundif(38))