#include <iostream>
typedef char nametype[20];
struct celltype {
	nametype element;
	celltype* next;
};
const int DICT_SIZE = 5;
typedef celltype* DICTIONARY[DICT_SIZE];

//хеш-функція
int hash(nametype x) {
	int sum = 0;
	for (unsigned int i = 0; i < strlen(x); i++)
		sum += (int)x[i];

	return sum % (DICT_SIZE);
}

void MAKENULL(DICTIONARY A) {
	for (int i = 0; i < DICT_SIZE - 1; i++)
		A[i] = NULL;
}

bool MEMBER(nametype x, DICTIONARY A) {
	celltype* current;
	current = A[hash(x)];

	while (current != NULL) {
		if (current->element == x)
			return true;
		else
			current = current->next;
		return false;
	}
}


void INSERT(nametype x, DICTIONARY * A) {
	int bucket;
	celltype* oldheader;
	celltype* newheader = new celltype;
	*newheader->element = *x;
	

	if (MEMBER(x, *A) == false) {
		bucket = hash(x);
		oldheader = *A[bucket];
		newheader->next = oldheader;
		//celltype *  A[bucket] = new celltype ;
		*A[bucket] = newheader;
		
	}
}


void DELETE(nametype x, DICTIONARY A) {
	int bucket;
	celltype* current = new celltype;

	bucket = hash(x);
	if (A[bucket] != NULL) {

		if (A[bucket]->element == x)//перший елемент
			A[bucket] = A[bucket]->next;

		else
			current = A[bucket];
		while (current->next != NULL) {
			if (current->next->element == x) {
				current->next = current->next->next;
				return;
			}
			else
				current = current->next;
		}
	}
}
