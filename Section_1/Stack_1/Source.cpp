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

stack* result(stack*& h) {
	stack* even = NULL; //�������������
	stack* odd = NULL;

	while (h)
	{
		int x = pop(h); //������� ������ �������
		if (x % 2 == 0)
		{
			push(even, x); //���������� � ���� � ������� ����������
		}
		else
			push(odd, x);//���������� � ���� � �� ������� ����������	
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
	reverse(h); //�������������� �������������� ����
	return h;
}

int main()
{
	ifstream in("input1.txt");
	ofstream out("output1.txt");
	stack* head = NULL; //�������������
	int x;
	while (in.peek() != EOF)//��������� ����
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
