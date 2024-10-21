def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def selection_sort_ascending(arr):
    n = len(arr)
    for i in range(n):
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        swap(arr, min_index, i)

def display_array(arr):
    for i in arr:
        print(i, end=" ")
    print()

if __name__ == "__main__":
    arr = [91, 32, 86, 37, 12]

    print("Unsorted Array")
    display_array(arr)

    selection_sort_ascending(arr)
    print("Sorted Array")
    display_array(arr)
