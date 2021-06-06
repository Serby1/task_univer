#include<fstream>
using namespace std;

struct queue
{
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x)
{ //вставка элемента в очередь
	queue* r = new queue; //создаем новый элемент
	r->inf = x;
	r->next = NULL; //всегда последний
	if (!h && !t) { //если очередь пуста
		h = t = r; //это и голова и хвост
	}
	else {
		t->next = r; //r - следующий для хвоста
		t = r; //теперь r - хвост
	}
}

int pop(queue*& h, queue*& t)
{ //удаление элемента из очереди
	queue* r = h; //создаем указатель на голову
	int i = h->inf; //сохраняем значение головы
	h = h->next; //сдвигаем указатель на следующий элемент
	if (!h) //если удаляем последний элемент из очереди
		t = NULL;
	delete r; //удаляем первый элемент
	return i;
}

queue* result(queue*& h, queue*& t)
{
	queue* h1 = NULL;//инициализация буферных очередей
	queue* t1 = NULL;
	queue* h2 = NULL;
	queue* t2 = NULL;
	int x;
	while (h)
	{
		x = pop(h, t);
		if (x < 0)
		{
			push(h1, t1, x);
		}
		else
		{
			push(h2, t2, x);
		}
	}
	while (h1)
	{
		x = pop(h1, t1);
		push(h, t, x);
	}
	while (h2)
	{
		x = pop(h2, t2);
		push(h, t, x);
	}
	return h;
}
int main()
{
	ifstream in("input3.txt");
	ofstream out("output3.txt");
	queue* head = NULL; //инициализация
	queue* teil = NULL;
	int x;
	while (in.peek() != EOF)//заполняем стек
	{
		in >> x;
		push(head, teil, x);
	}
	queue* res = result(head, teil);
	while (res)
		out << pop(res, teil) << " ";

	in.close();
	out.close();
}