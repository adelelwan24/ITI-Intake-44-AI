from authenticationSys import login, register
from fundRaiseCompain import createCompain, viewCompains, editCompain, delCompain, searchCompain


curUser = None
while True:

    if not curUser:
        action = input("Select an Action: l=login, r=register, x=exit: ")
        if action == "l":
            curUser = login()
        elif action == "r":
            curUser = register()
    else:
        action = input("Select an Action on projects: n=new, v=viewProj, e=edit, d=delete, s=search, x=exit: ")
        if action == "n":
            createCompain(curUser)
        elif action == 'v':
            viewCompains()
        elif action == "e":
            title = input("Enter compain title: ")
            editCompain(title, curUser)
        elif action == 'd':
            title = input("Enter compain title: ")
            delCompain(title, curUser)
        elif action == "s":
            date = input("Enter a date to search with: ")
            searchCompain(date)


    if action == 'x':
        print("See you next time!!")
        exit()
