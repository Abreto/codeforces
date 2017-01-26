import java.util.*;

public class test{
	
	public static long n;
	public static long m;
	public static long k;
	public static long calD(long st,long ed){
		return (st+ed)*(ed-st+1)/2;
	}
	public static long cal(long a,long b){
		if(a>=b)
			return calD(1,b)+(a-b);
		else
			return calD(b-a+1,b);
	}
	public static boolean check(long x){
		long ans = 0;
		ans=cal(k,x)+cal(n-k+1,x)-x;
		if(ans>m)
			return false;
		else 
			return true;
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		n = in.nextLong();
		m = in.nextLong();
		k = in.nextLong();
		
		long l = 1,r = m,ans = 1;
		while(l<=r){
			long mid = (l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		System.out.println(ans);
	}
}