# Problem A - A new chess game

## Description

You are working on a new chess computer game with an infinite chessboard and only knights. Of course, you cannot have an infinite chessboard because you don't have infinite RAM! But you can compute the largest chessboard that you need since you know the current location of the knights and how many moves they can do.

The goal is to know the number of distinct chessboard cells that can be visited by n knights after a given number of moves of each knight. You can assume that two or more knights can be in the same cell at the same time.

We remind you that a knight can perform 8 different moves.

## Input

The first line indicates the number of knights (1 <= _n_ <= 30). Then, _n_ lines follow. Each line gives the position (x,y) of a knight in the chessboard as well as the number of moves m (0<= _m_ <= 7) that it is allowed to perform. You may assume that knights never travel beyond coordinates -200 to 200.

## Output

For each test case, print the number of distinct cells that can be
visited by the _n_ knights.

##  Example
**Example input**
> 4
> -1 -1 2
> 2 2 1
> 3 3 3
> 4 4 3

* * *

**Example output:**

> 155
