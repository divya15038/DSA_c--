#bfs: Traverse a graph in breadth first manner.
#Time complexity: O(V+E)
#Space complexity: O(V)

Graph = {
    '5' : ['3','7'],
    '3' : ['2', '4'],
    '7' : ['8'],
    '2' : [],
    '4' : ['8'],
    '8' : []
}

#function to implement bfs
def bfs(source):
    #to avoid duplication of nodes while traversal
    visited = []

    #to store the order for printing in bfs, fifo
    queue = []

    #add source to visited and queue
    queue.append(source)
    visited.append(source)

    #while queue is not empty, pop the first element, print the element and repeat same procedure for unvisited neighbours
    while(queue):
        v = queue.pop(0)
        print(v, end = " ")
        
        #check for the neighbours of popped vertex
        for nbr in Graph[v]:
            if nbr not in visited:
                visited.append(nbr)
                queue.append(nbr)
                
bfs('5')
#numVertices = input("Enter the number of vertices in graph:")



