/*
 * simulation.cpp
 *
 *  Created on: 13-Dec-2018
 *      Author: Naruto
 */

#include "cashier.h"
#include "customer.h"
#include<queue>
#include <list>
#include <vector>
#include<algorithm>
#include "stdlib.h"
#define numberofcashier 3
#define simulationTime 100

void simulation() {
	vector<cashier> cashiers;
	cashier lane;
	lane.isbusy = false;
	for (int i = 0; i < numberofcashier; i++)
		cashiers.push_back(lane);
	int numberofcustomers = 0;

	queue<customer> customerQueue;
	{
		customer new_cust;
		ifstream fin;
		fin.open("simulation.txt");
		while (!fin.eof()) {
			fin >> new_cust;
			customerQueue.push(new_cust);
			numberofcustomers++;
		}
		fin.close();
	}
	cout << "Number of customers " << numberofcustomers << endl;
	list<int>wait_time;
	int sum = 0;
	float avg = 0.0;
	for (int clock = 1; clock <= simulationTime; clock++) {
		for (int i = 0; i < numberofcashier; i++) {
			if (cashiers[i].isbusy) {
				cashiers[i].checkout_time--;
				if (cashiers[i].checkout_time <= 0) {
					cashiers[i].isbusy = false;
					cout << "At time" << clock << " Cashier" << i
							<< " has finished serving Customer"
							<< cashiers[i].current_cust.customer_Number << endl;
				}
			} else if (cashiers[i].isbusy == false) {
				if (customerQueue.empty())
					continue;
				if (customerQueue.front().arrival_time > clock)
					continue;

				customer new_cust = customerQueue.front();
				customerQueue.pop();
				cashiers[i].isbusy = true;
				new_cust.service_start_time = clock;
				//cout << clock << endl;
				//cout << new_cust.arrival_time << endl;
				cashiers[i].current_cust = new_cust;
				cashiers[i].checkout_time = new_cust.numberofItems;
				cout << "Cashier Number" << i << " is serving customer "
						<< cashiers[i].current_cust.customer_Number
						<< " at time " << new_cust.service_start_time << endl;
				cout << "Wait Time for Customer"
						<< cashiers[i].current_cust.customer_Number << " is "
						<< clock - cashiers[i].current_cust.arrival_time
						<< endl;
				wait_time.push_back(clock - cashiers[i].current_cust.arrival_time);
			}

		}
	}
	for(list<int>::iterator i=wait_time.begin();i!=wait_time.end();i++)
	{
		//cout<<*i<<endl;
		sum=sum+*i;
	}
	cout <<"Sum is "<<sum<<endl;
	avg = sum / numberofcustomers;
	cout << "Average wait time is "<< avg<<endl;
	int max=*max_element(wait_time.begin(),wait_time.end());
	int min=*min_element(wait_time.begin(),wait_time.end());

	cout<<"Max wait time is "<<max<<endl;
	cout<<"Min wait time is "<<min<<endl;

	if (avg>15)
	{
		cout<<"There is need for extra Cashier Counter"<<endl;
	}
	else
		cout<<"Everything seems proper , There is no need for extra Cashier Counter"<<endl;

}
