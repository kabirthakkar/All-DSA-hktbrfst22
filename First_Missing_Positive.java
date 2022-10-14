/**  First Missing Positive
     Given an unsorted integer array nums, return the smallest missing positive integer in O(n) time and uses constant extra space .
**/

public class Main{
	public static int firstMissingPositive(int[] nums) {
        int i=0;
        while(i<nums.length){
            int correct=nums[i]-1;
            if(nums[i] > 0 && nums[i]<nums.length && nums[i]!=nums[correct])
                swap(nums,i,correct);
            else
                i++;
        }
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=j+1)
                return j+1;
        }        
        return nums.length+1;       
    }
    
    public static void swap(int[] arr,int i,int correct) {
        int temp=arr[i];
        arr[i]=arr[correct];
        arr[correct]=temp;
    }
    
    public static void main(String[] args) {
		int[] nums={3,4,-1,1};
		System.out.println(firstMissingPositive(nums));
	}
}

// O/p : 2