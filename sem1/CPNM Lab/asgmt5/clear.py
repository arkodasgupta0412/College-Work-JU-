import os

for file in os.listdir("."):
    if ".exe" in file:
        os.remove(file)






