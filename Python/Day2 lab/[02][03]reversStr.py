def reverseStr(text: str) -> str:
    lstr = list(text)
    lstr.reverse()
    new = "".join(lstr)
    return new

print(reverseStr("Hello world"))