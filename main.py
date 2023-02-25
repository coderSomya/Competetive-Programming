import os



files = os.listdir()
for file in files: 
    if '.exe' in file:
        os.remove(file)

# print(files)