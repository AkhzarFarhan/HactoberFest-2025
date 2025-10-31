import java.util.ArrayList;

public class PascalTriangle {
    public static void main(String[] args) {
        int numRows=5; 
        ArrayList<ArrayList<Integer>> triangle=pascalTriangle(numRows);

       
        for (ArrayList<Integer> row:triangle) {
            for (int num:row) {
                System.out.print(num+" ");
            }
            System.out.println();
        }
    }

    public static ArrayList<ArrayList<Integer>>pascalTriangle(int n) {
        ArrayList<ArrayList<Integer>> triangle=new ArrayList<>();

        for (int i=0;i<n;i++) {
            ArrayList<Integer> row=new ArrayList<>();
            for (int j=0;j<=i;j++) {
                if (j==0||j==i) {
                    row.add(1); 
                } else {
                    row.add(triangle.get(i - 1).get(j - 1) + triangle.get(i - 1).get(j));
                }
            }
            triangle.add(row);
        }
        return triangle;
    }
}


