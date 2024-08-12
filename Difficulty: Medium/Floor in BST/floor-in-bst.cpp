//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    void traverse(Node* root,int input,int& temp){
        if(root==NULL){
            return;
        }
        if(root->data<=input){
            temp=max(temp,root->data);
        }
        if(root->data>input){
            traverse(root->left,input,temp);
        }
        if(root->data<input){
            traverse(root->right,input,temp);
        }
    }

    int floor(Node* root, int input) {
        // Code here
    if (root == NULL) return -1;
    int temp=INT_MIN;
    traverse(root,input,temp);
    if(temp==INT_MIN) return -1;
    return temp;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends