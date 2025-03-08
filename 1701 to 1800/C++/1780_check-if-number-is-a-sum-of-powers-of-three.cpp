#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n>0){
                if(n%3==2) return false;
                n/=3;
            }
            return true;
        }
    };

/*
Let's walk through an example to understand why the condition `if (n % 3 == 2)` is used, 
and how the ternary (base-3) representation helps check if a number can be expressed as a sum of distinct powers of 3.

### Example 1: \( n = 13 \)

We want to check if \( n = 13 \) can be expressed as a sum of distinct powers of 3.

#### Step 1: Divide 13 by 3
```
n = 13
13 % 3 = 1   (remainder 1)
13 / 3 = 4   (quotient 4)
```
So the least significant digit in base-3 is 1.

#### Step 2: Divide 4 by 3
```
n = 4
4 % 3 = 1    (remainder 1)
4 / 3 = 1    (quotient 1)
```
The next digit in base-3 is 1.

#### Step 3: Divide 1 by 3
```
n = 1
1 % 3 = 1    (remainder 1)
1 / 3 = 0    (quotient 0)
```
The next digit in base-3 is 1.

Now, the ternary representation of 13 is `111` (in base-3). This means:
\[
13 = 3^2 + 3^1 + 3^0
\]
Thus, 13 **can** be expressed as a sum of distinct powers of 3, so the function should return `true`.

### Example 2: \( n = 14 \)

Let's check \( n = 14 \).

#### Step 1: Divide 14 by 3
```
n = 14
14 % 3 = 2   (remainder 2)
14 / 3 = 4   (quotient 4)
```
At this point, we hit the condition `n % 3 == 2`. This means that in the base-3 representation of 14, 
there's a digit `2`, which is not allowed because we can only use `0` or `1` to represent sums of distinct powers of 3.

Therefore, since `n % 3 == 2` occurs, the function will return `false` immediately. 
This shows that 14 **cannot** be expressed as a sum of distinct powers of 3.

### Ternary Representation Summary
- **13 in base-3** is `111` (valid, since all digits are `0` or `1`), and the function returns `true`.
- **14 in base-3** is `112` (invalid, since one of the digits is `2`), and the function returns `false`.

The condition `if (n % 3 == 2)` ensures that we only accept numbers whose base-3 representation consists of `0` or `1`, 
which corresponds to the sum of distinct powers of 3.
*/

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();