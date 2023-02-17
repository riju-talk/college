n=int(input("Pls enter your number: "))
def ones(n):
    index={0:"Zero",1:"one",2:"Two",3:"Three",4:"Four",5:"Five",6:"Six",7:"Seven",8:"Eight",9:"Nine"}
    print(index[n])
def tens(n):
    index={10:"Ten",20:"Twenty",30:"Thirty",40:"Forty",50:"Fifty",60:"Sixty",70:"Seventy",80:"Eighty",90:"Ninty"}
    print(index[n])
def teens(n):
    index={11:"ELeven",12:"Tweleve",13:"Thirteen",14:"Fourteen",15:"Fifteen",16:"Sixteen",17:"Seventeen",18:"Eighteen",19:"Nineteen"}
    print(index[n])
def ten_compx(n):
    index1={20:"Twenty",30:"Thirty",40:"Forty",50:"Fifty",60:"Sixty",70:"Seventy",80:"Eighty",90:"Ninty"}
    index2={1:"one",2:"Two",3:"Three",4:"Four",5:"Five",6:"Six",7:"Seven",8:"Eight",9:"Nine"}
    print(str(index1[n-n%10])+" " + str(index2[n%10]))
if(n<=99 and n>=0):
    if(n<10):
        ones(n)
    elif(n>=11 and n<20):
        teens(n)
    elif(n%10==0):
        tens(n)
    else:
        ten_compx(n)
