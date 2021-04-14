//OOP345 MS1
//3/17/2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my Project.
//David Zhu
//105936207
//dzhu34@myseneca.ca
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"


using namespace std;


namespace sdds {
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 1;

	Station::Station(const std::string str)
	{
		m_id = id_generator;
		id_generator++;
		Utilities u;
		size_t next_pos = 0;
		bool flag = true;
		std::string tempstr = str;

		try {
			m_name = u.extractToken(tempstr, next_pos, flag);
			m_sn = stoi(u.extractToken(str, next_pos, flag));
			m_qty = stoi(u.extractToken(str, next_pos, flag));
			m_description = u.extractToken(str, next_pos, flag);
			m_widthField = (m_widthField < m_name.length()) ? m_name.length() : m_widthField; 
			//updates the current object’s m_widthField data member if its current value is less than the size of the token extracted
		}
		catch (std::string& msg) {
			cout << msg;
		}
	}


	

	const std::string& Station::getItemName() const
	{
		return m_name;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_sn++;
	}
	size_t Station::getQuantity() const
	{
		return m_qty;
	}
	void Station::updateQuantity()
	{
		if (m_qty > 0) {
			m_qty--;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << "[" << std::setfill('0') << std::setw(3) << right << m_id
			<< "] Item: " << std::setfill(' ') << std::setw(m_widthField) << left << m_name
			<< " [" << std::setfill('0') << std::setw(6) << right << m_sn << "]";
		if (full)
		{
			os << std::setfill(' ') << " Quantity: " << setw(m_widthField) << left << m_qty
				<< " Description: " << m_description;
		}
		os << endl;
	}
	
}