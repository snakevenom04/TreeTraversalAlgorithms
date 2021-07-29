#include<iostream>
#include<stack>

using namespace std;

//The tree in consideration is the one below. Defined in main.
/*
									1
					2								3
			4				5				6				7
	   8						9			  10		11		12



*/


struct Node 
{
	int value;

	struct Node* left,* right;

	Node(int val)
	{
		value = val;

		left = right = NULL;
	}

};

void inorderIterative(struct Node* node)
{
	stack<Node*> mem;

	Node* current = node;

	while (mem.empty() == false || current != NULL) //Second condition is needed because when root is popped stack becomes empty while current holds the right tree
	{

		while (current != NULL)//inner loop to traverse down the left hand side of the tree 
		{	
			mem.push(current);
			current = current->left;
		}

		//after this mem will always contain the leftmost unpicked value at top

		current = mem.top();
		mem.pop();

		cout << current->value << " ";

		current = current->right;//starts the right sub tree
	}

}

void preorderIterative(struct Node* node)
{
	stack<Node*> mem;

	Node* current = node;

	
	while(current != NULL || mem.empty()== false)//can be done without two loops using if conditions.
	{ 
		while (current != NULL)//inner loop to go down left side
		{
			mem.push(current);

			cout << current->value << " ";

			current = current->left;
		}
		//after this loop current will be NULL and mem will have leftmost printed number in branch
		current = mem.top();
		mem.pop();
		current = current->right;//starts right subtree
	
	}

}

//If you look carefully at the results you ll see that postorder is basically pre order but from the right hand side in reverse.
//So all we will do here is flip our previous code store it in a second stack which will print it in reverse

void postorderIterative(struct Node* node)
{
	stack<Node*> mem;
	stack<int> reverse_mem;//second stack to reverse the content of the first one

	Node* current = node;


	while (current != NULL || mem.empty() == false)
	{
		while (current != NULL)//inner loop to go down right side
		{
			mem.push(current);

			reverse_mem.push(current->value);

			current = current->right;
		}
		//after this loop current will be NULL and mem will have rightmost printed number in branch
		current = mem.top();
		mem.pop();
		current = current->left;//starts left subtree

	}

	while (reverse_mem.empty() == false)//printing in reverse
	{

		cout << reverse_mem.top() << " ";
		reverse_mem.pop();
	}


}

void inorderRecursive(struct Node* node) //LEFT ROOT RIGHT
{
	
	if (node == NULL) return;
	
	
	inorderRecursive(node->left);

	cout << node->value << " ";

	inorderRecursive(node->right);

}

void preorderRecursive(struct Node* node) //ROOT LEFT RIGHT
{
	if (node == NULL) return;

	cout << node->value << " ";

	preorderRecursive(node->left);

	preorderRecursive(node->right);

}

void postorderRecursive(struct Node* node) //LEFT RIGHT ROOT
{
	if (node == NULL) return;

	postorderRecursive(node->left);

	postorderRecursive(node->right);

	cout << node->value << " ";

}

int main()
{
	struct Node* root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	root->left->left->left = new Node(8);
	root->left->right->right = new Node(9);

	root->right->left->right = new Node(10);
	root->right->right->left = new Node(11);
	root->right->right->right = new Node(12);

	cout << "Inorder recursive followed by iterative\n";

	inorderRecursive(root);
	cout << "\n---------------------\n";
	inorderIterative(root);
	cout << "\n---------------------\n";
	cout << "---------------------\n";
	cout << "Preorder recursive followed by iterative\n";

	preorderRecursive(root);
	cout << "\n---------------------\n";
	preorderIterative(root);

	cout << "\n---------------------\n";
	cout << "---------------------\n";

	cout << "Postorder recursive followed by iterative\n";

	postorderRecursive(root);
	cout << "\n---------------------\n";
	postorderIterative(root);
	cout << "\n---------------------\n";
	cout << "---------------------\n";


	return 0;
};