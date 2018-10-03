/*
fractional Knapsack
3
50
60 10
100 20
120 30
Ans is 240.0
*/
import java.util.*;
class Fractional{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		ArrayList<pair> al=new ArrayList();
		System.out.println("Enter no of Element:");
		int n=sc.nextInt();
		System.out.println("Enter Maxium waight:");
		int weight=sc.nextInt();
		int a[]=new int[n];
		for (int i=0;i<n ;i++) {
			int p=sc.nextInt();
			int w=sc.nextInt();
			double f=(double)p/(double)w;
			al.add(new pair(p,w,f));
		}
		double sum=0;
		System.out.println(al);
		Collections.sort(al);//sorting for fractional part
		System.out.println(al);
		for (int i=0;i<al.size();i++) {
			if ((weight-al.get(i).w)>=0) {
				sum=sum+al.get(i).p;
				weight-=al.get(i).w;
				System.out.println("weight "+weight+" price "+al.get(i).p);
			}
			else {
				 sum+=((al.get(i).p)*((double)weight/al.get(i).w));
				 double x=((al.get(i).p)*((double)weight/al.get(i).w));
				System.out.println("weight "+weight+" price1 "+x);
				weight-=al.get(i).w*(((double)weight/al.get(i).w));
			}
		}
		System.out.println("Maximum Profit is -> "+sum);

	}
}
class pair implements Comparable<pair>
{
	int p,w;
	double f;//sorting all pairs with fractinal parameter
	pair(int p,int w,double f)
	{
		this.p=p;
		this.w=w;
		this.f=f;
	}
	public String toString(){
		return this.p+" "+this.w+" "+this.f;
	}
	public int compareTo(pair pa)
	{
		//return -(int)(this.f-pa.f);//here is compare the values like 1.6 and 1.5
		if (this.f>pa.f) return -1;
		if (this.f<pa.f) return 1;
		else return 0;
	}
}