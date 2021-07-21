#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};
class Stack
{
public:
	node *stack[15];
	int top = -1;

	void push(node *val)
	{
		top++;
		stack[top] = val;
	}
	node *pop()
	{
		node *a;
		a = stack[top];
		top--;
		return a;
	}

	bool isempty()
	{
		if (top < 0)
			return true;
		return false;
	}
};
class BST
{
public:
	node *root = NULL;

	node *insertr(node *root, int key)
	{
		node *nn = new node();
		nn->data = key;
		nn->left = NULL;
		nn->right = NULL;

		if (root == NULL)
		{
			root = nn;
			return nn;
		}

		else if (key < root->data)
		{
			root->left = insertr(root->left, key);
		}
		else if (key > root->data)
		{
			root->right = insertr(root->right, key);
		}

		return root;
	}

	node *insertnr(node *root, int key)
	{
		node *nn = new node;
		nn->data = key;
		nn->left = nn->right = NULL;

		node *temp = root;
		node *parent = NULL;

		while (temp != NULL)
		{
			parent = temp;
			if (key < temp->data)
				temp = temp->left;
			else if (key > temp->data)
				temp = temp->right;
		}

		if (parent == NULL)
		{
			parent = nn;
		}
		else if (key < parent->data)
		{
			parent->left = nn;
		}
		else if (key > parent->data)
		{
			parent->right = nn;
		}

		return parent;
	}

	void inorder(node *r)
	{
		if (r == NULL)
			return;

		inorder(r->left);
		cout << r->data << " ";
		inorder(r->right);
	}

	void nrinorder(node *r)
	{
		Stack objS1;
		node *temp;
		temp = r;
		cout << endl;
		while (1)
		{
			while (temp != NULL)
			{
				objS1.push(temp);
				temp = temp->left;
			}
			if (!objS1.isempty())
			{
				temp = objS1.pop();
				cout << " " << temp->data;
				temp = temp->right;
			}
			else
				break;
		}
		cout << endl;
	}

	void nrpreorder(node *r)
	{
		Stack objS1;
		node *temp;
		temp = r;
		cout << endl;
		while (1)
		{
			while (temp != NULL)
			{
				cout << " " << temp->data;
				objS1.push(temp);
				temp = temp->left;
			}
			if (!objS1.isempty())
			{
				temp = objS1.pop();
				temp = temp->right;
			}
			else
				break;
		}
		cout << endl;
	}

	node *search(node *root, int key)
	{
		node *temp = root;

		while (temp != NULL)
		{
			if (key == temp->data)
				return temp;

			else if (key < temp->data)
				temp = temp->left;

			else if (key > temp->data)
				temp = temp->right;
		}

		return NULL;
	}

	int findmin(node *root)
	{
		node *temp = root;

		if (root->left == NULL)
			return root->data;

		else
			return findmin(root->left);
	}

	int longestpathcount(node *r)
	{
		if (r == NULL)
			return 0;

		else if (longestpathcount(r->left) >= longestpathcount(r->right))
			return (1 + longestpathcount(r->left));

		return (1 + longestpathcount(r->right));
	}

	void mirror(node *r)
	{
		node *temp = NULL;

		if (r != NULL)
		{
			mirror(r->left);
			mirror(r->right);
			temp = r->left;
			r->left = r->right;
			r->right = temp;
		}
	}

	void delete_node(node *r, int key)
	{
		node *parent = NULL;
		node *temp = root;

		while (temp != NULL && temp->data != key)
		{
			parent = temp;

			if (key < temp->data)
				temp = temp->left;

			else if (key > temp->data)
				temp = temp->right;
		}

		if (temp == NULL)
		{
			cout << "key not found\n";
			//return;
		}
		else
		{
			//case1: Leaf node deletion
			if (temp->left == NULL && temp->right == NULL)
			{
				if (temp == r)
					root = NULL;
				else if (temp == parent->left)
				{
					parent->left = NULL;
				}
				else
					parent->right = NULL;

				delete (temp);
			}

			//case2:node with one child
			else if (temp->left != NULL && temp->right == NULL)
			{
				if (temp == parent->left)
					parent->left = temp->left;
				else
					parent->right = temp->right;

				delete (temp);
			}

			else if (temp->left == NULL && temp->right != NULL)
			{
				if (temp == parent->left)
					parent->left = temp->right;
				else
					parent->right = temp->right;

				delete (temp);
			}

			// case 3: node having 2 children
			else if (temp->left != NULL && temp->right != NULL)
			{
				node *in_succ = temp->right;

				while (in_succ->left != NULL)
					in_succ = in_succ->left;

				int val = in_succ->data;

				delete_node(this->root, in_succ->data);
				temp->data = val;
				//updating the value
			}
		}
	}
};

int main()
{
	BST d;

	int ch, n, f, is_root_null, res;
	double kw;
	f = is_root_null = 0;
	node *found;

	while (1)
	{

		cout << "\n\n1.INSERT NODES.\n2.DISPLAY ALL NODES(RECURSIVE INORDER).\n3.SEARCH NODE.\n4.DELETE NODE.\n5.MINIMUM ELEMENT.\n6.LONGEST PATH COUNT.\n7.MIRRORING TREE.\n8.NON-RECURSIVE INORDER.\n9.NON-RECURSIVE PREORDER.\n10.EXIT.\n ";
		cout << "Enter your choice : ";
		cin >> ch;

		switch (ch)
		{

		case 1:

			cout << "\nENTER THE DATA: ";
			cin >> kw;

			if (!is_root_null)
			{

				d.root = d.insertnr(d.root, kw);
				is_root_null = 1;
			}
			else
			{
				d.insertr(d.root, kw);
			}

			break;
		case 2:
			d.inorder(d.root);

			break;
		case 3:
			cout << "\nENTER THE DATA : ";
			cin >> kw;
			found = d.search(d.root, kw);
			if (found == NULL)
			{
				cout << "\nDATA NOT FOUND.\n";
			}
			else
			{
				cout << "\nDATA FOUND.\n";
			}

			break;
		case 4:
			cout << "\nENTER THE DATA YOU WANT TO DELETE : ";
			cin >> kw;
			d.delete_node(d.root, kw);
			break;
		case 5:
			cout << "\nMINIMUM VALUE IN A TREE : " << d.findmin(d.root);
			cout << endl;
			break;
		case 6:
			cout << "\nTHE LONGEST PATH COUNT IS : " << d.longestpathcount(d.root);
			cout << endl;

			break;
		case 7:
			cout << "ORIGINAL TREE :";
			d.inorder(d.root);
			d.mirror(d.root);
			cout << endl;
			cout << "AFTER MIRRORING :";
			d.inorder(d.root);
			cout << endl;
			d.mirror(d.root);
			break;
		case 8:
			d.nrinorder(d.root);
			break;
		case 9:
			d.nrpreorder(d.root);
			break;
		case 10:
			f = 1;
			break;
		default:
			cout << "Invalid Choice !!! Please try again." << endl;
		}

		if (f == 1)
		{
			break;
		}
	}
	return 0;
}
