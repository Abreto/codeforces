import java.util.*;

public class test{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int [] p = new int[n];
		int [] b = new int[n];
		for(int i=0;i<n;i++)
			p[i] = in.nextInt()-1;
		for(int i=0;i<n;i++)
			b[i] = in.nextInt();
		int ones = 0;
		for(int i=0;i<n;i++)
			ones+=b[i];
		int ans = 0;
		if(ones%2==0)
			ans++;
		int circles = 0;
		int [] vis = new int[n];
		for(int i=0;i<n;i++){
			if(vis[i]==1)continue;
			circles = circles + 1;
			int pos = i;
			while(vis[pos]==0){
				vis[pos] = 1;
				pos = p[pos];
			}
		}
		if(circles == 1)
			circles = 0;
		System.out.println(circles+ans);
	}
}