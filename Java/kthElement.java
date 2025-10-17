	public static void main (String[] args) {
	  Scanner sc=new Scanner(System.in);
	  int test=sc.nextInt();
	  while(test-->0){
	      int length=sc.nextInt();
	      int arr[]=new int[length];
	      for(int i=0;i<length;i++){
	          arr[i]=sc.nextInt();
	      }
	      int k=sc.nextInt();
	      Arrays.sort(arr);
	      System.out.println(arr[k-1]);
	  }
	}
