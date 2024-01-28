
from getpass import getpass

#### global variable
usersFile = "users.txt"

#### Validation
def validateName(msg: str):
    while True:
        name = input(msg)
        if name.isalpha():
            return name
    # return validateName(msg)

def validateEmail(msg: str):
    email = input(msg)
    if "@" in email and "." in email and not email.endswith("."):
        atindex = email.index("@")
        dotindex = email.index(".")
        if atindex > 3 and dotindex > atindex + 3:
            return email
    return validateEmail(msg)

def validatePhone(msg: str):
    phone = input(msg)
    if phone.isdigit() and phone.startswith("01") and len(phone) == 11:
        return phone
    return validatePhone(msg)

def validatePassword(msg: str):
    while True:
        try:
            password = getpass(msg)
            passConf = getpass("Please enter password confirmation: ")
            assert password == passConf, "Passwords Doesn't match"
        except:
            print("Password Doesn't match!!")
        else:
            return password


#### Functionalities
def store(filename:str, data: str):
    data = data.strip(" \n")
    try:
        with open(filename, "a") as file:
            file.write(f"{data}\n")
        return True
    except:
        print("Couldn't add the user. Try again later!!")
        return False

def register():
    fName = validateName("Please enter your first name: ")
    lName = validateName("Please enter your last name: ")
    email = validateEmail("please enter your email: ")
    password = validatePassword("Please enter the password: ")
    phone = validatePhone("Please enter an egyption phone number: ")

    formated_data = f"{fName}:{lName}:{email}:{password}:{phone}"
    
    if store(usersFile, formated_data):
        return email
    return None

def login():
    #### Get the data from the database and prepare it
    try:
        with open(usersFile, "r") as file:
            lines = file.readlines()
    except FileNotFoundError as e:
        print(e)
        return None
    except Exception as e:
        print(e)
        return None
    
    for i in range(len(lines)):
        lines[i] = lines[i].split(":")[2:4]
    
    #### Validate the data
    email = validateEmail("Enter your email: ")
    for line in lines:
        if line[0] == email:
            for i in range(3):
                password = getpass("Enter your password")
                if line[1] == password:
                    print("Successfully logged in!!")
                    return email
                print("invalid password try again!!")
    return False
                

        


if __name__ == "__main__":
    print(register())
    print(login())
