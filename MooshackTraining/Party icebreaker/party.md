#  Problem B - Party icebreaker


###  Description

To cellebrate its success, a new company throws a really big party. Everyone who is someone in town is invited. To help people get to know each other, each guest is given a card with a number (a positive integer) upon arrival, and asked to find two other guests in the crowd to form a group of three such that: 

*   there is at least one man and one woman in the group
*   the sum of the numbers held by the two women (or two men) in the group is
    equal to the number held by the man (or woman, respectively).
    
The first group to meet these conditions will win 60.000$, or so say the
party organizers...

Since nobody could form such a group until the end of the party, some people
demanded that all cards be collected to see whether the game was rigged so that
the prize would not have to be paid. 
It is your job to find out whether, given the numbers handed out at the party,
it was possible to win the game and claim the prize.

### Input

For each test case, the number of guests, _n_, is given in the first line, and each guest's number is given in the next _n_ lines. 
To distinguish between men and women at the party, men's numbers were recorded
as negative numbers, whereas women's numbers were recorded as positive.
The end of the test case is indicated by a line containing "0". 
A new test case may then follow.

### Output

The output for each test case consists of a single line saying "Fair" if the game was fair and a winning group could indeed be found. Otherwise, the output must be "Rigged".

###  Example

**Example input:**

> 8
> -1
> 3
> 5
> -2
> 6
> 2
> -5
> 7
> 0
> 4
> -1
> -2
> 1
> 2
> 0
> 

* * *

**Example output:**

> Fair
> Rigged
> 
