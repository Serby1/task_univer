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

queue* result(queue*& h, queue*& t) {
	queue* h1 = NULL; //инициализация
	queue* t1 = NULL;
	queue* res1 = NULL;
	queue* res2 = NULL;
	while (h)
	{
		int x = pop(h, t); //удаляем первый элемент
		push(res1, res2, x); //записываем в результат
		while (h)
		{
			int y = pop(h, t); //удаляем элемент 
			if (x != y) push(h1, t1, y); //записываем в новую очередь
		}
		h = h1;
		t = t1;
		h1 = NULL;
		t1 = NULL;
	}

	return res1;

}
int main()
{
	ifstream in("input4.txt");
	ofstream out("output4.txt");
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