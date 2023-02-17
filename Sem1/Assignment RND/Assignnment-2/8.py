import re
import itertools

f=open(r"Assignment RND\Assignnment-2\pages.txt","r")
dump=f.read()
f.close()
ls=dump.split("\n")
for i in range(len(ls)):
    ls[i]=ls[i].split(":")
links=[]
dic={}
for i in ls:
    bruh=i[0].split(", ")
    dic[bruh[0]]=float(bruh[1])
    g=i[1]
    inter = re.findall(r'URL\d+', g)
    links.append(inter) 
    for i in inter:
        dic[i]=dic.get(i,0)
for i in links:
    unique=[]
    for j in i:
        if(j not in unique):
            unique.append(j)
    links[links.index(i)]=unique
links=[i for i in links if bool(i)]
init_importance=list(dic.values()).copy()
pages=list(dic.keys()).copy()
for i in range(len(pages)):
    for j in range(len(links)):
        if(pages[i] in links[j]):
            count=init_importance[i]/len(links[j])
            for k in range(len(links[j])):
                dic[links[j][k]]+=count
overall_importance=list(dic.values())
n_dic={}
for i in range(len(init_importance)):
    n_dic[pages[i]]=[init_importance[i],overall_importance[i]]
n_d= dict(sorted(n_dic.items(), key=lambda item: item[1][1], reverse=True))

n=int(input())
j=dict(itertools.islice(n_d.items(),n))
for i,k in j.items():
    print("%s %.2f %.2f"% (i,k[0],k[1]))