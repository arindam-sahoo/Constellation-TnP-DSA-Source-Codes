def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == "__main__":
    n = int(input("Please Enter the Position Number: "))
    print(f"Fibonacci Number at Position {n}: {fibonacci(n)}")
