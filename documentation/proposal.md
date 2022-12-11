## Leading Question 

The dataset we plan on utilizing is the Bitcoin OTC trust network. By utilizing the algorithms we aim to implement, we hope to gather information about the user base of Bitcoin OTC. We specifically are trying to gain insight into the behavior of the users of Bitcoin OTC and trustworthiness among the users in the network. With finding centrality among the users in the network, we could tell which users are the most active, important, and trusted to the community. We also will use the Dijkstra algorithm to find the most trusted link between two users. This will give insight into the mutual relationship between two members of the network based on maximal trust. Lastly, we aim to find strongly connected components within the graph to discover the existence of tight-knit trading sub-communities.

## Data Format

Our input dataset is the Bitcoin OTC Trust Network (http://snap.stanford.edu/data/soc-sign-bitcoin-otc.html). The data is stored in a csv file where each row has the following information: SOURCE, TARGET, RATING, TIME. The dataset has 5, 881 nodes and 35,592 edges. Since the dataset is relatively small, we plan to use the entire provided dataset. 

## Data Correction

We plan to parse the input data line-by-line in the CSV file and add its corresponding components to the adjacency list. The main source of “impossibility” is if the weight of the edge isn’t between the numbers [-10, 10]. If a source of input data doesn’t comply with this requirement, then we’ll throw it out of computation. Also if the data doesn’t have a source and a target, we will throw it out. We aren’t concerned about the time as well.

As a side-note, if there are multiple ratings from person A to person B, we plan to take the average of those ratings. For example, if A rates B as a 5 one time, and A rates B as a 10 another time, the average rating is a 7.5.


## Data Storage

We are going to use an adjacency list to store the data. Specifically, we’re going to use an adjacency list where each node is associated with a list of AdjacentNode objects. An AdjacentNode object contains the node and the weight of the edge connecting them. The total storage cost of our dataset should be O(|E|), because each edge corresponds to one AdjecentNode object. 

For the PageRank algorithm, we also plan to parse the data as an adjacency matrix this would have O(|V|^2) space because the matrix is a |V| x |V| matrix.


## Algorithm 

For this final project, we will be using a PageRank algorithm to determine the most important user based on the data. The PageRank algorithm analyzes the incoming edges at each node to determine its importance. This score is calculated based on each edge, which has a weight with the percentage of the total ratings being given by the node. This will help us find the most important user based on both their score (from -10 to 10) and their number of incoming ratings. Each node represents a user on the platform. The directed edges of the graph represent the ratings being given by one user for another user. The respective weights of these edges are the percentages of the total ratings being given by the node. To account for the negative ratings that are being given, each rating will be raised by 10 points. We will store our output for the PageRank algorithm by using an adjacency matrix. Each row and column index represents a node in the graph. The rows represent outgoing edges in the graph, while the columns represent the incoming edges. Each entry in the matrix represents a relationship between two nodes. A value stored at the ith row and the jth column is a rating from node i for node j. The value stored at that index represents the rating being given.

Alongside using the PageRank algorithm, we will utilize the Strongly Connected Component (SCC) Algorithm. The Strongly Connected Component algorithm will allow us to explore the trading sub-communities. The SCC algorithm defines “strongly connected” to be when every vertex is reachable from every other vertex. With these connections we can translate groups of communities that recurrently trust each other to be “strongly connected.” We can do this by finding the “strongly connected components” which are defined to be the partition formed into subgraphs that showcase “strongly connected” networks. 
 
For Dijkstra's algorithm the inputs will be two randomly selected nodes within the graph. We aim to maximize trust rating when using Dijkstra’s algorithm for our optimization heuristic.
 
Function Outputs What is the expected output for your algorithm? How will you store, print, or otherwise visualize the outcome?
 
We will store our output for the PageRank algorithm by using a vector. Each index of the vector represents the node that has been scored. The value at each index represents the importance score given to the respective node.
 
For Dijkstra’s algorithm we plan to create a singly linked list to represent the specific path of the nodes that represent the maximal path based on trust. 
	
For the Strongly Connected Component (SCC) we will represent the data using adjacency lists. An adjacent list is described to be a collection of unordered lists. These lists are then represented by a graphical interface. 
 
 
Function Efficiency Your algorithm likely has a theoretically optimal Big O that you can find online. But most algorithms also have multiple implementations and there is no guarantee that your implementation of this algorithm is optimal. As part of this proposal you must include an estimate or target goal on the Big O efficiency of your algorithm in both time and memory.
 
 
For the PageRank algorithm, there are multiple possible implementations, but our target/goal for the time complexity is O(n + m). In this estimate, n represents the number of nodes to be visited, while m represents each of the directed edges in the graph.
 
 
When looking at time complexity for the Strongly Connected Component (SCC) Algorithm it can be seen that the DFS is a huge part of the algorithm. When looking at DFS the Big O runtime is O(V+E). However this current algorithm can be tweaked to follow Tarjan’s or path-based algorithms. The Big O runtime would still remain the same at O(V+E) since the DFS algorithm would still be used. The only difference would be by using a single DFS search to find the SCCs. 
 
 
 
 
For Dijkstra's algorithm, assuming the graph we are using is connected, we can have a maximum running time bound of O((|E| + |V|) * log(V)) where E is the number of edges and V is the number of vertices. Most likely the graph will not be connected which would mean true runtime will be less but not significantly.


## Timeline

Data acquisition

Download the csv file and upload to GitHub

Data processing

Write code to do the following

Parse through data file

For Djikstra’s algorithm, if there exists multiple outgoing edges to the same node, find the average outgoing rating and combine to a single edge

Convert data into an adjacency list and store into our own CSV/txt file

Convert data into an adjacency matrix as well

Write code to load the adjacency list from our own generated CSV/txt file

Djikstra’s algorithm

PageRank algorithm

Strongly connected components
