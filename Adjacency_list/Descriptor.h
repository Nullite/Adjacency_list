#pragma once
class Descriptor
{
public:
	//�������� ���� ��� ������������ ��������� ������� ��� ������ ������ descript.
	enum desc_Code { CORRECTLY_DONE, COMMANDS_ERROR, NO_INPUT_COMMANDS };
	void descript(desc_Code code);
};

