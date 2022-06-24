//--------------------------------------------------------->
// crazy_string_lib.cpp file.
// Author		: Jayakrishnan P
// Last modified: 24/06/2022
//--------------------------------------------------------->

#include "crazy_string_lib.h"

namespace CrazyStringLib
{
	bool oneBig = false;
	bool twoBig = false;
	bool isSameLenght = false;

	//-------------------------------------------------------------------------------->
	// Function   : WhichAreDiffPositions
	// Return Type: std::vector<int> -- Vector of postions of difference.
	// Parameters : (2) -- std::string -- Two strings we need to compare.
	// Remarks    : Giving two strings as parameters, this function will return a list
	//				which contains positions of string where characters are not the same.
	//-------------------------------------------------------------------------------->
	std::vector<int> WhichAreDiffPositions(std::string texti, std::string textii)
	{
		std::vector<int> diff;

		std::vector<char> text1, text2;


		//Loading two std::string into vectors.
		for (int i = 0; i < texti.length(); i++) {
			text1.push_back(texti[i]);
		}

		for (int i = 0; i < textii.length(); i++) {
			text2.push_back(textii[i]);
		}

		//Finding which is bigger text.
		int large = WhichIsBig(text1.size(), text2.size());


		//Filling rest of smaller vector with '\0' upto size of larger vector.
		//This is to make size of both vectors same.
		if (oneBig == true)
		{
			for (int i = text2.size(); i < text1.size(); i++)
			{
				text2.push_back('\0');
			}
		}
		if (twoBig == true)
		{
			for (int i = text1.size(); i < text2.size(); i++)
			{
				text1.push_back('\0');
			}
		}


		//Getting positions of difference between two strings into a std::list.
		for (int i = 0; i < large; i++)
		{
			if (text1[i] != text2[i])
			{
				diff.push_back(i);
			}
		}

		return diff;
	}

	//-------------------------------------------------------------------------------->
	// Function   : WhichIsBig
	// Return Type: int -- Lenght of larger string.
	// Parameters : (2) -- int -- lenght of two strings.
	// Remarks    : This function find which of the two string is big or whether they
	//				are of same lenght and lenght of the larger string.
	//-------------------------------------------------------------------------------->
	int WhichIsBig(int text1Size, int text2Size)
	{
		if (text1Size > text2Size)
		{
			oneBig = true;
			twoBig = false;
			isSameLenght = false;
			return text1Size;
		}
		if (text1Size < text2Size)
		{
			twoBig = true;
			oneBig = false;
			isSameLenght = false;
			return text2Size;
		}
		if (text1Size == text2Size)
		{
			isSameLenght = true;
			oneBig = false;
			twoBig = false;
			return text2Size;
		}
	}

	//-------------------------------------------------------------------------------->
	// Function   : WhereAllMyChar
	// Return Type: std::vector<int> -- Vector of positions where given character is 
	//				seen in given string.
	// Parameters : (2) -- std::string -- String where we need to search for given character.
	//				   -- char -- charecter whose position in string we need to find out.
	// Remarks    : This function returns a vector of positions(indeces) where given character 
	//				is found in the given string.
	//-------------------------------------------------------------------------------->
	std::vector<int> WhereAllMyChar(std::string textString, char character)
	{
		std::vector<int> pos;

		std::vector<char> text;


		//Loading the std::string into vector.
		for (int i = 0; i < textString.length(); i++) {
			text.push_back(textString[i]);
		}


		//Taking positions of given characters in given string.
		//example: string:- "Hellow world" and char:- 'l' , the position we need
		//will be 2, 3.
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == character)
			{
				pos.push_back(i);
			}
		}

		return pos;
	}
}