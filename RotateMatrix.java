class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i< (matrix.length+1)/2; i++){
            for (int j = i; j<matrix.length-i; j++){
                int a = matrix[j][i];
                int b = matrix[matrix.length-1-i][j];
                matrix[matrix.length-1-i][j] = a;
                matrix[j][i] = b;
            }
            for (int j = i+1; j< matrix.length-i; j++){
                int a = matrix[matrix.length-1-i][j];
                int b = matrix[matrix.length-j-1][matrix.length-1-i];
                matrix[matrix.length-j-1][matrix.length-1-i] =a;
                matrix[matrix.length-1-i][j] = b;


            }

            for (int j = matrix.length-2-i;j>i; j--){
                int a = matrix[j][matrix.length-1-i];
                int b = matrix[i][j];
                matrix[i][j] =a ;
                matrix[j][matrix.length-1-i]=b;
            }

        }
    }
}
