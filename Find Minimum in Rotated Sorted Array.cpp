class Solution {
public:
int pivot(vector& nums)
{
int n=nums.size();
int l=0,u=n-1;
while(l<=u)
{
int mid=l+(u-l)/2;
int nxt=(mid+1)%n;
int prev=(mid+n-1)%n;

        if(nums[mid]<=nums[prev] && nums[mid]<=nums[nxt])
        {
            return mid;
        }
         else if(nums[mid]<=nums[u])
        {
            u=mid-1;
        }
        else if(nums[mid]>=nums[l])
        {
            l=mid+1;
        }
    }
    return -1;
    
}
int findMin(vector<int>& nums) {
    int k=pivot(nums);
    return nums[k];
}
};

TC: O(log n)
SC: O(1)
