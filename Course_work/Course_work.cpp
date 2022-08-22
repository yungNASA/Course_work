#define _SRT_SECURE_NO_WARNINGS

#include <string>//������ �� ��������
#include <iostream>//����-�����
#include <cstdlib>//��������� ������

using namespace std;

struct predl {
	string* data;
	predl* next;
};//�������� ��������� �����������//�������� ��������� �����������

struct mnoz {
	predl* data;
	struct mnoz* next;
	struct mnoz* prev;
};  //�������� ��������� ���������

predl* addfirst(string data)
{
	predl* P1 = (predl*)calloc(1, sizeof(predl));
	string* f = new string();
	*f = data;
	if (P1 == NULL) { std::cout << "������. ������ ������������.\n"; exit(1); }
	P1->next = NULL;
	P1->data = f;
	return P1;
}//�������� ������� �������� ������� �������� �����������, ������� ���������� ��� �����

predl* addpredl(predl* aP, string data)
{
	predl* addP, * p;
	addP = (predl*)calloc(1, sizeof(predl)); 
	if (addP == NULL) { std::cout << "������. ������ ������������.\n"; exit(1); }
	p = aP->next;
	aP->next = addP;
	addP->next = p;
	string* f = new string();
	*f = data;
	addP->data = f;
	return addP;

}//�������� �������� ����������� �� ����������

void printactP(predl* fP, predl* aP)
{
	predl* f = fP;
	int i = 1;
	while (f != NULL) {
		if (f == aP)
			cout << "������� �� ����������: " << "\t" << *(f->data) << "\n";
		f = f->next;
		i++;
	}
	printf("\n");
} //����� �������� ����������� �� ����������

void printP(predl* fP, predl* aP)
{
	predl* f = fP;
	int i = 1;
	cout << "�����������:\n";
	while (f != NULL) {
		if (f == aP)
			cout << "�������* " << i << "\t" << *(f->data) << "\n";
		else
			cout << "������� " << i << "\t" << *(f->data) << "\n";
		f = f->next;
		i++;
	}
	printf("\n");
} //����� ��������� ����������� �� ����� � ������� �������

predl* changeactP(predl* fP, predl* aP, string data)
{
	predl* change = fP;
	while (!(change == aP))
		change = change->next;
	string* f = new string();
	*f = data;
	change->data = f;
	return fP;
} //��������� �������� �������� �� ����������

void deleteallP(predl* uk)
{
	predl* a = uk;
	predl* buffer = uk;
	do {
		buffer = a->next;
		free(a);
		a = buffer;
	} while (a != NULL);
} //�������� ���� ��������� �����������

predl* delelm(predl* aP, predl* fP)
{
	predl* dell;
	dell = fP;
	while (dell->next != aP)
		dell = dell->next;
	dell->next = aP->next;
	free(aP);
	return dell;
}//�������� �������� �� ����������

predl* menuP()
{
	string data;
	predl* firstP = NULL;
	predl* lastP = NULL;
	predl* actP = NULL;
	bool begin = false;
	int choice = -1;

	while (1)
	{
		cout << "\n��������� ������: �����������\n";
		cout << "��������� ��������:\n";
		cout << "1\t������ ������\n";
		cout << "2\t������� ����������� ������\n";
		cout << "3\t��������� ����������� �� �������\n";
		cout << "4\t���������� ������� ��������� � ������ �����������\n";
		cout << "5\t���������, ��������� �� ��������� � ����� �����������\n";
		cout << "6\t����������� ������� ��������� �����\n";
		cout << "7\t������� ����� �� ����������\n";
		cout << "8\t������� ����� �� ����������\n";
		cout << "9\t����� ����� �� ����������\n";
		cout << "10\t�������� ����� �� ����������\n";
		cout << "11\t�������� ����� �� ����������\n";
		cout << "12\t������� �����������\n";
		cout << "13\t��������� ������ � ������������\n";

		cin >> choice;
		system("cls");
		if ((choice > 13) || (choice < 1))
			cout << "������� ����� �� 1 �� 13\n\n";
		else if
			((begin == false) && (choice != 1))
			cout << "���������� ������ ������. ����� 1.\n\n";
		else
			switch (choice)
			{
			case 1:
				cout << "������ ������\n\n";
				begin = true;
				break;
			case 2: 
			{
				if (firstP == NULL)
				{
					cout << "����������� ��� �����\n";
					break;
				}
				deleteallP(firstP);
				actP = lastP = firstP = NULL;
				cout << "����������� �������";
				break;
			}
			case 3:
			{
				if (firstP == NULL)
					cout << "����������� �����\n";
				else
					cout << "����������� �� �����\n";
				break;
			}
			case 4:
			{
				if (firstP == NULL)
				{
					cout << "����������� �����\n";
					break;
				}
				actP = firstP;
				cout << " ������� ��������� ���������� � ������ �����������\n";
				break;
			}
			case 5:
			{
				if (firstP == NULL)
				{
					cout << "����������� �����\n";
					break;
				}
				if ((actP->next) == NULL)
					cout << "��������� ��������� � ����� �����������\n";
				else
					cout << "��������� ��������� �� � ����� �����������\n";
				break;
			}
			case 6:
			{
				if (firstP == NULL)
				{
					cout << "����������� �����\n";
					break;
				}
				if (actP->next) {
					actP = actP->next;
					cout << "��������� ���������� �����\n";
				}
				else
					cout << "��������� ��������� � ����� �����������\n";
				break;
			}
			case 7:
			{
				if (firstP == NULL)
				{
					cout << "����������� �����\n";
					break;
				}
				if (actP->next) 	printactP(firstP, actP->next); else cout << "�� ���������� ��� ��������\n";
				break;
			}
			case 8:
			{
				if (firstP == NULL)
				{
					printf("����������� �����\n");
					break;
				}
				if (actP->next) 	actP = delelm(actP->next, firstP); else cout << "�� ���������� ��� ��������\n";
				break;
			}
			case 9:
			{
				if (firstP == NULL)
				{
					printf("����������� �����\n");
					break;
				}
				if (actP->next) {
					cout << "������ �����: " << *(actP->next->data) << "\n";
					actP = delelm(actP->next, firstP);
				}
				else cout << "�� ���������� ��� ��������\n";
				break;
			}
			case 10:
			{
				if (firstP == NULL)
				{
					printf("����������� �����\n");
					break;
				}
				if (actP->next) {
					cout << "������� ������\n";
					cin >> data;
					firstP = changeactP(firstP, actP->next, data);
				}
				else cout << "�� ���������� ��� ��������\n";
				break;
			}
			case 11:
			{	cout << "������� ������\n";
			cin >> data;
			if (firstP == NULL)
			{
				lastP = actP = firstP = addfirst(data);
			}
			else
			{
				actP->next = addpredl(actP, data);
				if (actP->next == NULL) lastP = actP;
			}
			break;
			}
			case 12:
			{	printP(firstP, actP); break; }
			case 13:
				return firstP;
			}
		if(firstP) printP(firstP, actP);
	}
}//���� ��� ������ � ������������


int sravP(predl* a, predl* b)
{
	while (a != NULL) {
		if (*(a->data) != *(b->data)) return 0;
		a = a->next;
		b = b->next;
	}
	return 1;
} //��������� ���� �����������

void printznachP(predl* uk)
{
	predl* a = uk;
	while (a != NULL) {
		cout << *(a->data) << "\t";
		a = a->next;
	}
	printf("\n");
} //����� �������� ������ ��������� �� �����

mnoz* addfirstM(predl* data)
{
	mnoz* a;
	a = (mnoz*)malloc(sizeof(mnoz));
	if (a == NULL) { std::cout << "������ - ������ ������������\n"; exit(1); }
	else {
		a->data = data;
		a->next = NULL;
		a->prev = NULL;
	}
	return a;
} //���������� ������� �������� ���������, ������� ���������� ��� �����

mnoz* addmnoz(mnoz* a, predl* d)
{
	while (a->next != NULL) {
		a = a->next;
	}
	mnoz* addedmnoz = (mnoz*)malloc(sizeof(mnoz));
	if (addedmnoz == NULL) { std::cout << "������ - ������ ������������\n"; exit(1); }
	else {
		addedmnoz->next = NULL;
		addedmnoz->data = d;
		addedmnoz->prev = a;
		a->next = addedmnoz;
	}
	return a->next;
} //�������� ������� � ����������� ��������� ���������

void printmnoz(mnoz* a, mnoz* b)
{
	int i = 1;
		printf("���������:\n");
		while (a != NULL) {
			printf("�������[%d] ", i);
			printznachP(a->data);
			a = a->next;
			i++;
		}
	printf("\n");
} //����� ��������� �� �����

int lenghtM(mnoz* uk)
{
	int len = 0;
	if (uk == NULL) return 0;
	else {
		while (uk != NULL) {
			uk = uk->next;
			len++;
		}
		return len;
	}
} //������� ���������� ��������� ���������

void deleteallM(mnoz* uk)
{
	mnoz* a = uk;
	mnoz* buffer = uk;
	do {
		buffer = a->next;
		free(a);
		a = buffer;
	} while (a != NULL);
} //�������� ���� ��������� ���������

int sravM(mnoz* a, predl* b)
{
	while (a != NULL) {
		if (sravP(a->data, b)) return 1;
		a = a->next;
	}
	return 0;
} //��������� ��������� ��������� � ������������

mnoz* deletefirstM(mnoz* e)
{
	if (!(e->next)) return NULL;
	mnoz* buffer = e->next;
	free(e);
	e = buffer;
	if (!(buffer))
		e->prev = NULL;
	return e;
} //�������� ������� �������� ���������

mnoz* deletethisM(mnoz* e, mnoz* last, predl* b)
{
	mnoz* head = e;
	if (sravP(e->data, b)) {
		cout << "��������� ����������� ������� �� ���������\n";
		return deletefirstM(e);
	}
	if (sravP(last->data, b)) {
		last->prev->next = NULL;
		free(last);
		cout << "��������� ����������� ������� �� ���������\n";
		return e;
	}
	while (e != NULL) {
		if (sravP(e->data, b)) {
			mnoz* prev = e->prev;
			mnoz* next = e->next;
			e->next->prev = prev;
			e->prev->next = next;
			free(e);
			cout << "��������� ����������� ������� �� ���������\n";
			return head;
		}
		e = e->next;
	}
	cout << "��������� ����������� ����������� � ���������\n";
	return head;
}//�������� ���������� �������� ��������� ��� ��� �������

mnoz* menuM()
{
	int number = -1;
	int mode = 0;
	predl* takeP = 0;//��������� �� �����������
	mnoz* firstM = NULL; //��������� �� ������ ������� ���������
	mnoz* lastM = NULL; //��������� �� ��������� ������� ���������
	while (1) {
		cout << "\n��������� ������: ���������\n";
		cout << "��������� ��������:\n";
		cout << "1.\t������ ������ � ����������\n";
		cout << "2.\t������� ��������� ������\n";
		cout << "3.\t��������� ��������� �� �������\n";
		cout << "4.\t������� ��������� ����������� �� ���������\n";
		cout << "5.\t����� �����-���� ����������� �� ���������\n";
		cout << "6.\t�������� ����������� � ���������\n";
		cout << "7.\t��������� ����������� �� �������������� ���������\n";
		cout << "8.\t������� ���������\n";
		cout << "9.\t��������� ������ � ����������\n\n";
		cout << "101.\t��������� ������ ���������\n\n";
		cout << "�������� ����� ����:\n";

		cin >> number;
		system("cls"); 
		if (number == 101) return firstM;
		if (number == 1 && mode == 1)
			cout << "�� ��� ������ ������ � ����������.\n";
		if ((number == 1) && (mode == 0)) {
			mode = 1;
			cout << "������ � ���������� ������\n";
		}
		if (mode == 1) 
		{
			if (number == 2)
			{
				if (lenghtM(firstM)) {
					deleteallM(firstM);
					lastM = NULL;
					firstM = NULL;
					cout << "��������� �������.\n";
				}
				else cout << "��������� �����.\n";
			}
			if (number == 3)
				if (lenghtM(firstM))
					cout << "��������� �� �����\n";
				else
					cout << "��������� �����\n";
			if (number == 4)
			{
				if (lenghtM(firstM))  firstM = deletethisM(firstM, lastM, menuP());
				else cout << "��������� �����.\n";
			}
			if (number == 5) 
			{
				if (lenghtM(firstM))
				{
					takeP = firstM->data;
					cout << "�������� ������� ����������� ����� = ";
					printznachP(takeP);
					if (lenghtM(firstM) > 1)
						firstM = deletefirstM(firstM);
					else {
						deleteallM(firstM);
						lastM = NULL;
						firstM = NULL;
					}
				}
				else cout << "��������� �����.\n";
			}
			if (number == 6) 
			{
				if (lenghtM(firstM))
				{
					predl* read = menuP();
					if (sravM(firstM, read))
						cout << "������ ����������� ��� ���� � ���������.\n";
					else lastM = addmnoz(firstM, read);
				}
				else
				{
					firstM = addfirstM(menuP());
					lastM = firstM;
				}
			}
			if (number == 7) 
			{
				if (lenghtM(firstM))
					if (sravM(firstM, menuP()))
						cout << "������ ����������� ������������ � ���������.\n\n";
					else
						cout << "������� ����������� � ��������� ���.\n\n";
				else cout << "��������� �����.\n";
			}
			if ((number == 8))
				if (lenghtM(firstM)) printmnoz(firstM, lastM); else cout << "��������� �����\n";
			if (number == 9) 
			{
				mode = 0;
				if (lenghtM(firstM)) {
					deleteallM(firstM);
					lastM = NULL;
					firstM = NULL;
				}
				cout << "������ � ���������� ���������.\n";
			}
			if (number > 9 || number < 1)
				cout << "������� ����� �� 1 �� 9" << '\n';
			if (number == 101) return firstM;
		}
		else cout << "�� �� ������ ������ � ����������. ����� 1.\n";
		if ((number!=8)&&(mode==1)&&(lenghtM(firstM)))
			printmnoz(firstM, lastM);
	}
} //���� ��� ������ � ����������

int main()
{
	setlocale(LC_ALL, "Russian");
	menuM();
	return 0;

}
