import os
check = True
difficulty = input("E, M, or H for difficulty: ")
if difficulty=="E":
    difficulty="Easy"
elif difficulty=="M":
    difficulty="Medium"
elif difficulty=="H":
    difficulty="Hard"
else:
    check = False
number = input("Enter the Number: ").strip()
name = input("Enter the Problem Name: ").strip()
link = input("Enter the Link: ").strip()

print("\n")
print(f"Difficulty: {difficulty}")
print(f"number: {number}")
print(f"name: {name}")
print(f"link: {link}")
print("\n")

confirm = input("Enter 1 to Confirm Info: ").strip()
check = check and confirm=="1"
if check==False:
    print("Error during input")
else:
    mode = 0o666
    parent_dir = os.path.join(os.getcwd(), difficulty)
    os.chdir(parent_dir)

    folder_name = f"{number}. {name}"
    os.mkdir(folder_name, mode)
    os.chdir(os.path.join(parent_dir, folder_name))

    words = name.split(' ')
    file_name = "".join(list(map(lambda x: x.capitalize(), words)))

    #Create cpp file
    f = open(file_name+".cpp", "w")
    f.write(f"/*\nLeetCode {difficulty}: {number}. {name}\n")
    f.write(f"{link}\n\nBrief Solution Explanation:\n\n")
    f.write(f"Time Complexity: O()\nMemory Complexity: O()\n*/")
    f.close()
    #Create java file
    f = open(file_name+".java", "w")
    f.write(f"/*\nLeetCode {difficulty}: {number}. {name}\n")
    f.write(f"{link}\n\n")
    f.write(f"Check {file_name}.cpp for brief solution explanation.\n*/")
    f.close()
    #Create python file
    f = open(file_name+".py", "w")
    f.write(f"'''\nLeetCode {difficulty}: {number}. {name}\n")
    f.write(f"{link}\n\n")
    f.write(f"Check {file_name}.cpp for brief solution explanation.\n'''")
    f.close()