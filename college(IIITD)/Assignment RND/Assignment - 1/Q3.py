x0=0
y0=0
dist=0
while(True):
    x=int(input("Enter the distance traelled: "))
    if(x>51 and x<75):
        x0+=x
        dist+=x
    elif(x>=76):
        x0-=x
        dist+=x
    elif(x<=25):
        y0+=x
        dist+=x
    elif(x>26 and x<50):
        y0-=x
        dist+=x
    f=input("Press enter to see the result or press c to continue: ")
    if(f==""):
        break
print("\n")
print("The current coordinates are (" + str(x0) + "," + str(y0) + ")" )
print("The total distance travelled is",dist,"m")
print("The distance between the point is\n\r"+str((x0**2+y0**2)**0.5))