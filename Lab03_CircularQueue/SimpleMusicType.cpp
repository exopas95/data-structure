#include "SimpleMusicType.h"

bool SimpleMusicType::operator== (const SimpleMusicType &obj)
{
	return (this->m_sID==obj.m_sID);
}
bool SimpleMusicType::operator> (const SimpleMusicType &obj)
{
	return (this->m_sID>obj.m_sID);
}

bool SimpleMusicType::operator< (const SimpleMusicType &obj)
{
	return (this->m_sID<obj.m_sID);
}

bool SimpleMusicType::operator>= (const SimpleMusicType &obj)
{
	return (this->m_sID>=obj.m_sID);
}

bool SimpleMusicType::operator<= (const SimpleMusicType &obj)
{
	return (this->m_sID<=obj.m_sID);
}
