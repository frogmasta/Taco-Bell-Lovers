# ericcr2- azarcon3 - ojama2 - shiva4
# Final Project 

This is the repository for the Taco Bell Lovers team (Eric Roth, Robert Azarcon, Omeed Jamali, Shiva Malhotra). If you want to run the project on your own [computers](https://github.com/frogmasta/Taco-Bell-Lovers#Installation).

## Installation

1.) Clone the respository into a folder of your choice. An example through command line is shown below (you're welcome to clone it another way too). 

```bash
git clone https://github.com/frogmasta/Taco-Bell-Lovers.git
```

2.) Set-up the CS 225 Docker environment. Instructions can be found [here](https://courses.engr.illinois.edu/cs225/fa2022/resources/own-machine/). Place the Docker file in the root directory of the project.

3.) Run the following commands to generate your build environment:
```bash
mkdir build
```

```bash
cd build
```

```bash
cmake ..
```

4.) Your development environment is finished! Refer to the [Full-Output](https://github.com/frogmasta/Taco-Bell-Lovers/edit/master/README.md#full-output)  section for valid commands.

## How to Build & Run

If you haven't installed the requirements yet, refer to [Installation](https://github.com/frogmasta/Taco-Bell-Lovers#Installation). 

When building and running the program, you want to be in your projects ```\build``` directory you created above. Once you're there, you can build the project in two ways.

### Test-Suite

You can look at the test suite code in the ```\tests``` folder. If you want to add a test of your own, put the .cpp test file in this folder. Check to make sure that the test file follows the same format as ours. 

1.) To build the test-suite: 
```bash
make test
```

2.) To run the tests:
```bash
./test
```

### Full-Output
First run the following (again in your ```\build``` directory):
```bash
make test
```

In our final project, there are 4 key algorithms/methods that you can run on datasets. These algorithms include: Breadth-First-Search (BFS), Dijkstra's, Strongly Connected Components (SCC), and PageRank. If you want to run your own dataset, put it in a .csv file format and put it in the data folder.

Details on how to run all of them are outlined below. If an input csv is not provided, it defaults to our Bitcoin dataset. Make sure you are still in your ```\build``` folder.

```bash 
./main                                                              # Executes every algorithm in the suite
./main bfs [starting node] [input.csv]                              # Runs BFS
./main dijkstra [starting node] [ending node] [input.csv]           # Runs Dijkstra's
./main scc [cutoffWeight] [input.csv]                               # Runs Strongly Connected Components
./main pagerank [input.csv]                                         # Runs PageRank
```

## Documentation & Results

All of our documentation and results can be found in the ```\documentation``` folder. This includes our final video, final written report, dev logs, and team contract. 

## Project Structure

* ### ```\```
  * Project configuration files (e.x. README.md, CMakeLists.txt, etc.)
* ### ```\data```
  * Contains all the input files. For example our bitcoin dataset and test case datasets. Also has some PNGs that demonstrate SCC working properly.
* ### ```\documentation```
  * Development Logs, Team Contract, Project Proposal, Final Report, and Final Presentation Link
* ### ```\entry```
  * Driver file for the entire project. Runs the algorithms specified by the user in ```main.cpp```.
* ### ```\src```
  * #### Parser Class
    * Converts .csv input into Edges that can then be turned into a Graph
  * #### Graph Class
    * Utilizes the adjacency list representation for a graph
    * Graph interactivity such as adding edges, checking if a vertex exists, etc.
    * Contains the algorithm code for BFS, Strongly Connected Components, and PageRank (each implementation is in a seperate file)
  * #### Dijkstra Class
    * Implements Dijkstra's algorithm
* ### ```\tests```
  * Contains all of our testing code in their respective ```.cpp``` files
