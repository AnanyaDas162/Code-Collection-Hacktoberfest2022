/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int i=1;i<=T;i++)
		{
		    int w1,w2,x1,x2,M;
		    w1=sc.nextInt();
		    w2=sc.nextInt();
		    x1=sc.nextInt();
		    x2=sc.nextInt();
		    M=sc.nextInt();
		    int diff,temp1,temp2;
		    diff=(w2-w1);
		    temp1=(x1*M);
		    temp2=(x2*M);
		    if((diff>=temp1 && diff<=temp2))
		    {
		        System.out.println("1");
		        //System.out.println("\n");
		    }
		    else
		    {
		        System.out.println("0");
		        //System.out.println("\n");   
		    }
		    
		    
		}
	}
}
