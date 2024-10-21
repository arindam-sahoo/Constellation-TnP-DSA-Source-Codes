public class Arrays {
    public static void main(String[] args) {
        int[] x = {5, 4, 3, 2, 1};

        int length = x.length;

        System.out.println("Accessing elements in the array:");
        for (int i = 0; i < length; i++) {
            System.out.print(x[i] + " ");
        }
    }
}
