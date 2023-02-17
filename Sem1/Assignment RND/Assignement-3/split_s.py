c="A healthy lifestyle is essential for a happy,,,,,,and fulfilling life..:.;;..,,. By taking care of our bodies and minds, we can improve our physical and mental well-being. This can be achieved through a balanced diet, regular exercise, and proper sleep. In addition;;;;;;;;; engaging in activities that bring joy and reduce stress can also contribute to a healthy lifestyle. By making these positive choices:::::::: we can reduce the risk of developing chronic illnesses, maintain a healthy weight, and improve our overall quality of life. Ultimately, a healthy lifestyle leads to a happier and more fulfilling life."
def split_sp(g):
    st=[]
    for i in g.split():
        if "(" in i.strip():
            st.append("(")
            st.append(i.strip()[1:].lower())
        elif ")" in i.strip():
            st.append(i.strip()[:-1].lower())
            st.append(")")
        elif "," in i.strip():
            st.append(i.strip()[:-1].lower())
            st.append(",")
        elif "." in i.strip():
            st.append(i.strip()[:-1].lower())
            st.append(".")
        elif "[" in i.strip():
            st.append("[")
            st.append(i.strip()[1:].lower())
        elif "]" in i.strip():
            st.append(i.strip()[:-1]).lower()
            st.append("]")
        elif "(" in i.strip():
            st.append("(")
            st.append(i.strip()[1:].lower())
        elif ")" in i.strip():
            st.append(i.strip()[:-1]).lower()
            st.append(")")
        elif "{" in i.strip():
            st.append("{")
            st.append(i.strip()[1:].lower())
        elif "}" in i.strip():
            st.append(i.strip()[:-1].lower())
            st.append("}")
        elif ":" in i.strip():
            st.append(i.strip()[:-1].lower())
            st.append(":")
        elif ";" in i.strip():
            st.append(i.strip()[:-1].lower())
            st.append(";")
        else:
            st.append(i.strip().lower())
    return st

def dot_s(x):
    g=[]
    for i in split_sp(x):
        if(len(i)!=0 and ord(i) in range(65,91) or ord(i) in range(97,123)):
            g.append(i)
    return g

def split_sen(x):
    ls=[]
    while(len(x)!=0):
        for i in x:
            if(i=="."):
                ls.append(x[:x.index(i)].strip())
                break
        x=x[x.index(i)+1:]
    return ls
            