
arr = []
for i in range(5):
    arr.append(input("Please enter an element: "))

print(arr)

print("############# Ascending ##################")
arr.sort()
print(arr)

print("############# Descending ##################")
arr.reverse()
print(arr)