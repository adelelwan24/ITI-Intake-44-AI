sum = 0
count = 0
while (True):
    num = input("Enter a number: ")
    if num.isdigit():
        num = int(num)
        sum += num
        count +=1
    elif num == "done":
        break
    else:
        print("Invalid value. Enter numbers")


print(f"Count = {count} Sum = {sum} Avg = {sum / count}")