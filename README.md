# ericcr2- azarcon3 - ojama2 - shiva4
# Final Project 

This is the repository for the Taco Bell Lovers team (Eric Roth, Robert Azarcon, Omeed Jamali, Shiva Malhotra). If you want to run the project on your own [computers](https://github.com/frogmasta/Taco-Bell-Lovers#Installation). If you want to look at our [results]. If you want to read our [final report and/or final video]. 

## Installation

1.) Clone the respository into a folder of your choice. An example through command line is shown below (you're welcome to clone it another way as well). 

```bash
git clone https://github.com/frogmasta/Taco-Bell-Lovers.git
```

2.) Set-up the CS 225 Docker environment. Instructions can be found [here](https://courses.engr.illinois.edu/cs225/fa2022/resources/own-machine/). Place the Docker file in the root directory of the project.

3.) Run the following commands to generate your build environment:
```bash
mkdir build
```

```bash
mkdir build
```

```bash
cmake ..
```

4.) Your development environment is finished! Refer to the [How to Use] section for valid commands.

## How to Build & Run

If you haven't installed the requirements yet, refer to [Installation](https://github.com/frogmasta/Taco-Bell-Lovers#Installation). 

When building and running the program, you want to be in your projects ```\build``` directory you created above. Once you're there, you can build the project in two ways.

### Test-Suite
1.) To build the test-suite: 
```bash
make test
```

2.) To run the tests:
```bash
./test
```

### Entire Project
First you need to run the following command:
```bash
make test
```

In our final project, there are 4 key algorithms/methods that you can run on datasets. These algorithms include: Breadth-First-Search (BFS), Dijkstra's, Strongly Connected Components (SCC), and PageRank. 

Details on how to run all of them are outlined below. If [input.csv] is not provided, it defaults to our Bitcoin dataset.
```bash 
./main                                                              # Executes every algorithm in the suite
./main bfs [starting node] [input.csv]                              # Runs bfs
./main dijkstra [starting node] [ending node] [input.csv]           # Runs dijkstra's
./main scc [input.csv]                                              # Runs Strongly Connected Components
./main pagerank [input.csv]                                         # Runs PageRank
```

## Documentation

## Features

## Testing

## Project Structure
