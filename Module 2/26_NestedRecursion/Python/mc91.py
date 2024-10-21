def mc91(n):
    if n > 100:
        return n - 10
    else:
        return mc91(mc91(n + 11))

print(mc91(99))
