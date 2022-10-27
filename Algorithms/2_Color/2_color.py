"""
Driver to test DFS algorithm to solve 2 color graph problem
Can a graph be colored with only 2 colors such that no to connected nodes have the same color
if so the graph cna be represented bipartide
"""

from random import randint


class node:
    """ Node class for Graph """
    def __init__(self, id):
        self.id = id
        self.color = ""
        self.edges = []
        self.visited = False
    
    def addNode(self, edge):
        self.edges.append(edge)
    
    def addColor(self, color):
        self.color = color
    
    def getColor(self): return self.color

    def getEdges(self): return self.edges

    def visit(self): self.visited = True



class graph:
    """Graph class for algo testing """
    def __init__(self, node_count):
        self.node_count = node_count
        self.nodes = []
        self.path = []
        for i in range(node_count):
            self.nodes.append(node(i))
    
    def addEdge(self, l_node, r_node):
        self.nodes[l_node].addNode(self.nodes[r_node])
        self.nodes[r_node].addNode(self.nodes[l_node])
    
    def twoColor(self, node, colorCode):
        self.path.append(node)
        cur = self.nodes[node]
        cur.visit()
        val = True
        
        if colorCode == 0:
            cur.addColor("red")
        else:
            cur.addColor("green")
        for n in cur.getEdges():
            if cur.getColor() == n.getColor():
                return False
            if not n.visited:
                val = self.twoColor(n.id, (colorCode + 1)%2)
        
        return val


if __name__ == "__main__":
    g1 = graph(4)
    g2 = graph(5)
    g3 = graph(8)
    
    g1.addEdge(0,1)
    g1.addEdge(1,2)
    g1.addEdge(2,3)
    g1.addEdge(3,0)
    
    g2.addEdge(0,1)
    g2.addEdge(1,2)
    g2.addEdge(2,3)
    g2.addEdge(3,4)
    g2.addEdge(4,0)

    g3.addEdge(0,1)
    g3.addEdge(0,2)
    g3.addEdge(1,3)
    g3.addEdge(3,6)
    g3.addEdge(6,7)
    g3.addEdge(7,4)
    g3.addEdge(0,5)
   
    

    

    print("Graph one, two colorable? {0}".format(g1.twoColor(3,0)))
    print("With path: \n" + str(g1.path))
    for nod in g1.nodes:
        print("{0} -> {1}".format(nod.id, nod.color))
    

    print("Graph two, two colorable? {0}".format(g2.twoColor(2,0)))
    print("With path: \n" + str(g2.path))
    for nod in g2.nodes:
        print("{0} -> {1}".format(nod.id, nod.color))

    print("Graph three, two colorable? {0}".format(g3.twoColor(0,0)))
    print("With path: \n" + str(g3.path))
    for nod in g3.nodes:
        print("{0} -> {1}".format(nod.id, nod.color))
        