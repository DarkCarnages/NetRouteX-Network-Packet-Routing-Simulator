import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

# read graph file
with open("input_graph.txt") as f:
    V, E = map(int, f.readline().split())

    for _ in range(E):
        u, v, w = map(int, f.readline().split())
        G.add_edge(u, v, weight=w)

pos = nx.spring_layout(G)

nx.draw(G, pos, with_labels=True, node_color='lightblue')
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.title("Network Graph Visualization")
plt.show()