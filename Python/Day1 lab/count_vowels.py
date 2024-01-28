var = "adel mamoun elwan"

count = 0
for char in var:
    if char in "aeiou":
        count +=1
    
print(f"The count of vowels is {count}")
