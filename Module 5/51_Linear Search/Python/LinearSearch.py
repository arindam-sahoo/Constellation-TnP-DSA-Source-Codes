def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

arr = [27, 45, 32, 98, 78, 67, 54, 24, 51, 52]
target = 54

index = linear_search(arr, target)

if index > -1:
    print(f"The target value has been found at index {index}.")
else:
    print("The target value has not been found.")
