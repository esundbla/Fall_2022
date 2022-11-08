"""
Shortest string alorithm implementation
Algorithms Fall 2022
Erik Sundblad
"""
STRINGMAX = 100
STRINGS1 = ["hello","hi","chao","hola","greetings","bonjour","salam"]
STRINGS2 = ["catg", "ctaagt", "gcta", "ttca", "atgcatc"]

class Node:
    """Node class for graph"""
    def __init__(self, str, id):
        self.id = id
        self.str = str
        self.connections = []  
        self.visited = False
    
    def addEdge(self, node):
        substring = ""
        weight = 0
        for char in node.str:
            substring += char
            if not substring in self.str:
                weight = weight+1
        self.connections.append((node.id, weight))
        
    
    def __str__(self):
        out = ""
        for i in self.connections:
            out = out + " ({0}, w={1}) ".format(i[0], i[1])
        return out




class Graph:
    """Graph class for solution"""
    def __init__(self, strings):
        self.nodes = []
        self.supString= ""
        counter = 0
        for str in strings:
            self.nodes.append(Node(str, counter))
            counter +=1
    
    def fullyConnect(self):
        """Fully connect the graph"""
        for n in self.nodes:
            for m in self.nodes:
                if not n.id == m.id:
                    n.addEdge(m) 
    
    def superString(self, index):
        node = self.nodes[index]
        node.visited = True
        acumulator =""
        for char in node.str:
            acumulator += char
            if not acumulator in self.supString:
                self.supString += char
        sor =  sorted(node.connections, key=lambda x: x[1])
        #print(sor)
        for edge in sor:
            if not self.nodes[edge[0]].visited:
               self.superString(edge[0])
               break
    
    
    def bestString(self):
        strings = []
        self.unVisit()
        for node in self.nodes:
            self.supString = ""
            self.superString(node.id)
            strings.append(self.supString)
            self.unVisit()
        
        for val in strings:
            print("{0}: {1}".format(len(val), val))
        sort = sorted(strings, key=lambda x: len(x))
        return sort[0]

    def unVisit(self):
        for node in self.nodes:
            node.visited = False


    def printGraph(self):
        for node in self.nodes:
            print("{0}: {1} ".format(node.id, str(node)))
            


if __name__ == "__main__":
   g1 =  Graph(STRINGS1)
   g1.fullyConnect()
   g1.printGraph()
   print()
   print(g1.bestString(), len(g1.bestString()))

   g2 =  Graph(STRINGS2)
   g2.fullyConnect()
   g2.printGraph()
   print()
   print(g2.bestString(), len(g2.bestString()))
