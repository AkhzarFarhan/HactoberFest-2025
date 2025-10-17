public class Find Ncr & Npr {
    public static void main(String[] args) {
        int n = 5, r = 2;
        System.out.println("NCR: " + nCr(n, r));
        System.out.println("NPR: " + nPr(n, r));
        

    }   
    static int nCr(int n, int r) {
        return fact(n) / (fact(r) * fact(n - r));
    }
    static int nPr(int n, int r) {
        return fact(n) / fact(n - r);
    }
    static int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++) {
            f *= i;
        }
        return f;
        
    }
    
}
