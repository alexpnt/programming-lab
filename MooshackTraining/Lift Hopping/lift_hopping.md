#Lift Hopping! 

##Description

A skyscraper has no more than 100 floors, numbered from 0 to 99. It has n (1<=n<=5) elevators which travel up and down at (possibly) different speeds. For each i in {1, 2,... n}, elevator number i takes Ti (1<=Ti<=100) seconds to travel between any two adjacent floors (going up or down). Elevators do not necessarily stop at every floor. What's worse, not every floor is necessarily accessible by an elevator.

You are on floor 0 and would like to get to floor k as quickly as possible. Assume that you do not need to wait to board the first elevator you step into and (for simplicity) the operation of switching an elevator on some floor always takes exactly a minute. Of course, both elevators have to stop at that floor. You are forbiden from using the staircase. No one else is in the elevator with you, so you don't have to stop if you don't want to. Calculate the minimum number of seconds required to get from floor 0 to floor k (passing floor k while inside an elevator that does not stop there does not count as "getting to floor k"). 

##Input

The input will consist of a number of test cases. Each test case will begin with two numbers, n and k, on a line. The next line will contain the numbers T1, T2,... Tn. Finally, the next n lines will contain sorted lists of integers - the first line will list the floors visited by elevator number 1, the next one will list the floors visited by elevator number 2, etc. 

##Output

For each test case, output one number on a line by itself - the minimum number of seconds required to get to floor k from floor 0. If it is impossible to do, print "IMPOSSIBLE" instead. 

##Example

####Example input:

    2 30
    10 5
    0 1 3 5 7 9 11 13 15 20 99
    4 13 15 19 20 25 30
    2 30
    10 1
    0 5 10 12 14 20 25 30
    2 4 6 8 10 12 14 22 25 28 29
    3 50
    10 50 100
    0 10 30 40
    0 20 30
    0 20 50
    1 1
    2
    0 2 4 6 8 10

####Example output:

    275
    285
    3920
    IMPOSSIBLE

####Explanation of examples:

In the first example, take elevator 1 to floor 13 (130 seconds), wait 60 seconds to switch to elevator 2 and ride it to floor 30 (85 seconds) for a total of 275 seconds.

In the second example, take elevator 1 to floor 10, switch to elevator 2 and ride it until floor 25. There, switch back to elevator 1 and get off at the 30'th floor. The total time is
10*10 + 60 + 15*1 + 60 + 5*10 = 285 seconds.

In example 3, take elevator 1 to floor 30, then elevator 2 to floor 20 and then elevator 3 to floor 50.

In the last example, the one elevator does not stop at floor 1. 
