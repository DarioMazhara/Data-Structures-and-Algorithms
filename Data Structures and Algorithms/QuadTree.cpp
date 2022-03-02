//
//  QuadTree.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/23/22.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) {
        this->x = x; this->y = y;
    }
    Point() {this->x = this->y = 0;}
};
struct Node {
    Point pos;
    int data;
    Node(Point pos, int data) {
        this->pos = pos;this->data = data;
    }
    Node() {data = 0;}
};

class QuadTree {
    Point topLeft, botRight;
    
    Node *n;
    
    QuadTree *topLeftTree, *topRightTree, *botLeftTree, *botRightTree;
    
public:
    QuadTree() {
        topLeft = botRight = Point(0, 0);
        n = NULL;
        topLeftTree = topRightTree = botLeftTree = botRightTree = NULL;
    }
    QuadTree(Point topL, Point botR) {
        n = NULL;
        topLeftTree = topRightTree = botLeftTree = botRightTree = NULL;
        topLeft = topL;
        botRight = botR;
    }
    
    bool inBoundary(Point);
    void insert(Node* node) {
        if (node == NULL)
            return;
        
        if (!inBoundary(node->pos))
            return;
        
        if (abs(topLeft.x - botRight.x) <= 1 &&
            abs(topLeft.y - botRight.y) <= 1)
        {
            if (n == NULL)
                n = node;
            return;
        }
        
        if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
            
                if ((topLeft.y + botRight.y) /2 >= node->pos.y) {
                    if (topLeftTree == NULL)
                        topLeftTree = new QuadTree(
                        Point(topLeft.x, topLeft.y),
                        Point((topLeft.x + botRight.x) / 2,
                        (topLeft.y + botRight.y) / 2));
                    topLeftTree->insert(node);
                }
        
                else {
                    if (botLeftTree == NULL)
                        botLeftTree = new QuadTree(
                        Point(topLeft.x, (topLeft.y + botRight.y) / 2),
                        Point((topLeft.x + botRight.x)/2, botRight.y));
                    botLeftTree->insert(node);
                     }
        }
        else {
            if((topLeft.y + botRight.y) / 2 >= node->pos.y)
            {
                if(topRightTree == NULL)
                    topRightTree = new QuadTree(
                            Point((topLeft.x + botRight.x) / 2,
                                  topLeft.y),
                            Point(botRight.x,(topLeft.y + botRight.y) / 2));
                topRightTree->insert(node);
            }
            
            else {
                if (botRightTree == NULL)
                    topRightTree = new QuadTree(
                                                Point((topLeft.x + botRight.x) / 2,
                                                      (topLeft.y + botRight.y) / 2),
                                                Point(botRight.x, botRight.y));
                botRightTree->insert(node);
            }
        }
    }
};
