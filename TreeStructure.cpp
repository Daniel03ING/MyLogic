#include <iostream>
#include <locale.h>

using namespace std;

struct tree {
    //Creates the tree data structure with left and right pointers simulating the left and right nodes of a tree
    int controlVariable;
    tree *leftSideOfDataStructure, *rightSideOfDataStructure;
};

tree* createNode(int controlVariable) {
    //Creates a new node within the tree structure
    tree* newNode = new tree();
    newNode->controlVariable = controlVariable;
    //Creates left and right nodes with an initial value of NULL, indicating they don't have any value
    newNode->leftSideOfDataStructure = newNode->rightSideOfDataStructure = NULL;
    return newNode;
}

void insertTree(tree*& root, int controlVariable) {
    //Creates the tree if it doesn't exist
    if (root == NULL) {
        root = createNode(controlVariable);
    //Evaluates if the node to be introduced is smaller than the previously entered node
    } else if (controlVariable < root->controlVariable) {
        //If smaller, it is placed on the left side
        insertTree(root->leftSideOfDataStructure, controlVariable);
        //If greater, it is placed on the right side
    } else {
        insertTree(root->rightSideOfDataStructure, controlVariable);
    }
}

tree* seachMininumNode(tree* root) {
    //Traverses and searches for the smallest (left) node
    while (root->leftSideOfDataStructure != NULL) {
        root = root->leftSideOfDataStructure;
    }
    return root;
}

tree* searchMaximumNode(tree* root) {
    //Traverses and searches for the largest (right) node
    while (root->rightSideOfDataStructure != NULL) {
        root = root->rightSideOfDataStructure;
    }
    return root;
}


tree* eliminateNode(tree* root, int controlVariable, bool& electionMethod) {
    // If the tree is empty, return the root
    if (root == NULL) return root;

    // If the value to be deleted is smaller than the root's value, go to the left subtree
    if (controlVariable < root->controlVariable) {
        root->leftSideOfDataStructure = eliminateNode(root->leftSideOfDataStructure, controlVariable, electionMethod);
    } 
    // If the value to be deleted is greater than the root's value, go to the right subtree
    else if (controlVariable > root->controlVariable) {
        root->rightSideOfDataStructure = eliminateNode(root->rightSideOfDataStructure, controlVariable, electionMethod);
    } 
    // If the value is the same as the root's value, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->leftSideOfDataStructure == NULL) {
            tree* temp = root->rightSideOfDataStructure;
            delete root;
            return temp;
        } else if (root->rightSideOfDataStructure == NULL) {
            tree* temp = root->leftSideOfDataStructure;
            delete root;
            return temp;
        } 
        // Node with two children
        else {
            cout << "The node has two children. Do you want to delete using the method of the smallest of the largest (1) or largest of the smallest (2)? ";
            int choose;
            cin >> choose;

            if (choose == 1) {
                // Find the smallest node in the right subtree
                tree* temp = seachMininumNode(root->rightSideOfDataStructure);
                // Copy the value of the smallest node to this node
                root->controlVariable = temp->controlVariable;
                // Delete the smallest node in the right subtree
                root->rightSideOfDataStructure = eliminateNode(root->rightSideOfDataStructure, temp->controlVariable, electionMethod);
            } else if (choose == 2) {
                // Find the largest node in the left subtree
                tree* temp = searchMaximumNode(root->leftSideOfDataStructure);
                // Copy the value of the largest node to this node
                root->controlVariable = temp->controlVariable;
                // Delete the largest node in the left subtree
                root->leftSideOfDataStructure = eliminateNode(root->leftSideOfDataStructure, temp->controlVariable, electionMethod);
            } else {
                cout << "Invalid option. No deletion will be performed." << endl;
            }
        }
    }
    return root;
}

void showTreeInorder(tree* root) {
    //Traverses and displays the tree in Inorder
    if (root != NULL) {
        showTreeInorder(root->leftSideOfDataStructure);
        cout << root->controlVariable << " ";
        showTreeInorder(root->rightSideOfDataStructure);
    }
}

void showTreePreorder(tree* root) {
    //Traverses and displays the tree in Preorder
    if (root != NULL) {
        cout << root->controlVariable << " ";
        showTreePreorder(root->leftSideOfDataStructure);
        showTreePreorder(root->rightSideOfDataStructure);
    }
}

void showTreePostorder(tree* root) {
    //Traverses and displays the tree in Postorder
    if (root != NULL) {
        showTreePostorder(root->leftSideOfDataStructure);
        showTreePostorder(root->rightSideOfDataStructure);
        cout << root->controlVariable << " ";
    }
}

int calculateHeight(tree* root) {
    //Traverses the child nodes of the main node and determines the height of the left and right nodes
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(root->leftSideOfDataStructure);
        int rightHeight = calculateHeight(root->rightSideOfDataStructure);
        return 1 + max(leftHeight, rightHeight);
    }
}

void showLeaves(tree* root) {
    //Traverses, determines if the right and left sides have no nodes, and displays the leaf if the condition is met
    if (root != NULL) {
        if (root->leftSideOfDataStructure == NULL && root->rightSideOfDataStructure == NULL) {
            cout << root->controlVariable << " ";
        }
        showLeaves(root->leftSideOfDataStructure);
        showLeaves(root->rightSideOfDataStructure);
    }
}

void showLevel(tree* root, int level) {
    //Returns to the parent function if it reaches the end
    if (root == NULL) return;
    if (level == 1) {
        cout << root->controlVariable << " ";
    } else if (level > 1) {
        //Displays the left and right sides of each node, including their levels
        showLevel(root->leftSideOfDataStructure, level - 1);
        showLevel(root->rightSideOfDataStructure, level - 1);
    }
}

void showForLevels(tree* root) {
    //Takes the paths of the tree and calculates its height to determine and display its levels
    if (root == NULL) return;
    int maxHeight = calculateHeight(root);
    for (int i = 1; i <= maxHeight; i++) {
        showLevel(root, i);
        cout << endl;
    }
}


void menu() {
    cout << "MENU:" << endl;
    cout << "1. Insert your tree" << endl;
    cout << "2. Display traversal, Calculate height, Show leaves, Show levels" << endl;
    cout << "3. Delete a node" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Enter your option: ";

}

main() {
    tree* root = nullptr;
    int choose, value;
    bool electionMethod;

    do {
        menu();
        cin >> choose;

        switch (choose) {
            case 1:
                cout << "Enter the value to insertTree: ";
                cin >> value;
                cout << endl;
                insertTree(root, value);
                break;
            case 2:
                cout << endl;
                cout << "Traversal: " << endl;
                cout << "Inorder: ";
                showTreeInorder(root);
                cout << endl;
                cout << "Preorder: ";
                showTreePreorder(root);
                cout << endl;
                cout << "Postorder: ";
                showTreePostorder(root);
                cout << endl;
                cout << "Height of the tree: " << calculateHeight(root) - 1 << endl;
                cout << "Leaves of the tree: ";
                showLeaves(root);
                cout << endl;
                cout << "Tree by levels: " << endl;
                showForLevels(root);
                cout << endl;
                break;
            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = eliminateNode(root, value, electionMethod);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choose != 4);
}
