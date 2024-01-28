while(True):
    num = input("Please enter a number: ")
    if num.isdigit():
        num = int(num)
        break
    else:
        continue

output = []
for i in range(1, num+1):
    tmp = []
    for j in range(1, i+1):
        tmp.append(i * j)
    output.append(tmp)

print(output)