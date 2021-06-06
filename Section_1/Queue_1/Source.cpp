#include<fstream>
using namespace std;

struct queue
{
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x)
{ //������� �������� � �������
	queue* r = new queue; //������� ����� �������
	r->inf = x;
	r->next = NULL; //������ ���������
	if (!h && !t) { //���� ������� �����
		h = t = r; //��� � ������ � �����
	}
	else {
		t->next = r; //r - ��������� ��� ������
		t = r; //������ r - �����
	}
}

int pop(queue*& h, queue*& t)
{ //�������� �������� �� �������
	queue* r = h; //������� ��������� �� ������
	int i = h->inf; //��������� �������� ������
	h = h->next; //�������� ��������� �� ��������� �������
	if (!h) //���� ������� ��������� ������� �� �������
		t = NULL;
	delete r; //������� ������ �������
	return i;
}

queue* result(queue*& h, queue*& t)
{
	queue* h1 = NULL;//������������� �������� ��������
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
	queue* head = NULL; //�������������
	queue* teil = NULL;
	int x;
	while (in.peek() != EOF)//��������� ����
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