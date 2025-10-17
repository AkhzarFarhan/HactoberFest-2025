// Freinds Pairing Problem 

// Given n freinds , each one can remain single or can be paired up with some other freind .
// Each freind can be paired only once .
//  find out the total number of ways in which  freinds can remain single or can be paired up

public class Solution {
    public static int friendsPairing(int n){
        if(n==1 || n==2) return n;

        // single
        int way1 = friendsPairing(n-1);

        // paired up
        int way2 = (n-1)*friendsPairing(n-2);

        return way1 + way2;
    }  

    public static void main(String[] args) {
        System.out.println(friendsPairing(3));
    }
}
