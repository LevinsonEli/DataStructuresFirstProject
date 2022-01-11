#include <iostream>
#include "List.h"
#include "Stack.h"
using namespace std;

void FindAccessibles1(List ** networkStruct, int moked, int * colorsArr, List * accessList);
void FindAccessibles2(List ** networkStruct, int moked, int * colorsArr, List * accessList);

int main() {
    // Getting the input from the user
	int numOfComputers, numOfLinks;
	cout << "Enter number of computers: " << endl;
	cin >> numOfComputers;
	if (numOfComputers <= 0) {
		cout << "Incorrect number of computers (must be a positive number). " << endl;
		exit(1);
	}
	cout << "Enter number of links: " << endl;
	cin >> numOfLinks;
	if (numOfLinks < 0) {
		cout << "Incorrect number of links (must be a non-negative number). " << endl;
		exit(1);
	}
	int *links = new int[numOfLinks * 2];
	for (int i = 0; i < numOfLinks * 2; i++) {
		cin >> links[i];
		if (links[i] <= 0 || links[i] > numOfComputers) {
			cout << "no such computer " << links[i] << endl;
			exit(1);
		}
	}
	int moked;
	cout << "Enter the \"moked\":" << endl;
	cin >> moked;
	if (moked <= 0 || moked > numOfComputers) {
		cout << "no such computer " << moked << endl;
		exit(1);
	}

    // Creating a network structure
	List ** networkStruct = new List*[numOfComputers];
	for (int i = 0; i < numOfComputers; i++)
		networkStruct[i] = new List(numOfComputers);
	for (int i = 0; i < numOfLinks * 2 - 1; i += 2)
		networkStruct[links[i] - 1]->addToHead(links[i + 1]);
	// 0 - black, 1 - white
	int * colorsArr = new int[numOfComputers];
	for (int i = 0; i < numOfComputers; i++)
		colorsArr[i] = 1;

    // FindAccessibles Recursivly
	List * accessList1 = new List(numOfComputers);

	FindAccessibles1(networkStruct, moked, colorsArr, accessList1);

	while (!accessList1->isEmpty())
		cout << accessList1->removeFromTail() << " ";
	cout<<endl;
	
	//FindAccessibles Iterativly
	List * accessList2 = new List(numOfComputers);

    // Setting the input
	for (int i = 0; i < numOfLinks * 2 - 1; i += 2)     // for network structure
		networkStruct[links[i] - 1]->addToHead(links[i + 1]);
	for (int i = 0; i < numOfComputers; i++)            // for array of colors
		colorsArr[i] = 1;

	FindAccessibles2(networkStruct, moked, colorsArr, accessList2);

	while (!accessList2->isEmpty())
		cout << accessList2->removeFromTail() <<  " ";
	cout<<endl;
	
	return 0;
}

void FindAccessibles1(List ** networkStruct, int moked, int * colorsArr, List * accessList) {
	if (colorsArr[moked - 1] == 1) {    // 1 - stands for white computer
		colorsArr[moked - 1] = 0;       // set the computer to black - 0
		accessList->addToHead(moked);
		while (!networkStruct[moked - 1]->isEmpty()) {
			FindAccessibles1(networkStruct, networkStruct[moked - 1]->removeFromTail(), colorsArr, accessList);
		}
	}
}
void FindAccessibles2(List ** networkStruct, int moked, int * colorsArr, List * accessList) {
	Stack stackOfComputers;
	stackOfComputers.Push(moked);
	int newMoked;
	while (!stackOfComputers.isEmpty()) {
		newMoked = stackOfComputers.Pop();
		if (colorsArr[newMoked - 1] == 1) {     // 1 - stands for white computer
			colorsArr[newMoked - 1] = 0;        // set the computer to black - 0
			accessList->addToHead(newMoked);
			while (!networkStruct[newMoked - 1]->isEmpty()) {
				stackOfComputers.Push(networkStruct[newMoked - 1]->removeFromHead());
			}
		}
	}
}