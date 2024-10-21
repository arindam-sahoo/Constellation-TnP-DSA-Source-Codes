public class Main {

    public static int mc91(int n) {
        if (n > 100) {
            return (n - 10);
        } else {
            return mc91(mc91(n + 11));
        }
    }

    public static void main(String[] args) {
        System.out.println(mc91(99));
    }
}
