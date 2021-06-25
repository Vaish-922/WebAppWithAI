#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node *>child;
};
  
Node *newNode()
{
    Node *temp = new Node;
    return temp;
}


Node* root = newNode();

void inittree()
{
  root->child = {newNode(),newNode(),newNode()};

  root->child[0]->child={newNode(),newNode(),newNode()};
  root->child[0]->child[0]->child={newNode(),newNode()};
  root->child[0]->child[0]->child[0]->val=4;
  root->child[0]->child[0]->child[1]->val=13;
  root->child[0]->child[1]->child={newNode(),newNode()};
  root->child[0]->child[1]->child[0]->child={newNode(),newNode()};
  root->child[0]->child[1]->child[0]->child[0]->val=5;
  root->child[0]->child[1]->child[0]->child[1]->val=10;
  root->child[0]->child[1]->child[1]->val = 11;
  root->child[0]->child[2]->val=16;

  root->child[1]->child={newNode(),newNode()};
  root->child[1]->child[1]->val=12;
  root->child[1]->child[0]->child ={newNode(),newNode(),newNode()};
  root->child[1]->child[0]->child[1]->val=9;
  root->child[1]->child[0]->child[0]->child={newNode(),newNode()};
  root->child[1]->child[0]->child[2]->child={newNode(),newNode()};
  root->child[1]->child[0]->child[0]->child[0]->val=1;
  root->child[1]->child[0]->child[0]->child[1]->val=8;
  root->child[1]->child[0]->child[2]->child[0]->val=6;
  root->child[1]->child[0]->child[2]->child[1]->val=12;

  root->child[2]->child={newNode(),newNode()};
  root->child[2]->child[0]->child ={newNode(),newNode(),newNode()};
  root->child[2]->child[0]->child[0]->val=10;
  root->child[2]->child[0]->child[1]->val=8;
  root->child[2]->child[0]->child[2]->child={newNode(),newNode(),newNode()};
  root->child[2]->child[0]->child[2]->child[0]->val=2;
  root->child[2]->child[0]->child[2]->child[1]->val=5;
  root->child[2]->child[0]->child[2]->child[2]->val=7;
  root->child[2]->child[1]->child ={newNode(),newNode()};
  root->child[2]->child[1]->child[1]->val=4;
  root->child[2]->child[1]->child[0]->val=7; 

}

int ab(Node* node = root, int alpha = INT_MIN, int beta = INT_MAX, bool maximise= true)
 {
		//printf("%c\n", node);
		if(node->child.size()) {
			if(maximise) {
				node->val = INT_MIN;
				for(int i = 0; i < node->child.size(); i++) {
							
					int child_val = ab(node->child[i], alpha, beta, !maximise);
					node->val = max(node->val, child_val);
					
					alpha = max(alpha, node->val);
          if(alpha >= beta) {
						break;
					}
				}
			}
			else {
				node->val = INT_MAX;
				for(int i = 0; i < node->child.size(); i++) {
					int child_val = ab(node->child[i], alpha, beta);
					node->val = min(node->val, child_val);
					beta = min(beta, node->val);	
          if(alpha >= beta) {
						break;			
				}	
			}
		}
		
	}
  printf(" %d\n",node->val);
		printf("alpha = %d, beta = %d\n", alpha, beta);
		printf("\n");
		return node->val;

 }

int main(){

  inittree();
  ab();

  
}