# Solve it Mathematically

![alt text](image.png)

From the figure, we can see that from digit '1' at `ones` place repeat in group of 1 after interval of 10. Similarly, '1' at tens place repeat in group of 10 after interval of 100. <br>
This can be formulated as `(n/(i∗10))∗i`.
<br>
Also, notice that if the digit at tens place is '1', then the number of terms with '1' is increased by x+1, if the number is say "ab1x". As if digits at tens place is greater than 1, then all the 10 occurances of numbers with '1' at tens place have taken place, hence, we add 10.<br>
This is formluated as `min⁡(max⁡((n mod (i*10))−i+1,0),i)`.
<br>
Lets take an example, say n=1234.
<br>

```cpp
int countDigitOne(int n) {
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        // 0LL is number zero in long long format
    }
    return countr;
}
```

Complexity analysis

- Time complexity: O(log10(n)).
- - No of iterations equal to the number of digits in n which is log10(n).
- Space complexity: O(1) space required.