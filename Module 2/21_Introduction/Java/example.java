public class example {

    public static void WholeNos(int n) {
        if (n <= 5) {
            System.out.print(n + " ");
            WholeNos(n + 1);
        }
    }

    public static void main(String[] args) {
        WholeNos(1);
    }
}
