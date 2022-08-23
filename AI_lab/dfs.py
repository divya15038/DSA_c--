#dfs: Depth first traversal of graph using stack
#Time Complexity: O(v)
#Space Complexity: O(logV)
Graph = {
    '5' : ['3','7'],
    '3' : ['2', '4'],
    '7' : ['8'],
    '2' : [],
    '4' : ['8'],
    '8' : []    
}

#take user input
Graph = {}
vNum = int(input("Enter the number of vertices:"))
for i in range(vNum):
    nbr = []
    V = input("Enter the value of vertex:")
    nbrNum = int(input("Enter the number of neighbouring nodes for node " + str(i)))
    for j in range(nbrNum):
        nbr.append(input("Enter neighbouring node for node " + str(i) + ":"))
    Graph += {V : nbr}

visited = [] #for keeping note of nodes already visited, to prevent printing of duplicates

#dfs is implemented using call stack through recursion
def dfs(source, Graph):
    #check if source is already visited
    if source not in visited:
        print(source, end = " ")
        visited.append(source)

    for nbr in Graph[source]:
        dfs(nbr)
    return


def dfsStack(source):
    #append the source into stack
    stack = []
    stack.append(source)
    path = []

    #while stack is not empty
    while(stack):
        v = stack.pop()
        if v in path:
            continue
        path.append(v)
        for nbr in Graph[v]:
            stack.append(nbr)
    
    #print path
    for node in path:
        print(node, end = " ")

dfsStack('5')
print()
dfs('5')

 


