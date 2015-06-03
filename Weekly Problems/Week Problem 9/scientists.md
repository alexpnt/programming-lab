#Scientists 

##Description

Your brother is a scientist at CERN and his doing weird calculations about area and perimeter of rectangles in the plane. In particular, he wants to find a closed formula for the ratio between the area and the perimeter of the union of a set of rectangles randomly located in the plane, as they may help him to speed-up the calculations of the Large Hadron Collider.

However, your brother does not know how to program, so he needs your help to perform simulations. First, your program generates hundreds of rectangles randomly located in the plane and consider their union. Then, it should compute the area and perimeter of the union of these rectangles. That's quite simple for you, right?

##Input

Each test case gives the location of several rectangles on the plane. Each line describes the coordinates of the rectangle, that is, the coordinates (integer values) of the top-right corner and bottom-left corner. The plane ranges from 0 to 215 and there are no repeated coordinates. There are no more than one thousand rectangles.

##Output

For each test case, output the total area and total perimeter of the union of the rectangles. 

##Example

####Example input:

    1 7 6 15
    3 17 8 19
    4 1 12 13
    7 7 17 20
    14 4 17 12
    10 14 14 18
    11 2 15 5

####Example output:

    249 90
