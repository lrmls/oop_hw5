Sprint 3
I did it. i completed all the features i wanted to.
Menu based navigation:
	a manager is creating automatically as you only need one, and
		creates parts and robots and stores them in stock
	customer creates self and chooses an associate to shop through 
		and buys robots from stock, creating an order and storing  
		it in shop
	associate creates himself.... I thought of how to connect customer
		and associate to work in tandem to create orders. after
		considering storing an instance of each order in each 
		customer and each associate i decided to simplify by just
		have one instance of all orders that contain the name
		of the associate and customer, then search through 
		orders by name, either associate or customer, to get
		a grouping of all orders by each associate or customer.
		this kinda left the associate class not in charge of much.
		but otherwise customer wouldnt have done much...
	boss is created automatically as theres only one. Boss evaluates
		orders by associate and grants raises. Also can store and
		save the shop state to a .txt file
robots are defined as a collection of parts, each of which is derived
	from the same base part class with their own unique attributes added
orders are a collection of robots, a customer, and an associate object

Shop is saved and read from "shopImage.txt"
submission contains sample file "sample.txt" that i used for testing
	and can be copied into shopImage.txt for quick demo/test
