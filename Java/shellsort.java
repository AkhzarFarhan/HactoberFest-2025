public class Demo {
   int shell_sort(int my_arr[]) {
      int arr_len = my_arr.length;
      for (int gap = arr_len / 2; gap > 0; gap /= 2) {
         for (int i = gap; i < arr_len; i += 1) {
            int temp = my_arr[i];
            int j;
            for (j = i; j >= gap && my_arr[j - gap] > temp; j -= gap)
            my_arr[j] = my_arr[j - gap];
            my_arr[j] = temp;
         }
      }
      return 0;
   }
   public static void main(String args[]) {
      int my_arr[] = { 12, 34, 54, 2, 3 };
      Demo my_instance = new Demo();
      my_instance.shell_sort(my_arr);
      System.out.println("The array, after performing shell sort is : ");
      int arr_len = my_arr.length;
      for (int i = 0; i < arr_len; ++i)
      System.out.print(my_arr[i] + " ");
      System.out.println();
   }
}
shellsort(arr, num);    
System.out.println("\n Sorted array is: ");    
for (k = 0; k<num; k++)    
System.out.println(arr[k]);    
}    
}  
