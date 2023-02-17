#include "FileReader.h"
#include <iostream>
#include <list>
#include <sstream>

void FileReader::getCommands(std::string command, std::vector<std::vector<int>>& commands)
{
    std::vector<int> intCommand;
    int intCommandPart;
    //ќбъ€влем объект класса istringstream из библиотеки sstream дл€ получени€ чисел из строки (чтение из файла производитс€ в виде строки, необходимо преобразование).
    std::istringstream readIntfromString(command);
    //пока не прочитаетс€ строка, добавл€ем числа в вектор "команда".
    while (readIntfromString)
    {
        readIntfromString >> intCommandPart;
        if (readIntfromString)
        {
            intCommand.push_back(intCommandPart);
        }
        
    }
    //добавл€ем команду в вектор команд.
    commands.push_back(intCommand);
}

FileReader::FileReader()
{
    //при объ€влении объекта класса, определ€ем директорию файлов непосредственно в рабочей области нашей программы.
    std::string file_path = __FILE__;
    dir_path = file_path.substr(0, file_path.rfind("\\"));
    //автоматически создаем (или пересоздаем) файл output.txt
    std::string path = dir_path + OUTPUT;
    std::ofstream ofs(path);
}
//ћетод считывани€ команд из input.txt
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
    //читаем команды из файла построчно, с помощью определенного выше метода добавл€ем команды в вектор команд.
    while (std::getline(file, command))
    {
        getCommands(command, commands);
    }
    file.close();
    return commands;
}
//метод, позвол€ющий записать в строку в файле все смежные вершины дл€ одной из вершин.
void FileReader::writeOutput(std::list<int> vertexes)
{
    std::string path = dir_path + OUTPUT;
    std::fstream file;

    file.open(path, std::ios_base::app);
    //в цикле for итеррируемс€ через указатель с начала списка смежных вершин до конца, и записываем в файл значение предварительно разыменованного указател€.
    for (std::list<int>::iterator i = vertexes.begin(); i != vertexes.end(); ++i)
    {
        file << *i << ' ';
    }
    file << '\n';
    file.close();
    return;
}
