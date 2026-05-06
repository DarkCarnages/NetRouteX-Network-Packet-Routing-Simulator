# NetRouteX: Network Packet Routing Simulator

# 🚀 Algorithms Implemented

## Routing Algorithms

### 1. Bellman-Ford Algorithm

* Distance Vector Routing
* Used in RIP-like protocols
* Supports edge relaxation
* Generates routing tables

### 2. Dijkstra Algorithm

* Link State Routing
* Used in OSPF-like protocols
* Computes shortest path using global topology

### 3. Floyd-Warshall Algorithm

* All-Pairs Shortest Path
* Computes shortest paths between every node pair
* Centralized routing analysis

### 4. A* Algorithm

* Heuristic-based smart routing
* Optimized shortest path computation
* Packet-based routing simulation

---

## Graph Traversal Algorithms

### 5. BFS (Breadth First Search)

* Network traversal
* Connectivity analysis
* Layer-wise exploration

### 6. DFS (Depth First Search)

* Recursive traversal
* Deep path exploration
* Network connectivity checking

---

# 📊 Performance Features

The simulator measures:

* Execution time
* Path cost
* Routing efficiency
* Algorithm comparison

Outputs include:

* performance.txt
* performance.csv

---

# 📁 Project Structure

```text
project/
│
├── main.c
├── main2.c
│
├── graph.c
├── graph.h
│
├── bellman_ford.c
├── bellman_ford.h
│
├── dijkstra.c
├── dijkstra.h
│
├── floyd_warshall.c
├── floyd_warshall.h
│
├── astar.c
├── astar.h
│
├── bfs_dfs.c
├── bfs_dfs.h
│
├── simulation.c
├── simulation.h
│
├── comparison.c
├── comparison.h
│
├── utils.c
├── utils.h
│
├── list.c
├── list.h
│
├── algo_list_impl.c
├── algo_list_impl.h
│
├── input_graph.txt
│
├── output/
│   ├── performance.txt
```

---

# ⚙️ Compilation

## Matrix-Based Simulator

```bash
gcc main.c graph.c bellman_ford.c dijkstra.c floyd_warshall.c astar.c bfs_dfs.c comparison.c simulation.c utils.c -o sim1.exe
```

Run:

```bash
.\sim1.exe
```

---

## Adjacency List Optimized Simulator

```bash
gcc main2.c list.c algo_list_impl.c utils.c -o sim2.exe
```

Run:

```bash
.\sim2.exe
```

---

# 📄 Input Graph Format

Example:

```text
8 14
0 1 4
0 2 3
1 2 1
1 3 2
2 3 4
2 4 6
3 4 1
3 5 7
4 5 2
4 6 5
5 6 3
5 7 8
6 7 2
1 7 12
```

Format:

```text
Vertices Edges
Source Destination Weight
```

---

# 📈 Time Complexity Analysis

| Algorithm      | Matrix Complexity | Adjacency List Complexity |
| -------------- | ----------------- | ------------------------- |
| Bellman-Ford   | O(V³)             | O(VE)                     |
| Dijkstra       | O(V²)             | O((V+E) log V)            |
| Floyd-Warshall | O(V³)             | O(V³)                     |
| A*             | O(V²)             | O((V+E) log V)            |
| BFS            | O(V²)             | O(V+E)                    |
| DFS            | O(V²)             | O(V+E)                    |

---

# 📦 Features

* Menu-driven simulation
* Packet routing visualization
* Routing table generation
* Distance Vector simulation
* Link State simulation
* Adjacency Matrix implementation
* Adjacency List optimization
* Execution time comparison

---

# 📌 Conclusion

NetRouteX successfully simulates multiple routing strategies and shortest-path algorithms while comparing their behavior, efficiency, and routing logic.

The project provides both conceptual understanding and practical implementation of routing mechanisms used in computer networks.
