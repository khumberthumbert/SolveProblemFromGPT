#include "contact.h"

typedef struct ContactNode {
	CONTACT data;
	struct ContactNode* prev;
	struct ContactNode* next;
} ContactNode;