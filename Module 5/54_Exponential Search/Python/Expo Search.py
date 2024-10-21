def binary_search(arr, left, right, target):
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1

def expo_search(arr, n, target):
    if arr[0] == target:
        return 0

    i = 1
    while i < n and arr[i] <= target:
        i = i * 2

    return binary_search(arr, i // 2, min(i, n - 1), target)

def main():
    arr = [3, 7, 12, 24, 32, 36, 51, 67, 86, 91]
    n = len(arr)
    target = int(input("Enter the target: "))

    result = expo_search(arr, n, target)

    if result != -1:
        print(f"The target is found in the array at index number {result}.")
    else:
        print("The target is not found in the array.")

if __name__ == "__main__":
    main()
