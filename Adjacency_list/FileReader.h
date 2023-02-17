#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <list>

class FileReader
{
	std::string dir_path;
	const std::string INPUT = "/input.txt";
	const std::string OUTPUT = "/output.txt";

	void getCommands(std::string command, std::vector<std::vector<int>>& commands);

public:
	FileReader();
	std::vector<std::vector<int>> readInput();
	void writeOutput(std::list<int> vertexes);
};

