###Publish or Perish

State-funded research units are increasingly under pressure to publish in scientific journals, in order to secure more funding in the future. Therefore, the director of a Research Unit has asked members to propose project ideas for the current year, indicating how much funding they would require to conduct the research and how many papers they would publish as a result. Each member is allowed to submit several proposals but, in order to keep as many members active as possible, at most one project per member will be funded. Members that do not receive funding are not expected to publish any paper. 

Now, the director must decide which member projects to fund. The Research Unit's budget is limited, and the goal is to maximise the number of papers published as a result. Any funding which is not allocated to projects will have to be returned to the funding agency. 

##Input

There is a single test case in an input file. The first line contains two integers n and m corresponding to the number of researchers in the Unit and the Unit's budget in k€. The next line contains n positive integers p1,p2,...,pn representing the number of proposals submitted by each member. Finally, for each proposal of each member, the amount of funding required and the number of papers promised follow on a separate line. The first p1 lines correspond to the projects of the first member, the next p2 lines correspond to the projects of the second member, and so on.

The maximum budget considered is 5 000 k€. Research units have n ≤ 200 researchers. Each researcher submits at least 1 proposal and at most 10. 

##Output

The output for each test case is a line containing a single integer, indicating the maximum number of papers that can be obtained by funding at most one project per member. 

##Example

####Example input:

    5 20
    3 4 2 1 3
    10 3
    5 10
    8 10
    3 3
    1 18
    5 10
    10 3
    10 8
    8 7
    1 5
    4 2
    11 11
    5 5

####Example output:

    45
