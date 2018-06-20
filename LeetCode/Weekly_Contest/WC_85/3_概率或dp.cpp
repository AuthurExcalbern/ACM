//概率解法
class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> p(K+W+1);
        double s=0.0;
        //停下后的分数为 K~K+W
        //计算比 N 小的可能情况个数为 s
        for(int i=K;i<K+W;i++) p[i]=1.0*(i<=N),s+=p[i];
        //当分数为 K-1 时，有 s/w 的可能取完最后一次后比 N 小
        //当p[i+W] == 0时
        //当p[i+W] == 1时
        for(int i=K-1;i>=0;i--){
            p[i]=s/W;
            s+=p[i]-p[i+W];
            // cout<<i<<' '<<p[i]<<'\n';
        }
        return p[0];
    }
};
