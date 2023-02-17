#include "Graph.h"
#include <iostream>

Graph::Graph()
{
	//получаем список комманд из файла Input.txt
	commands = fr.readInput();
	//проверяем, что комманды загружены в память (первые две комманды - технические (количество вершин и количество комманд)).
	//если команды есть в векторе комманд, определяем количество вершин графа.
	//если команд нет, то ставим количество вершин графа в 0, так как дальнейшая обработка нам не понадобится по условию.
	commands.size() ? numVertices = commands[0][0] : 0;
	//заполняем каждую вершину пустым листом связей (ребер), связи будут заполняться по мере обработки комманд далее по коду.
	for (int i = 0; i <= numVertices; ++i)
	{
		adjLists.push_back(std::list<int>());
	}
}
//метод позволяет настроить связи (ребра) между двумя вершинами (в список связей для вершины u добавляем вершину v и наоборот).
void Graph::addEdge(int u, int v)
{
	adjLists[u].push_back(v);
	adjLists[v].push_back(u);
}
//метод записывает ребра для выбранной вершины u в файл, используя класс FileReader, определенный нами заранее.
void Graph::vertex(int u)
{
	fr.writeOutput(adjLists[u]);
}
//главный метод обработки команд из вектора commands, последовательно, начиная со 3 команды (первые две технические команды пропускаем). 
void Graph::process()
{
	//если команд нет, вызываем описание из класса Descriptor, определенного нами заранее, о том, что в списке нет команд и завершаем работу.
	if (!commands.size())
	{
		desc.descript(desc.NO_INPUT_COMMANDS);
		return;
	}

	for (int i{2}; i < commands.size(); ++i)
	{
		switch (commands[i][0])
		{
		case 1:
			addEdge(commands[i][1], commands[i][2]);
			break;
		case 2:
			vertex(commands[i][1]);
			break;
		//если в списке команд попалась некорректная команда, вызываем соответствующее описание и завершаем работу.
		default:
			desc.descript(desc.COMMANDS_ERROR);
			return;
		}
	}
	//если все команды успешно обработаны, вызываем описание, процесс отработал корректно.
	desc.descript(desc.CORRECTLY_DONE);
}
