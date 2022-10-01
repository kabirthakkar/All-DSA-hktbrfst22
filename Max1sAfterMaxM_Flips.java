import java.util.*;
/**
 * Given a binary array arr of size N and an integer M. 
 * Find the maximum number of consecutive 1's produced by flipping at most M 0's.
 */
class Solve {
    // m is maximum of number zeroes allowed to flip
    static int findZeroes(int arr[], int n, int m) {
         int max=0;
         
         int firstZero=-1,cnt=0;
         for(int i=0;i<n;i++){
             if(arr[i]==0)cnt++;
             while(cnt>m){
                 firstZero++;
                 if(arr[firstZero]==0)cnt--; 
             }
             int len=i-firstZero;
             max=Math.max(max,len);
         }
         return max;
    }
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int arr[]=new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i]=sc.nextInt();
        }
        int ans=findZeroes(arr,n,m);
        System.out.println("Maximum number of 1's that can be obtained are "+ans);
    }
}