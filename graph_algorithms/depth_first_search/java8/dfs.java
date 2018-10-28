/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ram2408
 */

import java.util.*; 
public class dfs{  
    public static void main(String args[]) throws Exception
    { 
        Graph g = new Graph(4); 
  
        g.addEdge(0, 1); 
        g.addEdge(1, 0);
        g.addEdge(0, 2); 
        g.addEdge(2, 1); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3);
        g.addEdge(3, 2);
  
        System.out.println("Dfs using starting vertex "+1); 
        g.DFS(1); 
        System.out.println("\nDone DFS");
    } 
} 
class Graph 
{ 
    private int V;   // No. of vertices 
    private boolean visited[];
    
    private Vector adj[];  //Adjacency Matrix
  
    Graph(int n) 
    { 
        V = n; 
        adj = new Vector[n]; 
        visited=new boolean[n];
        for (int i=0; i<n; ++i){
            adj[i] = new Vector<>();
            visited[i]=false;
        }
    } 
  

    void addEdge(int v, int w)     //Adding Edges
    { 
        adj[v].add(w);  // Add w to v's list. 
    } 
  
    // A function used by DFS 
    void DFSUtil(int v) 
    { 
        // Mark the current node as visited and print it 
        visited[v] = true; 
        System.out.print(v+" "); 
  
        // Recur for all the vertices adjacent to this vertex 
        Iterator<Integer> i = adj[v].listIterator(); 
        while (i.hasNext()) 
        { 
            int n = i.next(); 
            if (!visited[n]) 
                DFSUtil(n); 
        } 
    } 
  
    // The function to do DFS traversal. It uses recursive DFSUtil() 
    void DFS(int v) 
    {   
        DFSUtil(v); //Function which does dfs
    } 
}