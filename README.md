# Iterated Local Search for Problem NQueens
The Local Search (LS) is the basis of many methods used for optimization problems. Your process can be seen as iterative starting with an initial solution and improving it by making local modifications. Its system is based on the search for neighborhoods that obtain a better solution. The design of the neighborhood is crucial to the performance of the algorithm. The neighborhood is all possible solutions to consider in each search.

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

<p>The neighborhood search and pivot rule used for replacement are usually:</p>
<ol type="A">
  <li>Select the best neighbor of all (best-improvement rule).</li>
  <li>Select the first neighbor that improves the solution (first-improvement rule).</li>
</ol>
<p>
The eight queens problem is a very popular strategy that consists of placing eight queens within a chessboard without threatening them. Finding the solution for different dimensions is the same as finding the solution for a minimal problem.
</p>

![image](https://user-images.githubusercontent.com/45026559/115155094-f5ade780-a043-11eb-922a-cca9caa1b9fa.png)
