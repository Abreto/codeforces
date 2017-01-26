import java.util.*;

public class test{
	public static void main(String[] args){
		int [] month ={31,28,31,30,31,30,31,31,30,31,30,31};
		Scanner In = new Scanner(System.in);
		int a = In.nextInt();
		int b = In.nextInt();
		a=a-1;
		b=b-1;
		int ans = 1;
		int weeknum = b;
		for(int i=0;i<month[a]-1;i++){
			weeknum = (weeknum + 1) % 7;
			if(weeknum==0)
				ans=ans+1;
		}
		System.out.println(ans);
		In.close();
	}
}