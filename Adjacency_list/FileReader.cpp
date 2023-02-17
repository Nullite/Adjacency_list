#include "FileReader.h"
#include <iostream>
#include <list>
#include <sstream>

void FileReader::getCommands(std::string command, std::vector<std::vector<int>>& commands)
{
    std::vector<int> intCommand;
    int intCommandPart;
    //Объявлем объект класса istringstream из библиотеки sstream для получения чисел из строки (чтение из файла производится в виде строки, необходимо преобразование).
    std::istringstream readIntfromString(command);
    //пока не прочитается строка, добавляем числа в вектор "команда".
    while (readIntfromString)
    {
        readIntfromString >> intCommandPart;
        if (readIntfromString)
        {
            intCommand.push_back(intCommandPart);
        }
        
    }
    //добавляем команду в вектор команд.
    commands.push_back(intCommand);
}

FileReader::FileReader()
{
    //при объявлении объекта класса, определяем директорию файлов непосредственно в рабочей области нашей программы.
    std::string file_path = __FILE__;
    dir_path = file_path.substr(0, file_path.rfind("\\"));
    //автоматически создаем (или пересоздаем) файл output.txt
    std::string path = dir_path + OUTPUT;
    std::ofstream ofs(path);
}
//Метод считывания команд из input.txt
std::vector<std::vector<int>> FileReader::readInput()
{
    std::vector <std::vector<int>> commands;
    std::string command;
    

    std::string path = dir_path + INPUT;
    std::fstream file;
    //открываем файл input.txt, если файла нет в директории, он будет автоматически создан пустым.
    file.open(path);
    if (!file) {
        std::ofstream ofs(path);
        ofs.close();
    }
   //читаем команды из файла построчно, с помощью определенного выше метода добавляем команды в вектор команд.
    while (std::getline(file, command))
    {
        getCommands(command, commands);
    }
    file.close();
    return commands;
}
//метод, позволяющий записать в строку в файле все смежные вершины для одной из вершин.
void FileReader::writeOutput(std::list<int> vertexes)
{
    std::string path = dir_path + OUTPUT;
    std::fstream file;

    file.open(path, std::ios_base::app);
    //в цикле for итеррируемся через указатель с начала списка смежных вершин до конца, и записываем в файл значение предварительно разыменованного указателя.
    for (std::list<int>::iterator i = vertexes.begin(); i != vertexes.end(); ++i)
    {
        file << *i << ' ';
    }
    file << '\n';
    file.close();
    return;
}
