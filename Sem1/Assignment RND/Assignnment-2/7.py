import json
"""
input:
name, address, phone, email
"""

#------Add function-----------
def add(dic,inp):
    d={}
    d["address"]=inp[1]
    d["phone"]=inp[2]
    d["email"]=inp[3]
    if(inp[0] not in dic.keys()):
        dic[inp[0]]=d
    else:
        if(type(dic[inp[0]])==list):
            dic[inp[0]].append(d)
        else:
            ls = [d]   
            dic[inp[0]] = [dic[inp[0]]]+ls

#------delete function----------
def delete(dic,inp):
    if(type(dic[inp[0]])!=list):
        dic.pop(inp[0])
    else:
        d=inp[1:]
        for i in dic[inp[0]]:
            if(i["address"]==d[1] and i["phone"]==d[2] and i["email"]==d[3]):
                break
        dic[inp[0]].remove(i)
        if(len(dic[inp[0]])==1):
            dic[inp[0]]=dic[inp[0]][0]

#------search function partial name-----------
def search(dic,inp):
    vr=[]
    for i in dic.keys():
        flag=False
        for j in range(len(i)):
            flag=False
            for k in range(len(i)-j):
                flag=False
                for l in range(k):
                    if(inp.lower()==i[l:k].lower()):
                        flag=True
                        break
                if(flag):
                    break
            if(flag):
                break
        if(flag):
            vr+=[i]
    sr=""
    if(len(vr)==0):
        return "No such Value found"
    else:
        for i in vr:
            nd={i:d[i]}
            sr+=str(nd)+" "
        return sr

#------search function number,email-----------
def search_p_e(dic,inp):
    ls=[]
    for i,j in dic.items():
        flag=False
        if(type(j)==list):
            for k in j:
                if inp in k.values():
                    flag=True
                    m=k
                    break
        else:
            if inp in j.values():
                m=j
                flag=True
        if(flag):
            ls.append({i:m})
    if(len(ls)==0):
        print("No such value found")
    else:
        for i in ls:
            print(i)
#------exit function-----------
def exitp(dic):
    f=open(r"Assignment RND\Assignnment-2\addrbook.txt","w")
    ob=json.dumps(dic)
    f.write(ob)
    f.close

#------merge function-----------
def merge(f1,f2):
    ls=[]
    
    f=open(f1,"r")
    d=f.read()
    g=json.loads(d)
    f.close()
    ls.append(g)
    
    f=open(f2,"r")
    d=f.read()
    g=json.loads(d)
    f.close()
    ls.append(g)
    
    f=open("merger.txt","w")
    dump=json.dumps(ls)
    f.write(dump)
    f.close()
    
    return "merger.txt"

f=open(r"Assignment RND\Assignnment-2\addrbook.txt","r")
dump = f.read()
f.close()

#--------------main program----------------
print("------The Address Book-------")
d={"adarsh": [{"address": "h3/81/b1,mahavir enclave,110075", "phone": "9871603930", "email": "marshall.bleucore@gmail.com"},
              {"address": "g-20,janakpuri,110025", "phone": "9899234284", "email": "rijusmit.biswas@gmail.com"}],
   "adesh":{"address":"12-g/10,dwarka sec-14,110075","phone":"9899927270","email":"technosniper.net@gmail.com"},
   "anish":{"address":"12-g/10,dwarka sec-14,110075","phone":"9899234284","email":"technosniper.net@gmail.com"}}
if(len(dump)==0):
    d=d
else:
    dic=json.loads(dump)
    d=dic
print()
print(d)
print()
while(True):
    print("Press A to add values to Address book")
    print("Press B to delete values to Address book")
    print("Press C to search values from Address book from names")
    print("Press D to search values from Address book from phone and email")
    print("Press E to exit and save")
    x=input()
    if(x.lower()=="a"):
        print("input format:\
\nname    address    phone    email\n seperator=\" tab\"")
        print("\nEnter your data:")
        y=input().split("\t")
        add(d,y)
        print("\n",d)
    elif(x.lower()=="b"):
        print("input format:\
\nname    address    phone    email\n seperator=\" tab\"")
        print("\nEnter your data:")
        y=input().split("\t")
        delete(d,y)
        print("\n",d)
    elif(x.lower()=="c"):
        print("\nEnter input normally:\n")
        y=input()
        v=search(d,y)
        print(v)
    elif(x.lower()=="d"):
        print("\nEnter input normally:\n")
        y=input()
        v=search_p_e(d,y)
        print(v)
    elif(x.lower()=="e"):
        exitp(d)
        break
    else:
        print("Enter a valid prompt")
"""
#------------bonus-------
f1=r"Assignment RND\Assignnment-2\f1.txt"
f2=r"Assignment RND\Assignnment-2\f2.txt"
f=merge(f1,f2)
print(f)
"""