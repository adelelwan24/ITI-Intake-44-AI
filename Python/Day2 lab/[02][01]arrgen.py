def genArr(length: int, start: int) -> list:
    assert isinstance(length, int) and isinstance(start, int), "must be int"
    arr = []
    for i in range(start, start + length):
        arr.append(i)
    return arr

print(genArr(3, 1))
