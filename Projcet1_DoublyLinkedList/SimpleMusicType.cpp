#include "SimpleMusicType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool SimpleMusicType::operator== (const SimpleMusicType &obj)
{
	return (this->m_sID==obj.m_sID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool SimpleMusicType::operator> (const SimpleMusicType &obj)
{
	return (this->m_sID>obj.m_sID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool SimpleMusicType::operator< (const SimpleMusicType &obj)
{
	return (this->m_sID<obj.m_sID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool SimpleMusicType::operator>= (const SimpleMusicType &obj)
{
	return (this->m_sID>=obj.m_sID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool SimpleMusicType::operator<= (const SimpleMusicType &obj)
{
	return (this->m_sID<=obj.m_sID);
}

