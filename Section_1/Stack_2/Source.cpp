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

stack* result(stack*& h, int k) {
	stack* h1 = NULL; //инициализация
	int min = INT16_MAX;//присваиваем максимальное значени типа int
	while (h)// поиск минимума в стеке
	{
		int x = pop(h); //удаляем первый элемент
		if (x < min)
		{
			min = x;
		}
		push(h1, x);
	}
	while (h1)
	{
		int x = pop(h1); //удаляем первый элемент
		if (x == min)
		{
			push(h, k);
			push(h, x);
		}
		else
		{
			push(h, x);
		}
	}
	reverse(h); //переворачиваем результирующий стек
	return h;
}

int main()
{
	ifstream in("input2.txt");
	ofstream out("output2.txt");
	stack* head = NULL; //инициализация
	int k = 0;//вставляем перед каждым минимальным элекментом
	int x;
	while (in.peek() != EOF)//заполняем стек
	{
		in >> x;
		push(head, x);
	}
	stack* res = result(head, k);
	while (res)
		out << pop(res) << " ";

	in.close();
	out.close();
}
