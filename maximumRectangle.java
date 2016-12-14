//Ashena Gorgan Mohammadi, 610394128

import java.util.Scanner;


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

    private int n;
    private int m;
    private char[][] pattern;
    private int[] area;

    public findRect(int n, int m, char[][] pat){
        this.n = n;
        this.m = m;
        pattern = new char[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                pattern[i][j] = pat[i][j];
    }
}

class sizeColor{

    public int val;
    public char color;

    public sizeColor(int a, char c){
        val = a;
        color = c;
    }
}
