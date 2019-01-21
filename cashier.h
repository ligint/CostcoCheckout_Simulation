/*
 * cashier.h
 *
 *  Created on: 13-Dec-2018
 *      Author: Naruto
 */

#ifndef CASHIER_H_
#define CASHIER_H_

#include "customer.h"

class cashier{
public:
	customer current_cust;
	int checkout_time;
	int cashier_number;
	bool isbusy;
	int waiting_time;

};




#endif /* CASHIER_H_ */
