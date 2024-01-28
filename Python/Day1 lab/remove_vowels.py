var = "aeiou"

text = "Wow nice to see you!"
for char in var:
    text = text.replace(char, "")

print(text)