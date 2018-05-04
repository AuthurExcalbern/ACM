// 输入 N 求 N!

import java.math.*;
import java.util.*;

public class HDU1042_大数阶乘
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        while(in.hasNext())
        {
            int n = in.nextInt();
            BigInteger ans = BigInteger.ONE;
            
            for(int i = 1; i <= n; i++)
                ans = ans.multiply(BigInteger.valueOf(i));
            
            System.out.println(ans);
        }
    }
}