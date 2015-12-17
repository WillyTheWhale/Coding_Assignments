///***********************************************************************************

/// Title: PC18 

/// Description: Queues and Stacks

/// 

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: December 5, 2015

/// Status : Inomplete 

/// 

/// 

///***********************************************************************************
#ifndef STACK_H
#define STACK_H


class Stack
{
private:
	struct Node
	{
		int i;

		Node* next;

	};

	Node* top;

public:

	Stack();
	~Stack();

	int push(int);
	int pop(int &);
	void clear();
	int peek(int &);
	bool isEmpty() const;
	bool isFull() const;
	void print();
	int size() const;




};

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{

	Node* nextNode = NULL;
	while (top != NULL)
	{
		nextNode = top->next;
		delete top;
		top = nextNode;
	}

}

int Stack::push(int input)
{
	if (isFull())
	{
		return -1;
	}

	else
	{
		Node* newNode = new Node;
		newNode->i = input;
		newNode->next = top;
		top = newNode;

		return 0;
	}


}

int Stack::pop(int &output)
{
	if (isEmpty())
	{
		return -1;
	}

	else
	{
		output = top->i;
		Node* newTop = top->next;
		delete top;
		top = newTop;

		return 0;
	}


}

void Stack::clear()
{

	Node* nextNode = NULL;
	while (top != NULL)
	{
		nextNode = top->next;
		delete top;
		top = nextNode;
	}

}

int Stack::peek(int &output)
{
	if (isEmpty())
	{
		return -1;
	}

	else
	{
		output = top->i;
		return 0;
	}
}

int Stack::size() const
{
	int count = 0;
	Node* travelerNode = top;
	while (travelerNode != NULL)
	{
		travelerNode = travelerNode->next;
		count++;
	}
	return count;
}

void Stack::print()
{
	Node* travelerNode = top;
	while (travelerNode != NULL)
	{
		cout << " " << travelerNode->i;
		travelerNode = travelerNode->next;
	}
	cout << endl;
}



bool Stack::isFull() const
{
	Node* test = new Node;
	if (test = NULL)
	{
		delete test;
		return true;
	}

	else
	{
		delete test;
		return false;
	}

}

bool Stack::isEmpty() const
{
	if (top == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}

#endif