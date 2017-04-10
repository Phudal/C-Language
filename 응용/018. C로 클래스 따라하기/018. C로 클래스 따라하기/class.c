/*
 * class.c
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++의 클래스를 C로 만든 소스 코드가 적혀있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * 오버로딩과 오버라이딩은 컴파일러 단계에서 처리해야 합니다.
 * 따라서 다형성(폴리모피즘)은 구현할 수 없습니다.
 * 편법을 쓰면 가능하긴 한데 편법은 예외 사항을 무시하므로 생략합니다.
 * 
 * 함수 포인터에는 매개변수의 식별자를 쓸 필요가 없지만
 * 가독성을 위해 식별자를 표시했으니 참고하시기 바랍니다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 구조체를 클래스처럼 구현하기
typedef struct Parent
{
	// this 포인터
	struct Parent *this;

	// 멤버 변수, 필드
	int money_;

	// 멤버 함수, 메서드
	void (*PrintInfo)(struct Parent *this);

	// 접근 함수, 액세스 메서드
	int (*get_money)(const struct Parent *this);
	void (*set_money)(struct Parent *this, int money);
}Parent;

// 생성자, 소멸자
Parent *NewParent(int money);
void DeleteParent(struct Parent *parent_ptr);

// 함수 외부 선언
void PrintInfo_(const struct Parent *this);
int get_money_(const struct Parent *this);
void set_money_(struct Parent *this, int money);

// 상속 실험하기 => Has A 관계로 됨
typedef struct Child
{
	Parent parent;

	struct Child *this;

	int ball_;

	int (*get_ball)(const struct Child *this);
	void (*set_ball)(struct Child *this, int ball);
}Child;

// 생성자, 소멸자
Child *NewChild(int money, int ball);
void DeleteChild(struct Child *child_ptr);

int get_ball_(const struct Child *this);
void set_ball_(struct Child *this, int ball);

int main()
{
	int money;
	int ball;

	system("title C로 클래스 만들기");

	// 생성자 따라하기
	Parent *parent_ptr = NewParent(10000);
	
	printf("처음에 가진 돈은 아래와 같습니다.\n");
	parent_ptr->this->PrintInfo(parent_ptr->this);

	parent_ptr->set_money(parent_ptr, 40000);

	printf("\n변화된 돈은 아래와 같습니다.\n");
	parent_ptr->PrintInfo(parent_ptr);

	money = parent_ptr->get_money(parent_ptr);
	printf("\n가져온 돈은 %d원입니다.\n", money);

	// 소멸자 따라하기
	DeleteParent(parent_ptr);

	printf("--------------------------------------\n");
	Child *child_ptr = NewChild(5000, 100);

	printf("\n자식이 가진 돈은 아래와 같습니다.\n");
	child_ptr->parent.PrintInfo((Parent *)child_ptr);

	ball = child_ptr->get_ball(child_ptr);
	printf("\n가져온 공은 %d개입니다.\n", ball);

	DeleteChild(child_ptr);

	system("pause");
	return 0;
}

Parent * NewParent(int money)
{
	Parent *temp = (Parent *)malloc(sizeof(Parent));
	temp->money_ = money;

	// 함수 포인터 등록
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
	printf("현재 돈 : %d원\n", this->money_);
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
	printf("부모 클래스의 크기 : %d\n", _msize(temp));

	temp = (Child *)realloc(temp, sizeof(Child));
	printf("자식 클래스의 크기 : %d\n", _msize(temp));
	temp->ball_ = ball;

	// 함수 포인터 등록
	temp->this = temp;
	temp->get_ball = get_ball_;
	temp->set_ball = set_ball_;
	return temp;
}

void DeleteChild(struct Child *child_ptr)
{
	// 원래는 자식을 먼저 소멸하고 부모를 소멸하지만
	// realloc() 때문에 이 방법이 최선임...
	//free(child_ptr);
	//DeleteParent(&child_ptr->parent);

	// 그래서 그냥 자식만 소멸시키면 됨
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