// 输入两个浮点的大数 输出和

import java.math.BigDecimal;
import java.util.Scanner;

public class HDU1753_f大数加
{
    public static void main(String[] atgs)
    {
        Scanner in = new Scanner(System.in);
        
        BigDecimal a, b;
        while(in.hasNext())
        {
            a = in.nextBigDecimal();
            b = in.nextBigDecimal();
            System.out.println(a.add(b).stripTrailingZeros().toPlainString());
        }
    }
}