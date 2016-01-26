#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t* temp = NULL;
	list_t* next = head->next;
	//if the index of new_element is smaller than head, replace head
	if (new_element->index < head->index) {
		new_element->next = head;
		head = new_element;
		return head;
	}
	while (new_element->index > next->index) {
		temp = next;
		next = next->next;
		if (next == NULL) {
			temp->next = new_element;
			new_element->next = NULL;
			return head;
		}
	}
	next->next = temp;
	next->next = new_element;
	new_element->next = temp;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
	list_t* prev = NULL;
	list_t* next = NULL;
	list_t* temp = head;
	if (head->next == NULL) return head;

	while (temp->next != NULL) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = temp;
	head->next = prev;

	return head;
}

