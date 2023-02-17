#include "Descriptor.h"
#include <iostream>
//��������������� ����� ��� ������ � ������� �������� ��������� ������� ��� ���������� ������.
void Descriptor::descript(desc_Code code)
{
	switch (code)
	{
	case CORRECTLY_DONE:
		std::cout << "process correctly done\n";
		break;
	case COMMANDS_ERROR:
		std::cout << "incorrect command input\n";
		break;
	case NO_INPUT_COMMANDS:
		std::cout << "process can not find commands";
	}
}
