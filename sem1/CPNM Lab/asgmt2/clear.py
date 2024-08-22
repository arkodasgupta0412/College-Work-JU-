import os

for file in os.listdir(r"."):
    if ".exe" in file:
        os.remove(file)