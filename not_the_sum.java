// Ashena Gorgan Mohammadi, 610394128

class not_the_sum{
    public static int findTheNumber(int []A, int n){
        int max = A[0];
        for(int i = 1; i < n; i++){
            if(A[i] > max)
                max = A[i];
        }
        return 2 * max + 1;
    }

    public static void main(String []args){
        int []A = {10, -88, 45, 30, 77, 999, -1001, 2, 3954, -112};
        int ans = findTheNumber(A, A.length);
        System.out.println(ans);
    }
}