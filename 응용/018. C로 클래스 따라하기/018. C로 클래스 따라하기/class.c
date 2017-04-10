/*
 * class.c
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++�� Ŭ������ C�� ���� �ҽ� �ڵ尡 �����ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * �����ε��� �������̵��� �����Ϸ� �ܰ迡�� ó���ؾ� �մϴ�.
 * ���� ������(����������)�� ������ �� �����ϴ�.
 * ����� ���� �����ϱ� �ѵ� ����� ���� ������ �����ϹǷ� �����մϴ�.
 * 
 * �Լ� �����Ϳ��� �Ű������� �ĺ��ڸ� �� �ʿ䰡 ������
 * �������� ���� �ĺ��ڸ� ǥ�������� �����Ͻñ� �ٶ��ϴ�.
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// ����ü�� Ŭ����ó�� �����ϱ�
typedef struct Parent
{
	// this ������
	struct Parent *this;

	// ��� ����, �ʵ�
	int money_;

	// ��� �Լ�, �޼���
	void (*PrintInfo)(struct Parent *this);

	// ���� �Լ�, �׼��� �޼���
	int (*get_money)(const struct Parent *this);
	void (*set_money)(struct Parent *this, int money);
}Parent;

// ������, �Ҹ���
Parent *NewParent(int money);
void DeleteParent(struct Parent *parent_ptr);

// �Լ� �ܺ� ����
void PrintInfo_(const struct Parent *this);
int get_money_(const struct Parent *this);
void set_money_(struct Parent *this, int money);

// ��� �����ϱ� => Has A ����� ��
typedef struct Child
{
	Parent parent;

	struct Child *this;

	int ball_;

	int (*get_ball)(const struct Child *this);
	void (*set_ball)(struct Child *this, int ball);
}Child;

// ������, �Ҹ���
Child *NewChild(int money, int ball);
void DeleteChild(struct Child *child_ptr);

int get_ball_(const struct Child *this);
void set_ball_(struct Child *this, int ball);

int main()
{
	int money;
	int ball;

	system("title C�� Ŭ���� �����");

	// ������ �����ϱ�
	Parent *parent_ptr = NewParent(10000);
	
	printf("ó���� ���� ���� �Ʒ��� �����ϴ�.\n");
	parent_ptr->this->PrintInfo(parent_ptr->this);

	parent_ptr->set_money(parent_ptr, 40000);

	printf("\n��ȭ�� ���� �Ʒ��� �����ϴ�.\n");
	parent_ptr->PrintInfo(parent_ptr);

	money = parent_ptr->get_money(parent_ptr);
	printf("\n������ ���� %d���Դϴ�.\n", money);

	// �Ҹ��� �����ϱ�
	DeleteParent(parent_ptr);

	printf("--------------------------------------\n");
	Child *child_ptr = NewChild(5000, 100);

	printf("\n�ڽ��� ���� ���� �Ʒ��� �����ϴ�.\n");
	child_ptr->parent.PrintInfo((Parent *)child_ptr);

	ball = child_ptr->get_ball(child_ptr);
	printf("\n������ ���� %d���Դϴ�.\n", ball);

	DeleteChild(child_ptr);

	system("pause");
	return 0;
}

Parent * NewParent(int money)
{
	Parent *temp = (Parent *)malloc(sizeof(Parent));
	temp->money_ = money;

	// �Լ� ������ ���
	temp->this = temp;
	temp->PrintInfo = PrintInfo_;
	temp->get_money = get_money_;
	temp->set_money = set_money_;
	return temp;
}

void DeleteParent(struct Parent *parent_ptr)
{
	free(parent_ptr);
}

void PrintInfo_(const struct Parent *this)
{
	printf("���� �� : %d��\n", this->money_);
}

int get_money_(const struct Parent *this)
{
	return this->money_;
}

void set_money_(struct Parent *this, int money)
{
	this->money_ = money;
}

Child *NewChild(int money, int ball)
{
	Child *temp;
	temp = (Child *)NewParent(money);
	printf("�θ� Ŭ������ ũ�� : %d\n", _msize(temp));

	temp = (Child *)realloc(temp, sizeof(Child));
	printf("�ڽ� Ŭ������ ũ�� : %d\n", _msize(temp));
	temp->ball_ = ball;

	// �Լ� ������ ���
	temp->this = temp;
	temp->get_ball = get_ball_;
	temp->set_ball = set_ball_;
	return temp;
}

void DeleteChild(struct Child *child_ptr)
{
	// ������ �ڽ��� ���� �Ҹ��ϰ� �θ� �Ҹ�������
	// realloc() ������ �� ����� �ּ���...
	//free(child_ptr);
	//DeleteParent(&child_ptr->parent);

	// �׷��� �׳� �ڽĸ� �Ҹ��Ű�� ��
	free(child_ptr);
}

int get_ball_(const struct Child *this)
{
	return this->ball_;
}

void set_ball_(struct Child *this, int ball)
{
	this->ball_ = ball;
}