// Name:David Zhu
// Seneca Student ID:105936207
// Seneca email:dzhu34@myseneca.ca	
// Date of completion:2021-04-03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <string>
#include "Station.h"

namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};
	class CustomerOrder {
		
		//instance variables:
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem{};

		//class variable:
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string str);
		CustomerOrder(CustomerOrder&);
		CustomerOrder& operator=(CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&)noexcept;
		CustomerOrder& operator=(CustomerOrder&& co) noexcept;
		~CustomerOrder();

		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

	};
	
}
#endif