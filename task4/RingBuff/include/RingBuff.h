#include <ostream>

struct Node {
        int value = NULL;
        Node* next;
    };
    inline Node* head;
    inline Node* tmp;
	
class List {
public:
	List();

	void init(int length);

	void Print(std::ostream& os);

	void add(char x);
};
