public class SparseTable {
	
	private static final int MAXN = 105000;
	private static final int MAXLOG = 21;
	static int table[][] = new int[MAXLOG][MAXN];
	static int logs[] = new int[MAXN];
	private static int n;
	
	
	private static void computeLogs() {
		for (int i = 2; i <= n; i++) {
		    logs[i] = logs[i / 2] + 1;
		  }
		
	}
	
	
	private static void initTable(int[] arr) {
		for (int i = 0; i <= logs[n]; i++) {
		    int curLen = 1 << i;
		    for (int j = 0; j + curLen <= n; j++) {
		      if (curLen == 1) {
		        table[i][j] = arr[j];
		      } else {
		        table[i][j] = Math.min(table[i - 1][j], table[i - 1][j + (curLen / 2)]);
		      }
		    }
		  }
		
	}
	
	

	private static int getMin(int l, int r) {
		int p = logs[r - l + 1];
		int pLen = 1 << p;
		return Math.min(table[p][l], table[p][r - pLen + 1]);
	}

	
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		int arr[] = new int[n+1];
		for(int i=0; i<n; i++)arr[i] = sc.nextInt();
		computeLogs();
		initTable(arr);
		int q = sc.nextInt();
		while(q-- != 0) {
			int l = sc.nextInt(),r = sc.nextInt();
			int ans = getMin(l,r);
			System.out.println(ans);
		}
	}



}
