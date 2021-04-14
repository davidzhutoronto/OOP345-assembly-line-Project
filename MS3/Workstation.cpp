// Name:David Zhu
// Seneca Student ID:105936207
// Seneca email:dzhu34@myseneca.ca	
// Date of completion:2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"

using namespace std;
namespace sdds {
	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};

	Workstation::Workstation(const std::string& str):Station(str)
	{
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os)
	{
		//if there are CustomerOrders in the queue; otherwise, does nothing
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool flag = false;

		if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName())) {
	
			if (m_pNextStation != nullptr) {
				*m_pNextStation += move(m_orders.front());			
				flag = true;
			}
			else {
				completed.push_back(move(m_orders.front()));
				flag = true;
			}
			m_orders.pop_front();
		}

		else if (!m_orders.empty() && !m_orders.front().isFilled()) {
			if (m_pNextStation != nullptr) {
				*m_pNextStation += move(m_orders.front());
				flag = true;
			}
			else {
				incomplete.push_back(move(m_orders.front()));
				flag = true;
			}
			m_orders.pop_front();
		}
		return flag;
	}

	void Workstation::setNextStation(Workstation* station) 
	{
			m_pNextStation = (Workstation *)station;
	}

	const Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() << " --> ";
		if (getNextStation()) {
			os << getNextStation()->getItemName();
		}
		else {
			os << "End of Line";
		}
		os << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}

}