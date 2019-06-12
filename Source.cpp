#include <iostream>
using namespace std;

typedef char elementtype;
#define mxl 10

struct QUEUE {
	elementtype elements[mxl];
	int front;
	int rear;
};
int ADDONE(int i) {
	return i % mxl + 1;
}
void MAKENULL(QUEUE& Q) {
	Q.front = 1;
	Q.rear = mxl;
}
bool EMPTY(QUEUE& Q) {
	if (ADDONE(Q.rear) == Q.front)
		return true;
	return false;
}

elementtype FRONT(QUEUE& Q) {
	if (EMPTY(Q)) {
		cout << "queue is empty" << endl;
		return NULL;
	}
	else
		return Q.elements[Q.front];

}
void ENQUEUE(elementtype x, QUEUE& Q) {
	if (ADDONE(ADDONE(Q.rear)) == Q.front) {
		cout << "queue is overflow" << endl;
		return;
	}
	else {
		Q.rear = ADDONE(Q.rear);
		Q.elements[Q.rear] = x;
	}
}
void DEQUEUE(QUEUE& Q) {
	if (EMPTY(Q)) {
		cout << "queue is empty" << endl;
		return;
	}
	else {
		Q.front = ADDONE(Q.front);
	}
}

int main()
{
	QUEUE Q = QUEUE();
	char c;
	MAKENULL(Q);
	cin >> c;

	while (c != '=') {
		ENQUEUE(c, Q);
		cin >> c;
	}

	DEQUEUE(Q);
	DEQUEUE(Q);
	ENQUEUE('<', Q);

	while (!EMPTY(Q)) {
		printf("%c,", FRONT(Q));
		DEQUEUE(Q);
	}
	cout << endl;

	system("pause");
	return 0;
}
