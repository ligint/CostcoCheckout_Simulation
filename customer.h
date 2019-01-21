/*
 * customer.h
 *
 *  Created on: 13-Dec-2018
 *      Author: Naruto
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include<iostream>
#include<fstream>
using namespace std;

class customer{

	friend istream& operator >> (istream&, customer&);
	friend ostream& operator << (ostream&, customer&);

public:
	int customer_Number;
	int arrival_time;
	int numberofItems;
	//int transaction_time;
	int checkout_time;
	int service_start_time;
};



#endif /* CUSTOMER_H_ */
