#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum CoordType { Wall, Object, Exit, Empty };

struct Node {
    CoordType type;
    int distance;
    Node* up;
    Node* down;
    Node* left;
    Node* right;
};

typedef vector<Node*> Row;
typedef vector<Row> Matrix;

int main() {
    int R, C;
    Matrix mat = Matrix();
    Node* exit = nullptr;
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        string temp = "";
        cin >> temp;
        Row r = Row();
        mat.push_back(r);
        for(int j = 0; j < C; j++) {
            Node* n = new Node();
            n->distance = -1;
            n->up = nullptr;
            n->down = nullptr;
            n->right = nullptr;
            n->left = nullptr;
            switch (temp[j])
            {
            case '.':
                n->type = Empty;
                if(j > 0) {
                    if(mat[i][j-1]->type == Empty || mat[i][j-1]->type == Exit) {
                        n->left = mat[i][j-1];
                        n->left->right = n;
                    }
                }
                if(i > 0) {
                    if(mat[i - 1][j]->type == Empty || mat[i - 1][j]->type == Exit) {
                        n->up = mat[i - 1][j];
                        n->up->down = n;
                    }
                }
                break;
            case '#':
                n->type = Wall;
                break;
            case 'X':
                n->type = Object;
                break;
            case 'E':
                n->type = Exit;
                exit = n;
                n->distance = 0;
                if(j > 0) {
                    if(mat[i][j-1]->type == Empty || mat[i][j-1]->type == Exit) {
                        n->left = mat[i][j-1];
                        n->left->right = n;
                    }
                }
                if(i > 0) {
                    if(mat[i - 1][j]->type == Empty || mat[i - 1][j]->type == Exit) {
                        n->up = mat[i - 1][j];
                        n->up->down = n;
                    }
                }
                break;
            }
            mat[i].push_back(n);
        }
    }

    queue<Node*> q = queue<Node*>();
    q.push(exit);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        if(current->up && current->up->type == Empty && current->up->distance == -1) {
            current->up->distance = current->distance + 1;
            q.push(current->up);
        }
        if(current->down && current->down->type == Empty && current->down->distance == -1) {
            current->down->distance = current->distance + 1;
            q.push(current->down);
        }
        if(current->right && current->right->type == Empty && current->right->distance == -1) {
            current->right->distance = current->distance + 1;
            q.push(current->right);
        }
        if(current->left && current->left->type == Empty && current->left->distance == -1) {
            current->left->distance = current->distance + 1;
            q.push(current->left);
        }
    }

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int I, J;
        cin >> I >> J;
        switch (mat[I-1][J-1]->type)
        {
        case Wall:
            cout << 'W' << endl;
            break;
        case Object:
            cout << 'X' << endl;
            break;
        case Exit:
            cout << 'E' << endl;
            break;
        case Empty:
            if(mat[I-1][J-1]->distance == -1) {
                cout << '?' << endl;
            }
            else {
                char minC = ' ';
                int minD = INT_MAX;

                if(mat[I-1][J-1]->left && mat[I-1][J-1]->left->distance < minD) {
                    minC = 'L';
                    minD = mat[I-1][J-1]->left->distance;
                }
                if(mat[I-1][J-1]->down && mat[I-1][J-1]->down->distance < minD) {
                    minC = 'D';
                    minD = mat[I-1][J-1]->down->distance;
                }
                if(mat[I-1][J-1]->right && mat[I-1][J-1]->right->distance < minD) {
                    minC = 'R';
                    minD = mat[I-1][J-1]->right->distance;
                }
                if(mat[I-1][J-1]->up && mat[I-1][J-1]->up->distance < minD) {
                    minC = 'U';
                    minD = mat[I-1][J-1]->up->distance;
                }

                cout << minC << endl;
            }
            break;
        }
    }

}