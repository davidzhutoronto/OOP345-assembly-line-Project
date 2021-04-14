// Name:David Zhu
// Seneca Student ID:105936207
// Seneca email:dzhu34@myseneca.ca	
// Date of completion:2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINGMANAGER_H
#define SDDS_LINGMANAGER_H
#include <iostream>
#include <vector>
#include "CustomerOrder.h"
#include "Workstation.h"
namespace sdds {
	class LineManager {

		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;
		
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;


	};
}
#endif