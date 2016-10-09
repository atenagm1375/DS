//Ashena Gorgan Mohammadi, 610394128

/* This program is to calculate the maximum summation of a subarray. It recursively
 * divides the array into halves and calculates the maximum summation for left, right,
 * and center and find the maximum between the three values.
 */

import java.util.Scanner;

class maxSum
{
	public static void main(String[] args)
	{
		int n, start, end;
		n = 8;
		int[] set = {-2, -3, 4, -1, -2, 1, 5, -3};
		maxSubSeqSum Ms = new maxSubSeqSum(n, set);
		int []max = new int[3];
		max = Ms.maxSubArraySum(0, n - 1);
		//start = Ms.getStart();
		//end = Ms.getEnd();
		System.out.println(max[0]);
		for(int i = max[1]; i <= max[2]; i++)
			System.out.print(set[i]+" ");
	}
}
class maxSubSeqSum
{
	private int n;
	private int[] array;
	private int start;
	private int end;
	private int s, e;
	
	maxSubSeqSum(int n, int []A){
		this.n = n;
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
				s = i;
			}
		}
		sum = 0;
		int rightSum = Integer.MIN_VALUE;
		for(int i = m + 1; i <= h; i++){
			sum += array[i];
			if(sum > rightSum){
				rightSum = sum;
				e = i;
			}
		}
		return leftSum + rightSum;
	}

	int []maxSubArraySum(int l, int h){
		int[] max = new int[3];
		if(l == h){
			max[0] = array[l];
			max[1] = max[2] = l;
			return max;
		}
		else{
			int m = (l + h) / 2;
			int []left = new int[3];
			left = maxSubArraySum(l, m);
			int []right = new int[3];
			right = maxSubArraySum(m + 1, h);
			if(left[0] > right[0]){
				for(int i = 0; i < 3; i++)
					max[i] = left[i];
			}
			else{
				for(int i = 0; i < 3; i++)
					max[i] = right[i];
			}
			int center = maxSubArrayMiddle(l, m, h);
			if(center > max[0]){
				max[0] = center;
				max[1] = s;
				max[2] = e;
			}
			return max;
		}
	}
}