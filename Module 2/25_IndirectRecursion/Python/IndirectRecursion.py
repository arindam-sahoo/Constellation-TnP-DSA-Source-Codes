def func2(n):
    if n <= 5:
        print(n, end=" ")
        func1(n + 1)

def func1(n):
    if n <= 5:
        print(n, end=" ")
        func2(n + 1)

if __name__ == "__main__":
    func1(1)
