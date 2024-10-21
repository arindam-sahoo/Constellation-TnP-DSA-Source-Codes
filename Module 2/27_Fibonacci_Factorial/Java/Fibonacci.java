import java.util.Scanner;

public class Fibonacci {
    public static int fibonacci(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Please Enter the Position Number: ");
        int n = sc.nextInt();
        System.out.println("Fibonacci Number at Position " + n + ": " + fibonacci(n));
    }
}
