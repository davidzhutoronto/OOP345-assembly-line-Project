// Name:David Zhu
// Seneca Student ID:105936207
// Seneca email:dzhu34@myseneca.ca	
// Date of completion:2021-04-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <algorithm>
#include <iostream>
#include <deque>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities u;
		string record;
		m_firstStation = nullptr;

		ifstream f(file);
		if (!f)
			throw string("Unable to open [" + file + "] file.");

		while (!f.eof())
		{
			std::getline(f, record);
			bool more = false;
			size_t next_pos = 0;

			string str1 = u.extractToken(record, next_pos, more);
			bool find1 = any_of(stations.begin(), stations.end(),
				[=](Workstation* ws1)mutable->bool {
					if (ws1->getItemName() == str1)
					{
						ws1->setNextStation();
						if (more)
						{
							string str2 = u.extractToken(record, next_pos, more);
							bool find2 = any_of(stations.begin(), stations.end(),
								[=](Workstation* ws2)mutable->bool {
									if (ws2->getItemName() == str2)
									{
										ws1->setNextStation(ws2);
										return true;
									}
									else return false;
								});
							if (!find2) {
								throw "error";
							}
							else if (str1 == str2)
							{
								throw "error";
							}

						}

						activeLine.push_back(ws1);
						return true;
					}
					else return false;
				});


			if (!find1) {
				throw "error";
			}

		}
		f.close();
		for_each(activeLine.begin(), activeLine.end(), [=](Workstation* wstat) {
			bool find = false;
			find = any_of(activeLine.begin(), activeLine.end(), [=](Workstation* wstation)mutable {
				if (wstation->getNextStation() == wstat)
					return true;
				else return false;
				});

			if (find == false)
				m_firstStation = wstat;
			return true;
			});

		m_cntCustomerOrder = pending.size();

	}

	LineManager::LineManager()
	{
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	}

	void LineManager::linkStations() {
		std::vector<Workstation*> temp;
		temp.push_back(m_firstStation);

		const Workstation* iterator = m_firstStation->getNextStation();
		Workstation* next;
		do {
			for (auto e : activeLine) {
				if (e == iterator) {
					next = e;
				}
			}
			temp.push_back(next);
			iterator = next->getNextStation();
		} while (iterator);

		std::copy(temp.begin(), temp.end(), activeLine.begin());
	}
	
	bool LineManager::run(std::ostream& os) {
		static size_t count = 1u;

			os << "Line Manager Iteration: " << count << endl;

			if (!pending.empty()) {
				*m_firstStation += std::move(pending.front());
				pending.pop_front();
			}

			for_each(activeLine.begin(), activeLine.end(), [&](Workstation* wstation) {
				wstation->fill(os);
				});

			for (int i = activeLine.size(); i > 0; --i) {
				activeLine.at(i - 1)->attemptToMoveOrder();
			};

			count++;
			
			return m_cntCustomerOrder == (completed.size() + incomplete.size());
	}
		
	void LineManager::display(std::ostream& os) const
	{
		if (!activeLine.empty()) {
			for (auto& i : activeLine) {
				i->display(os);
			}
		}
	}
}