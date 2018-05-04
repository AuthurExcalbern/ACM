//大菲波数
import java.math.BigDecimal;
import java.util.Scanner;

public class HDU1715_fibonaqi
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        BigDecimal a[] = new BigDecimal[1005];
        a[1] = a[2] = new BigDecimal(1);
        
        for(int i = 3; i <= 1000; i++)
            a[i] = a[i-1].add(a[i-2]);
        
        while(n-->0)
        {
            int x = in.nextInt();
            System.out.println(a[x]);
        }
    }
}