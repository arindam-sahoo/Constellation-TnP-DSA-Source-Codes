import java.util.Scanner;

public class ExpoSearch {

    public static int binarySearch(int[] arr, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    public static int expoSearch(int[] arr, int n, int target) {
        if (arr[0] == target) {
            return 0;
        }

        int i = 1;
        while (i < n && arr[i] <= target) {
            i = i * 2;
        }

        return binarySearch(arr, i / 2, Math.min(i, n - 1), target);
    }

    public static void main(String[] args) {
        int[] arr = {3, 7, 12, 24, 32, 36, 51, 67, 86, 91};
        int n = arr.length;
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the target: ");
        int target = sc.nextInt();

        int result = expoSearch(arr, n, target);

        if (result != -1) {
            System.out.println("The target is found in the array at index number " + result + ".");
        } else {
            System.out.println("The target is not found in the array.");
        }
        
        sc.close();
    }
}
