# Capstone_Project
Given: a social network 𝐺 = (𝑉 , 𝐸), an initiator 𝑣0 ∈ 𝑉 , vertex weight w(𝑢) ≥ 0, edge weight f(𝑢, 𝑣) ≥ 0, hop count ℎ ∈ N, a local density metric dH (𝑢) (i.e., 𝑑𝑒𝑔𝐻 (𝑢)), and personalized local density thresholds 𝑑<sub>upper</sub> (𝑢) and 𝑑<sub>lower</sub> (𝑢), for all 𝑢, 𝑣 ∈ 𝑉 . 

Find: a subgraph 𝐻* ⊆ 𝐺 to maximize the total vertex weight of vertices in 𝐻*. such that:

(1)	 𝑣0 ∈ 𝐻*

(2)	 The distance between all vertices in  𝐻* and 𝑣0 does not exceed ℎ

(3)	 𝑑<sub>upper</sub>(𝑢) ≥ 𝑑𝐻*(𝑢) ≥ 𝑑<sub>lower</sub>(𝑢), for all vertices u ∈ 𝐻*

# How to Run
If you have make tool, run:
```
make run
```
else run the command: 
```
g++ -mcmodel=medium -Ofast -o solver ./main.cpp

./solver.exe
```

# Sample input

The first line contains two integers, 𝑛 and 𝑚, representing the number of nodes and the number of edges.

The second line contains 𝑛 integers representing 𝑑<sub>upper</sub>(𝑢).

The third line contains 𝑛 integers representing 𝑑<sub>lower</sub>(𝑢).

The following 𝑚 lines each contain three integers 𝑢, 𝑣, and 1, indicating that there is an edge with weight 1 between nodes 𝑢 and 𝑣.

```
8 9
1 3 1 7 3 1 1 3
3 1 2 1 3 2 1 1
2 0 0 1 0 0 0 0
1 2 1
2 3 1
1 3 1
1 4 1
1 5 1
1 6 1
5 6 1
6 7 1
6 8 1
```

