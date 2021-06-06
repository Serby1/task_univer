#include<fstream>
using namespace std;

struct stack {
	int inf;
	stack* next;

};

void push(stack*& h, int x) {//�������
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h) { //��������
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}
void reverse(stack*& h) { //"���������"�����
	stack* head1 = NULL; //������������� ��������� �����
	while (h) //���� ���� �� ����
		push(head1, pop(h)); //������������ �� ������ ����� � ������
	h = head1; //�������������� ���������
}

stack* result(stack*& h, int k) {
	stack* h1 = NULL; //�������������
	int min = INT16_MAX;//����������� ������������ ������� ���� int
	while (h)// ����� �������� � �����
	{
		int x = pop(h); //������� ������ �������
		if (x < min)
		{
			min = x;
		}
		push(h1, x);
	}
	while (h1)
	{
		int x = pop(h1); //������� ������ �������
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
	reverse(h); //�������������� �������������� ����
	return h;
}

int main()
{
	ifstream in("input2.txt");
	ofstream out("output2.txt");
	stack* head = NULL; //�������������
	int k = 0;//��������� ����� ������ ����������� ����������
	int x;
	while (in.peek() != EOF)//��������� ����
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
