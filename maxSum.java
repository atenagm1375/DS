//Ashena Gorgan Mohammadi, 610394128
import java.util.Scanner;
class maxSum
{
	public static void main(String[] args)
	{
		int n, max, start, end;
		n = 8;
		int[] set = {-2, -3, 4, -1, -2, 1, 5, -3};
		maxSubSeqSum Ms = new maxSubSeqSum();
		max = Ms.findMax(set, 0, 0);
		start = Ms.getStart();
		end = Ms.getEnd();
		for(int i = start; i<=end; i++)
			System.out.print(set[i]+" ");
	}
}
class maxSubSeqSum
{
	private int start;
	private int end;
	private Scanner scan;
	maxSubSeqSum(){}
	public int findMax(int[] A, int max, int i)
	{
		if(i==A.length)
			return max;
		else{
			int Sum = 0;
			max = maximum(A, max, i, i, Sum);
			return findMax(A, max, i+1);
		}
	}
	public int maximum(int[] A, int max, int i, int j, int Sum)
	{
		if(j==A.length)
			return max;
		else{
			Sum+=A[j];
			if(Sum>max){
				max = Sum;
				start = i;
				end = j;
			}
			return maximum(A, max, i, j+1, Sum);
		}
	}
	public int getStart()
	{
		return start;
	}
	public int getEnd()
	{
		return end;
	}
}
