

class Solution
{
    //Function to sort an array using quick sort algorithm.
    static void quickSort(int arr[], int low, int high)
    {
        
             if(low<high)
             {
                int ind=partition(arr,low,high);
                quickSort(arr,low,ind-1);
                quickSort(arr,ind+1,high);
             }
        
        
        
        
    }
    static int partition(int arr[], int low, int high)
    {
       int pivot=arr[low];
       
       int i=low;
       int j=high;
       while(i<j)
       {
           while(i<=high &&arr[i]<=pivot)
               i++;
               
               
       while(arr[j]>pivot)
       j--;
       
       if(i<j)
       {
         int t=arr[i];
         arr[i]=arr[j];
         arr[j]=t;
       }
       
       
       }
    //   sawp(low,j); swap pivot and end
       int t=arr[low];
       arr[low]=arr[j];
       arr[j]=t;
     
       
        return j;
    } 
}
