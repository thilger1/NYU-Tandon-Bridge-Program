/*
Ted Hilger - th3093

Question 1.

To prove the theory that for all integers n >= 1, (1 + 2^n) <= 3^n, we will start with the base case of n = 1.
(1 + 2^1) <= 3^1 = 1 + 2 <= 3 = 3 <= 3, which is true. 
Next, we will assume that our theory is true for an integer, k. 
(1 + 2^k) <= 3^k 
Now, we will prove through induction that our theory is true for the next integer, k + 1
1 + 2^(k + 1) <= 3^(k+1)
Now, through algebra...
1 + 2^k + 2^1 <= 3^k + 3^1
3 + 2^k <= 3^k + 3
subtract 3 from both sides
2^k <= 3^k
From our inductive step, we know that 2^k + 1 is less than or equal to 3^k. Now that 2^k is proven to be
less than or equal to 3^k, we know that 2^k + 1 must at least be more than or equal to 2^k
Therefore, 
2^k <= 2^k + 1
Which is a true statement, thus proving our theory. *


Question 2.

a. Total options = 26 upper + 26 lower + 10 digits = 62 options
Password = 10 * 62^4 options
Since one char must be a digit, 10 (for the one slot that is at least a digit) is multiplied by
It will take 10*62^4 units of time in the worst case scenario

b. C(8, 5) = 8! / (8-5)! * 5!
Since you are looking for subsets, order of elements does not matter, and you will choose 5 elements from the 
10 total options for each. But, of those 10 options, 3 and 4 are not allowed, which are two elements. 
10 - 2 = 8. Ultimately, you will be choosing 5-element subsets from 8 options


Question 3.
a. # of bit strings of length 8 - 2^8 = 256

b. 
Probabilities:
1 - 2/6
2 - 3/6
3 - 1/6
Expected value of one dice
1 * 2/6 = 2/6
2 * 3/6 = 6/6
3 * 1/6 = 3/6
Sum - 11/6
Since 2 identical dice are rolled and we are looking for the sum, we can multiply this by 2 to get 22/6
Expected value: 22/6 or ~3.66

Question 4.

Function 1:
The first for loop runs in constant time theta(1) because i iterates to the same value every time. Nested within it 
is a loop that will run in theta(logn) time because every iteration j is halved.
The loop below will also run in theta(logn) time because i also halves after every iteration. 
The total here is theta(1) * theta(logn) + theta(logn), which simplifies to theta2(logn). Since we drop constants,
the function runtime is theta(logn).

Function 2: 
For this function, runtime is only dependent on n, so we can mostly ignore the a variable in terms of runtime.
Since there are if statements, either possibility happens a fraction of the runtime. Since we will ultimately drop
the constants, we can ignore this as well.  
As this function recurses, the first if statement has n divided by 2, then multiplied by duplicate recursive call, n/2. This would give 
a square root of n, but since it is multiplied by itself, it will just become n again (root times root = whole)
The else statement does the same, but n is subtracted by 1 before, so the equation would be root(n-1) * root (n-1)
The overall equation would be something like 1/2(root(n) * root(n)) + 1/2((root(n-1) * (root(n-1)))), but since we can
drop constants, the overall runtime will simplify to theta(n).



*/