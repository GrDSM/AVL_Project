#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

//finds the heights of the node's children and sets the node's height to 1 plus the height of the tallest child
int findHeight(Node* node)
{
    int leftHeight = 0;
    int rightHeight = 0;
    int finalHeight = 0;
    if (node->left != nullptr)
    {
        leftHeight = node->left->height;
    }

    if (node->right != nullptr)
    {
        rightHeight = node->right->height;
    }

    if (leftHeight > rightHeight)
    {
        finalHeight = 1 + leftHeight;
    } else if (leftHeight <= rightHeight) {
        finalHeight = 1 + rightHeight;
    }
    return finalHeight;
}

Node* rightRotation(Node* node)
{
    Node* topNode = node;
    Node* middleNode = topNode->left;

    topNode->left = middleNode->right;
    middleNode->right = topNode;

    topNode->height = findHeight(topNode);
    middleNode->height = findHeight(middleNode);

    return middleNode;
}

Node* leftRotation(Node* node)
{
    Node* topNode = node;
    Node* middleNode = topNode->right;

    topNode->right = middleNode->left;
    middleNode->left = topNode;

    topNode->height = findHeight(topNode);
    middleNode->height = findHeight(middleNode);

    return middleNode;
}

Node* leftRightRotation(Node* node)
{
    Node* topNode = node;
    Node* middleNode = topNode->left;
    Node* bottomNode = middleNode->right;

    topNode->left = bottomNode->right;
    middleNode->right = bottomNode->left;
    bottomNode->right = topNode;
    bottomNode->left = middleNode;

    bottomNode->right->height = findHeight(bottomNode->right);
    bottomNode->left->height = findHeight(bottomNode->left);
    bottomNode->height = findHeight(bottomNode);

    return bottomNode;
}

Node* rightLeftRotation(Node* node)
{
    Node* topNode = node;
    Node* middleNode = node->right;
    Node* bottomNode = node->right->left;



    topNode->right = bottomNode->left;
    middleNode->left = bottomNode->right;
    bottomNode->left = topNode;
    bottomNode->right = middleNode;

    bottomNode->left->height = findHeight(bottomNode->left);
    bottomNode->right->height = findHeight(bottomNode->right);
    bottomNode->height = findHeight(bottomNode);

    return bottomNode;
}

Node* reorganize(Node* node)
{
    int balance = findBalance(node);

     if (balance >= 2)
    {
        if (findBalance(node->left) >= 1)
        {
            return rightRotation(node);
        } else {
            return leftRightRotation(node);
        }
    } else if (balance <= -2) {
        if (findBalance(node->right) >= 1)
        {
            return rightLeftRotation(node);
        } else {
            return leftRotation(node);
        }
    }
    return node;
}

Node* insert(Node* node, int value, string name, int &amount, int height)
{

    if (node == nullptr)
    {
        cout << "successful";
        amount++;
        return new Node(name, value, height);
    } else if (node->value == value) {
        cout << "unsuccessful";
        return node;
    } else if (value < node->value) {
        node->left = insert(node->left, value, name, amount, height);
    } else {
        node->right = insert(node->right, value, name, amount, height);
    }

    node->height = findHeight(node);

    return reorganize(node);
}

Node* remove(Node* node, int ID, int& amount)
{
    if (node == nullptr)
    {
        cout << "unsuccessful";
        return nullptr;
    } else if (ID < node->value){
        node->left = remove(node->left, ID, amount);
    } else if (ID > node->value){
        node->right = remove(node->right, ID, amount);
    } else{
        cout << "successful";
        amount--;
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        } else if (node->right == nullptr){
            Node* nextNode = node->left;
            delete node;
            return nextNode;
        } else if (node->left == nullptr){
            Node *nextNode = node->right;
            delete node;
            return nextNode;
        } else{
            Node* successor = node->right;
            Node* predecessor = node;

            while (successor->left != nullptr)
            {
                predecessor = successor;
                successor = successor->left;
            }

            if (successor == node->right)
            {
                successor->left = node->left;
                delete node;
                return successor;
            } else {
                predecessor->left = successor->right;
                successor->left = node->left;
                successor->right = node->right;
                delete node;
                return successor;
            }
        }

    }
    node->height = findHeight(node);
    return reorganize(node);
}

void searchID(Node* node, int value, bool& tester)
{
    if (node == nullptr)
    {
        return;
    } else if (value == node->value){
        cout << node->name;
        tester = false;
        return;
    } else if (value < node->value){
        searchID(node->left, value, tester);
    } else if (value > node->value){
        searchID(node->right, value, tester);
    }
}

void searchName(Node* node, string name, bool& tester)
{
    if (node == nullptr)
    {
        return;
    } else if (name == node->name){
        if (!tester)
        {
            cout << "\n";
        }
        tester = false;
        cout << node->value;
        return;
    }
    if (node->left != nullptr)
    {
        searchName(node->left, name, tester);
    }
    if (node->right != nullptr)
    {
        searchName(node->right, name, tester);
    }
}

void printInorder(Node* node, int amount, int& count)
{
    if (node->left != nullptr)
    {
        printInorder(node->left, amount, count);
    }
    count++;
    cout << node->name;
    if (count < amount)
    {
        cout << ", ";
    }
    if (node->right != nullptr)
    {
        printInorder(node->right, amount, count);
    }
}

void printPreorder(Node* node, int amount, int &count)
{
    count++;
    cout << node->name;
    if (count < amount)
    {
        cout << ", ";
    }
    if (node->left != nullptr)
    {
        printPreorder(node->left, amount, count);
    }
    if (node->right != nullptr)
    {
        printPreorder(node->right, amount, count);
    }
}

void printPostorder(Node* node, int amount, int& count)
{
    if (node->left != nullptr)
    {
        printPostorder(node->left, amount, count);
    }
    if (node->right != nullptr)
    {

        printPostorder(node->right, amount, count);
    }
    count++;
    cout << node->name;
    if (count < amount)
    {
        cout << ", ";
    }
}

int printLevelCount(Node* node)
{
    return node->height;
}

Node* removeInorder(Node* node, int& counter, int value, bool& remover, int& amount, int& ID)
{

    if (node->left != nullptr && !remover)
    {
        removeInorder(node->left, counter, value, remover, amount, ID);
    }

    counter++;
    if (value == counter && !remover)
    {
        ID = node->value;
        remover = true;
    }

    if (node->right != nullptr && !remover)
    {
        removeInorder(node->right, counter, value, remover, amount, ID);
    }
    counter--;

    if(counter == 0 && remover)
    {
        return remove(node, ID, amount);
    }
    return node;
}

int main()
{
    Node* root = nullptr;
    int bstAmount = 0;
    int counter = 0;
    bool tester = false;


    string line;
    getline(cin, line);
    int convertedNumber = 0;
    bool converted = true;
    for (char c : line)
    {
        if (!isdigit(c))
            converted = false;
    }
    if (converted)
    {
        convertedNumber = stoi(line);
    }

    for (int i = 0; i < convertedNumber; i++)
    {
        cin >> line;
        if (line == "insert")
        {
            string name;
            int ID;
            getline(cin, line, '"');
            getline(cin, line, '"');
            bool onlyLetters = true;
            for (int j = 0; j < (int) line.length(); j++)
            {
                if (line[j] != ' ' && !isalpha(line[j]))
                {
                    onlyLetters = false;
                    cout << "unsuccessful";
                    break;
                }
            }

            if (onlyLetters)
            {
                name = line;
                cin >> line;
                bool isNumber = true;
                for (char c: line)
                {
                    if (!isdigit(c))
                        isNumber = false;
                }

                if (line.length() == 8 && isNumber)
                {
                    ID = stoi(line);
                    root = insert(root, ID, name, bstAmount, 1);

                }
                else
                {
                    cout << "unsuccessful";
                }
            }
            getline(cin, line);
        }
        else if (line == "remove")
        {
            cin >> line;

            bool isNumber = true;
            for (char c: line)
            {
                if (!isdigit(c))
                    isNumber = false;
            }

            if (line.length() == 8 && isNumber)
            {
                int ID = stoi(line);
                root = remove(root, ID, bstAmount);
            } else {
                cout << "unsuccessful";
            }
        }
        else if (line == "search")
        {
            getline(cin, line);
            line.erase(line.begin());
            if (isdigit(line[0]))
            {
                bool isNumber = true;
                for (char c: line)
                {
                    if (!isdigit(c))
                        isNumber = false;
                }

                if (line.length() == 8 && isNumber)
                {
                    int ID = stoi(line);
                    tester = true;
                    searchID(root, ID, tester);
                    if (tester)
                    {
                        cout << "unsuccessful";
                    }
                }
                else
                {
                    cout << "unsuccessful";
                }
            }
            else if (line[0] == '"')
            {
                line.erase(line.begin());
                line.erase(line.end() - 1, line.end());
                bool onlyLetters = true;
                for (int j = 0; j < (int) line.length(); j++)
                {
                    if (line[j] != ' ' && !isalpha(line[j]))
                    {
                        onlyLetters = false;
                        cout << "unsuccessful";
                        break;
                    }
                }
                if (onlyLetters)
                {
                    tester = true;
                    searchName(root, line, tester);
                    if (tester)
                    {
                        cout << "unsuccessful";
                    }
                }

            }
            else
            {
                cout << "unsuccessful";
            }


        }
        else if (line == "printInorder")
        {
            counter = 0;
            if (root != nullptr)
            {
                printInorder(root, bstAmount, counter);
            }
            else
            {
                cout << "unsuccessful";
            }
        }
        else if (line == "printPreorder")
        {
            counter = 0;
            if (root != nullptr)
            {
                printPreorder(root, bstAmount, counter);
            }
            else
            {
                cout << "unsuccessful";
            }
        }
        else if (line == "printPostorder")
        {
            counter = 0;
            if (root != nullptr)
            {
                printPostorder(root, bstAmount, counter);
            }
            else
            {
                cout << "unsuccessful";
            }
        }
        else if (line == "printLevelCount")
        {
            if (root != nullptr)
            {
                int levelCount = printLevelCount(root);
                cout << levelCount;
            } else {
                cout << 0;
            }

        }
        else if (line == "removeInorder")
        {
            cin >> line;
            bool isNumber = true;
            for (char c: line)
            {
                if (!isdigit(c))
                    isNumber = false;
            }

            if (isNumber && stoi(line) <= bstAmount)
            {
                counter = 0;
                int ID = stoi(line);
                bool remover = false;
                int value = 0;
                removeInorder(root, counter, ID, remover, bstAmount, value);

            } else {
                cout << "unsuccessful";
            }
        }
        else
        {
            cout << "unsuccessful";
        }

        if (i < convertedNumber-1)
        {
            cout << "\n";
        }

    }
}
