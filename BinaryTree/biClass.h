class BinTree{
    public:
        BinTree();
        bool isEmpty() const;
        ~BinTree();
        void insert(int x);

    private:
        struct Node{
            Node* left;
            int val;
            Node* right;
        };
        Node* root;
        static Node* makeLeaf(int x);
        static void destroyTree(Node*& t);
        static Node* copyTree(const Node* t);
        static Node* insert(Node* t, int x);
        bool search(int x, const Node*t);
};

BinTree::BinTree()
{
    root = nullptr;
}

bool BinTree::isEmpty() const
{
    return root == nullptr;
}

BinTree::Node* BinTree::makeLeaf(int x)
{
    return (new Node{nullptr, x, nullptr});
}

BinTree::~BinTree()
{
    //USES POSTORDER FOR DELETION
    destroyTree(root); //want root set to nullptr
}

void BinTree::destroyTree(Node* &t)
{
    if (t == nullptr)
    {
        return;
    }
    destroyTree(t->left);
    destroyTree(t->right);
    delete t;
    t = nullptr;
}

BinTree::Node* BinTree::copyTree(const Node*  t)
{
    //USES PREORDER
    if (t == nullptr)
    {
        return nullptr;
    }
    Node* p = makeLeaf(t->val);
    p->left = copyTree(t->left);
    p->right = copyTree(t->right);
    return p;
}

void BinTree::insert(int x)
{
    root = insert(root, x);
}

BinTree::Node* BinTree::insert(Node* t, int x)
{
    if (t == nullptr)
    {
        return new Node{nullptr, x, nullptr};
    }
    else if (x < t->val)
    {
        t->left = insert(t->left, x);
    }
    else
    {
        t->right  = insert(t->right, x);
    }
    return t;
}

bool BinTree::search(int x, const Node*t)
{
    if (t == nullptr)
    {
        return false;
    }
    if (x == t->val)
    {
        return true;
    }
    if (x < t->val)
    {
        return search(x, t->left);
    }
    else
    {
        return search(x, t->right);
    }
}