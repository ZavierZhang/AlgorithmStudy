#pragma once
struct Node
{
	Node()
	{
		value = 0;
		next = NULL;
	}
	int value;
	Node* next;
};
class CLinkList
{
public:
	CLinkList();
	~CLinkList();
	Node* GetHead();
	//Ìí¼Ó½Úµã
	void AddNode(int value);
	//
private:
	Node* m_header;

};

