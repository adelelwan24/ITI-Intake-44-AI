while(True):
    num = input("Please enter a number: ")
    if num.isdigit():
        num = int(num)
        break
    else:
        continue

for i in range(1, num+1):
    print(" " * (num - i), "*" * i)
