//Ashena Gorgan Mohammadi, 610394128
import java.util.Scanner;
class maxSum
{
	public static void main(String[] args)
	{
		int n, max, start, end;
		n = 8;
		int[] set = {-2, -3, 4, -1, -2, 1, 5, -3};
		maxSubSeqSum Ms = new maxSubSeqSum(n, set);
		max = Ms.maxSubArraySum(0, n - 1);
		start = Ms.getStart();
		end = Ms.getEnd();
		for(int i = start; i<=end; i++)
			System.out.print(set[i]+" ");
	}
}
class maxSubSeqSum
{
	private int n;
	private int[] array;
	private int start;
	private int end;
	
	maxSubSeqSum(int n, int []A){
		this. n = n;
		array = new int[n];
		array = A;
	}
	
	public int getStart(){
		return start;
	}

	public int getEnd(){
		return end;
	}

	public int maxSubArrayMiddle(int l, int m, int h){
		int sum = 0;
		int leftSum = Integer.MIN_VALUE;
		for(int i = m; i >= l; i--){
			sum += array[i];
			if(sum > leftSum){
				leftSum = sum;
				start = i;
			}
		}
		sum = 0;
		int rightSum = Integer.MIN_VALUE;
		for(int i = h; i > m; i++){
			sum += array[i];
			if(sum > rightSum){
				rightSum = sum;
				end = i;
			}
		}
		return leftSum + rightSum;
	}

	int maxSubArraySum(int l, int h){
		if(l == h)
			return array[l];
		else{
			int m = (l + h) / 2;
			int left = maxSubArraySum(l, m);
			int right = maxSubArraySum(m + 1, h);
			int center = maxSubArrayMiddle(l, m, h);
			int max = center;
			if(right > max){
				max = right;
				start = m + 1;
				end = h;
			}
			if(left > max){
				max = center;
				start = l;
				end = m;
			}
			return max;
		}
	}
}
