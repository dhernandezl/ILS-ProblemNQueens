# Iterated Local Search for Problem N Queens
The **Local Search (LS)** is the basis of many methods used for optimization problems. Your process can be seen as iterative starting with an initial solution and improving it by making local modifications. Its system is based on the search for neighborhoods that obtain a better solution. The design of the neighborhood is crucial to the performance of the algorithm. The neighborhood is all possible solutions to consider in each search.

```
proccedure local search
  s = generate initial solution
  while s is not optimal local do
    s' ∈ N(s) with ƒ(s) < ƒ(s')
    (best solution within the neighborhood of s)
    s ← s'
  end
  return s
```

**S** generates several candidate solutions that can be obtained by applying specific modifications or "moves" to **S**. The neighborhood search and pivot rule used for replacement are usually:
* Select the best neighbor of all (best-improvement rule).
* Select the first neighbor that improves the solution (first-improvement rule).

**Iterated local search (ILS)** is based on a simple but successful idea, where it avoids rebooting found solutions like reboot approaches do, instead ILS starts with a solution (s*) and successively applies local search and disturbance to the optimal solution local. This procedure is performed a specified number of iterations or until a satisfactory solution has been found.

```
proccedure iterated local search
  s0 = generate initial solution
  s* = local search(s0)
  repeat
    s' = modify(s*, history)
    s*' = local search(s')
    s* = acceptance criterion(s*, s*', history)
  until termination criteria
  return s*
```
**Problem N Queens** - The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

## Result of experimentation
Table of generation of neighborhoods for problem of 16 queens (h = Cost).
Rule | 5 neighbours | 10 neighbours| 15 neighbours
------------ | ------------- | ------------- | -------------
best-improvement| h: 10 ↔ 14 | h: 8 ↔ 9 | h: 6 ↔ 8
first-improvement| h: 10 ↔ 15| h: 12 ↔ 10 | h: 6 ↔ 9

Table of ILS results by iterations in problem of 16 queens.
Iterations | Resultant vector | Cost (h)
:-----------: | ------------- | :-----------:
10| 14 8 1 8 1 5 1 1 12 7 2 2 15 14 1 14 | 10
25| 13 1 1 8 3 1 6 9 10 12 10 2 5 10 1 6 | 10
50| 7 5 3 15 12 9 4 1 1 6 1 13 15 9 14 4 | 6
100| 3 15 15 5 1 1 14 6 9 14 4 1 16 13 7 12 | 6

**Result of application**
```
 _  _  _  _  _  _  _  _  Q  _  _  _  _  _  _  _ 
 _  _  _  _  _  _  _  _  _  Q  _  _  _  _  _  _ 
 _  Q  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 
 _  _  _  _  _  _  _  _  _  _  _  _  _  Q  _  _ 
 _  _  _  _  _  _  _  Q  _  _  _  _  _  _  _  _ 
 _  _  _  _  _  _  _  _  _  _  _  _  _  _  Q  _ 
 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  Q 
 _  _  _  _  _  _  _  Q  _  _  _  _  _  _  _  _ 
 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  Q 
 _  _  _  Q  _  _  _  _  _  _  _  _  _  _  _  _ 
 _  _  _  _  _  _  Q  _  _  _  _  _  _  _  _  _ 
 _  _  Q  _  _  _  _  _  _  _  _  _  _  _  _  _ 
 _  _  _  _  _  _  _  _  _  _  Q  _  _  _  _  _ 
 Q  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 
 Q  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 
 _  _  _  _  _  Q  _  _  _  _  _  _  _  _  _  _ 

Solution: 9 10 2 14 8 15 16 8 16 4 7 3 11 1 1 6 
Cost:8
```

## Get the source
Clone the Git repository from GitHub
```github
git clone https://github.com/dhernandezl/ILS-ProblemNQueens.git
```

## References
To delve into local search algorithms, check out the following references:
- T. Stützle and R. Ruiz, “Iterated local search,” Handb. Heuristics, vol. 1–2, pp. 579–605, 2018, isbn.9783319071244, doi.10.1007/978-3-319-07124-4_8.
- O. Kramer, “Iterated local search,” in SpringerBriefs in Applied Sciences and Technology, no. 9783319034218, Springer Verlag, 2014, pp. 45–54, issn.21915318, doi.10.1007/978-3-319-03422-5_5.
