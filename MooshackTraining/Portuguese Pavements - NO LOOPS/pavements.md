###  Portuguese Pavements - NO LOOPS 

###  Problem

The company "Nova Calçada Portuguesa" designs contemporaneous
portuguese pavements, with black and white stones, for large
pedestrian areas by following a simple mathematical aesthetic principle. 

The design of the pavement is based a squared boolean matrix, where each entry corresponds to a stone. If an entry in the matrix is <tt>false</tt>, then the corresponding stone is white, otherwise, is black. The matrices are build with two parameters, _N_ and _R_. Given a non-negative integer _N_, the matrix has
size _2<sup>N</sup>_. For _N=0_, the matrix has only one entry with value <tt>false</tt>. 
For _R=0_, a matrix for a given positive _N_ is obtaining by aligning  4 copies of a matrix for _N-1_, and then negating the values in the lower  right matrix. **This rule changes for a positive _R_: the negation occurs in the lower  right matrix shifted _R_ times in the counterclockwise direction.**

The following figure illustrates how a matrix for _N=3_  (for _R=0_) can be
obtained from another matrix for _N=2_, where
<tt>1</tt> means <tt>true</tt> and <tt>0</tt> means <tt>false</tt>.

    0000|0000
    0101|0101
    0011|0011
    0110|0110
    
    0000|1111
    0101|1010
    0011|1100
    0110|1001
 

The following shows for _R=6_:

    1001|0110
    0011|1100
    0101|1010
    1111|0000

    0110|0110
    1100|1100
    1010|1010
    0000|0000


Clearly, the designers cannot do it by hand, so they decided to call
you to make a program that computes such matrix for a given _N_
and _R_.


###  Input

Each line corresponds to a test case with the values of _N_ and _R_.

###  Output

Print the resulting matrix where <tt>1</tt> corresponds to <tt>true</tt> and
<tt>0</tt> corresponds to <tt>false</tt>.



###  Constraints

1 &#8804; _N_ &#8804; 10 and 0 &#8804;_R_ &#8804; 1000.



###  Example

**Input**:

    2 0
    3 6


**Output**:

    0000
    0101
    0011
    0110
    10010110
    00111100
    01011010
    11110000
    01100110
    11001100
    10101010
    00000000
