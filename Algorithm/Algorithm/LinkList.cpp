#include "stdafx.h"
#include "LinkList.h"


CLinkList::CLinkList()
{
	m_header = NULL;
}


CLinkList::~CLinkList()
{

}

Node* CLinkList::GetHead()
{
	return m_header;
}
void CLinkList::AddNode(int value)
{
	Node* pNode = new Node;
	pNode->value = value;
	pNode->next = NULL;
	if (NULL == m_header)
	{
		m_header = pNode;
	}
	else
	{
		Node* q = m_header;
		while (NULL != q->next)
		{
			q = q->next;
		}
		q->next = pNode;
	}
}
