//Ashena Gorgan Mohammadi, 610394128

/* This is one of the projects for Data Structure course 2016-2017.
 * It calculates the maximal rectangle with one color in a rectangle 
 * with colored pixels of black and white.
 */

import java.util.Scanner;
import java.util.Stack;

public class maximumRectangle{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the dimensions of your rectangle:");
        int n = scan.nextInt();
        int m = scan.nextInt();
        char[][] pattern = new char[n][m];
        System.out.println("Enter the color of each pixel of the rectangle(w for white and b for black):");
        for(int i = 0; i < n; i++){
            String str = scan.next();
            for(int j = 0; j < m; j++)
                pattern[i][j] = str.charAt(j);
        }
        findRect fr = new findRect(n, m, pattern);
    }

}

class findRect{

    private int n; //number of rows
    private int m; //number of columns
    private char[][] pattern; //the main rectangle
    private int start; //start point of the answer rectangle
    private int end; //end point of the answer rectangle

    public findRect(int n, int m, char[][] pat){
        this.n = n;
        this.m = m;
        pattern = new char[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                pattern[i][j] = pat[i][j];
            start = 0;
            end = 0;
            colHeight();
    }

    //finds maximum rectangular area for each histogram
    private int[] findAns(int[] sc){
        Stack<Integer> s = new Stack<Integer>();
        int maxArea = 0;
        int top = 0;
        int curArea = 0;
        int i = 0, x1 = 0, x2 = 0;
        while(i < m){
            if(s.empty() || sc[i] >= sc[(int)s.peek()]){
                s.push(i++);
            }
            else{
                top = (int)s.pop();
                curArea = sc[top] * (s.empty() ? i : i - (int)s.peek() - 1);
                if(curArea > maxArea){
                    maxArea = curArea;
                    x1 = top;
                    x2 = i;
                }
            }
        }
        while(!s.empty()){
            top = (int)s.pop();
            curArea = sc[top] * (s.empty() ? i : i - (int)s.peek() - 1);
            if(curArea > maxArea){
                maxArea = curArea;
                x1 = top;
                x2 = i;
            }
        }
        int[] ans = {maxArea, x1, x2};
        return ans;
    }

    /* finds the answer by finding the area under histograms and the 
     * calculating the maximum rectangular area using area of the histograms
     */
    private void colHeight(){
        int[][] hw = new int[n][m]; //white histograms
        int[][] hb = new int[n][m]; //black histograms
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(i > 0 && pattern[i][j] == 'w')
                    hw[i][j] = hw[i - 1][j] + 1;
                else if(i > 0 && pattern[i][j] == 'b')
                    hb[i][j] = hb[i - 1][j] + 1;
                else if(pattern[i][j] == 'w')
                    hw[i][j] = 1;
                else
                    hb[i][j] = 1;
            }
        int maxArea = 0, index = n - 1;
        boolean isBlack = false;
        for(int i = n - 1; i >= 0; i--){
            int[] ans = findAns(hw[i]);
            if(ans[0] > maxArea){
                maxArea = ans[0];
                index = i;
                start = ans[1];
                end = ans[2];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            int[] ans = findAns(hb[i]);
            if(ans[0] > maxArea){
                isBlack = true;
                maxArea = ans[0];
                index = i;
                start = ans[1];
                end = ans[2];
            }
        }
        int y = index - maxArea / (end - start) + 1;
        System.out.println("The area of the maximal rectangle is " + maxArea);
        System.out.println("The maximal rectangle starts at (" + start + ", " + y + ") and ends at (" + (end - 1) + ", " + index + ")");
        System.out.print("The color of this rectangle is ");
        System.out.println(isBlack ? "black" : "white");
    }
}
