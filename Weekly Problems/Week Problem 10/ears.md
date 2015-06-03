#Polygons have ears! 

##Description

A simple polygon has an ear at vertex v if the triangle formed by v and its two adjacent vertices shares two edges with the polygon and the other edge lies completely in the interior of the polygon.

For a given simple polygon (the edges do not cross), your goal is to count how many ears exist. 

##Input

There is a single test case per input file. The first line of each test case contains an integer n indicating the number of vertices of the polygon. Each of the next n lines contains the coordinates of a vertex. The vertices are sorted clockwise.

We assume that the polygon has no holes, is closed and there exist no three adjacent points that are colinear.

##Output

The output is the number of ears for each test case. 

##Example

####Example input:

    5
    1 2
    2 3
    1 4
    5 5
    5 1

####Example output:

    4
