import os

# list of file names
files = ["297.txt", "328.txt", "316.txt", "230.txt", "387.txt", "205.txt", "325.txt", "390.txt"]

# path to directory where the text files will be stored
directory = r"D:\college\college(IIITD)\Assignment RND\Assignement-3\3correct"

# create the directory if it doesn't exist
if not os.path.exists(directory):
    os.makedirs(directory)

# generate text files
for file in files:
    with open(os.path.join(directory, file), "w") as f:
        f.write("This is the contents of file {}".format(file))

print("Text files generated successfully in directory:", directory)