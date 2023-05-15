#include<iostream>
#include<stack>
#include<queue>

int max(const int& a, const int& b) { return a > b ? a : b ; }
int min(const int& a, const int& b) { return a < b ? a : b ; }
class BST
{
    private : 
    int data ; 
    BST* right ; 
    BST* left ;
    int size ;

    public : 
    //BST():/*data(0),*/right(0),left(0) {}
    BST()
    {
        right = NULL ; 
        left = NULL ; 
        size = 0 ; 
    }
    BST(int Data):data(Data),right(NULL),left(NULL),size(0) {}
    BST* insert(BST* root, int Data)
    {
        if(!root) return new BST(Data) ; 
        if(Data > root->data) root->right = insert(root->right , Data) ; 
        else if(Data < root->data) root->left = insert(root->left, Data) ; 
        size++ ; 
        return root ;
    }
    BST* search(BST* root, int key)
    {
        if(!root or key == root->data) return root ; 
        if(key > root->data) return search(root->right, key) ; 
        else if(key < root->data) return search(root->left, key) ; 
    }
    bool exist(BST* root , int key)
    {
        if(!root) return false ; 
        if(root->data == key) return true ; 
        bool b1 = exist(root->left , key) ; 
        if(b1) return true ; 
        bool b2 = exist(root->right , key) ; 
        if(b2) return true ; 
        return false ;
    }
    void inorder(BST* root)
    {
        if(!root) return ; 
        inorder(root->left) ; 
        std::cout << root->data << std::endl ; 
        inorder(root->right) ; 
    }
    int height(BST* root, int& zero)
    {
        if(!root) return 0 ; 
        if(root->right) 
        {
            zero++ ; 
            return height(root->right, zero) ;
        } 
        if(root->left) 
        {
            zero++ ; 
            return height(root->left, zero) ; 
        }
        return 1 + max(height(root->right, zero), height(root->left, zero)) ; 
    }
    int height(BST* root)
    {
        if(!root) return 0 ; 
        int hl = height(root->left) ; 
        int hr = height(root->right) ; 
        return 1 + max(hl , hr) ; 
    }
    void preorder(BST* root)
    {
        if(!root) return ; 
        std::cout << root->data << std::endl ; 
        preorder(root->left) ; 
        preorder(root->right) ; 
    }
    void postorder(BST* root)
    {
        if(!root) return ; 
        postorder(root->left) ; 
        postorder(root->right) ; 
        std::cout << root->data << std::endl ; 
    }
    bool isComplete(BST* root)
    {
        if (!root) return true ;
        std::queue<BST*> q ;
        q.push(root) ;
        bool flag = false ;
        while (!q.empty()) 
        {
            BST* temp = q.front() ;
            q.pop() ;
            if (!temp) flag = true ;
            else 
            {
                if (flag) return false ; 
                q.push(temp->left) ;
                q.push(temp->right) ;
            }
        }
        return true;
    }
    bool isFull(BST* root)
    {
        if(!root) return true ; 
        if(!root->right and !root->left) return true ; 
        if(root->right and root->left) return (isFull(root->right) and isFull(root->left)) ;
        return false ; 
    }
    int max_value(BST* root)
    {
        if(!root) return INT16_MIN ; 
        int value = root->data ; 
        int left_max = max_value(root->left) ; 
        int right_max = max_value(root->right) ; 
        return max(value , max(left_max , right_max)) ; 
    }
    int min_value(BST* root)
    {
        if(!root) return INT16_MAX ; 
        int value = root->data ; 
        int left_min = min_value(root->left) ; 
        int right_min = min_value(root->right) ;
        return min(value , min(left_min , right_min)) ; 
    }
    BST* min_value_node(BST* root)
    {
        BST* current = root ; 
        while(current and current->left) current = current->left ; 
        return current ; 
    }
    bool isBST(BST* root)
    {
        if(!root) return true ; 
        if(root->right and max_value(root->right) < root->data) return false ; 
        if(root->left and min_value(root->left) > root->data) return false ; 
        if(!isBST(root->right) or !isBST(root->left)) return false ;
        return true ; 
    }
    int getLength(BST* root)
    {
        if(!root) return 0 ; 
        return 1 + getLength(root->right) + getLength(root->left) ;
    }
    bool isPerfect(BST* root) 
    {
        int length = getLength(root) ;
        //return !(length and (length+1)) ; 
        return (length and (length+1)) == 0 ; 
    }
};


int main()
{
    std::cout.setf(std::ios_base::boolalpha) ; 
    BST* root = new BST(1) ; 
    root = root->insert(root, 10) ;  
    root->insert(root, 25) ; 
    root->insert(root, 60) ; 
    root->insert(root, 35) ; 
    root->insert(root, 10) ; 
    root->insert(root, 5) ; 
    root->insert(root, 20) ;
    root->insert(root, 65) ;
    root->insert(root, 45) ;
    root->insert(root, 70) ;
    root->insert(root, 40) ;
    root->insert(root, 50) ;
    root->insert(root, 55) ;
    root->insert(root, 30) ;
    root->insert(root, 15) ;
    std::cout << "exist : " << root->exist(root , 22) << std::endl ; 
    root->inorder(root) ;
    int zero = 0 ; 
    root->height(root, zero) ; 
    std::cout << "height : " << zero << std::endl ; 
    std::cout << "complete : " << root->isComplete(root) << std::endl ; 
    std::cout << "full : " << root->isFull(root) << std::endl ;
    std::cout << "BST : " << root->isBST(root)  << std::endl ; 
    std::cout << "length : " << root->getLength(root) << std::endl ; 
    std::cout << "perfect : " << root->isPerfect(root) << std::endl ; 
    return 0 ;
}