//OOP345 MS1
//3/17/2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my Project.
//David Zhu
//105936207
//dzhu34@myseneca.ca
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>

namespace sdds {
	
class Utilities {
	size_t m_widthField = 1;
	static char m_delimiter;

public:

	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;

	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	static void setDelimiter(char newDelimiter);
	static char getDelimiter();

	};
}
#endif
