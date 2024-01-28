import re 
from authenticationSys import validateName, store

projectsFile = "projects.txt"

def validateNum(msg:str):
    target = input(msg)
    if target.isdigit():
        return target
    return validateNum(msg)

def validateDate(msg):
    date = input(msg + " in the format YYYY-MM-DD: ")
    date_pattern = re.compile(r'^\d{4}-\d{2}-\d{2}$')
    if  bool(date_pattern.match(date)):
        return date
    return validateDate(msg)

def validateCompain():
    title = input("Enter compain title: ")
    details = input("Enter compain details:")
    target = validateNum("Enter compain target: ")

    startDate = validateDate("Enter compain start date")
    endDate = validateDate("Enter compain end date")
    return title, details, target, startDate, endDate

def createCompain(ownerEmail:str):
    data = validateCompain()

    formated = f"{data[0]}:{data[1]}:{data[2]}:{data[3]}:{data[4]}:{ownerEmail}"
    print(formated)

    return store("projects.txt", formated)

def viewCompains(filename:str = projectsFile):
    #### Get the data from the database and prepare it
    try:
        with open(filename, "r") as file:
            lines = file.read()
        print("#" * 20)
        print(lines)
        print("#" * 20)
        return True
    except Exception as e:
        print(e)
        return False
    
def editCompain(title:str, ownerEmail:str, filename:str = projectsFile):
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
    except Exception as e:
        print(e)
        return False

    index = -1
    for i in range(len(lines)):
        tmp = lines[i].split(":")
        if tmp[0] == title and tmp[-1].strip("\n") == ownerEmail:
            index = i
            break
    
    if index != -1:
        data = validateCompain()
        formated = f"{data[0]}:{data[1]}:{data[2]}:{data[3]}:{data[4]}:{ownerEmail}"
        lines[i] = formated + "\n"
        try:
            with open(filename, "w") as file:
                lines = file.writelines(lines)
            print(lines)
            return True
        except Exception as e:
            print(e)
            return False
    return False

def delCompain(title:str, ownerEmail:str, filename:str = projectsFile):
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
    except Exception as e:
        print(e)
        return False

    index = -1
    for i in range(len(lines)):
        tmp = lines[i].split(":")
        print(tmp)
        if tmp[0] == title and tmp[-1].strip("\n") == ownerEmail:
            index = i
            break
    
    if index != -1:
        lines.pop(index)
        try:
            with open(filename, "w") as file:
                lines = file.writelines(lines)
            print(lines)
            return True
        except Exception as e:
            print(e)
            return False
    return False

def searchCompain(date, filename:str = projectsFile):
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
    except Exception as e:
        print(e)
        return False

    res = []
    for i in range(len(lines)):
        tmp = lines[i].split(":")
        print(tmp)
        if tmp[3] == date or tmp[4] == date:
            print(lines[i])
            res.append(lines[i])
    return res

if __name__ == "__main__":
    createCompain("adel@gmail.com")