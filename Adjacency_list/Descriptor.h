#pragma once
class Descriptor
{
public:
	//объ€влем поле дл€ перечислени€ возможных комманд дл€ работы метода descript.
	enum desc_Code { CORRECTLY_DONE, COMMANDS_ERROR, NO_INPUT_COMMANDS };
	void descript(desc_Code code);
};

