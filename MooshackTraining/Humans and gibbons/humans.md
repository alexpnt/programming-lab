#Humans and gibbons! 

##Description

You are leading a Bioinformatics lab and working with biologists and programmers to understand the evolutionary relationship between humans and gibbons. The experimental protocol works as follows: first, your assistant assigns a distinct number to each human or gibbon genome sequence. Then, he forms several pairs of sequences by choosing one human sequence and one gibbon sequence at a time, and runs an sequence alignment algorithm on each pair. Each pair produces a data file. During the testing, he records the numbers of the tested pairs in his notebook. Finally, you analyse the data.

One morning, you arrive to the lab and you don't find your assistant, only a note on his desk:

"Sorry for the bad news, but I messed up the analysis. I did the pairwise comparison between sequences, but I forgot to record which group each sequence number belongs to. Therefore, I think that I made some comparisons between sequences in the same group. I am so embarrassed about this that I have decided to quit this job! The list of pairs that were tested is on your desk. I am sorry, and good luck!" 

Given this list of pairs of numbers, you have to use your programming skills to try to detect whether your assistant made a mistake or not. 

##Input

The first line of each test case indicates the total number of sequences tested (m) and number of pairwise comparisons that were performed (n). Then, n lines follow, each giving the numbers of the two sequences that were tested, as integers between 1 and m. Other test cases may follow.

There are most 300 sequences and 5000 pairwise comparisons. Each file may contain up to 100 test cases. 

##Output

For each test case, output "Yes" if you can be sure that at least one pair of sequences tested correspond to sequences in the same group. Otherwise, output "No".

##Example

####Example input:

    8 5
    1 2
    2 3
    4 5
    6 7
    7 8
    5 7
    2 4
    1 4
    1 3
    3 5
    1 2
    2 5
    1 5
    10 9
    4 10
    5 2
    2 9
    5 8
    2 1
    1 4
    5 6
    4 7
    2 3


####Example output:

    No
    Yes
    No
