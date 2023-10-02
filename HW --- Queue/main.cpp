#include <iostream>
using namespace std;

struct Elem
	{
	    int data;
	    Elem* next, * prev;
	};
	template <class T>
	class Queue
	{
	    Elem* Head, * Tail;
	    int Count;
	
	public:
		Queue <T>();
		Queue <T>(T amount);
	    ~Queue <T>();
	    int GetCount();
	    void DelAll();
	    void Del(int pos);
	    void Add(T n);
	    void Show();
		void Extract();
	};

	template<class T>
	Queue<T>::Queue()
	{
		Head = Tail = NULL;
		Count = 0;
	}

	template<class T>
	Queue<T>::Queue(T amount)
	{
		Head = Tail = NULL;
		Count = amount;
	}

	template<class T>
	Queue<T>::~Queue()
	{
		DelAll();
	}

	template<class T>
	int Queue<T>::GetCount()
	{
		return Count;
	}

	template<class T>
	void Queue<T>::DelAll()
	{
		while (Count != 0)
			Del(1);
	}

	template<class T>
	void Queue<T>::Del(int pos)
	{
		if (pos == 0)
		{
			cout << "Input position: ";
			cin >> pos;
		}
		if (pos < 1 || pos > Count)
		{
			cout << "Incorrect position !!!\n";
			return;
		}
		int i = 1;
			
		Elem* Del = Head;
			
		while (i < pos)
		{
			Del = Del->next;
			i++;
		}
			
		Elem* PrevDel = Del->prev;
		Elem* AfterDel = Del->next;
			
		// Удаляются крайние?
		if (pos == 1)
			Head = AfterDel;
		if (pos == Count)
			Tail = PrevDel;
			
		// Удаление элемента
		delete Del;
			
		Count--;
}

	template<class T>
	void Queue<T>::Add(T n)
	{
		Elem* temp = new Elem;
		// Предыдущего нет
		temp->prev = 0;
		// Заполняем данные
		temp->data = n;
		// Следующий - бывшая голова
		temp->next = Head;
		
		// Если элементы есть?
		if (Head != 0)
		    Head->prev = temp;
		
		// Если элемент первый, то он одновременно и голова и хвост
		if (Count == 0)
		    Head = Tail = temp;
		else
		    // иначе новый элемент - головной
		    Head = temp;
}



	template<class T>
	void Queue<T>::Show()
	{
		if (Count != 0)
		{
			Elem* temp = Head;
			cout << "first element->( ";
			while (temp->next != 0)
			{
				cout << temp->data << ", ";
				temp = temp->next;
			}

			cout << temp->data << " )\n";
		}
	}

	template<class T>
	void Queue<T>::Extract()
	{
		Del(1);
	}
	

	int main() {
		srand(time(0));

		Queue<int> QU(5);			//create a queue
		for (int i = 0; i < 5; i++) {
			QU.Add(rand() % 50);
		}
		do {
			QU.Show();
			QU.Extract();			//extract first element (First In First Out)
			if (QU.GetCount() == 0) {
				cout << "there is no queue!" << endl;
			}
		} while (QU.GetCount() > 0);
		

	}