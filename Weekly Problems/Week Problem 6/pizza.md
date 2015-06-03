#Merge that! 

##Description

You are planning a party with your friends and you want to prepare a big, big pizza. In order to know their preferences you wrote a facebook application that shows a list of possible ingredients for the pizza. Then, each of your friends can choose at most 3 ingredients that he/she would either hate or love to have in the pizza and you will try to satisfy at least one of the ingredient requirements for each friend. In that case, you assume that your friend is happy with the pizza.

Of course, you do not weight the opinion of your friends in the same way, since some of them are more close to you than others. Therefore, you decided to assign a "friendship" value, from 1 to 100, to each of your friends; the larger the friendship value, more weight you give to the choices of this person.

Now you have to write a program to find the ingredients for your pizza that minimizes the degree of "unhappiness": the sum of the friendship values of unhappy friends.

##Input

The first line for each test case has two integers n and m corresponding, respectively, to the total number of ingredients, and the total number of friends. Then, m lines of data follow. Each line i starts with an integer value v, which corresponds to the friendship value of your i-th friend, followed by up to three (possibly negative) integers a, b, c, where the absolute value of the integer is just the ID of the ingredient, and its sign indicates whether the ingredient must be in the pizza (if positive) or not (if negative), and a trailing 0 (zero) to indicate the end of the line. 

##Constraints

n ≤ 200
m ≤ 2 000 

##Output

The output for each test case is a line containing a single integer, indicating the minimum degree of unhappiness. 

##Example

####Example input:

    2 10
    24 -2 0
    57 2 0
    23 -1 2 0
    77 -2 0
    93 -2 -1 0
    7 1 0
    24 1 -2 0
    15 1 2 0
    53 1 0
    36 2 0

####Example output:

    116
