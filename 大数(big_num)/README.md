## Java

- 位于java.math包内: 大数处理类BigInteger和BigDecimar浅析
    + 常量: ONE,ZERO,TEN分别代表1,0,10.
    + 声明赋值:
        - `BigInteger bi = new BigInteger("100");`或:`BigInteger bi = BigInteger.valueOf(100);`
        - `BigDecimal bd = new BigDecimal(100);`或:`BigDecimal bd = BigDecimal.valueOf(100);`
    + 操作:
        - 加 `bi1.add(bi2)`
        - 减 `bi1.subtract(bi2)`
        - 乘 `bi1.multiply(bi2)`
        - 指数 `bi1.pow(2)`
        - 除(int)
            + 整数商 `bi1.divide(bi2)`
            + 余数 `bi1.remainder(bi2)`
            + 整数商+余数 `bi1.divideAndRemainder(bi2)[0] + bi1.divideAndRemainder(bi2)[1]`
        - 相反数 ` bi1.negate()`
        - 绝对值 `bi3.abs()`

## C++

- 分治乘法：最简单的是Karatsuba乘法，一般化以后有Toom-Cook乘法
    + Karatsuba乘法 O(nlog3) 需要`-std=c++11`
        //核心算法公式
        
        num1 = x1 * 10^mid + x0
        num2 = y1 * 10^mid + y0
        
        z0 = x0 * y0
        z1 = (x1 + x0) * (y1 + y0)
        z2 = x1 * y1
        
        r1 = z2 * 10^(2*(len-mid))
        r2 = (z1 - z2 -z0) * 10^(len-mid)
        
        num1 * num2 = r1 + r2 + z0

- 快速傅里叶变换FFT：（为了避免精度问题，可以改用快速数论变换FNTT），时间复杂度O(N lgN lglgN)。