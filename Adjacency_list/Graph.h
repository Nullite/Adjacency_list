#pragma once
#include <list>;
#include <vector>;
#include "FileReader.h"
#include "Descriptor.h"

class Graph
{
    int numVertices;
    std::vector <std::list<int>> adjLists;
    std::vector<std::vector<int>> commands;

    FileReader fr = FileReader();
    Descriptor desc = Descriptor();

    void addEdge(int u, int v);
    void vertex(int u);

public:
    Graph();   
    void process();
};

