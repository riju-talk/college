def f(x):
    global y
    y = 10
    return (y+10)
y = 0
print(f(y), y)
