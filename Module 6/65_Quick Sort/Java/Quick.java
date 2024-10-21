public class Quick {

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }

        swap(arr, i + 1, high);
        return (i + 1);
    }

    public static void QuickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
        }
    }

    public static void displayArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {91, 32, 86, 37, 12};
        System.out.print("Array Before Quick Sort: ");
        displayArray(arr);

        QuickSort(arr, 0, arr.length - 1);

        System.out.print("Array After Quick Sort: ");
        displayArray(arr);
    }
}
