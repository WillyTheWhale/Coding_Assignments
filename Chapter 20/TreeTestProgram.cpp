///***********************************************************************************

/// Title: Tree Class Tester

/// Description: Tests a tree class' functions as specified by the PC20 UML.

/// It runs the class through a series of tests.

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: December 10, 2015

/// Status : Complete 

/// 

/// 

///***********************************************************************************
using namespace std;

#include <iostream>
#include "Tree.h"



int main()
{
	Tree test;
	int result;

	cout << "Tree initialized.\n";
	cout << "Attempting to search for 's', and should FAIL...\n";
	if (test.search('s'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found" << endl;
	cout << "Attempting to print, should print nothing:\n";
	test.print();
	cout << endl;
	cout << "The number of nodes in the tree is: " << test.count() << endl;
	cout << "Attempting to print the values of leaves in the tree, should print nothing:\n";
	test.printLeaves();
	cout << endl;
	cout << "Attempting to remove a node with a char 's', should FAIL...\n";
	if (test.remove('s') == 0)
		cout << "Success! Removed a node\n";
	else
		cout << "Failed! Did not remove a node\n";
	cout << "Attempting to add a node with char 'a'...\n";
	if (test.insert('a') == 0)
		cout << "Success\n";
	else
		cout << "Failed.. what?\n";

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to add another node with char 'a', should SUCCEED." << endl;
	if (test.insert('a') == 0)
		cout << "Success" << endl;
	else
		cout << "Fail...what??" << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for a node with char 'a', should succeed.\n";
	if (test.search('a'))
		cout << "Found!\n";
	else
		cout << "Not found!..what?\n";
	cout << "Attempting to print.. Should print a a:\n";
	test.print();
	cout << endl;
	cout << "Attempting to print just the leaves.\n";
	test.printLeaves();
	cout << endl;
	cout << "Attempting to remove a node with char 'a', should succeed.\n";
	if (test.remove('a') == 0)
		cout << "Success!\n";
	else
		cout << "Failed!...what?\n";

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "adding 'b'\n";
	test.insert('b');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;
	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'b', and should SUCCEED...\n";
	if (test.search('b'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'g'\n";
	test.insert('g');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'g', and should SUCCEED...\n";
	if (test.search('g'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'e'\n";
	test.insert('e');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'e', and should SUCCEED...\n";
	if (test.search('e'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'd'\n";
	test.insert('d');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'd', and should SUCCEED...\n";
	if (test.search('d'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'f'\n";
	test.insert('f');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'f', and should SUCCEED...\n";
	if (test.search('f'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'c'\n";
	test.insert('c');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'c', and should SUCCEED...\n";
	if (test.search('c'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "Removing 'c'\n";
	if (test.remove('c') == 0)
		cout << "SUCCESS\n";
	else
		cout << "FAILED..what?\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'c', and should FAIL...\n";
	if (test.search('c'))
		cout << "True, found...what?" << endl;
	else
		cout << "Fail, not found" << endl;

	cout << "Removing 'e'\n";
	if (test.remove('e') == 0)
		cout << "SUCCESS\n";
	else
		cout << "FAILED..what?\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'e', and should FAIL...\n";
	if (test.search('e'))
		cout << "True, found..what?" << endl;
	else
		cout << "Fail, not found" << endl;

	cout << "Clearing tree...\n";
	test.clear();
	cout << "Printing... " << endl;
	test.print();
	cout << endl;
	cout << "Printing leaves: ";
	test.printLeaves();
	cout << endl;
	cout << "Printing Count: " << test.count() ;
	cout << endl;

	cout << "Removing 'c', should FAIL\n";
	if (test.remove('c') == 0)
		cout << "SUCCESS..what?\n";
	else
		cout << "FAILED..\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Attempting to search for 'c', and should FAIL...\n";
	if (test.search('c'))
		cout << "True, found..what?" << endl;
	else
		cout << "Fail, not found" << endl;
	cout << "Number of Nodes : " << test.count() << endl;
	cout << "Attempting to search for 's', and should FAIL...\n";
	if (test.search('s'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found" << endl;
	cout << "Attempting to print, should print nothing:\n";
	test.print();
	cout << endl;
	cout << "The number of nodes in the tree is: " << test.count() << endl;
	cout << "Attempting to print the values of leaves in the tree, should print nothing:\n";
	test.printLeaves();
	cout << endl;
	cout << "Attempting to remove a node with a char 's', should FAIL...\n";
	if (test.remove('s') == 0)
		cout << "Success! Removed a node\n";
	else
		cout << "Failed! Did not remove a node\n";
	cout << "Attempting to add a node with char 'a'...\n";
	if (test.insert('a') == 0)
		cout << "Success\n";
	else
		cout << "Failed.. what?\n";

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to add another node with char 'a', should SUCCEED." << endl;
	if (test.insert('a') == 0)
		cout << "Success" << endl;
	else
		cout << "Fail...what??" << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for a node with char 'a', should succeed.\n";
	if (test.search('a'))
		cout << "Found!\n";
	else
		cout << "Not found!..what?\n";
	cout << "Attempting to print.. Should print a a:\n";
	test.print();
	cout << endl;
	cout << "Attempting to print just the leaves.\n";
	test.printLeaves();
	cout << endl;
	cout << "Attempting to remove a node with char 'a', should succeed.\n";
	if (test.remove('a') == 0)
		cout << "Success!\n";
	else
		cout << "Failed!...what?\n";

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "adding 'b'\n";
	test.insert('b');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;
	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'b', and should SUCCEED...\n";
	if (test.search('b'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'g'\n";
	test.insert('g');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'g', and should SUCCEED...\n";
	if (test.search('g'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'e'\n";
	test.insert('e');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'e', and should SUCCEED...\n";
	if (test.search('e'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'd'\n";
	test.insert('d');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'd', and should SUCCEED...\n";
	if (test.search('d'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'f'\n";
	test.insert('f');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'f', and should SUCCEED...\n";
	if (test.search('f'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'c'\n";
	test.insert('c');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'c', and should SUCCEED...\n";
	if (test.search('c'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "Removing 'c'\n";
	if (test.remove('c') == 0)
		cout << "SUCCESS\n";
	else
		cout << "FAILED..what?\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'c', and should FAIL...\n";
	if (test.search('c'))
		cout << "True, found...what?" << endl;
	else
		cout << "Fail, not found" << endl;

	cout << "Removing 'e'\n";
	if (test.remove('e') == 0)
		cout << "SUCCESS\n";
	else
		cout << "FAILED..what?\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'e', and should FAIL...\n";
	if (test.search('e'))
		cout << "True, found..what?" << endl;
	else
		cout << "Fail, not found" << endl;

	cout << "Clearing tree...\n";
	test.clear();
	cout << "Printing... " << endl;
	test.print();
	cout << endl;
	cout << "Printing leaves: ";
	test.printLeaves();
	cout << endl;
	cout << "Printing Count: " << test.count() ;
	cout << endl;

	cout << "Removing 'c', should FAIL\n";
	if (test.remove('c') == 0)
		cout << "SUCCESS..what?\n";
	else
		cout << "FAILED..\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Attempting to search for 'c', and should FAIL...\n";
	if (test.search('c'))
		cout << "True, found..what?" << endl;
	else
		cout << "Fail, not found" << endl;
	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 's', and should FAIL...\n";
	if (test.search('s'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found" << endl;
	cout << "Attempting to print, should print nothing:\n";
	test.print();
	cout << endl;
	cout << "The number of nodes in the tree is: " << test.count() << endl;
	cout << "Attempting to print the values of leaves in the tree, should print nothing:\n";
	test.printLeaves();
	cout << endl;
	cout << "Attempting to remove a node with a char 's', should FAIL...\n";
	if (test.remove('s') == 0)
		cout << "Success! Removed a node\n";
	else
		cout << "Failed! Did not remove a node\n";
	cout << "Attempting to add a node with char 'a'...\n";
	if (test.insert('a') == 0)
		cout << "Success\n";
	else
		cout << "Failed.. what?\n";

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to add another node with char 'a', should SUCCEED." << endl;
	if (test.insert('a') == 0)
		cout << "Success" << endl;
	else
		cout << "Fail...what??" << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for a node with char 'a', should succeed.\n";
	if (test.search('a'))
		cout << "Found!\n";
	else
		cout << "Not found!..what?\n";
	cout << "Attempting to print.. Should print a a:\n";
	test.print();
	cout << endl;
	cout << "Attempting to print just the leaves.\n";
	test.printLeaves();
	cout << endl;
	cout << "Attempting to remove a node with char 'a', should succeed.\n";
	if (test.remove('a') == 0)
		cout << "Success!\n";
	else
		cout << "Failed!...what?\n";

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "adding 'b'\n";
	test.insert('b');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;
	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'b', and should SUCCEED...\n";
	if (test.search('b'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'g'\n";
	test.insert('g');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'g', and should SUCCEED...\n";
	if (test.search('g'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'e'\n";
	test.insert('e');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'e', and should SUCCEED...\n";
	if (test.search('e'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'd'\n";
	test.insert('d');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'd', and should SUCCEED...\n";
	if (test.search('d'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'f'\n";
	test.insert('f');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'f', and should SUCCEED...\n";
	if (test.search('f'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "adding 'c'\n";
	test.insert('c');
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'c', and should SUCCEED...\n";
	if (test.search('c'))
		cout << "True, found." << endl;
	else
		cout << "Fail, not found..what?" << endl;

	cout << "Removing 'c'\n";
	if (test.remove('c') == 0)
		cout << "SUCCESS\n";
	else
		cout << "FAILED..what?\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'c', and should FAIL...\n";
	if (test.search('c'))
		cout << "True, found...what?" << endl;
	else
		cout << "Fail, not found" << endl;

	cout << "Removing 'e'\n";
	if (test.remove('e') == 0)
		cout << "SUCCESS\n";
	else
		cout << "FAILED..what?\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Number of Nodes : " << test.count() << endl;

	cout << "Attempting to search for 'e', and should FAIL...\n";
	if (test.search('e'))
		cout << "True, found..what?" << endl;
	else
		cout << "Fail, not found" << endl;

	cout << "Clearing tree...\n";
	test.clear();
	cout << "Printing... " << endl;
	test.print();
	cout << endl;
	cout << "Printing leaves: ";
	test.printLeaves();
	cout << endl;
	cout << "Printing Count: " << test.count() ;
	cout << endl;

	cout << "Removing 'c', should FAIL\n";
	if (test.remove('c') == 0)
		cout << "SUCCESS..what?\n";
	else
		cout << "FAILED..\n";
	cout << "normal print: ";
	test.print();
	cout << endl;
	cout << "leaf print: ";
	test.printLeaves();
	cout << endl;

	cout << "Attempting to search for 'c', and should FAIL...\n";
	if (test.search('c'))
		cout << "True, found..what?" << endl;
	else
		cout << "Fail, not found" << endl;
	cout << "Number of Nodes : " << test.count() << endl;
	cout << "TEST CONCLUDED";
	return 0;
}