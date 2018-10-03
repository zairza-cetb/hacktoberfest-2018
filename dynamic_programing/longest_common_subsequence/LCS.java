import java.util.*;
class LCS {
  public static void main(String[] args) {
  Scanner sc=new Scanner(System.in);
  System.out.println("Enter 1st String : ");
  String c=sc.next();
  System.out.println("Enter 2nd String : ");
  String b=sc.next();
  String x[]=c.split("");
  String y[]=b.split("");
  int n=c.length();
  int m=b.length();
  int a[][]=new int[n+1][m+1];
  
  for(int i=0;i<n+1;i++)
  {
    for(int j=0;j<m+1;j++)
    {
      if(i==0 || j==0)
       a[i][j]=0;
      else if(x[i-1].equals(y[j-1]))
       a[i][j]=a[i-1][j-1]+1;
      else
       a[i][j]=Math.max(a[i][j-1],a[i-1][j]);
    }
  }
  
  for(int i=0;i<n+1;i++)
  {
    for(int j=0;j<m+1;j++)
    {
      System.out.print(a[i][j]+" ");
    }
    System.out.println();
  }
  int i=n;
  int j=m;
  StringBuffer sb=new StringBuffer("");
  while(i!=0&&j!=0)
  {
    if(a[i][j-1]==a[i-1][j] &&a[i][j]>a[i-1][j-1])
    {
      sb.append(x[i-1]);
      --i;--j;
    }
    else if(a[i][j-1]==a[i-1][j] &&a[i][j]==a[i-1][j-1])
    {
      --i;
    }
    else if(a[i][j-1]>a[i-1][j])
    {
      --j;
    }
    else{
      --i;
    }
  }
    System.out.println();

  System.out.print("LCS Lenght :-> "+a[n][m]);
  System.out.println();
  
  System.out.print("LCS is:-> ");
  System.out.println(sb.reverse());
  }
}