//OOP345 MS1
//3/17/2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my Project.
//David Zhu
//105936207
//dzhu34@myseneca.ca
#include <iostream>
#include <cstring>
#include "Utilities.h"

using namespace std;
namespace sdds {
	
	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	/*– extracts a token from string str referred to by the first parameter
	This function uses the delimiter to extract the next token from str starting at position next_pos.
		If successful, this function returns a copy of the extracted token found, updates next_pos with the position of the next token, and sets more to true (false otherwise0.
			This function reports an exception a delimiter is found at next_pos.
			This function updates the current object’s m_widthField data member if its current value is less than the size of the token extracted.
			Note: in this application, str represents a single line that has been read from an input file*/
	/*std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string tempString = str;
		std::string token;
		size_t posIni = next_pos;
		size_t posFinal = tempString.find(m_delimiter, posIni);
		size_t size = posFinal - posIni;

		if (posFinal > tempString.length()) {
			posFinal = tempString.length();
			size = getFieldWidth();
			token = tempString.substr(posIni);
			more = false;
		}
		else if (posFinal <= tempString.length())
		{
			token = tempString.substr(posIni, size);
			more = true;
		}
		if (token != "") {
			
			posFinal++;
			next_pos = posFinal;
			if (m_widthField < token.length()) {
				m_widthField = token.length();
			}
		}
		else {
			more = false;
			throw "Exception";
		}
		return token;
	}*/
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string Token;
		size_t next_next_pos;

		if (str.find(m_delimiter, next_pos) != std::string::npos) {
			next_next_pos = str.find(m_delimiter, next_pos);
			more = true;
		}
		else {
			next_next_pos = str.length();
			more = false;
		}

		if (next_next_pos == next_pos) {
			more = false;
			throw  "A delimiter is found at " + to_string(next_pos);
		}
		else if (next_next_pos > next_pos) {
			Token = str.substr(next_pos, (next_next_pos - next_pos));
			next_pos = next_next_pos + 1;

		}
		else { more = false; }

		if (Token.length() > m_widthField)
			m_widthField = Token.length();

		return Token;

	}

	
	/*std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string Token;
		size_t next_next_pos;

		if (str.find(m_delimiter, next_pos) != std::string::npos) {
			next_next_pos = str.find(m_delimiter, next_pos);
			more = true;
		}
		else {
			next_next_pos = str.length();
			more = false;
		}

		if (next_next_pos == next_pos) {
			more = false;
			throw  "A delimiter is found at " + to_string(next_pos);
		}
		else if (next_next_pos > next_pos) {
			Token = str.substr(next_pos, (next_next_pos - next_pos));
			next_pos = next_next_pos + 1;

		}
		else { more = false; }

		if (Token.length() > m_widthField)
			m_widthField = Token.length();

		return Token;

	}*/
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}