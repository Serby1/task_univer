#include<fstream>
#include<string>
using namespace std;

struct queue
{
	string inf;
	queue* next;
};

void push(queue*& h, queue*& t, string x)
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

string pop(queue*& h, queue*& t)
{ //�������� �������� �� �������
	queue* r = h; //������� ��������� �� ������
	string i = h->inf; //��������� �������� ������
	h = h->next; //�������� ��������� �� ��������� �������
	if (!h) //���� ������� ��������� ������� �� �������
		t = NULL;
	delete r; //������� ������ �������
	return i;
}

queue* result(queue*& h, queue*& t) {
	queue* h1 = NULL; //�������������
	queue* t1 = NULL;
	queue* res1 = NULL;
	queue* res2 = NULL;
	while (h)
	{
		string x = pop(h, t); //������� ������ �������
		push(res1, res2, x); //���������� � ���������
		while (h)
		{
			string y = pop(h, t); //������� ������� 
			if (x != y) push(h1, t1, y); //���������� � ����� �������
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
	ifstream in("input5.txt");
	ofstream out("output5.txt");
	queue* head = NULL; //�������������
	queue* teil = NULL;
	string x;
	while (in.peek() != EOF)//��������� ����
	{
		in >> x;
		push(head, teil, x);
	}
	queue* res = result(head, teil);
	while (res)
		out << pop(res, teil) << " ";
	string a = "";
	in.close();
	out.close();
}