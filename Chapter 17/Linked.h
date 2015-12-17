///***********************************************************************************

/// Title:

/// Description: 

/// 

/// Author: Willy Ma

/// COMSC 165 Section 8326

/// Date: June 16, 2014

/// Status : Complete 

/// 

/// 

///***********************************************************************************
#ifndef LINKED_H
#define LINKED_H

class Linked
{
private:

	struct Node
	{

		int i;
		Node *next;
	};

	Node *head;

public:

	Linked();
	~Linked();
	int  append(int);
	int  insert(int);
	int  remove(int);
	bool find(int) const;
	bool isFull() 	 const;
	bool isEmpty() 	 const;
	int  size() 	 const;
	void print()	 const;
	void clear();
};

Linked::Linked()
{
	head = NULL;
}

Linked::~Linked()
{
	Node* nextNode = NULL;
	while (head != NULL)
	{
		nextNode = head->next;
		delete head;
		head = nextNode;
	}

}

int Linked::append(int value)
{

	if ( isFull() )
	{
		return -1;
	} 

	else
	{
		Node* nodeptr = head;
		Node* newNode = new Node;
		newNode->i = value;
		newNode->next = NULL;
		if ( isEmpty() )
		{
			head = newNode;
			return 0;
		}

		else
		{

			while (nodeptr->next != NULL)
			{
				nodeptr = nodeptr->next;
			}
			nodeptr->next = newNode;

			return 0;
		}
	}

}

int Linked::insert(int value)
{

	if (isFull())
	{
		return -1;
	}

	else
	{
		Node* nodeptr = head;
		Node* newNode = new Node;
		newNode->i = value;
		newNode->next = NULL;
		Node* previousptr = nodeptr;
		if (head == NULL)
		{
			head = newNode;
			return 0;
		}
		else
		{
			nodeptr = nodeptr->next;
			while (nodeptr != NULL && value <= nodeptr->i)
			{
				nodeptr = nodeptr->next;
				previousptr = previousptr->next;
			}

			newNode->next = nodeptr->next;
			previousptr->next = newNode;
			return 0;
		}
	}
}

int Linked::remove(int value)
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		Node* nodeptr = head->next;
		Node* previousptr = head;
		bool found = false;

		while (nodeptr != NULL)
		{
			if (nodeptr->i == value)
			{
				previousptr->next = nodeptr->next;
				delete nodeptr;
				found = true;
				return 0;
			}

			else
			{
				nodeptr = nodeptr->next;
				previousptr = previousptr->next;
			}
		}

		if (found == false)
		{
			return -1;
		}

	}
}

bool Linked::find(int value) const
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node* nodeptr = head;

		bool found = false;

		while (nodeptr != NULL)
		{
			if (nodeptr->i == value)
			{
				return true;
			}

			else
			{
				nodeptr = nodeptr->next;
			}
		}

		if (found == false)
		{
			return false;
		}

	}
}

bool Linked::isFull() const
{
	Node* test = new Node;
	if (test == NULL)
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

bool Linked::isEmpty() const
{
	if (head == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}

}

int Linked::size() const
{
	int count = 0;

	if (isEmpty())
	{
		return 0;
	}
	else
	{
		Node* travelerNode = head;
		while (travelerNode != NULL)
		{
			count++;
			travelerNode = travelerNode->next;
		}
		return count;
	}
}

void Linked::print() const
{
	if (isEmpty() == false)
	{
		Node* travelerNode = head;
		while (travelerNode != NULL)
		{
			cout << travelerNode->i << " ";
				travelerNode = travelerNode->next;
		}
		cout << endl;
	}
}

void Linked::clear()
{
	Node* nextNode = NULL;
	while (head != NULL)
	{
		nextNode = head->next;
		delete head;
		head = nextNode;
	}
}


#endif