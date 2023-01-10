"""
This program takes user input and produces a reciept for the given user order.

"""
matrix=[]#this matrix stores all the input for processing further

#this list of tuples is the menu of items present in the cafeteria
menu = [("1.Samosa", 15), ("2.Idli", 30), ("3.Maggie", 50), ("4.Dosa", 70), ("5.Tea", 10), ("6.Coffee", 20), ("7.Sandwich", 35), ("8.ColdDrink", 25)]

for i in menu:
    print(i[0],i[1],sep=": ")

"""
This is for taking user input order
"""
print("Enter your Order: ")
while(True):
    print("Add your order or press enter to confirm order:")
    ls=list(map(int,input().split()))
    if(bool(ls)==False):
        break
    matrix.append(ls)
"""
The main program to calculate and printout the reciept
"""
tot_amt=0
no_of_items=0
final_lst=[]
for i in matrix:
    tot_amt+=menu[i[0]-1][1]*i[1]
    no_of_items+=i[1]
    final_lst.append([menu[i[0]-1][0][2:],i[1],menu[i[0]-1][1]*i[1]])
"""
Output or printing the reciept
"""
for i in final_lst:
    print(f"{i[0]} ,{i[1]}, Rs {i[2]}")
print("\n")
print("TOTAL,",no_of_items,"items","Rs",tot_amt)