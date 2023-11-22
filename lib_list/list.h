#include <iostream>

template <class T>
class TNode {
	T data;
	TNode* next;
public:
	TNode(const TNode& node);
	TNode(T data, TNode* next = nullptr);
	//~TNode();
	int operator==(const TNode& node) const;
	TNode& operator=(const TNode& node);
	friend std::ostream& operator<<(std::ostream out, const TNode& node);
};

template <class T>
class TList {
	friend class TNode;
	TNode* head;
	TNode* tail;
	int count;
public:
	TList();
	TList(T* massData, int size);
	~TList();
	bool isEmpty();
	void push_back(T data);
	void push_front(T data);
	void insert(TNode* p, T data);
	void reset_back();
	void reset_front();
	void reset(TNode* p);
	void replace(TNode* p, T data);
	void clear();
	void insert_mass(T* mass, int size, TNode* p);
	void reset_mass(TNode* from, TNode* to);
};