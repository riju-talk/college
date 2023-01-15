class complex:
    def __init__(self,r,i):
        self.real=r
        self.image=i
    def getreal(self):
        return self.real
    def getimage(self):
        return self.image
    def add(self,c):
        self.image+=c.getimage()
        self.real+=c.getreal()
    def equal(self,c):
        return (self.image==c.getimage() and self.real==c.getreal())
    
# Main program
c1, c2, c3 = complex(1,2), complex(3,4), complex(3,4)
print(c1.equal(c2))
c1.add(c2)
print(c1.getreal(), c1.getimage())
print(type(c1))