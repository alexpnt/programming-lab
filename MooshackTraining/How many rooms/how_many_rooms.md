###How many rooms?

##Description

Given a map of a house, write a program that computes how many rooms it has. 

##Input

Each test case describes the distribution of rooms in a house. Houses have a rectangular shape and no house is more than 50 meters on each side. In the first line of each test case, the first number gives the length of the house from north to south (in meters) and the second number gives the length from east to west. The following lines describe the location of walls for each square meter of the house, which is given by an integer value between 0 and 15. This value is the sum of the following numbers: 1 if there is a wall to the west, 2 if there is a wall to the north, 4 if there is a wall to the east and 8 if there is a wall to the south. If the value is equal to 0, then there is no wall on any side of that square meter. Note that inner walls are repeated twice in the input data; for instance, a wall to the east at a given square is also a wall to the west on the east-adjacent square. The house has at least one room.

As an example, the following input 

    4 5
    11 14 7 11 6
    3 14 5 15 5
    5 15 5 3 12
    9 14 13 13 15

corresponds to the following map. 

     _ _ _ _ _
    |_ _| |_  |
    |  _| |_| |
    | |_| |  _|
    |_ _|_|_|_|


##Output

The output for each test case is a single number in a line. 

##Example

####Example input:

    4 5
    11 14 7 11 6
    3 14 5 15 5
    5 15 5 3 12
    9 14 13 13 15

####Example output:

    7
