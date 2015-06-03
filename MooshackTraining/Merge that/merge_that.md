###Merge that! 

##Description

The personnel department at your company needs to merge a number of files containing employee records from the various divisions and sub-divisions of the company. The records in each file are sorted by name in alphabetical order, and are to be merged into a single file, sorted in the same way.

Unfortunately, the Human Resource Management software in use at the company can only merge two files at a time, and save the result as a third file as it goes. Merge time depends essentially on reading input files from, and writing the result to, disk, so it can be considered to be proportional to the combined length of the files being merged.

Your job is to determine how the various files should be merged so as to minimise the total time required to merge all files. Merging two files with p and q records, respectively, is assumed to take t = p + q time units.

##Input

Each input consists of a number of test cases. The first line of each test set consists of an integer indicating the number of files to merge, n ≤ 5 000. The second line contains a sequence of n integers indicating the number of records in each file. 

##Output

For each test case, print on a separate line the minimum number of time units required to merge all files.

##Example

####Example input:

    6
    10 4 7 20 11 9
    8
    12 3 17 14 5 15 7 9

####Example output:

    152
    237
