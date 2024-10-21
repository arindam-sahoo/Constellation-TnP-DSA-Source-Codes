def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            swap(arr, i, j)

    swap(arr, i + 1, high)
    return i + 1

def QuickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        QuickSort(arr, low, pi - 1)
        QuickSort(arr, pi + 1, high)

def displayArray(arr):
    print(" ".join(map(str, arr)))

def main():
    arr = [91, 32, 86, 37, 12]
    print("Array Before Quick Sort:", end=" ")
    displayArray(arr)

    QuickSort(arr, 0, len(arr) - 1)

    print("Array After Quick Sort:", end=" ")
    displayArray(arr)

if __name__ == "__main__":
    main()
