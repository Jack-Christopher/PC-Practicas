#include <iostream>

class Node
{
    public:
    Node(int value);   
    int value;
    int quantity;
    Node* left;
    Node* right;
};

Node::Node(int value)
{
    this->value = value;
    this->quantity = 1;
    this->left = NULL;
    this->right = NULL;
}

class BST
{
private:
    Node* root;
public:
    BST();
    void insert(int value);
    int pop_min();
    int pop_max();
    void delete_node(Node* node);
    ~BST();
};

BST::BST()
{ this->root = nullptr;}

void BST::insert(int value)
{
    if(this->root == nullptr)
    {
        this->root = new Node(value);
        return;
    }
    Node* current = this->root;
    while(true)
    {
        if (value == current->value)
        {
            current->quantity++;
            return;
        }
        if (value < current->value)
        {
            if (current->left == NULL)
            {
                current->left = new Node(value);
                return;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = new Node(value);
                return;
            }
            current = current->right;
        }
    }
}

int BST::pop_min()
{
    if(this->root == nullptr)
    {
        return -1;
    }
    Node* current = this->root;
    Node* previous = nullptr;
    while(current->left != nullptr)
    {
        previous = current;
        current = current->left;
    }
    
    int min = current->value;

    if(current->quantity > 1)
    {
        current->quantity--;
    }
    else
    {
        Node* temp;
        if (current == this->root)
        {
            temp = this->root;
            this->root = current->right;
            delete temp;
        }
        else
        {
            temp = current;
            previous->left = current->right;
            delete temp;
        }
    }

    return min;
}   


int BST::pop_max()
{
    if(this->root == nullptr)
    {
        return -1;
    }
    Node* current = this->root;
    Node* previous = nullptr;
    while(current->right != nullptr)
    {
        previous = current;
        current = current->right;
    }
        
    int max = current->value;

    if(current->quantity > 1)
    {
        current->quantity--;
    }
    else
    {
        Node* temp;
        if (current == this->root)
        {
            temp = this->root;
            this->root = current->left;
            delete temp;
        }
        else
        {
            Node* temp = current;
            previous->right = current->left;
            delete temp;
        }
    }

    return max;
}

void BST::delete_node(Node* node)
{
    if(node->left != nullptr)
    {
        delete_node(node->left);
    }
    if(node->right != nullptr)
    {
        delete_node(node->right);
    }
    delete node;
}

BST::~BST()
{
    if (this->root != nullptr)
    {
        delete_node(this->root);
    }
}



int main()
{
    int n;
    while (std::cin >> n)
    {
        if (n == 0)
            break;

        BST bst;
        int quantity, suma = 0;
        for (int p = 0; p < n; p++)
        {
            std::cin >> quantity;
            int value;
            for (int k = 0; k < quantity; k++)
            {
                std::cin >> value;
                bst.insert(value);
            }
            // std::cout<< "inserted\n";
            int max = bst.pop_max();
            // std::cout<< "max: " << max << "\n";
            int min = bst.pop_min();
            // std::cout<< "min: " << min << "\n";
            suma += (max - min);
        }
        std::cout << suma << std::endl;
    }

    return 0;
}




