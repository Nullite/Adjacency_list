#include "FileReader.h"
#include <iostream>
#include <list>
#include <sstream>

void FileReader::getCommands(std::string command, std::vector<std::vector<int>>& commands)
{
    std::vector<int> intCommand;
    int intCommandPart;
    //�������� ������ ������ istringstream �� ���������� sstream ��� ��������� ����� �� ������ (������ �� ����� ������������ � ���� ������, ���������� ��������������).
    std::istringstream readIntfromString(command);
    //���� �� ����������� ������, ��������� ����� � ������ "�������".
    while (readIntfromString)
    {
        readIntfromString >> intCommandPart;
        if (readIntfromString)
        {
            intCommand.push_back(intCommandPart);
        }
        
    }
    //��������� ������� � ������ ������.
    commands.push_back(intCommand);
}

FileReader::FileReader()
{
    //��� ���������� ������� ������, ���������� ���������� ������ ��������������� � ������� ������� ����� ���������.
    std::string file_path = __FILE__;
    dir_path = file_path.substr(0, file_path.rfind("\\"));
    //������������� ������� (��� �����������) ���� output.txt
    std::string path = dir_path + OUTPUT;
    std::ofstream ofs(path);
}
//����� ���������� ������ �� input.txt
std::vector<std::vector<int>> FileReader::readInput()
{
    std::vector <std::vector<int>> commands;
    std::string command;
    

    std::string path = dir_path + INPUT;
    std::fstream file;
    //��������� ���� input.txt, ���� ����� ��� � ����������, �� ����� ������������� ������ ������.
    file.open(path);
    if (!file) {
        std::ofstream ofs(path);
        ofs.close();
    }
    //������ ������� �� ����� ���������, � ������� ������������� ���� ������ ��������� ������� � ������ ������.
    while (std::getline(file, command))
    {
        getCommands(command, commands);
    }
    file.close();
    return commands;
}
//�����, ����������� �������� � ������ � ����� ��� ������� ������� ��� ����� �� ������.
void FileReader::writeOutput(std::list<int> vertexes)
{
    std::string path = dir_path + OUTPUT;
    std::fstream file;

    file.open(path, std::ios_base::app);
    //� ����� for ������������ ����� ��������� � ������ ������ ������� ������ �� �����, � ���������� � ���� �������� �������������� ��������������� ���������.
    for (std::list<int>::iterator i = vertexes.begin(); i != vertexes.end(); ++i)
    {
        file << *i << ' ';
    }
    file << '\n';
    file.close();
    return;
}
