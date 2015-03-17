###Delicious Pasta

Bored of being a programmer, you decided to collect the recipes from your italian grand-mother and open an Italian restaurant called "Delicious Pasta!" in Coimbra.

In her book of recipes, you found a list of different types of pasta. For each type of pasta, there is a "taste value" that depends of the cooking time. According to your grand-mother, the taste of pasta improves over the cooking time, which corresponds to an increase of the taste value. However, different types of pasta need different amounts of cooking time to achieve a certain taste value. You want to introduce a new dish containing as many types of pasta as it may be needed to achieve the ultimate flavour. Therefore, you would like to know which types of pasta you should use and for how long each of them should be cooked so that the sum of the corresponding taste values is the maximum possible. Each type of pasta must be cooked separately from the rest, and you have only one cooker. In addition, you have a cooking-time bound, so you cannot afford to make mistakes! 

##Input

The first line of each test case gives the number of different types of pasta and the time bound for cooking time in minutes. Then, in each of the following lines, you find three numbers: the first is the identification number of the pasta, the second is the cooking time (in minutes) and the third is the corresponding taste value. We assume that the cooking time in minutes is larger or equal to the number of different types of pasta. You need to decide on the cooking time for each type of pasta. If the cooking time is zero, the pasta is not to be used in the dish. 

##Output

The output for each test case is a single number, the maximum overall taste value that can be achieved by cooking different types of pasta so that the overall cooking time does not exceed a given time bound. 

##Example

####Example input:

    4 5
    1 1 5
    1 2 5
    1 3 6
    1 4 7
    1 5 8
    2 1 5
    2 2 5
    2 3 6
    2 4 7
    2 5 8
    3 1 5
    3 2 6
    3 3 7
    3 4 8 
    3 5 8 
    4 1 6 
    4 2 7
    4 3 8
    4 4 9
    4 5 9

####Example output:
    22
