# LadderProblem


## :tophat: Introduction


Our wanderer lives in Gridland. Gridland consists of N rows and M columns where every point has a height. To go from one cell to it's adjacent ones wanderer needs a ladder which is at least as long as the height difference. For example to go from a cell which has height X to a cell which has height Y wanderer needs a ladder at least jX-Yj units long. Our wanderer wants to know the the shortest ladder which allows him to go from one given cell, X, to the other, Y.
Our wanderer can only travel from a cell to it's adjacent ones in a single step.(i.e he can go 4 directions which are left,right,bottom and up.) The upper leftmost cell is (1,1) and the bottom rightmost cell is (N,M).

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


<p align="left">
<a href = "https://github.com/yilmazvolkan/LadderProblem/blob/master"><img 
<img src="https://github.com/yilmazvolkan/LadderProblem/blob/master/sample1.png" width="350" height="250"></a>
</p>


<p align="left">
<a href = "https://github.com/yilmazvolkan/LadderProblem/blob/master"><img 
<img src="https://github.com/yilmazvolkan/LadderProblem/blob/master/sample2.png" width="350" height="300"></a>
</p>


## LICENCE
All Solutions licensed under [The MIT Licence](https://github.com/yilmazvolkan/LadderProblem/blob/master/LICENSE).

## COPYRIGHT
Copyright (c) 2018 [yilmazvolkan](https://github.com/yilmazvolkan).
