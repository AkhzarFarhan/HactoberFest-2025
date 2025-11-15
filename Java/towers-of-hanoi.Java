public class TowerOfHanoi {

    public static void toh(int n, String src, String helper, String dest) {

        if (n == 1) {
            System.out.println("Transfer disk " + n + " from " + src + " to " + dest);
            return;
        }

        toh(n - 1, src, dest, helper);

        System.out.println("Transfer disk " + n + " from " + src + " to " + helper);

        toh(n - 1, helper, src, dest);
    }

    public static void main(String[] args) {
        int n = 4;
        toh(n, "A", "B", "C");
    }
}
