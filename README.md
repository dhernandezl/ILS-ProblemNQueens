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
Rule | 5 neighbours | 10 neighbours| 15 neighbours
------------ | ------------- | ------------- | -------------
best-improvement| h: 10 ↔ 14 | h: 8 ↔ 9 | h: 6 ↔ 8
first-improvement| h: 10 ↔ 15| h: 12 ↔ 10 | h: 6 ↔ 9
