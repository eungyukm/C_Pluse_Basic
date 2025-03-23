#include "unique_ptr_03.h"
#include <memory>
#include <iostream>
using namespace std;

// unique_ptr�� C++���� �����ϴ� ����Ʈ ��������
// �� �����Դϴ�.
// ���� ������(single ownership) �����
// �޸� ���� �����Դϴ�.
// �Ϲ����� �����ʹ� new�� delete�� ���� ��������
// �޸� ������ �ؾ�������,
// unique_ptr�� �ڵ� �޸� ������ ����
// �޸� ������ �����մϴ�.
int main()
{
	unique_ptr<int> ptr = make_unique<int>(10);
	cout << *ptr << endl;
}