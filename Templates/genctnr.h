#ifndef GENCTNR_H
#define GENCTNR_H

template<typename Any>
class SimpleList
{
public:
	SimpleList()
	{
		front = back = 0;
	}

	void PushBack(const Any& value)
	{
		ListNode* node = new ListNode(value);
		
		if(front == 0)
			front = back = node;
		else
			back->next = node, back = node;
	}

	bool Empty() const
	{
		return front == 0;
	}

	Any& Front() const
	{
		return front->value;
	}

	void PopFront()
	{
		ListNode* node = front;

		front = front->next;
		delete node;
	}

	~SimpleList()
	{
		while(front)
			PopFront();
	}
private:
	class ListNode
	{
	public:
		ListNode(const Any& v) : value(v)
		{
			next = 0;
		}

		Any value;
		ListNode* next;
	};

	ListNode* front;
	ListNode* back;
};

#endif















