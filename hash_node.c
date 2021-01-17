 #include <stdio.h>
 #include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 100;

struct node {
	int key;
	int value;
	
	struct node* next;
	
};

struct bucket {
	struct node* head;
	int count;
};

void init() {
	hashTable = (struct bucket*)malloc(SIZE * sizeof(struct node));
	int i;
	for (i = 0; i < SIZE; i++) {
		hashTable[i].count = 0;
		hashTable[i].head = NULL;
	}
}


struct node* createNode(int key, int value) {
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->key = key;
	newNode->value = value;

	newNode->next = NULL;


	return newNode;
}


int hash(int key) {

	return key % SIZE;
}

void insert(int key, int value) { //호출될때 전달된 kew, value 를  가진 노드를 해시맵 안에 넣는 함수
	int hashIndex = hash(key);

	struct node* newNode = createNode(key, value);

	if (hashTable[hashIndex].count ==0) {
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count = 1;
	}
	else {
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;

	}
	return;
}

void remove(int key) {
	int hashIndex = hash(key);
	struct node* node;
	struct node* trace = NULL;
	node = hashTable[hashIndex].head;

	if (node == NULL) {
		printf("비어있음"); return;
	}
	while (node != NULL) {
		if (node->key = key) {
			if (node = hashTable[hashIndex].head) {

				hashTable[hashIndex].head = node->next;

			}
			else {
				trace->next = node->next;
			}
			hashTable[hashIndex].count--;
			free(node);
			return;



		}
		trace = node;
		node = node->next;

		printf("/n 찾는 값 없음");
		return;

	}
}

void search(int key) {
	int hashIndex = hash(key);
	struct node* node = hashTable[hashIndex].head;
	if (node == NULL) {
		printf("/n 찾는 값 없음");
		return;
	}
	while (node != NULL) {
		if (node->key =key) {
			printf("key = %d // value=%d", node->key, node->value);
			return;

		}
		node = node->next;
	}
}

void display() {
	struct node* node;
	int i = 0;
	for (int i = 0; i < SIZE; i++) {

		node = hashTable[i].head;
		printf("bucket[%d] : ", i);
		while (node != NULL) {
			printf("key : %d  value : %d", node->key, node->value);
			node = node->next;
		}
		printf("\n");
	}
	return;
}

int main() {

	init();
	insert(0, 1);
	insert(1, 10);

	insert(11, 10);
	insert(21, 10);
	insert(31, 10);
	insert(25, 33);
	insert(200, 55);

	display();
	


	remove(11);
	remove(25);
	display();


	printf("/////////////////");


	search(21);
	return 0 ;
}