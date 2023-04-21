import os

files = os.listdir()
for file in files: 
    if '.exe' in file:
        os.remove(file)

for i in range(10):
   os.mkdir("a")



# print(files)