#Wireless in a tunnel 

##Description

You are now working on a telecommunication company, mounting wireless access points in complicated places. Your first duty is to locate the best position of routers for wireless access in very long road tunnels (such as the Lærdal Tunnel in Norway or Gotthard Tunnel in Switzerland). 

For each tunnel, you have some possible locations for access points, each one with a given range. To simplify maintenance and repair, you would like to use as few access points as possible to cover the entire tunnel with wireless access.

##Input

Each test case describes possible places to mount an access point and the corresponding range. It starts with the lenght of the tunnel (in meters) in the first line and the number of places (n) in the second line. Then, each of the following n lines describes a possible location for an access point in the tunnel (the distance from the beginning of the tunnel, in meters) and the corresponding range (also in meters). Here is an example input: 

    20
    10
    5 4
    10 4
    14 12
    4 18
    6 24
    6 12
    4 14
    12 6
    2 30
    10 14

##Output

The output is an integer in a single line that corresponds to the minimum number of access points needed to cover the tunnel. Note that you only care about coverage inside the tunnel. Overlapping accesses are allowed. In case it is not possible to cover the tunnel, the output should be "I give up!".

##Example

####Example input:

    20
    10
    5 4
    10 4
    14 12
    4 18
    6 24
    6 12
    4 14
    12 6
    2 30
    10 14

    10
    2
    1 2
    7 4

####Example output:

    2
    I give up!
