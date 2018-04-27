// 输入 R n 求 R^n

import java.math.BigDecimal;
import java.util.Scanner;

public class HDU1063_大数幂
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            BigDecimal a = in.nextBigDecimal();
            int b = in.nextInt();
            
            //使用BigDecimal原生方法stripTrailingZeros实现末尾去0
            //BigDecimal.toPlainString() 返回此BigDecimal的字符串表示形式不带指数字段。为具有正的精度值，中位数的小数点右边的数字用于指示精度。
            String ans = a.pow(b).stripTrailingZeros().toPlainString();
            
            //按要求去0
            if(ans.startsWith("0"))
                ans = ans.substring(1);
            
            System.out.println(ans);
        }
    }
}