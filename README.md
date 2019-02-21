# LadderProblem

## :tophat: Introduction




## :flashlight: How to compile

Before you go you should increase your stack limit.
Write on the terminal
```
ulimit -s 65536

```
In a terminal, call commands:
```
>cmake CMakeLists.txt
>make

OR

>cmake CMakeLists.txt && make

```
Make sure the executable is produced.

Then you can test the project with the command:
```
>./KeyFinder inputFile.txt outputFile.txt
```

## :arrow_heading_up: Input Format
The first line of the input file holds two integers, N and M, showing the number of rows and the number of columns respectively.


In the following N lines, heights of cells are given, M integers in every line.


In the following line, number of queries Q is given.


Then, the next Q lines will have 4 integers indicating two cells of a query.


## :arrow_heading_down: Output Format

Print the answer for the each query, minimum length of the ladder that wanderer can travel from a cell to the other one, in a new line.

## :mushroom: Examples 


<p align="center">
<a href = "https://github.com/yilmazvolkan/LadderProblem/blob/master"><img 
<img src="https://github.com/yilmazvolkan/LadderProblem/blob/master/sample1.png" width="150" height="250"></a>
</p>


<p align="center">
<a href = "https://github.com/yilmazvolkan/LadderProblem/blob/master"><img 
<img src="https://github.com/yilmazvolkan/LadderProblem/blob/master/sample2.png" width="150" height="250"></a>
</p>


## LICENCE
All Solutions licensed under [The MIT Licence](https://github.com/yilmazvolkan/LadderProblem/blob/master/LICENSE).

## COPYRIGHT
Copyright (c) 2018 [yilmazvolkan](https://github.com/yilmazvolkan).
