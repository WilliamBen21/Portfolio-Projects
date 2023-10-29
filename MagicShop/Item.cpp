#include <string>
using namespace std;


class Item
{
private: //Members
	string name;
	int cost;

public: //Constructors

	Item(string _itemName, int _itemCost)
	{
		name = _itemName;
		cost = _itemCost;
	}
	Item() //Default Constructor
	{
		 name = "";
		 cost = 0;
	}
	//Accessors (Getters)
	string GetName()
	{
		return name;
	}
	int GetCost()
	{
		return cost;
	}
	//Mutators (Setters)

	void SetName(string _itemName)
	{
		name = _itemName;
		//return _itemName;
	}
	void SetCost(int _itemCost)
	{
		cost = _itemCost;
		//return _itemCost;
	}

	/* TODO: Create an Item class
	* ===================================
	* The class should contain 2 data members:
	* - A string called name
	* - An int called cost.
	*
	* This class should have a default constructor
	* that sets name to "" and cost to 0.
	*
	* It should also have an overloaded constructor
	* that accepts 2 parameters:
	* - A string
	* - An int.
	*
	* Write getters/accessors for each data member.
	* They should be called GetName and GetCost.
	*
	* Write setters/mutators for each data member.
	* They should be called SetName and SetCost.
	*/




};