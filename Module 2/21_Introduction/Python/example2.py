def WholeNos(n):
    if n <= 5:
        WholeNos(n + 1)
        print(n, end=" ")

WholeNos(1)
