
/*#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/Node.h"
#include <vector>
#include <algorithm>*/

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

/*TEST_CASE("AVL Tree: Incorrect Commands")
{
    //initializes inputTree node, amount int, and finalString string
    Node* inputTree = nullptr;
    int amount = 0;
    string finalString;

    //checks insert function if the name has characters other than letters and spaces
    inputTree = inputTree->initializeInsert(inputTree, 10000000, "$0nny_B01", amount, finalString);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //checks insert function if the ID is more than 8 digits
    inputTree = inputTree->initializeInsert(inputTree, 425336822, "Sonny", amount, finalString);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //checks insert function if the ID is less than 8 digits
    inputTree = inputTree->initializeInsert(inputTree, 424, "Sonny", amount, finalString);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //makes inputTree have a node so that if the commands were correct they would work
    inputTree = inputTree->initializeInsert(inputTree, 42456278, "Sonny", amount, finalString);
    finalString = "";

    //checks remove function if the ID is not 8 digits
    inputTree = inputTree->initializeRemove(inputTree, 424562780, amount, finalString);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //checks search function if the ID is not 8 digits
    finalString = inputTree->initializeSearchID(inputTree, 424562780);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //checks search function if the name has characters other than letters and spaces
    finalString = inputTree->initializeSearchName(inputTree, "$0nny");
    REQUIRE(finalString == "unsuccessful");
}

TEST_CASE("AVL Tree: Edge Cases")
{
    //initializes inputTree node, amount int, and finalString string
    Node* inputTree = nullptr;
    int amount = 0;
    string finalString;

    //makes inputTree have nodes so that if commands were not edge cases they would work
    inputTree = inputTree->initializeInsert(inputTree, 12345678, "Hailey", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345679, "Johnathan", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345677, "Tommy", amount, finalString);
    finalString = "";

    //checks for removing a node that doesn't exist
    inputTree = inputTree->initializeRemove(inputTree, 12345670, amount, finalString);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //checks for inserting a node that already has a node with the same ID
    inputTree = inputTree->initializeInsert(inputTree, 12345679, "Peter", amount, finalString);
    REQUIRE(finalString == "unsuccessful");
    finalString = "";

    //checks for searching for a node that does not exist
    finalString = inputTree->initializeSearchName(inputTree, "Brook");
    REQUIRE(finalString == "unsuccessful");
}

TEST_CASE("AVL Tree: Rotation Cases")
{
    //initializes rightTree node, amount int, and finalString string
    Node* rightTree = nullptr;
    int amount = 0;
    string finalString;

    //insert 3 nodes into the rightTree that where the second and third are on the left, making a right rotation
    rightTree = rightTree->initializeInsert(rightTree, 12345678, "Peter", amount, finalString);
    rightTree = rightTree->initializeInsert(rightTree, 12345677, "Charlie", amount, finalString);
    rightTree = rightTree->initializeInsert(rightTree, 12345676, "George", amount, finalString);
    finalString = "";

    //checks if rightTree's nodes are in the correct position
    finalString = rightTree->initializePrintInorder(rightTree, amount);
    string correctString = "George, Charlie, Peter";
    REQUIRE(finalString == correctString);
    finalString = "";

    //initializes leftTree node and resets amount
    Node* leftTree = nullptr;
    amount = 0;

    //insert 3 nodes into the leftTree that where the second and third are on the left, making a left rotation
    leftTree = leftTree->initializeInsert(leftTree, 12345678, "Sadie", amount, finalString);
    leftTree = leftTree->initializeInsert(leftTree, 12345679, "Connor", amount, finalString);
    leftTree = leftTree->initializeInsert(leftTree, 12345680, "Veronica", amount, finalString);
    finalString = "";

    //checks if leftTree's nodes are in the correct position
    finalString = leftTree->initializePrintInorder(leftTree, amount);
    correctString = "Sadie, Connor, Veronica";
    REQUIRE(finalString == correctString);
    finalString = "";

    //initializes leftRightTree node and resets amount
    Node* leftRightTree = nullptr;
    amount = 0;

    //insert 3 nodes into the leftRightTree that where the second is on the left and the third are on the right, making a left right rotation
    leftRightTree = leftRightTree->initializeInsert(leftRightTree, 12345678, "Kaiden", amount, finalString);
    leftRightTree = leftRightTree->initializeInsert(leftRightTree, 12345675, "Carolyn", amount, finalString);
    leftRightTree = leftRightTree->initializeInsert(leftRightTree, 12345677, "Jake", amount, finalString);
    finalString = "";

    //checks if leftRightTree's nodes are in the correct position
    finalString = leftRightTree->initializePrintInorder(leftRightTree, amount);
    correctString = "Carolyn, Jake, Kaiden";
    REQUIRE(finalString == correctString);
    finalString = "";


    //initializes rightLeftTree node and resets amount
    Node* rightLeftTree = nullptr;
    amount = 0;

    //insert 3 nodes into the rightLeftTree that where the second is on the right and the third are on the left, making a right left rotation
    rightLeftTree = rightLeftTree->initializeInsert(rightLeftTree, 12345678, "Arlo", amount, finalString);
    rightLeftTree = rightLeftTree->initializeInsert(rightLeftTree, 12345693, "Cody", amount, finalString);
    rightLeftTree = rightLeftTree->initializeInsert(rightLeftTree, 12345689, "Waldo", amount, finalString);
    finalString = "";

    //checks if rightLeftTree's nodes are in the correct position
    finalString = rightLeftTree->initializePrintInorder(rightLeftTree, amount);
    correctString = "Arlo, Waldo, Cody";
    REQUIRE(finalString == correctString);
}

TEST_CASE("AVL Tree: Deletion Case")
{
    //initializes inputTree node, amount int, and finalString string
    Node* inputTree = nullptr;
    int amount = 0;
    string finalString;

    //makes inputTree have nodes so that the remove functions actually remove nodes
    inputTree = inputTree->initializeInsert(inputTree, 12345678, "Trevor", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345679, "Neil", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345677, "Vera", amount, finalString);
    finalString = "";

    //checks remove function if the node has no children
    inputTree = inputTree->initializeRemove(inputTree, 12345677, amount, finalString);
    finalString = "";
    finalString = inputTree->initializePrintInorder(inputTree, amount);
    string correctString = "Trevor, Neil";
    REQUIRE(finalString == correctString);

    //makes inputTree have nodes so that the remove functions can remove the right type of Node
    inputTree = inputTree->initializeInsert(inputTree, 12345675, "Buffy", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345673, "Mary", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345690, "Melissa", amount, finalString);

    //checks remove function if the node has one child on the left
    inputTree = inputTree->initializeRemove(inputTree, 12345675, amount, finalString);
    finalString = "";
    finalString = inputTree->initializePrintInorder(inputTree, amount);
    correctString = "Mary, Trevor, Neil, Melissa";
    REQUIRE(finalString == correctString);

    //checks remove function if the node has one child on the right
    inputTree = inputTree->initializeRemove(inputTree, 12345679, amount, finalString);
    finalString = "";
    finalString = inputTree->initializePrintInorder(inputTree, amount);
    correctString = "Mary, Trevor, Melissa";
    REQUIRE(finalString == correctString);

    //checks remove function if the node has two children that are leaves
    inputTree = inputTree->initializeRemove(inputTree, 12345678, amount, finalString);
    finalString = "";
    finalString = inputTree->initializePrintInorder(inputTree, amount);
    correctString = "Mary, Melissa";
    REQUIRE(finalString == correctString);

    //makes inputTree have nodes so that the remove functions can remove the right type of Node
    inputTree = inputTree->initializeInsert(inputTree, 12345668, "Donnie", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345663, "Lela", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345669, "Jeff", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345689, "Doug", amount, finalString);
    inputTree = inputTree->initializeInsert(inputTree, 12345699, "Ollie", amount, finalString);

    //checks remove function if the node has two children that are not leaves
    inputTree = inputTree->initializeRemove(inputTree, 12345673, amount, finalString);
    finalString = "";
    finalString = inputTree->initializePrintInorder(inputTree, amount);
    correctString = "Lela, Donnie, Jeff, Doug, Melissa, Ollie";
    REQUIRE(finalString == correctString);
}

TEST_CASE("AVL Tree: Large Tree")
{
    //initializes inputTree node, amount int, and finalString string,
    Node* inputTree = nullptr;
    int amount = 0;
    string finalString;

    //initialize correctOrder vector<pair<int, string>>, randomNum int, alphabet array of characters, and word string
    vector<pair<int, string>> correctOrder;
    int randNum = 0;
    char alphabet[26] =  { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };
    string word;


    //loops for 100 times and make a random 8-digit number and random name
    for (int i = 0; i < 100; i++)
    {
        randNum = rand() % (99999999 - 10000000 + 1) + 10000000;
        for (int j = 0; j < 10; j++)
        {
            word = word + alphabet[rand() % 26];
        }
        //adds the random number and name to the correctOrder vector
        correctOrder.emplace_back(randNum, word);

        //adds the random number and name to the inputTree
        inputTree = inputTree->initializeInsert(inputTree, randNum, word, amount, finalString);

        //resets the variables
        finalString = "";
        randNum = 0;
        word = "";
    }

    //creates the printInorder string
    finalString = inputTree->initializePrintInorder(inputTree, amount);

    //sorts the correctOrder vector by the IDs
    sort(correctOrder.begin(), correctOrder.end());

    //creates correctString and make it be each name in the correctOrder vector, with ", " between each.
    string correctString;
    for(int i = 0; i < 100; i++)
    {
        correctString += get<1>(correctOrder[i]);
        if(i < 99)
        {
            correctString += ", ";
        }
    }


    //tests to see if the strings are the same
    REQUIRE(correctString == finalString);

    //resets the finalString and correctString
    finalString = "";
    correctString = "";

    //initializes randPosition and removedValue
    int randPosition;
    int removedValue;


    //goes through 10 times and find a random position in correctOrder and deletes it in both correctOrder and inputTree
    for(int i = 0; i < 10; i++)
    {
        //finds a random position from 0-99
        randPosition = rand() % ((99 - i) - 0 + 1) + 0;

        //gets the value at the position
        removedValue = get<0>(correctOrder[randPosition]);

        //remove the value from both correctOrder and inputTree
        inputTree->initializeRemove(inputTree, removedValue, amount, finalString);
        correctOrder.erase(correctOrder.begin() + randPosition);

        //resets finalString
        finalString = "";
    }

    //creates the printInorder string
    finalString = inputTree->initializePrintInorder(inputTree, amount);

    //sorts the correctOrder vector by the IDs
    sort(correctOrder.begin(), correctOrder.end());


    //creates correctString and make it be each name in the correctOrder vector, with ", " between each.
    for(int i = 0; i < 90; i++)
    {
        correctString += get<1>(correctOrder[i]);
        if(i < 89)
        {
            correctString += ", ";
        }
    }

    //tests to see if the strings are the same
    REQUIRE(correctString == finalString);
}*/