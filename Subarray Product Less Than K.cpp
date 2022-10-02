class Solution {
public:
int numSubarrayProductLessThanK(vector& nums, int k) {
int prod=1;
int n=nums.size();
int i=0,j=0;
int c=0;
while(j<n)
{
prod*=nums[j];

         while(prod>=k && i<=j)
         {
             prod=prod/nums[i];
              i++;
        }
         c+=(j-i+1);
            j++;
    }
    return c;
}
};

TC: O(n)
SC: O(1)
