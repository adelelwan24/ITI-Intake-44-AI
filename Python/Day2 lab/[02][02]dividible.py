def divisible(num: int) -> str:
    assert isinstance(num, int), "must be int"
    if num % 3 == 0 and num % 5 == 0 :
        return "FizzBuzz"
    elif num % 3 ==0:
        return "Fizz"
    elif num % 5 == 0:
        return "Buzz"

print(divisible(4))
print(divisible(6))
print(divisible(10))
print(divisible(15))
