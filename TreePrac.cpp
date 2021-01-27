#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *pRight , *pLeft;
        Node(){
            pRight = NULL;
            pLeft = NULL;
        }
};
class Tree{
    private:
        Node *pRoot;
    public:
        Tree(){
            pRoot = NULL;
        }
        
        void addNode(int x){
            Tree t;
            if(pRoot == NULL){
                Node *p = new Node();
                p->data = x;
                pRoot = p;
            }else{
                if(x < pRoot->data){
                    t.pRoot = pRoot->pLeft;
                    t.addNode(x);
                    pRoot->pLeft = t.pRoot;
                }else if (x > pRoot->data){
                    t.pRoot = pRoot->pRight;
                    t.addNode(x);
                    pRoot->pRight = t.pRoot;
                }
            }
        }

        void NLR(){
            Tree t1,t2;
            if(pRoot !=NULL){
                cout << pRoot->data <<"\t";

                t1.pRoot = pRoot->pLeft;
                t1.NLR();

                t2.pRoot = pRoot->pRight;
                t2.NLR();
            }
        }
        
        void LNR(){
            Tree t1,t2;
            if(pRoot != NULL){
                t1.pRoot = pRoot->pLeft;
                t1.LNR();

                cout <<pRoot->data<<"\t";

                t2.pRoot = pRoot->pRight;
                t2.LNR();
            }
        }

        void LRN(){
            Tree t1,t2;
            if(pRoot !=NULL){
                t1.pRoot = pRoot->pLeft;
                t1.LRN();

                t2.pRoot = pRoot->pRight;
                t2.LRN();

                cout << pRoot->data <<"\t";
            }
        }

        void RLN(){
            Tree t1,t2;
            if(pRoot !=NULL){
                t1.pRoot = pRoot->pRight;
                t1.RLN();

                t2.pRoot = pRoot->pLeft;
                t2.RLN();

                cout << pRoot->data <<"\t";
            }
        }


        void findMax(){
            Tree t; 
            if(pRoot != NULL){
                if(pRoot->pRight == NULL){
                    cout <<"MAX: "<<pRoot->data<<endl;
                }else{
                    t.pRoot = pRoot->pRight;
                    t.findMax();
                }
            }
        }

        void findMin(){
            Tree t;
            if(pRoot !=NULL){
                if(pRoot->pLeft ==NULL){
                    cout << "MIN: "<< pRoot->data<<endl;
                }else{
                    t.pRoot = pRoot->pLeft;
                    t.findMin();
                }
            }
        }

        Node *findValue(int x){
            Tree t;
            if(pRoot != NULL){
                if(x == pRoot->data){
                    return pRoot;
                }else if(x < pRoot->data){
                        t.pRoot = pRoot->pLeft;
                        return t.findValue(x);
                } else{
                        t.pRoot = pRoot->pRight;
                        return t.findValue(x);
               }
            }
            return NULL;
        }
        
        int totalNodes(){
            Tree t1,t2;
            int nL ; 
            int nR ;
            if(pRoot !=NULL){
                t1.pRoot = pRoot->pLeft;
                nL = t1.totalNodes();

                t2.pRoot = pRoot->pRight;
                nR = t2.totalNodes();
                return (nL + nR + 1);
            } else {
                return 0;
            }
        }

        void nodeLa(){
            Tree t1,t2;
            if(pRoot->pLeft ==NULL && pRoot->pRight == NULL){
                cout <<pRoot->data << "\t";
            } 
            if(pRoot->pLeft !=NULL){
                t1.pRoot = pRoot->pLeft;
                t1.nodeLa();
            }
            if(pRoot->pRight !=NULL){
                t2.pRoot = pRoot->pRight;
                t2.nodeLa();
            }
        }

        void nodeMotCon(){
            Tree t1,t2;
            if(pRoot->pLeft != NULL && pRoot->pRight == NULL || 
            pRoot->pLeft == NULL && pRoot->pRight !=NULL){
                cout <<pRoot->data<<"\t";
            }
            if(pRoot->pLeft != NULL){
                t1.pRoot = pRoot->pLeft;
                t1.nodeMotCon();
            }
            if(pRoot->pRight !=NULL){
                t2.pRoot = pRoot->pRight;
                t2.nodeMotCon();
            }
        }

        void nodeHaiCon(){
            Tree t1,t2;
            if(pRoot->pLeft !=NULL && pRoot->pRight !=NULL){
                cout <<pRoot->data <<"\t";
            }
            if(pRoot->pLeft != NULL){
                t1.pRoot = pRoot->pLeft;
                t1.nodeHaiCon();
            }
            if(pRoot->pRight != NULL){
                t2.pRoot = pRoot->pRight;
                t2.nodeHaiCon();
            }
        }

        void xoaCay(){
            Tree t1,t2;
            if(pRoot !=NULL){
                t1.pRoot = pRoot->pLeft;
                t1.xoaCay();

                t2.pRoot = pRoot->pRight;
                t2.xoaCay();

                delete pRoot;
                pRoot = NULL;
            }
        }

        void xoaNodeX(int x){
            Tree t1,t2;
            
            if(pRoot !=NULL){
                if(x < pRoot->data){
                    t1.pRoot = pRoot->pLeft;
                    t1.xoaNodeX(x);
                    pRoot->pLeft = t1.pRoot;
                } else if (x > pRoot->data){
                    t2.pRoot = pRoot->pRight;
                    t2.xoaNodeX(x);
                    pRoot->pRight = t2.pRoot;
                } else {
                    Node *pTemp = pRoot;
                    //x == pRoot->data
                     if (pRoot->pLeft == NULL){ // node co 1 con
                        pRoot =pRoot->pRight;
                        delete pTemp;
                    }else if (pRoot->pRight == NULL){
                        pRoot =pRoot->pLeft;
                        delete pTemp;
                    }else if (pRoot->pLeft != NULL && pRoot->pRight != NULL){
                        Tree t;
                        Node *q = pRoot->pRight; // tro qua ben phai 
                        while(q->pLeft !=NULL){
                            q=q->pLeft; // cho toi gia tri nho nhat ben tran cua nhanh phai;
                        }
                        pRoot->data = q->data;
                        t.pRoot = pRoot->pRight;
                        t.xoaNodeX(q->data);
                        pRoot->pRight = t.pRoot;

                    }


                }
                
            }
        }
};

int main(){
    Tree t;
    t.addNode(5);
    t.addNode(3);
    t.addNode(6);
    t.addNode(3);
    t.addNode(4);
    t.addNode(7);
    t.addNode(9);
    // t.addNode(14);
    // t.addNode(19);
    // t.addNode(7);
    // t.RLN();
    t.LNR();
    // t.NLR();
    // cout <<endl;
    // t.LNR();
    // cout <<endl;
    // t.LRN();
    // cout <<endl;

    // t.findMax();
    // cout <<endl;
    // t.findMin();
    // cout <<endl;

    // int x;
    // cout <<"Phan tu muon tim kiem: ";
    // cin >> x;
    // cout << t.findValue(x)->data<<endl;

    // cout << t.totalNodes() << endl;
    cout << endl;
    t.xoaNodeX(9);
    // t.nodeLa();
    // cout <<endl;
    t.LNR();
    // t.nodeMotCon();
    // cout <<endl;

    // t.nodeHaiCon();
    // cout <<endl;

    t.xoaCay();
    cout <<"show"<<endl;
    // t.LNR();
    system("pause");
    return 0;
}