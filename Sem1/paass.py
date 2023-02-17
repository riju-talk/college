import json

f=open("ff.txt","r")
d=f.read()
f.close()
f=json.loads(d)
print(f)