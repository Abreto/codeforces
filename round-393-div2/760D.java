import java.util.*;

public class test{
	public static long inf = Long.MAX_VALUE/3;
	public static long getmin(long a,long b){
		if(a>b)return b;
		return a;
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long [] res = new long[n+1];
		int [] time = new int[n+1];
		for(int i=1;i<=n;i++){
			time[i] = in.nextInt();
			res[i]=res[i-1]+20;
			for(int j=i-1;j>=0;j--){
				if(time[j]>=time[i]-90)
					res[i]=getmin(res[i],res[j]+50);
				if(time[j]>=time[i]-1440)
					res[i]=getmin(res[i],res[j]+90);
				if(time[j]+1440<time[i])
					break;
			}
		}
		for(int i=1;i<=n;i++)
			System.out.println(res[i]-res[i-1]);
	}
}