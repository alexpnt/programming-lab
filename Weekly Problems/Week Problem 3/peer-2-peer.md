###Printing in a peer-2-peer network

You have to install a structured peer-2-peer computer network in a large company. The only requirement is that all computers should have access to printers, either directly or through a computer in the network that is directly connected to a printer. Given that you know which computers will be pairwise connected in the network, your have to decide which ones will be directly connected to printers. Since the company needs to save money on printers, the number of such computers should be as least as possible.

##Input

The first line indicates the total number of computers in the peer-2-peer network (n). Then, in each of the following lines, two positive integer values denote a pairwise connection between two computers in the network. 

    3
    132 73
    49 86
    72 111

##Output

Your program should return the minimum number of computers that need to be directly connected to printers such that every computer in the network can reach a printer (under the restriction described above). 

##Constraints

n ≤ 35 

##Example

####Example input:

    5
    1 3
    2 3
    2 4
    2 5
    3 5
    4 5

####Example output:

    2
