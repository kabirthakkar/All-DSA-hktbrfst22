#A binary search code in c++

class Solution {
public:
int pivot(vector& nums)
{
int n=nums.size();
int l=0;
int u=n-1;
while(l<=u)
{
int mid=l+(u-l)/2;
int next=(mid+1)%n;
int prev=(mid+n-1)%n;

        if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
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
int bi_search(vector<int>& nums, int l,int u, int target)
{
    while(l<=u)
    {
        int mid=l+(u-l)/2;
        if(nums[mid]==target)
            return mid;
        else if(target>=nums[mid])
        {
            l=mid+1;
        }
        else
        {
            u=mid-1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pi=pivot(nums);
    int ans1=bi_search(nums,0,pi-1,target);
    int ans2=bi_search(nums,pi,nums.size()-1,target);
    int res=max(ans1,ans2);
    return res;
}
};

TC: O(log n)
SC: O(1)
