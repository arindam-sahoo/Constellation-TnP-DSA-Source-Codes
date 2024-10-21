def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

n = int(input("Please Enter the Number to see its Factorial: "))
print(f"Factorial of {n} : {factorial(n)}")
