#  Problem A - Maze

* * *

##  Problem

While on your vacations you take a tour to visit to a sumptuous palace
in central Europe. The visit includes the gardens of the palace, and
while you were taking some pictures the rest of the tour group moved
along and now you have to cross the garden's maze by yourself.

The garden's maze consists of a rectangular matrix where each block
either contains a bush which you cannot go through, or a 
straightforward, or a diagonal path.

The following figure illustrates how a garden with 4 rows and 7 columns
looks like. The sharp signs '#' indicates a bush, the '|' indicates a 
straightforward path from one place in the maze to another, and the '/'
and '\' indicate diagonal paths.

    ###|###
    ##/#\##
    #|##\## 
    ##\####

The moves in a path can be performed only between adjacent cells.
The following pictures illustrate the moves that can be performed. 

     \\|/  	\/    |	
      |	   /\	/|\	               	  	        

In this maze there is only one path that goes through the positions 
(1,4),(2,3),(3,2),(4,3), since the diagonal path segments in (2,5) 
and (3,5) lead nowhere.

You do have a map of the garden, so you can build a small computer
program to figure out for yourself one of the paths you can take to
go through the garden, from the top to the bottom of the matrix, if
there is one! Each maze either has exactly one path from the top to
the bottom, or none at all (i.e., there are no two distinct paths in
any maze), and there are no cycles in the paths. The path, if it 
exists, has no upwards moves, i.e., from each step of the path to the
next you always either stay on the same row or go down to the row below.

* * *

##  Input

The first line of the input file contains the number of rows (R) and columns (C) of the matrix.
From the second line onwards you have the maze as shown in the example above. 
Other test cases may follow.

* * *

##  Output

For each test case, print the sequence of matrix cells corresponding to the path to take to 
cross the garden, or **No Path!** if there is no path across the garden.
You cannot go outside the lateral frontiers of the maze.

* * *

##  Constraints

1 ≤ R ≤ 100 and 1 ≤ C  ≤ 100.

* * *

##  Example

**Input**:

    4 7
    ###|###
    ##/#\##
    #|##\##
    ##\####
    6 10
    ##\##|##|#
    ##/##|###\
    #|###|####
    /#\##|####
    ###\/#####
    ##########

**Output**:

    (1,4),(2,3),(3,2),(4,3)
    No Path!
