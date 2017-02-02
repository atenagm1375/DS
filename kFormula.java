//Ashena G.Mohammadi, 610394128

/* This is one of the projects for Data Structure course 2016-2017.
 * It is going to get either specifications of a graph and print out the
 * its k-formula or get the k-formula and print out the specifications of
 * the graph.
 */

import java.util.*;
import java.lang.StringBuffer;

public class kFormula{

    //reads in the graph specifications and prints out the k-formula
    public static void generate_kformula(Scanner scan){
        System.out.println("Enter number of edges:");
        int E = scan.nextInt(); //number of edges

        System.out.println("Enter connected vertices(as a b meaning a directed edge from a to b):");
        HashMap<String, ArrayList<String>> hm = new HashMap<String, ArrayList<String>>(); //graph's specification as an adjacency list

        /* reads in the specifications and adds the ending vertex to
         * to the list of starting vertex
         */
        for(int i = 0; i < E; i++){
            String u = scan.next();
            String w = scan.next();
            if(!hm.containsKey(u))
                hm.put(u, new ArrayList<String>());
            hm.get(u).add(w);
        }

        StringBuffer kformula = new StringBuffer(); //holder of k-formula
        Iterator it = hm.keySet().iterator(); //iterator over the graph adjacency list
        String s = (String) it.next(); //first edge of the graph
        kformula.append("*" + s + hm.get(s).get(0));
        hm.get(s).remove(0);
        /* after adding each edge to the k-formula, it is removed from the
         * adjacency list of the graph so that searching for substitutions
         * would be easier
         */
        while(!hm.isEmpty()){
            int i = kformula.indexOf(s);
            while(i >= 0 && !hm.get(s).isEmpty()){
                i = kformula.indexOf(s);
                kformula.deleteCharAt(i);
                kformula.insert(i, "*" + s + hm.get(s).get(0));
                hm.get(s).remove(0);
            }
            hm.remove(s);
            it = hm.keySet().iterator();
            if(it.hasNext()){
                s = (String) it.next();
                while(kformula.indexOf(s) == -1)
                    s = (String) it.next();
            }
        }
        System.out.println("k-formula: " + kformula);
    }

    //reads in the k-formula and prints the edges of the graph
    public static void generate_graph(Scanner scan){
        StringBuffer kformula = new StringBuffer(scan.next()); //k-formula holder
        System.out.println("Vertices of the graph:");
        /* starting from the end of the k-formula string, regreting *s,
         * the two vertices are connected
         */
        for(int i = kformula.length() - 1; i >= 0; i--){
            while(kformula.charAt(i) != '*')
                i--;
            System.out.println(kformula.charAt(i + 1) + "-->" + kformula.charAt(i + 2));
            char c = kformula.charAt(i + 1);
            kformula.delete(i, i + 3);
            kformula.insert(i, c);
        }
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int choice;
        do{
            System.out.println("Choose the activity(Enter 1 or 2):");
            System.out.println("1.Generate K-formula");
            System.out.println("2.Generate graph");
            choice = scan.nextInt();
            if(choice == 1)
                generate_kformula(scan);
            else if(choice == 2)
                generate_graph(scan);
        }while(choice == 1 || choice == 2);
   }
}
