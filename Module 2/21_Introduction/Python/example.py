def WholeNos(n):
    if n <= 5:
        print(n, end=" ")
        WholeNos(n + 1)

WholeNos(1)
