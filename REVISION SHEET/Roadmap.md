========================================================

INTERVIEW DSA PATTERN ROADMAP (INTUITION-FIRST)
========================================================

### PHASE 1 → ARRAY / TWO POINTER FOUNDATIONS
Goal:
Learn invariants + movement decisions

1. Two Pointers
   - Reader / Writer
   - Opposite Direction
   - Sliding Window
   - Slow / Fast Cycle Detection

Why first?
Almost every medium problem starts here.


--------------------------------------------------------

### PHASE 2 → HASHMAP + PREFIX THINKING
Goal:
Convert brute force lookup into O(1)

2. Frequency Map Pattern
   Problems:
   - Two Sum
   - Group Anagrams
   - Valid Anagram
   - Top K Frequent

Mental Shift:
"Can I trade memory for speed?"

--------------------------------------------------------

3. Prefix Sum Pattern
   Problems:
   - Subarray Sum Equals K
   - Continuous Subarray Sum
   - Product Except Self
   - Range Sum Query

Mental Shift:
"Can previous computation help current?"

--------------------------------------------------------

4. Prefix XOR Pattern
   Problems:
   - Single Number
   - XOR Queries
   - Subarray XOR K

Mental Shift:
Difference but for XOR world

--------------------------------------------------------

### PHASE 3 → INTERVAL / ORDER THINKING
Goal:
Reason about ranges

5. Sorting + Greedy
   Problems:
   - Merge Intervals
   - Insert Interval
   - Non-overlapping Intervals
   - Meeting Rooms

Mental Shift:
"Sort first, simplify later"

--------------------------------------------------------

6. Monotonic Stack
   Problems:
   - Next Greater Element
   - Daily Temperatures
   - Largest Rectangle Histogram
   - Trapping Rain Water

Mental Shift:
"Who invalidates whom?"

--------------------------------------------------------

7. Heap / Priority Queue
   Problems:
   - Kth Largest
   - Top K Frequent
   - Merge K Sorted Lists
   - Meeting Rooms II

Mental Shift:
"Need best candidate quickly"

--------------------------------------------------------

### PHASE 4 → GRAPH-LIKE THINKING
Goal:
Traversal intuition

8. BFS / DFS
   Problems:
   - Number of Islands
   - Clone Graph
   - Rotten Oranges
   - Course Schedule

Mental Shift:
"Traverse connected state space"

--------------------------------------------------------

9. Graph Patterns
   - Union Find (DSU)
   - Topological Sort
   - Shortest Path

Mental Shift:
Relationship modeling

--------------------------------------------------------

### PHASE 5 → TREE INTUITION
Goal:
Recursive state passing

10. Binary Tree DFS
   Problems:
    - Diameter
    - Max Path Sum
    - LCA
    - Validate BST

Mental Shift:
"What information should child return?"

--------------------------------------------------------

11. BST Pattern
   Problems:
    - Kth Smallest
    - Validate BST
    - Closest Value

Mental Shift:
Exploit ordering

--------------------------------------------------------

### PHASE 6 → BACKTRACKING
Goal:
Decision tree thinking

12. Backtracking
   Problems:
    - Subsets
    - Permutations
    - Combination Sum
    - N Queens

Mental Shift:
Choose → Explore → Undo

--------------------------------------------------------

### PHASE 7 → DYNAMIC PROGRAMMING
Goal:
State transition intuition

13. 1D DP
14. 2D DP
15. Knapsack DP
16. LIS Pattern
17. Interval DP

Mental Shift:
"Repeated work exists"

========================================================