class Solution {
    public int mySqrt(int x) {
        long st=0;
        long en=x;
        while(st+1<en)
        {
            long mid= st+(en-st)/2;
            if(mid*mid==x)
            {
                return (int)mid;
            }
            else if(mid*mid<x)
            {
                st=mid;
            }
            else
            {
                en=mid;
            }

        }
        if(en*en==x)return (int)en;
        return (int )st;
    }
}
