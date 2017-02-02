// Ashena Gorgan Mohammadi, 610394128

/* This is one of the projects for Data Dtructure course 2016-2017.
 * The task is to find the shortest path between each two vertices in a directed
 * graph and print that path.
 */

import java.util.Scanner;

public class allShortestPaths{

    public static Scanner scan = new Scanner(System.in);
    public static int v; //number of vertices
    public static int[] d; //distance handler
    public static boolean[] included; //shows if the vertex is in the answer or not
    public static int[] parent; //holds parent of each vertex

    public static int[][] createGraph(){
        int[][] graph = new int[v][v];
        System.out.printf("From\t To\t Distance\t Enter -1 -1 -1 to end input\n");
        int i, j;
        do{
            i = scan.nextInt();
            j = scan.nextInt();
            int a = scan.nextInt();
            if(a != -1)
                graph[i - 1][j - 1] = a;
            else
                break;
        }while(i != -1 && j != -1);
        return graph;
    }

    //returns the vertex with minimum distance
    public static int minIndex(){
        int min = Integer.MAX_VALUE, i = -1;
        for(int u = 0; u < v; u++){
            if(!included[u] && d[u] <= min && d[u] >= 0){
                min = d[u];
                i = u;
            }
        }
        if(min == Integer.MAX_VALUE)
            return -1;
        return i;
    }

    public static void printPath(int i){
        if(parent[i] == -1)
            return;
        printPath(parent[i]);
        System.out.printf(" -> %d", i + 1);
    }

    public static void print(int u){
        for(int i = 0; i < v; i++)
            if(i != u && d[i] != Integer.MAX_VALUE){
                System.out.printf("%2d %8d %14d %16d", u + 1, i + 1, d[i], u + 1);
                printPath(i);
                System.out.println();
            }
    }

    //The main dijkstra algorithm for all vertices
    public static void dijkstra(int[][] graph, int u){
        d = new int[v];
        included = new boolean[v];
        parent = new int[v];
        for(int i = 0; i < v; i++){
            d[i] = Integer.MAX_VALUE;
            included[i] = false;
            parent[i] = -1;
        }
        d[u] = 0;
        for(int i = 0; i < v; i++){
            int w = minIndex();
            if(w != -1){
                included[w] = true;
                for(int j = 0; j < v; j++)
                    if(!included[j] && graph[w][j] != 0 && d[w] + graph[w][j] < d[j]){
                        parent[j] = w;
                        d[j] = d[w] + graph[w][j];
                    }
            }
        }
        print(u);
    }
    
    public static void main(String[] args){
        System.out.println("Enter the number of vertices:");
        v = scan.nextInt();
        int[][] graph = new int[v][v];
        graph = createGraph();
        System.out.printf("From\t To\t Minimum Distance\t Path\n");
        for(int i = 0; i < v; i++)
            dijkstra(graph, i);
    }
}
