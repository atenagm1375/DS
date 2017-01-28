//Ashena G.Mohammadi, 610394128

import java.util.Scanner;

public class Pert{

    public static void main(String[] args){
        pertGraph pg = new pertGraph();
        pg.criticalPath();
    }
}

class pertGraph{

    public int V;
    public int E;
    public int start;
    public int end;
    public int[][] graph;
    private int[] TE;
    private int[] TL;

    public pertGraph(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number of states you have in the project:");
        V = scan.nextInt();
        System.out.println("Enter number of project's tasks:");
        E = scan.nextInt();
        System.out.println("Enter start and end states in order:");
        start = scan.nextInt();
        end = scan.nextInt();
        System.out.println("Enter time of each task between the two states:(0 1 3 means task between states 0 and 1 takes 3 days)");
        graph = new int[V][V];
        for(int i = 0; i < E; i++)
            graph[scan.nextInt()][scan.nextInt()] = scan.nextInt();
    }

    public void criticalPath(){
        TE = new int[V];
        TL = new int[V];
        TE[start] = 0;
        findTE(start);
        TL[end] = TE[end];
        findTL(end);
        printTE();
        printTL();
    }

    private void findTE(int i){
        for(int j = 0; j < V; j++)
            if(graph[i][j] != 0){
                if(TE[j] < TE[i] + graph[i][j])
                    TE[j] = TE[i] + graph[i][j];
                findTE(j);
            }
    }

    private void printTE(){
        System.out.println("----------------------------------");
        System.out.println("TE:"+'\n');
        for(int i = 0; i < V; i++)
            System.out.println(i + " : " + TE[i]);
        System.out.println("----------------------------------");
    }

    private void findTL(int i){
        for(int j = 0; j < V; j++)
            if(graph[j][i] != 0){
                if(TL[j] > TL[i] - graph[j][i] || (TL[j] == 0 && j != start))
                    TL[j] = TL[i] - graph[j][i];
                findTL(j);
            }
    }

    private void printTL(){
        System.out.println("----------------------------------");
        System.out.println("TL:"+'\n');
        for(int i = 0; i < V; i++)
            System.out.println(i + " : " + TL[i]);
        System.out.println("----------------------------------");
    }

}
