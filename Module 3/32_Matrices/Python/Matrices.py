# Declaring a matrix of 3 rows and 4 columns
x = [
    [4, 3, 2, 1],
    [8, 7, 6, 5],
    [12, 11, 10, 9]
]

x[2][2] = 100

print("Accessing elements in the matrix:")
for i in range(3):
    for j in range(4):
        # Accessed the element at ith row and jth column
        print(x[i][j], end="\t")
    print()
