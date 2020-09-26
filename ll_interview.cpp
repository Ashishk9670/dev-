#include<bits/stdc++.h>
using namespace std;

class LinkListNode
{
public:
	int val;
	LinkListNode* next;

	LinkListNode() {

	}
	LinkListNode(int data) {
		this->val = data;
		this->next = nullptr;
	}


	LinkListNode* addNodeAtEnd(LinkListNode* head, int data) {
		if (head == nullptr) {
			LinkListNode* temp = new LinkListNode(data);
			head = temp;
		}
		else {
			LinkListNode* temp = head;
			while (temp->next != nullptr)
				temp = temp->next;

			temp->next = new LinkListNode(data);
		}
		return head;
	}

	void ll_is_evenNodes_oddNodes(LinkListNode* head) {
		LinkListNode* temp = head;
		while (temp->next != nullptr and temp) {
			temp = temp->next;
		}
		if (temp) {
			cout << "odd nodes\n";

		}
		else cout << "even node\n";
		return ;
	}
	void insert_node_InSortedLL(LinkListNode* head, int data) {
		LinkListNode* newnode = new LinkListNode(data);
		if (head->val >= data or head == nullptr) {
			newnode->next = head;
			head = newnode;
		}

		LinkListNode* cur = head;
		while (cur->next->val < data and cur->next != nullptr) {
			cur = cur->next;
		}

		newnode->next = cur->next;
		cur->next = newnode;
	}

	int countNodes(LinkListNode* head) {
		LinkListNode* temp = head;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	int find_kth_node_From_end(LinkListNode* head, int k) {
		LinkListNode* temp = head, *kthNode = head;
		if (k > countNodes(head)) {
			cout << "insufficint nodes\n";
			return 0;
		}
		for (int i = 0; i < k - 1; i++) {
			temp = temp->next;
		}

		while (temp->next != nullptr) {
			temp = temp->next;
			kthNode = kthNode->next;
		}

		return kthNode->val;
	}

	void printLinklist(LinkListNode* head) {
		LinkListNode* temp = head;
		while (temp != nullptr) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void printRevereseLinkList(LinkListNode* head) {
		if (head == nullptr)
			return ;
		printRevereseLinkList(head->next);
		cout << head->val << " ";
	}

	LinkListNode* middleOfLinkList(LinkListNode* head) {
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		while (fast != nullptr and fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	LinkListNode* deleteMiddleofLinkedList(LinkListNode* head) {
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		LinkListNode* prev = slow;

		while (fast != nullptr and fast->next != nullptr) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = slow->next;
		delete(slow);
		return head;
	}

	LinkListNode* deleteLL(LinkListNode* head) {
		LinkListNode* prev = head;
		head = head->next;
		if (head == nullptr) {
			delete prev;
		}

		while (head != nullptr) {
			delete(prev);
			prev = head;
			head = head->next;
		}
		return head;
	}

	LinkListNode* reverseLinkedList(LinkListNode* head) {
		LinkListNode* cur = head, *next = nullptr, *prev = nullptr;

		while (cur != nullptr) {
			// write in order its important
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
		return head;
	}

	LinkListNode* reversell_recursive(LinkListNode* head) {
		// empty list or single element
		if (head == nullptr or head->next == nullptr)
			return head;

		LinkListNode* second = head->next;
		// disconnect the rest of list
		head->next = nullptr;
		LinkListNode* reverse_rest = reversell_recursive(second);
		second->next = head;
		return reverse_rest;
	}

	LinkListNode* reverse_ll_in_pairs_iteraticve(LinkListNode* head) {
		LinkListNode* temp1 = nullptr, *temp2 = nullptr, *cur = head;
		while (cur != nullptr and cur->next != nullptr  ) {
			if (temp1 != nullptr) {
				temp1->next->next = cur->next;
			}
			temp1 = cur->next;
			cur->next = cur->next->next;
			temp1->next = cur;
			if (temp2 == nullptr) {
				temp2 = temp1;
			}
			cur = cur->next;
		}
		return temp2;
	}

	bool detectCycle(LinkListNode* head) {
		// Floyd's algorithm or hare and tortoise algo
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		while (fast != nullptr and fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}


	// REMOVE LOOP
	// 1--IF LOOP IS found,MOVE SLOW TO HEAD OF LL
	// 2--MOVE SLOW AND FAST BY ONE STEP TILL SLOW->NEXT !=FAST->NEXT
	// 3--NOW ASSIGN FAST ->NEXT =nullptr


	LinkListNode* removeLoop(LinkListNode* head) {
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		while (fast != nullptr and fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (slow == fast) {
			slow = head;//notice change

			while (slow->next != fast->next) {//notice change
				slow = slow->next;
				fast = fast->next;
			}
			fast->next = nullptr;
		}
		return head;

	}




	int starting_point_of_loop(LinkListNode* head) {
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		while (fast != nullptr and fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (slow == fast) {
			slow = head;//notice change
			while (slow != fast) {//notice change
				slow = slow->next;
				fast = fast->next;
			}
			return slow->val;
		}
		return 0;
	}

	int noOfNodesInLoop(LinkListNode* head) {
		int counter = 0;
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		while (fast != nullptr and fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (slow == fast) {
			counter = 1;
			fast = fast->next;//notice change

			while (slow != fast) {//notice change
				counter++;
				fast = fast->next;//notice change
			}
			return counter;

		}
		return 0;
	}
	bool isPalindrome(LinkListNode* &left, LinkListNode* right) {
		if (right == nullptr)
			return true;
		// move right to end of list
		bool first = isPalindrome(left, right->next);
		// if at any step list is not palindromic
		if (first == false)
			return false;
		// compare value of left and right
		bool second = (right->val) == left->val;
		left = left->next;
		return second;
	}

	LinkListNode* delete_duplicate_From_soreted(LinkListNode* head) {
		LinkListNode* cur = head;
		while (cur->next != nullptr) {
			if (cur->val == cur->next->val) {
				LinkListNode *to_del = cur->next;
				cur->next = to_del->next;
				delete(to_del);
			}
			else
				cur = cur->next;
		}
		return head;
	}

	LinkListNode* delete_duplicate_From_unsortedLL(LinkListNode* head) {
		LinkListNode* cur = head;
		LinkListNode* prev = cur;//point to node previous to cur

		set<int> myset;
		while (cur != nullptr) {// dont use c->next otherwise if last node is duplicate
			// /it will not be deleted

			//duplicate found
			if (myset.count(cur->val)) {
				prev->next = cur->next;
				delete(cur);
			}
			else {
				myset.insert(cur->val);
				prev = cur;
			}
			cur = prev->next; //since cur has been delted if duplicated we cant use c=c->next
		}
		return head;
	}

	int intersection(LinkListNode* head1, LinkListNode* head2) {
		LinkListNode* cur1 = head1;
		LinkListNode* cur2 = head2;
		while (cur1 != cur2) {
			if (cur1 == nullptr)
				cur1 = head2;
			else
				cur1 = cur1->next;

			if (cur2 == nullptr)
				cur2 = head1;
			else
				cur2 = cur2->next;
		}
		return cur1->val;
	}

	LinkListNode* odd_even_ll(LinkListNode* head) {
		LinkListNode* odd = head, *even = head->next, *temp = even;
		while (even != nullptr and even->next != nullptr) {
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		// temp poit to starting of even link list and oddnext to end of odd ll
		odd->next = temp; //connecting odd and even list

		return head;
	}

	LinkListNode* merge(LinkListNode* head1, LinkListNode*head2) {
		if (head1 == nullptr or head2 == nullptr)
			return (head1 == nullptr ) ? head2 : head1;
		if (head1->val < head2->val) {
			head1->next = merge(head1->next, head2);
			return head1;
		}
		else {
			head2->next = merge(head1, head2->next);
			return head2;
		}
	}

	LinkListNode* mergeSort(LinkListNode* head) {
		if (head == nullptr or head->next == nullptr)
			return head;
		LinkListNode* slow = head;
		LinkListNode* fast = head;
		LinkListNode* prev = slow;
		while (fast and fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		prev->next = nullptr;
		LinkListNode* h1 = mergeSort(head);
		LinkListNode* h2 = mergeSort(slow);
		return merge(h1, h2);
	}

	// rearrange list so that it look
	// A1 AN A2 An-1 A3 . . . .. .
	LinkListNode*  rearrange_A1_An_A2_An_1(LinkListNode* head) {
		if (head == nullptr or head->next == nullptr)
			return nullptr;

		LinkListNode* slow = head, *fast = head, *mid_prev = slow;
		while (fast and fast->next) {
			mid_prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		mid_prev->next = nullptr;

//		printLinklist(head);
		// reverse second half
		LinkListNode* head2;
		LinkListNode* prev = nullptr, *next = nullptr, *cur = slow;
		while (cur != nullptr) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head2 = prev;

//		printLinklist(head2);

		// merging the two list
		LinkListNode* temp;
		LinkListNode* newnode = new LinkListNode;
		newnode->next = nullptr;
		temp = newnode;
		while (head != nullptr and head2 != nullptr) {
			temp->next = head;
			head = head->next;
			temp = temp->next;

			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;
		}
		if (head) {
			temp->next = head;
		}
		else {
			temp->next = head2;
		}
		temp = newnode->next;
		delete(newnode);

		return temp;
	}

	// segregate all even values first and then odd values
	// 2-8-10-1--5-9
	// maintain the order of even and odd values

	LinkListNode* segregateEvenOddValues(LinkListNode* head) {
		LinkListNode* evenHead = nullptr, *evenTail = nullptr;
		LinkListNode* oddHead = nullptr, *oddTail = nullptr;

		LinkListNode* itr = head;
		if (!head) {
			return nullptr;
		}
		else {
			while (itr != nullptr) {
				// even values
				if (itr->val % 2 == 0) {
					if (evenHead == nullptr) {
						// first even node
						evenTail = evenHead = itr;

					}
					else {
						// inserting node at end
						evenTail->next = itr;
						evenTail = itr;

					}
				}
				else {
					if (oddHead == nullptr) {
						// first odd node
						oddTail = oddHead = itr;

					}
					else {
						// inserting node at end
						oddTail->next = itr;
						oddTail = itr;

					}
				}
				itr = itr->next;
			}
			evenTail->next = oddHead;
			return evenHead;
		}

	}

	// find modular node ,sqaure node,fractional node
	LinkListNode* modularNodeFromStart(LinkListNode* head, int k) {
		LinkListNode* modularNode = nullptr;
		int i = 0;
		if (k <= 0)
			return nullptr;
		for (; head != nullptr; head = head->next) {
			if (i % k == 0) {
				modularNode = head;
			}
			i++;
		}
		return modularNode;
	}

	LinkListNode* modularNodeFromEnd(LinkListNode* head, int k) {
		LinkListNode* modularNodeEnd = head;
		int i = 0;
		if (k <= 0)
			return nullptr;
		for (i = 0; i < k; i++) {
			if (head)
				head = head->next;
			else return nullptr;
		}

		while (head != nullptr) {
			modularNodeEnd = modularNodeEnd->next;
			head = head->next;

		}

		return modularNodeEnd;
	}

	LinkListNode* fractionalNode(LinkListNode* head, int k) {
		LinkListNode* fracNode = nullptr;
		int i = 0;
		if (k <= 0)
			return nullptr;

		for (; head != nullptr; head = head->next) {
			if (i % k == 0) {
				if (fracNode == nullptr) {
					fracNode = head;

				}
				else
				{
					fracNode = fracNode->next;
				}
			}
			i++;
		}
		return fracNode;
	}

	LinkListNode* squareNode(LinkListNode* head) {
		LinkListNode* sq_Node = nullptr;

		int i = 1, j = 1;
		for (; head != nullptr; head = head->next) {
			if (i == j * j) {
				if (sq_Node == nullptr) {
					sq_Node = head;
				}
				else
					sq_Node = sq_Node->next;
				j++;
			}
			i++;
		}
		return sq_Node;
	}


	// partiton the linked list such that all the values less than x appear
	// before in the linked list and other at the end of linked list
	LinkListNode* partitonList(LinkListNode* head, int x) {
		LinkListNode* lesserHead = nullptr, *lesserTail = nullptr;
		LinkListNode* greaterHead = nullptr, *greaterTail = nullptr;

		while (head != nullptr) {
			LinkListNode* nextNode = head->next;
			if (head->val < x) {
				if (lesserTail == nullptr) {
					lesserTail = head;
					lesserHead = lesserTail;
				}
				lesserTail->next = head;
				lesserTail = head;
			} else {
				if (greaterTail == nullptr) {
					greaterTail = head;
					greaterHead = greaterTail;
				}
				greaterTail->next = head;
				greaterTail = head;
			}
			head = nextNode;
		}
		greaterTail->next = nullptr;

		lesserTail->next = greaterHead;
		return lesserHead;
	}



	ListNode* partition(ListNode* head, int x) {

		// before and after are the two pointers used to create the two list
		// before_head and after_head are used to save the heads of the two lists.
		// All of these are initialized with the dummy nodes created.
		ListNode* before_head = new ListNode(0);
		ListNode* before = before_head;
		ListNode* after_head = new ListNode(0);
		ListNode* after = after_head;

		while (head != null) {

			// If the original list node is lesser than the given x,
			// assign it to the before list.
			if (head->val < x) {
				befor->next = head;
				before = before->next;
			} else {
				// If the original list node is greater or equal to the given x,
				// assign it to the after list.
				after->next = head;
				after = after->next;
			}

			// move ahead in the original list
			head = head->next;
		}

		// Last node of "after" list would also be ending node of the reformed list
		after->next = null;

		// Once all the nodes are correctly assigned to the two lists,
		// combine them to form a single list which would be returned.
		before->next = after_head->next;

		return before_head->next;
	}


};




int main() {
	LinkListNode* head = nullptr;
	head = head-> addNodeAtEnd(head, 1);
	head = head-> addNodeAtEnd(head, 2);
	head = head-> addNodeAtEnd(head, 4);
	head = head-> addNodeAtEnd(head, 7);
	//
	head = head-> addNodeAtEnd(head, 3);
	head = head-> addNodeAtEnd(head, 5);
	head = head-> addNodeAtEnd(head, 6);

	// head = head->rearrange_A1_An_A2_An_1(head);
	// head-> printLinklist(head);

	// MAKING LOOP IN LL
	// LinkListNode* cur = head, *temp = head;
	// while (cur->next) {
	// 	cur = cur->next;
	// }

	// while (temp->val != 2)
	// 	temp = temp->next;
	// cur->next = temp;

//	head-> printLinklist(head);

	// cout << head->countNodes(head) << endl;
	// cout << head->find_kth_node_From_end(head, 3) << endl;

	// head->printRevereseLinkList(head);
//	head = head->reversell_recursive(head);
	// head->insert_node_InSortedLL(head, 5);
//	head->printLinklist(head);

//	head = head->reverse_ll_in_pairs_iteraticve(head);
//	head->printLinklist(head);

	// head->ll_is_evenNodes_oddNodes(head);
//	cout << "midlle of linked list : " << head->middleOfLinkList(head);
	// cout << endl;
	// head = head->deleteMiddleofLinkedList(head);

	// head = head->reverseLinkedList(head);

	// head = head->deleteLL(head);
	// if (head == nullptr)
	// 	cout << "deleteLL\n";
	// else
	// 	head-> printLinklist(head);

	// if (head->detectCycle(head))
	// 	cout << "cycle found\n";
	// else
	// 	cout << "no cycle found\n";


//	cout << head->noOfNodesInLoop(head) << endl;

	// cout << head->starting_point_of_loop(head) << endl;
	// head = head->removeLoop(head);
	// if (head->detectCycle(head))
	// 	cout << "cycle found\n";
	// else
	// 	cout << "no cycle found\n";


//	cout << head->isPalindrome(head, head);

	// head = head->delete_duplicate_From_soreted(head);
	// head = head->delete_duplicate_From_unsortedLL(head);

	// head-> printLinklist(head);



	// LinkListNode* head1 = nullptr;
	// LinkListNode* head2 = nullptr;

	// head1 = head1-> addNodeAtEnd(head1, 1);
	// head1 = head1->  addNodeAtEnd(head1, 2);
	// head1 = head1-> addNodeAtEnd(head1, 3);
	// head1 = head1-> addNodeAtEnd(head1, 4);
	// head1 = head1->  addNodeAtEnd(head1, 5);


	// head2 = head2-> addNodeAtEnd(head2, 8);
	// head2 = head2->  addNodeAtEnd(head2, 6);

	// LinkListNode* cur = head2, *temp = head1;
	// while (cur->next) {
	// 	cur = cur->next;
	// }

	// while (temp->val != 4)
	// 	temp = temp->next;
	// cur->next = temp;
	// cout << head1->intersection(head1, head2);

//	head = head->odd_even_ll(head);
	// head = head->mergeSort(head);
	// head->printLinklist(head);

	// head = head->segregateEvenOddValues(head);
//	head-> printLinklist(head);

//	head = head->modularNodeFromStart(head, 3);
//	cout << head->val << endl;

//	head = head->modularNodeFromEnd(head, 3);
//	cout << head->val << endl;

//	head = head->fractionalNode(head, 3);
//	cout << head->val << endl;

//	head = head->squareNode(head);
//	cout << head->val << endl;

	head = head->partitonList(head, 1);
	head->printLinklist(head);

	return 0;
}
