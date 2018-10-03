 /*
 For more information, see: https://java2blog.com/breadth-first-search-in-java/
 */
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
 
public class BreadthFirstSearchExampleNeighbourList
{ 
 
	private Queue<Node> queue;
	static ArrayList<Node> nodes=new ArrayList<Node>();
	static class Node
	{
		int data;
		boolean visited;
		List<Node> neighbours;
 
		Node(int data)
		{
			this.data=data;
			this.neighbours=new ArrayList<>();
 
		}
		public void addneighbours(Node neighbourNode)
		{
			this.neighbours.add(neighbourNode);
		}
		public List<Node> getNeighbours() {
			return neighbours;
		}
		public void setNeighbours(List<Node> neighbours) {
			this.neighbours = neighbours;
		}
	}
 
	public BreadthFirstSearchExampleNeighbourList()
	{
		queue = new LinkedList<Node>();
	}
 
	public void bfs(Node node)
	{
		queue.add(node);
		node.visited=true;
		while (!queue.isEmpty())
		{
 
			Node element=queue.remove();
			System.out.print(element.data + "t");
			List<Node> neighbours=element.getNeighbours();
			for (int i = 0; i < neighbours.size(); i++) {
				Node n=neighbours.get(i);
				if(n!=null && !n.visited)
				{
					queue.add(n);
					n.visited=true;
 
				}
			}
 
		}
	}
  }
