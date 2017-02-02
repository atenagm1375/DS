//Ashena G.Mohammadi, 610394128

/* This is one of the projects for Data Structure course 2016-2017.
 * It is asked to implement project handling using PERT graph.
 */

import java.util.*;

public class Pert{

    public static void main(String[] args){
        pertGraph pg = new pertGraph();
        pg.criticalPath();
    }
}

class pertGraph{

    public int V; //number of vertices(states)
    public int E; //number of edges(tasks)
    public int start; //start state of the project
    public int end; //end state of the project
    public int[][] graph; //pert graph adjacency matrix
    private int[] TE; //TE holder
    private int[] TL; // TL holder
    private ArrayList<Integer> path; //critical path holder

    public pertGraph(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number of states you have in the project:");
        V = scan.nextInt();

        System.out.println("Enter number of project's tasks:");
        E = scan.nextInt();

        System.out.println("Enter start and end states in order(states are numbered from 0 to STATES-1):");
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
        path = new ArrayList<Integer>();
        path.add(new Integer(start));
        System.out.println("----------------------------------" + '\n');
        System.out.println("Critical Path(s):");
        System.out.println("----------------------------------");
        printPath(start);
    }

    /* critical paths are calculated and printed in this function.
     * starting from the start state, all the states with same TE and TL
     * are contained in a critical path. This is implemented using dfs.
     */
    public void printPath(int state){
        if(state == end){
            for(int i = 0; i < path.size(); i++){
                System.out.print(path.get(i));
                if(i != path.size() - 1)
                    System.out.print("--" + graph[path.get(i)][path.get(i + 1)] + "-->");
            }
            System.out.println('\n' + "----------------------------------");
        }
        for(int i = 0; i < V; i++)
            if(graph[state][i] != 0 && TE[i] == TL[i]){
                path.add(new Integer(i));
                printPath(i);
                path.remove(path.size() - 1);
            }
    }

    /* This function finds TE of all vertices using dfs.
     */
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

    /* This function finds TL of all vertices using dfs.
     */
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
