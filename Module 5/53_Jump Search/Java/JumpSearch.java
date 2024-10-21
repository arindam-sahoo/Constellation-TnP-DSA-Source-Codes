import java.lang.Math;

public class JumpSearch {
    public static boolean Jump_Search(int arr[], int target) {
        int n = arr.length;
        int jump = (int) Math.sqrt(n);
        int prev = 0;

        while (arr[Math.min(jump, n) - 1] < target) {
            prev = jump;
            jump += (int) Math.sqrt(n);
            if (prev >= n) {
                return false;
            }
        }

        for (int i = prev; i < Math.min(jump, n); i++) {
            if (arr[i] == target) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        int arr[] = {3, 7, 12, 24, 32, 36, 51, 67, 86, 91};
        int target = 68;

        boolean result = Jump_Search(arr, target);
        if (result) {
            System.out.println("The target is found in the array.");
        } else {
            System.out.println("The target is not found in the array.");
        }
    }
}
