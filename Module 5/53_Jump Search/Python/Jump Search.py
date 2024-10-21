import math

def jump_search(arr, target):
    n = len(arr)
    jump = int(math.sqrt(n))
    prev = 0

    while arr[min(jump, n) - 1] < target:
        prev = jump
        jump += int(math.sqrt(n))
        if prev >= n:
            return False

    for i in range(prev, min(jump, n)):
        if arr[i] == target:
            return True

    return False

if __name__ == "__main__":
    arr = [3, 7, 12, 24, 32, 36, 51, 67, 86, 91]
    target = 67

    result = jump_search(arr, target)
    if result:
        print("The target is found in the array.")
    else:
        print("The target is not found in the array.")
