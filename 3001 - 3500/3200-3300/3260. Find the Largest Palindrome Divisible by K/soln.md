## Intuition
As value of K is upto 9 so it was very intuitive to just make the cases for each value of K.

## Approach

Cases :

- K=1 or K=3 or K=9 :- We just print all 9 as the number generated
would be a palindrome and also would be divisible by 1,3,9. Pattern:-(99...99)

- K=2 :- (The number should end with even number) So largest even number would be 8 , so we will start and end with 8 and to make it the largest we would just add all 9 between them. Pattern:-(899..998)

- K=4 :- (Last two digits must be divisible by 4) So the largest two digit number would be 88 for this as we need to put that sme number in start also to make it palindromic and thus 92 or 96 would make it smaller so 88 is the best choice.
So once we get this we just add 9's between 88..88 to make it the largest possible satisfying all conditions. (Handle cases for n=1,2 and 3 separately). Pattern:-(8899...9988)

- K=5 :- (Number should end with 5 or 0) So ending with 5 would be the best and only choice as if we end with 0 then we need to put 0 at start which is not possible. Apart from this we just add 9's in between 5 to make it of the required length n. Pattern:-(599..995)

- K=8 :- (Last 3 digit should be divisible by 8) For N>6 we add "888" in the start and end and just add all 9's in between to make it the largest palindrome. Pattern:-(88899...99888)
For N<=6 we just put 8's.

- K=6 :- (Divisible by 2 and 3) For n=1 6 is the only way and for n=2 66 is the only way. Rest for N>2 we would make the 1st half and just reverse and add it so make it palindromic. So as the number should be even we start and end with 8 which is the largest even.
Now we need to make the number divisible by 3 also and for that we need to make sum of digits divisible by 3.
Now as we have put 8 in start and end which gives us 16 as its sum so now to make the number divisible by 3 we need to manage the sum in between accordingly while making sure that we make the largest palindromic number.
So adding 9's will not make a change so we need some other number also other than 9 to compensate the sum 16 make by first and last digit. So for this we if the Value of N is even then we can add "77" in between which will give a sum of 14 and thus 14+16=30 is divisible by 3 (Add 9's in other places) Pattern:-(N is even) (8999..77..9998).
For N=Odd we just add a 8 in centre and rest 9's as 8+16=24 which is divisible by 3. Pattern:-(N is odd) (8999..8..9998).

## MOST AWAITED CASE:-

- k=7 :- Don't look at the divisiblity rule for this.
First just add all 9's in the answer to satisfy the greatest value property. Now we need to modify this to make it divisible by 7.
Now if N=Odd replace the middle value by 0 to 9 or for N=even by "00","11" ... "99" and check the number finally generated for divisibility by 7.
remainder=(remainder*10+ digit)%7
we would do it for all digits .. and if the remainder comes out to be 0 ... it means the string is divisible by 7.
for eg .. dry run for 861
digit=8 ..remainder=(0 * 10 + 8)%7 = 1
digit=6.. remainder=(1 * 10 + 6)%7 = 2
digit=1.. remainder=(2 * 10 + 1)%7 = 0

hence 861 is divisible by 7
This is similar to how we used to divide in lower classes on pen and paper.