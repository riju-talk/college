"""
   This program gives a user six tries to guess a random word stored in a file on the local machine and,
   if the user is successful the program gives a success message nd terminates while after six tries the
   program terminates saying sorry. 
"""
#imposting a custom fucntion from file Bonus
from Bonus import is_real
#importing randint function from the randim module.
from random import randint
file=open(r"Assignment RND\Assignnment-2\word.txt","rt")#file object being set up.

#file data being dumped into a variable.
dump=file.read()

file.close()#closing file object to save resources.
wrdlst=dump.split("\n")#spliting up data to create a list of words

#randint function takes anyrandom number from 0 till the index of the final element in the word list
fact=randint(0,len(wrdlst)-1)#fact varible will store that number to help us rerieving a random word from that list.

word=wrdlst[fact]#This is the word the user is going to guess

w=word.lower()#This is done so comparison between word can happen irrespective to what the case is.
"""
This is where the main program starts running. The game gives the user 6 chances to guess the random word and everytime
user finds one or more words that somewhat relate to the word it will show them the words that belong to the word whether
they are at the right position or not.
"""
print("Let the game begin start by entering the first word.")
#this is the main loop that runs six times 
loopi=0
while(loopi<=5):
    x=input()
    #This checks whether the input is a real word or not
    #If the word in not a real word then 
    if(not is_real(x)):
        loopi=0
        print("\nInvalid word")
        continue
    #Bonus
    x=x.lower()#this is also done for comparison purposes 
    wr_index=[]#this is where the letters with wrong indeces are stored.
    rt_places=[]#this is where the letters with correct indeces are stores along with
    #dashes which indicate a placholder which can be filled when user gusess more correct letters
    #resulting in forming the correct word
    count=0#this count indicates number of correct letters
    for j in range(len(x)):
        if(x[j] in w and x[j]!=w[j]):
            if(x[j]not in wr_index):
                wr_index.append(x[j])
            rt_places.append("-")
        elif(x[j] in w and x[j]==w[j]):
            count+=1
            rt_places.append(x[j])
        elif(x[j] not in w):
            rt_places.append("-")
            count+=0
    """
    For every letter up in string it will check for each letter in both string and carry out further decesions like 
    whether a string is in the right place or a string exists and not in a right place.
    """
    print("\n")
    
    if(count==5):#once the number of correct letters is 5 the game ends with success message
        print("Hurray you guessed right")
        print(f"{w}")
        break
    elif(loopi==5):#if the loop ends without count ever reaching 5 the game ends with a regret message
        print("Sorry, out of luck")
        print(f"The word was {w}")
        break
    
    if(len(wr_index)!=0):#every time a wrong guess is made the user will see all the letter they got right
        #and at wrong incdices
        for i in wr_index:
            print(i,end=" ")
        print("exist in word but at wrong positions\n")
    
    if(len(rt_places)!=0 and count!=5 or len(rt_places)==5):#every time a wrong guess is made the 
        #user will see all the letter they got right and at write incdices
        print("Words in right places are:")
        for i in rt_places:
            print(i,end="")
        print("\n")
    else:
        print("No correct words found\n")#when there are no correct letters are found This statement will return
    loopi+=1