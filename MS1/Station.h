//OOP345 MS1
//3/17/2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my Project.
//David Zhu
//105936207
//dzhu34@myseneca.ca
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>

namespace sdds {
	class Station {
		int m_id;
		std::string m_name;
		std::string m_description;
		size_t m_sn;
		size_t m_qty;

		//class variables
		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station(const std::string st);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
	
		void display(std::ostream& os, bool full) const;
	};

}





#endif