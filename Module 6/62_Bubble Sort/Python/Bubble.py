def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                # Swap without using a temporary variable
                arr[j] = arr[j] + arr[j + 1]
                arr[j + 1] = arr[j] - arr[j + 1]
                arr[j] = arr[j] - arr[j + 1]
                swapped = True
        if not swapped:
            break  # If no elements were swapped, the array is already sorted

def display_array(arr):
    print(" ".join(map(str, arr)))

def main():
    arr = [91, 32, 86, 37, 12]
    print("Unsorted Array")
    display_array(arr)

    bubble_sort(arr)
    print("Sorted Array")
    display_array(arr)

if __name__ == "__main__":
    main()
