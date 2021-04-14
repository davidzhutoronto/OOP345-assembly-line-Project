// Name:David Zhu
// Seneca Student ID:105936207
// Seneca email:dzhu34@myseneca.ca	
// Date of completion:2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include <vector>
#include <string>

#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {


	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation :public Station {
		std::deque<CustomerOrder>m_orders;
		Workstation* m_pNextStation;

	public:
		Workstation(const std::string&str);
		Workstation(Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		const Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}

#endif
