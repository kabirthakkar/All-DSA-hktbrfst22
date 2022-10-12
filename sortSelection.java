import java.util.*;

public class sortSelection{
    public static void printArray(int arr[]){
        for(int p = 0; p<arr.length; p++){
            System.out.print(arr[p]+" ");
        }
        System.out.println();
    }

    public static void main(String args[]){
        int arr[] = {7,8,1,3,2};

        for(int i=0; i<arr.length-1; i++){
            int smallest = i;
            for(int j=i+1; j<arr.length; j++){
                if(arr[j]<arr[smallest]){
                    smallest = j;
                }
            }

            //swap
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
        // for (int i = 0; i < arr.length - 1; i++)  
        // {  
        //     int index = i;  
        //     for (int j = i + 1; j < arr.length; j++){  
        //         if (arr[j] < arr[index]){  
        //             index = j;//searching for lowest index  
        //         }  
        //     }  
        //     int smallerNumber = arr[index];   
        //     arr[index] = arr[i];  
        //     arr[i] = smallerNumber;  
        // }

        printArray(arr);
    }
}


//Method 2

// public class sortSelection {  
//     public static void selectionSort(int[] arr){  
//         for (int i = 0; i < arr.length - 1; i++)  
//         {  
//             int index = i;  
//             for (int j = i + 1; j < arr.length; j++){  
//                 if (arr[j] < arr[index]){  
//                     index = j;//searching for lowest index  
//                 }  
//             }  
//             int smallerNumber = arr[index];   
//             arr[index] = arr[i];  
//             arr[i] = smallerNumber;  
//         }  
//     }  
       
//     public static void main(String a[]){  
//         int[] arr1 = {9,14,3,2,43,11,58,22}; 

//         selectionSort(arr1);//sorting array using selection sort  
//         for(int i:arr1){  
//             System.out.print(i+" ");  
//         }  
//     }  
// }