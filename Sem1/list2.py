import csv
f=open("newt.csv","r")
csv_w=csv.DictReader(f)
for i in csv_w:
    print(dict(i))
f.close()
