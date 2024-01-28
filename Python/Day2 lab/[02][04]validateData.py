name = input("Please enter your name: ")

while (True):
    if name and not name.isdigit():
        break
    name = input("Please enter your name: ")

email = input("Please enter your email: ")
while (True):
    if email and isinstance(email, str) and "@" in email:
        break
    email = input("Please enter your email: ")