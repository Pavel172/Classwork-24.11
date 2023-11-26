#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(int data);
	bool add_element(int data);
	bool add_element_first(int data);
	bool delete_element(int position);
	int find_element(LinkedList lst, int data);
	void print_list(LinkedList lst);
	bool sort_list(LinkedList lst, int count);
	~LinkedList();
private:
	Node* first;
	Node* last;
};

LinkedList::LinkedList()
{
	first = nullptr;
	last = nullptr;
}

LinkedList::LinkedList(int data)
{
	Node* nd = new Node{ data, nullptr, nullptr };
	first = nd;
	last = nd;
	last->next = nullptr;
	first->prev = nullptr;
}

LinkedList::~LinkedList() {}

bool LinkedList::add_element(int data) 
{
	Node* nd = new Node{ data, nullptr, last };
	if(last == nullptr)
	{
		first = nd;
		last = nd;
		return true;
	}
	last->next = nd;
	last = nd;
	return true;
}

bool LinkedList::add_element_first(int data)
{
	Node* nd = new Node{ data, first, nullptr };
	if (first == nullptr)
	{
		first = nd;
		last = nd;
		return true;
	}
	first->prev = nd;
	first = nd;
	return true;
}

bool LinkedList::delete_element(int position)
{
	int i = 0, a = 0, count_elem = 0;
	Node* elem_f = first;
	Node* elem_l = last;
	while(elem_f != NULL)
	{
		++count_elem;
		elem_f = elem_f->next;
	}
	if(position == 1)
	{
		first = first->next;
		delete elem_f;
	}

	if (position == count_elem)
	{
		Node* elem_f1 = first;
		Node* elem_f2 = first->next;
		while(elem_f2->next != NULL)
		{
			elem_f2 = elem_f2->next;
			elem_f1 = elem_f1->next;
		}
		elem_f1->next = NULL;
		last = elem_f1;
		delete elem_f2;
	}

	if(position < count_elem && position > 1)
	{
		Node* elem_f1 = first;
		Node* elem_f2 = first->next;
		for (int i = 1; i < position - 1; ++i)
		{
			elem_f2 = elem_f2->next;
			elem_f1 = elem_f1->next;
		}
		elem_f1->next = elem_f2->next;
		delete elem_f2;
		return true;
	}
	return true;
}

void LinkedList::print_list(LinkedList lst)
{
	Node* elem = first;
	while (elem != NULL) 
	{
		cout << elem->data << " ";
		elem = elem->next;
	}
}

int LinkedList::find_element(LinkedList lst, int data)
{
	int place = 0;
	Node* elem = last;
	while (elem != NULL)
	{ 
		++place;
		if ((elem->data) == data)
		{
			return place;
		}
		elem = elem->prev;
	}
	return 0;
}

bool LinkedList::sort_list(LinkedList lst, int count)
{
	Node* elem_f1 = first;
	Node* elem_f2 = first->next;
	Node* elem_fx = new Node;
	while (elem_f1->next != NULL)
	{
		while (elem_f2 != NULL)
		{
			if ((elem_f1->data) > (elem_f2->data))
			{
				elem_fx->data = elem_f1->data;
				elem_f1->data = elem_f2->data;
				elem_f2->data = elem_fx->data;
			}
			elem_f2 = elem_f2->next;
		}
		elem_f1 = elem_f1->next;
		elem_f2 = elem_f1->next;
	}
	return true;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	LinkedList lst;
	int x = 0, count = 0, n = 0;
	cout << "Введите количество символов, которое должно быть в списке: ";
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		x = rand() % 10;
		lst.add_element(x);
	}
	cout << "\nСписок: ";
	lst.print_list(lst);
	cout << endl;
	lst.sort_list(lst, count);
	cout << "\nОтсортированный по возрастанию список: ";
	lst.print_list(lst);
	cout << endl;
	return 0;
}