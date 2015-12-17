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
#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
private:
	int* q;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue(int);
	~Queue();
	int enqueue(int);
	int dequeue(int &);
	void clear();
	int peek(int &);
	bool isEmpty();
	bool isFull();
	void print();
	int size();





};

Queue::Queue(int size)
{
	q = new int[size];
	capacity = size;
	front = 0;
	rear = 0;
	count = 0;


}

Queue::~Queue()
{
	delete q;
}

int Queue::enqueue(int value)
{
	if (isFull())
	{
		return -1;
	}

	else
	{
		*(q + rear) = value;
		rear = (rear + 1) % capacity;
		count++;
		return 0;
	}

}

int Queue::dequeue(int &output)
{
	if (isEmpty())
	{
		return -1;
	}

	else
	{
		output = *(q + front);
		front = (front + 1) % capacity;
		count--;
		return 0;
	}

}

void Queue::clear()
{
	front = 0;
	rear = 0;
	count = 0;

}

int Queue::peek(int &output)
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		output = *(q + front);
		return 0;
	}


}

void Queue::print()
{
	if (count != 0)
	{
		int counter = 0;
	
		for (int i = front; counter < count; )
		{
			cout << *( q + i ) << " ";
			i = (i + 1) % capacity;
			counter++;
		}
		cout << endl;
	}
}

int Queue::size()
{
	return count;
}


bool Queue::isEmpty()
{
	if (count == 0)
	{
		return true;
	}

	else
	{
		return false;
	}

}

bool Queue::isFull()
{
	if (count == capacity)
	{
		return true;
	}

	else
	{
		return false;
	}


}





#endif