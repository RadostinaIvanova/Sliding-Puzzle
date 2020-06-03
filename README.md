# Sliding-Puzzle
Solving the Sliding puzzle with 8 pieces using A* algorithm
## Eight puzzle problem
The puzzle consists of 8 tiles and one empty space where the tiles can be moved. Start and Goal configurations of the puzzle are provided. The puzzle can be solved by moving the tiles one by one in the single empty space and thus achieving the Goal configuration
## A* Algorithm 
A* uses a combination of heuristic value (h-score: how far the goal node is) as well as the g-score (i.e. the number of nodes traversed from the start node to current node).
### Heuristic function
In this case the h-score is the summation of the Manhattan distance between misplaced nodes.
