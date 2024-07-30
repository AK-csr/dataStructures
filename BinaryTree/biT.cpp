#include<algorithm>
#include<iostream>

struct Node{
    Node* left;
    char val;
    Node* right;
};

struct DoIt{
    void operator()(char x)
    {
        std::cout << x << " ";
    }
};

void preorder(const Node* t, DoIt fct) //fct is a function object
{
    if (t == nullptr)
    {
        return;
    }
    fct(t->val); //Print character
    preorder(t->left, fct);
    preorder(t->right, fct);
}

void inorder(const Node* t, DoIt fct)
{
    if (t == nullptr)
    {
        return;
    }
    inorder(t->left, fct);
    fct(t->val);
    inorder(t->right, fct);
}

void postorder(const Node* t, DoIt fct)
{
    if (t == nullptr)
    {
        return;
    }
    postorder(t->left, fct);
    postorder(t->right, fct);
    fct(t->val);
}

int countNodes(const Node* t)
{
    if (t == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int getHeight(const Node* t)
{
    // if (t == nullptr)
    // {
    //     return 0;
    // }
    // int maxL = 1 + getHeight(t->left);
    // int maxR = 1 + getHeight(t->right);
    // if (maxL > maxR)
    // {
    //     return maxL;
    // }
    // else
    // {
    //     return maxR;
    // }

    if(t == nullptr)
    {
        return 0;
    }
    int h = std::max(getHeight(t->left), getHeight(t->right));
    return h + 1;
}

int main()
{
}