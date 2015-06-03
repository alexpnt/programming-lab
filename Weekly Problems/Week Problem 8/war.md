#War games

##Description

You are developing a war game that simulates military operations. Several units from both sides are spread in a map. At each turn, an unit has to decide among several possibilities, such as attack a neighboring position, surrender, run away, and so on. There is also a dice that, once it shows 6, it allows a given unit to choose a road to be bombed by a missile. This can be used to delay further advances of the enemy.

You are now programming the "tips" functionality to help the user. One of the tips is to tell to the user which roads should be bombed. The possibility that you are exploring is to highlight each road that, if destroyed, two positions in the map become not reachable from each other. How to do this efficiently?

##Input

Each test case starts with the number of positions (n ≤ 1000 ) and roads between positions (m < 91000). Each of the following m lines provides information about a road connecting two positions (two non-negative integers). Assume that the roads are bidirectional. Other test cases may follow.

##Output

For each test case, output the roads that can be destroyed. The ID of the positions that are connected by the road should be sorted in increasing order. The roads must be sorted in increasing order of the first ID, and break ties with the second ID. If no road exists, the output should be "No road".

##Example

####Example input:

    10 12 
    0 6
    1 2
    1 7
    2 3
    3 4
    3 7
    4 5
    4 6
    5 6
    7 8
    7 9
    8 9
    4 4
    0 1
    1 2
    2 3
    0 3

####Example output:

    0 6
    3 4
    No road
