// Name:David Zhu
// Seneca Student ID:105936207
// Seneca email:dzhu34@myseneca.ca	
// Date of completion:2021-04-03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <utility>
#include <stack>
#include <algorithm>
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0u;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string str)
	{
		Utilities temp;
		bool flag = false;
		size_t endPos, beginPos;
		char delimiter = temp.getDelimiter();

		endPos = str.find(delimiter);
		m_name = str.substr(0, endPos);

		beginPos = endPos + 1;
		endPos = str.find(delimiter, beginPos);
		m_product = temp.extractToken(str, beginPos, flag);

		m_cntItem = std::count(str.begin(), str.end(), delimiter) - 1;

		if (m_cntItem > 0) {
			m_lstItem = new Item * [m_cntItem];
			for (size_t i = 0u; i < m_cntItem; i++) {
				beginPos = endPos + 1;
				endPos = str.find(delimiter, beginPos);
				m_lstItem[i] = new Item(temp.extractToken(str, beginPos, flag));
			}
		}

		if (m_widthField < temp.getFieldWidth()) {
			m_widthField = temp.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder& co)
	{
		throw "Cope Constructor is not allowed in this class.";
	}


	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept
	{
		if (this != &co) {
			if (m_lstItem) {
				for (size_t i = 0u; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}
			m_name = co.m_name;
			m_product = co.m_product;
			m_cntItem = co.m_cntItem;
			m_widthField = co.m_widthField;
			m_lstItem = co.m_lstItem;

			co.m_name = "";
			co.m_product = "";
			co.m_cntItem = 0u;
			co.m_lstItem = { nullptr };
		}

		return *this;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept
	{
		*this = move(co);
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0u; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}

		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isFilled() const
	{
		bool flag = true;
		for (size_t i = 0u; i < m_cntItem &&flag== true; i++) {
			if (m_lstItem[i]->m_isFilled == false) {
				flag = false;
			}
		}
		return flag;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool flag = false;
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (itemName.compare(m_lstItem[i]->m_itemName) == 0) {
				flag = true;
			}
		}
		return flag;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0u; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0) {
				if (station.getQuantity() > 0) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << string(4, ' ') << "Filled " << m_name << ", " << m_product
						<< " [" << station.getItemName() << "]" << endl;
				}
				else {
					os << string(4, ' ') << "Unable to fill" << m_name << ", " << m_product
						<< " [" << station.getItemName() << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		int serialWidth = 6;
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0u; i < m_cntItem; ++i) {
			os << "[" << setw(serialWidth) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] "
				<< setw(m_widthField) << setfill(' ') << left << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED";
			}
			else {
				os << "TO BE FILLED";
			}

			os << std::endl;
		}
	}
}


