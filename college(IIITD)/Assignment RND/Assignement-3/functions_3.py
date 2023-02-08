from split_s import *

def f1(full_string):
    d=split_sp(full_string)
    e=[]
    for i in d:
        if(i!="."):
            e.append(i)
    total_words=len(e)
    uniqe_words=len(set(e))
    return uniqe_words/total_words
def f2(full_string):
    list_for_all=split_sp(full_string)
    e=[]
    for i in list_for_all:
        if(i!="."):
            e.append(i)
    uniq={}
    for i in e:
        uniq[i]=uniq.get(i,0)+1
    sorted_dict = dict(sorted(uniq.items(), key=lambda x: -x[1]))
    new_dic={}
    key=list(sorted_dict.keys())
    value=list(sorted_dict.values())
    for i in range(5):
        new_dic[key[i]]=value[i]
    return new_dic
def f3(full_string):
    ls=split_sen(full_string)
    condition=[]
    for i in ls:
        if(len(i)>35 or len(i)<5):
            condition.append(i)
    sen_35_or_5=len(condition)
    tot=len(ls)      
    return sen_35_or_5/tot
def f4(x):
    special_chars = [",", ".", ":", ";"]
    result = 0
    count = 0
    for i in range(len(x)):
        if x[i] in special_chars:
            count += 1
            if i == len(x) - 1 or x[i + 1] not in special_chars:
                result += 1
        else:
            count = 0
    return result / len(x.split())
def f5(x):
    f=split_sp(x)
    if(len(f)>750):
        return 1
    else:
        return 0