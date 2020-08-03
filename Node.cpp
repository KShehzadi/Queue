struct Node{
int data;
Node* next;

Node();
Node(int data);
};

Node::Node():data(0), next(NULL)
{

}

Node::Node(int data):data(data), next(NULL)
{

}
