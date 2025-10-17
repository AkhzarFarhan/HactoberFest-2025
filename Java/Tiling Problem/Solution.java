
// Tiling Problem

// Given a "2 x n❞ board and tiles of size "2 x 1", count the number of
// ways to tile the given board using the 2 x 1 tiles.

// (A tile can either be placed horizontally or vertically.)


public class Solution {
  public static int tilingProblem(int n){
    if(n==0 || n==1){
        return 1;
    }

    // when the tiles is horizontally placed
    // f(n-2)  => n me se 2 subtract hoga har bar bachi hui space nikalne ke liye 

    // when the tiles is vertically placed
    // f(n-1)  => n me se 1 subtract hoga har bar bachi hui space nikalne ke liye 

    return (tilingProblem(n-2) + tilingProblem(n-1));
  }   

  public static void main(String[] args) {
    int n = 4;
    
    System.out.println(tilingProblem(n));
  }
}
