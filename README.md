# CostcoCheckout_Simulation

Requirement-
Given a customer file, derive simulation results for your store manager to intelligently schedule checkout counters.

Initial Assumptions-
The queue is assumed to be empty initially. Maximum customers will be served till simulation time expires.Solution is designed in such a way that if wait time of customers is greater than the defined threshold then extra counters needs to be opened for smooth checkout.Number of counters required for smooth checkout needs to be calculated. 

Working of code-
The parameters- Customer No.,Arrival Time and Service time is parsed from the Simulation.txt file stored in an array with particular index reference.Operator overloading is carried out to store the inputs as a data structure. The entries are passed to the queue with methods customerQueue.push
 and removed from the queue using customerQueue.pop method. The billing counter is checked if it is free. The customer is sent to the billing counter. The transaction time decrements .[Waiting time =Service time-arrival time]. Flag is set to true when the server is busy. The transaction time is decremented till zero.The flag is reset to false as,  Now the billing counter will be free.
