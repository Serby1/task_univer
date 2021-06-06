#include<fstream>
using namespace std;

struct stack {
	int inf;
	stack* next;

};

void push(stack*& h, int x) {//вставка
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h) { //удаление
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}
void reverse(stack*& h) { //"обращение"стека
	stack* head1 = NULL; //инициализация буферного стека
	while (h) //пока стек не пуст
		push(head1, pop(h)); //переписываем из одного стека в другой
	h = head1; //переобозначаем указатели
}

stack* result(stack*& h) {
	stack* even = NULL; //инициализация
	stack* odd = NULL;

	while (h)
	{
		int x = pop(h); //удаляем первый элемент
		if (x % 2 == 0)
		{
			push(even, x); //записываем в стек с четными элементами
		}
		else
			push(odd, x);//записываем в стек с не четными элементами	
	}
	while (even)
	{
		int x = pop(even);
		push(h, x);
	}
	while (odd)
	{
		int x = pop(odd);
		push(h, x);
	}
	reverse(h); //переворачиваем результирующий стек
	return h;
}

int main()
{
	ifstream in("input1.txt");
	ofstream out("output1.txt");
	stack* head = NULL; //инициализация
	int x;
	while (in.peek() != EOF)//заполняем стек
	{
		in >> x;
		push(head, x);
	}
	stack* res = result(head);
	while (res)
		out << pop(res) << " ";

	in.close();
	out.close();
}
