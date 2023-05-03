template <class T>
class BSTNode {
    T data;
    BSTNode<T>* parent;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
    BSTNode(T newdata = T(), BSTNode<T>* newParent = nullptr, BSTNode<T>* newLeft = nullptr, BSTNode<T>* newRight = nullptr)
    : data(newdata), parent(newParent), left(newLeft), right(newRight) {}
    friend class BST<T>;
    int getSize() const;
};

