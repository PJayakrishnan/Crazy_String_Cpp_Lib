//--------------------------------------------------------->
// crazy_string_lib.h file.
// Author		: Jayakrishnan P
// Last modified: 24/06/2022
//--------------------------------------------------------->

#pragma once
#include <vector>
#include <string>

namespace CrazyStringLib
{
	std::vector<int> WhichAreDiffPositions(std::string, std::string);

	int WhichIsBig(int, int);

	std::vector<int> WhereAllMyChar(std::string, char);
}
