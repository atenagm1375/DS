//Ashena G.Mohammadi, 610394128

import java.util.Scanner;

public class Pert{

    public static void main(String[] args){
        pertGraph pg = new pertGraph();
        int[] ans = pg.criticalPath();
        for(int i = 0; i < pg.V; i++)
            System.out.println(ans[i]);
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

    public int[] criticalPath(){
        int[] path = new int[V];
        path[0] = start;
        path[V - 1] = end;
        TE = new int[V];
        TL = new int[V];
        TE[start] = 0;
        findTE(start);
        TL[end] = TE[end];
        findTL(end);
        for(int i = start, j = i + 1, k = 1; i != end; i = j)
            for( ; j != end; j++){
                if(TE[j] == TL[j]){
                    path[k++] = j;
                    break;
                }
                if(j == V - 1 && j != end)
                    j = -1;
            }
        return path;
    }

    private void findTE(int i){
        for(int j = 0; j < V; j++)
            if(graph[i][j] != 0){
                if(TE[j] < TE[i] + graph[i][j])
                    TE[j] = TE[i] + graph[i][j];
                findTE(j);
            }
    }

    private void findTL(int i){
        for(int j = 0; j < V; j++)
            if(graph[j][i] != 0){
                if(TL[j] > TL[i] - graph[j][i] || (TL[j] == 0 && j != start))
                    TL[j] = TL[i] - graph[j][i];
                findTL(j);
            }
    }
}
