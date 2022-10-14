#include <iostream>
using namespace std;

int getPivot (int *nums, int n)
{
  int s, e;
  s = 0;
  e = n - 1;
  while (s < e)
    {
      int mid = s + (e - s) / 2;
      if (nums[mid] >= nums[0])
	{
	  s = mid + 1;
	}
      else
	{
	  e = mid;
	}
    }
  return s;
}

  int main ()
  {
      int nums[2] = {3,1};
      
    cout << getPivot(nums, 2);

    return 0;
  }