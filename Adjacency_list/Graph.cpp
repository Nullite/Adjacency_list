#include "Graph.h"
#include <iostream>

Graph::Graph()
{
	//�������� ������ ������� �� ����� Input.txt
	commands = fr.readInput();
	//���������, ��� �������� ��������� � ������ (������ ��� �������� - ����������� (���������� ������ � ���������� �������)).
	//���� ������� ���� � ������� �������, ���������� ���������� ������ �����.
	//���� ������ ���, �� ������ ���������� ������ ����� � 0, ��� ��� ���������� ��������� ��� �� ����������� �� �������.
	commands.size() ? numVertices = commands[0][0] : 0;
	//��������� ������ ������� ������ ������ ������ (�����), ����� ����� ����������� �� ���� ��������� ������� ����� �� ����.
	for (int i = 0; i <= numVertices; ++i)
	{
		adjLists.push_back(std::list<int>());
	}
}
//����� ��������� ��������� ����� (�����) ����� ����� ��������� (� ������ ������ ��� ������� u ��������� ������� v � ��������).
void Graph::addEdge(int u, int v)
{
	adjLists[u].push_back(v);
	adjLists[v].push_back(u);
}
//����� ���������� ����� ��� ��������� ������� u � ����, ��������� ����� FileReader, ������������ ���� �������.
void Graph::vertex(int u)
{
	fr.writeOutput(adjLists[u]);
}
//������� ����� ��������� ������ �� ������� commands, ���������������, ������� �� 3 ������� (������ ��� ����������� ������� ����������). 
void Graph::process()
{
	//���� ������ ���, �������� �������� �� ������ Descriptor, ������������� ���� �������, � ���, ��� � ������ ��� ������ � ��������� ������.
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
		//���� � ������ ������ �������� ������������ �������, �������� ��������������� �������� � ��������� ������.
		default:
			desc.descript(desc.COMMANDS_ERROR);
			return;
		}
	}
	//���� ��� ������� ������� ����������, �������� ��������, ������� ��������� ���������.
	desc.descript(desc.CORRECTLY_DONE);
}
