#pragma once
class Descriptor
{
public:
	//объявлем поле для перечисления возможных комманд для работы метода descript.
	enum desc_Code { CORRECTLY_DONE, COMMANDS_ERROR, NO_INPUT_COMMANDS };
	void descript(desc_Code code);
};

