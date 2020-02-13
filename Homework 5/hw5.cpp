#include <iostream>
#include <assert.h>
#include "List.h"

using namespace std;


int main()
{
	List my_list;
	cout << "Please enter a set of nonnegative numbers for a List \n (Enter -1 when you are finished):" << endl << endl;
	int input;
	cin >> input;
	while (input > 0)
	{
		my_list.push_back(input);
		cin >> input;
	}

	cout << "Your list is" << endl;
	cout << my_list;
	
	cout << endl << endl;

	int insertion_index, insertion_value;
	cout << "Select an index for insertion (enter -1 when finished): ";
	cin >> insertion_index;
	while (insertion_index >= 0)
	{
		cout << "Select a value for insertion: ";
		cin >> insertion_value;
		Iterator insertion = my_list.begin();
		for (int i = 0; i < insertion_index; i++)
		{
			++insertion;
		}
		my_list.insert(insertion, insertion_value);

		cout << "Select an index for insertion (enter -1 when finished): ";
		cin >> insertion_index;
	}

	cout << endl << endl;
	cout << "The augmented list is\n";
	cout << my_list;
	cout << endl;

	cout << "When we sort the list we obtain" << endl;
	my_list.sort();
	cout << my_list;
	cout << endl;

	cout << "And this sorted list in reverse order is" << endl;
	my_list.reverse();
	cout << my_list;
	cout << endl;

	List other;
	other.push_back(2);
	other.push_back(3);
	other.push_back(5);
	other.push_back(7);
	other.push_back(11);
	cout << "If we merge this list with the list " << other << " we obtain" << endl;

	my_list.merge(other);
	cout << my_list;

}
