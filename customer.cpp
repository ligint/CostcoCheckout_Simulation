/*
 * customer.cpp
 *
 *  Created on: 13-Dec-2018
 *      Author: Naruto
 */
#include "customer.h"

ostream& operator<<(ostream& os, customer& cust) {
	os <<"Customer Number " << cust.customer_Number << " arrived at time "
			<< cust.arrival_time << " with " << cust.numberofItems << " items"
			<< "and check out at time" << cust.checkout_time;
	return os;
}

istream& operator>>(istream& is, customer& cust) {
	is >> cust.customer_Number >> cust.arrival_time >> cust.numberofItems;
	return is;
}

