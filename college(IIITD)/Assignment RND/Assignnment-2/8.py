import re

f=open(r"Assignment RND\Assignnment-2\pages.txt","r")
dump=f.read()
f.close()
ls=dump.split("\n")
for i in range(len(ls)):
    ls[i]=ls[i].split(":")
dic={}
for i in ls:
    bruh=i[0].split(", ")
    dic[bruh[0]]=bruh[1]
print(dic)
page,init_inportance,links=[],[],[]
for i in ls:
    l=i[0].split(", ")
    g=i[1]
    page.append(l[0])
    init_inportance.append(float(l[1])) 
    intr = re.findall(r'URL\d+', g)
    links.append(intr)
"""
for i in links:
    unique=[]
    for j in i:
        if(j not in unique):
            unique.append(j)
    links[links.index(i)]=unique
for i in links:
    for j in i:
        if(j not in page):
            page.append(j)
print(page)
print(init_inportance)
print(links)
n_link=[]
for j in range(len(page)):
    count=0
    for k in range(len(links)):
        if(type(links[k])==int):
            continue
        else:
            for m in range(len(links[k])):
                if(page[j]==links[k][m]):
                    count+=1
    n_link.append(count)
print(n_link)
rk={}
no_data=[]
for i in range(len(page)):
    if(n_link[i]>0):
        rk[page[i]]=[init_inportance[i],(init_inportance[i]/n_link[i])]
sorted_d = dict(sorted(rk.items(), key=lambda item: item[1][1], reverse=True))
print(sorted_d)"""