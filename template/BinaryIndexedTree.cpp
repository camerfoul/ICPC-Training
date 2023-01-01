#include <iterator>

using namespace std;

namespace BIT {
    const int MAXN = 2e5 + 10;
    typedef int T;

    int n;
    T val[MAXN + 10];
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, T value) {
        for(int i = x;i <= n;i += lowbit(i)) val[i] += x;
    }

    T getSum(int x, T value) {
        T result = 0;
        for(int i = x;i >= 0;i -= lowbit(i)) result += x;
        return result;
    }

    template <typename Iterator>
    void init(Iterator startIt, Iterator endIt) {
        int pos = 0;
        while(startIt != endIt) {
            val[i] += *startIt;
            int x = i + lowbit(i);
            if(x <= n) val[x] += *startIt;
            pos++;
            startIt++;
        }
    }

}