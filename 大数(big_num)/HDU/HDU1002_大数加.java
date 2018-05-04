//输入两个大数 A 和 B
//输出它们的和

import java.math.*;
import java.util.*;

public class HDU1002_大数加
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        for(int cnt = 1; cnt <= n; cnt++)
        {
            BigInteger a = in.nextBigInteger();
            BigInteger b = in. nextBigInteger();
            System.out.println("Case " + cnt + ":");
            System.out.println(a + " + " + b + " = " + a.add(b));
            
            if(cnt != n)
                System.out.println("");
        }
    }
}