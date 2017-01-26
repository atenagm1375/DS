//Ashena G.Mohammadi, 610394128

import java.util.Scanner;
import java.util.*;
import java.lang.StringBuffer;

public class kFormula{

    public static void generate_kformula(Scanner scan){
        System.out.println("Enter number of edges:");
        int E = scan.nextInt();
        System.out.println("Enter connected vertices(as a b meaning a directed edge from a to b):");
        HashMap<String, ArrayList<String>> hm = new HashMap<String, ArrayList<String>>();
        for(int i = 0; i < E; i++){
            String u = scan.next();
            String w = scan.next();
            if(!hm.containsKey(u))
                hm.put(u, new ArrayList<String>());
            hm.get(u).add(w);
        }
        StringBuffer kformula = new StringBuffer();
        Iterator it = hm.keySet().iterator();
        String s = (String) it.next();
        kformula.append("*" + s + hm.get(s).get(0));
        hm.get(s).remove(0);
        while(!hm.isEmpty()){
            int i = kformula.indexOf(s);
            System.out.println(i);
            while(i >= 0 && !hm.get(s).isEmpty()){
                i = kformula.indexOf(s);
                kformula.deleteCharAt(i);
                kformula.insert(i, "*" + s + hm.get(s).get(0));
                System.out.println(kformula);
                hm.get(s).remove(0);
            }
            System.out.println();
            hm.remove(s);
            it = hm.keySet().iterator();
            if(it.hasNext()){
                s = (String) it.next();
                while(kformula.indexOf(s) == -1)
                    s = (String) it.next();
            }
        }
        System.out.println(kformula);
    }

    public static void generate_graph(Scanner scan){
        StringBuffer kformula = new StringBuffer(scan.next());
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
