#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *pNext;

        Node(){
            pNext=NULL;
        }
};
class Linked{
    private:
        Node *pHead;
    public:
        Linked(){
            pHead = NULL;
        }

        void createNode(Node *pNode){
            if(pHead == NULL){
                pHead = pNode;
                pNode->pNext = pHead;
            }else{
                pNode->pNext = pHead->pNext;
                pHead->pNext = pNode;
            }
        }

        void addData(int data){
            Node *pTemp = new Node();
            if(pTemp == NULL){
                cout <<"Khong con bo nho \n";
            }
            else{
                pTemp->data = data;
                pTemp->pNext = NULL;
            }
            createNode(pTemp);
        }

        void show(){
            Node *p = pHead;
            if(pHead !=NULL){
                cout <<"\t\t HIEN THI LINK \t\t"<<endl;
                do{
                    cout <<p->data <<"\t";
                    p = p->pNext;
                }while(p!=pHead);
            }else{
                cout <<"\t\t LINKED RONG \t\t" <<endl;
            }
            cout <<endl;
        }
       
       void input(){
           int n ;
           cout <<"Nhap so luong phan tu n= ";
           cin >> n;

           for(int i=0;i<n;i++){
               int x;     
               cout <<"Phan tu thu "<<i <<" la: ";
               cin >>x;

               addData(x);
           }
           cout <<endl;
       }

       Node *getLastNode(){
            Node *p = pHead;
            if(pHead !=NULL){
                do{
                    p = p->pNext;
                }while(p->pNext!=pHead);
                return p;
            }   
       }

       void findMax(){
           Node *p = pHead;
           int pos =0;
           if(pHead != NULL){
               int temp = pHead->data;
               do{
                   if(temp < p->data){
                       temp = p->data;
                       pos++;
                       
                   }
                   p=p->pNext;
               }while(p!=pHead);

               cout <<"MAX: "<< temp << "\t Pos: "<<pos <<endl;
           }
       }
      
       void findMin(){
           Node *p = pHead;
           int pos=0;
           if(pHead != NULL){
               int temp = pHead->data;
               do{
                   if(temp > p->data){
                       temp = p->data;
                       pos++;
                   }
                  p=p->pNext; 
               }while(p!=pHead);

               cout <<"MIN: "<<temp<<"\t Pos: "<<pos<<endl;
           }
       }

       int totalNodes(){
           Node *p = pHead;
           int i=0;
           if(pHead != NULL){
               do{
                   i++;
                   p=p->pNext;
               }while(p!=pHead);
           }
           return i;      
       }

       void insertRandom(int data, int pos){
           // node moi can add
           Node *pAdd = new Node();
           pAdd->data = data;
           pAdd->pNext =NULL;
            // vi tri temp
            int count = 1; // bat dau vi tri thu 2

          if(pHead == NULL){
              if(pos == 0){
                  createNode(pAdd);
              }else{
                  cout <<"Khong ton tai vi tri ";
                  delete pAdd;
              }
          }else{
              Node *p = pHead;
              do{
                  // add tai HEAD
                  if(pos == 0){
                      Node *lastNode = getLastNode(); // lay node cuoi cung;
                      pAdd->pNext = lastNode->pNext; //  Next nodeAdd tro toi dau NodeHead bang lay node cuoi tro ve lai head
                      lastNode->pNext = pAdd; // Next node cuoi tro vo Node Add
                      pHead = pAdd; // gan pHead cho pAdd lam HEAD
                      return;
                  }else{
                      if(count == pos){
                          pAdd->pNext = p->pNext;
                          p->pNext = pAdd;
                          return;
                      }
                  }
                  count++;
                  p=p->pNext;
              }while(p!=pHead);    
                
          }
       }

       void AddNodeAfterNodeX(int data,int nodeX){
           Node *pAdd = new Node();
           pAdd->data = data;
           pAdd->pNext = NULL;

           if(pHead == NULL){
               cout <<"LINKED RONG NEN KHONG THE CO GIA TRI NODEX \n NEN DE THEM SAU NODEX DO NEN SE ADD VAO VI TRI DAU TIEN"<<endl;
               createNode(pAdd);
           }else{
               Node *p = pHead;

               do{
                   if(p->data == nodeX){
                       pAdd->pNext = p->pNext;
                       p->pNext = pAdd;
                       return;
                   }
                   p=p->pNext;
               }while(p!=pHead);
           }
       }

        // Xoa Head de thang ke tiep lam head;
       void removeHead(){
            if(pHead->pNext == pHead){
                pHead = NULL;
            }else{
                Node *p = pHead;
                Node *lastNode = getLastNode(); // lay Node CUOI 
                lastNode->pNext = p->pNext; // lay NEXT nodeCUOI tro ve dau` cua node ke Head 
                pHead = p->pNext; // gan pHead la Node ke tiep nodeHead
                delete p; // xoa node temp di 
                p = NULL; // gan node do thanh null
            }
        }

       void deletePosRandom(int pos){
           int count =1;
           if(pHead == NULL){
               cout << "LINKED RONG KHONG XOA DUOC"<<endl;
           }else{
               if(pos < 0 || pos >= totalNodes()){
                   cout <<"KHONG TON TAI VI TRI "<<endl;
                   return;
               }
               if(pos == 0){
                   removeHead();
                   return;
               }else{
                   Node *p = pHead;
                   do{
                       if(count == pos){
                            Node *pTemp = p->pNext;
                            p->pNext = p->pNext->pNext;
                            delete pTemp;
                            return;
                       }
                       count++;
                       p=p->pNext;
                   }while(p!=pHead);
               }
           }
       }

       void deleteNodeX(int x){
           if(pHead == NULL){
               cout <<"LINKED RONG KHONG CO GI DE XOA"<<endl;
           }else{
               Node *p = pHead;
               if(pHead->data == x){
                   removeHead();
                   return;
               }else{
                    do{
                        if(p->pNext->data == x){
                            Node *pTemp = p->pNext;
                            p->pNext = p->pNext->pNext;
                            delete pTemp;
                            return;
                        }
                    p=p->pNext;
                    }while(p!=pHead);
               }
           }
       }

        // Hoan vi 2 so 
       void swap(int &a , int &b){
           int temp = a;
           a = b;
           b = temp;
       }

       void interchangeSort(){
           if(pHead == NULL){
               cout <<" LINKED RONG KHONG CO PHAN TU DE SORT" <<endl;
            }else{
                for(Node *i = pHead;i->pNext!=pHead;i=i->pNext){  
                    for(Node *j = i->pNext;j!=pHead;j=j->pNext){
                        if(i->data > j->data){
                            swap(i->data,j->data);
                        }
                    }  
                }
            }
       }

       void selectionSort(){      
           if(pHead == NULL){
               cout <<"LINKED RONG KHONG CO PHAN TU DE SORT"<<endl;
           }else{
               for(Node *i=pHead;i->pNext !=pHead;i=i->pNext){
                   Node *min = i; // doi cho gia tri min
                   for(Node *j=i->pNext;j!=pHead;j=j->pNext){
                       if(min->data > j->data){
                          min = j;
                       }
                   }
                   swap(min->data,i->data);
               }
           }
       }

       void bubbleSort(){
           Node *pivot = pHead;
           Node *j;
           
           for(Node *i = pHead;i->pNext !=pHead;i=i->pNext){
               for(j = pHead;j->pNext != pivot;j=j->pNext){
                   if(j->data > j->pNext->data){
                       swap(j->data , j->pNext->data); 
                   }
               }
               pivot = j;
           }
       }

       void quickSort(){
           Linked l1 , l2;
           Node *p ,*tag,*temp;
           if(pHead == NULL){ 
            //    cout <<"LINKED RONG HET PTU"<<endl;
               return ;
           }else if(pHead->pNext == pHead){ //  tach cho den khi chi con 1 Node
               return;
           }
           tag = pHead; // co lap Head
           getLastNode()->pNext = pHead->pNext;
           pHead = pHead->pNext;
           temp = pHead;
           tag->pNext = NULL; // co lap tag
           do{
               p = temp; 
               temp = temp->pNext;
               p->pNext = NULL; // co lap tung phan tu cua temp ra de so snah
               
               if(p->data <= tag->data){
                   l1.addData(p->data); // tao list 1 voi phan tu nho hon or bang
               }else{
                   l2.addData(p->data) ; // tao list 2 voi phan tu lon hon
               }
           }while(temp !=pHead);    
            // De qui lai quick sort de tach phan tu tiep 
            l1.quickSort(); // tiep tuc chia nho list 1
            l2.quickSort(); // tiep tuc chia nho list 2
            
            // NOI LAI LIST L1 & L2
            if(l1.pHead !=NULL){
                pHead = l1.pHead;
                l1.getLastNode()->pNext = tag; // noi list 1 nho vao  tag
            }else{
                pHead = tag; //Rong thi HEAD tro vao tag;
            }

            if(l2.pHead !=NULL){
                tag->pNext = l2.pHead; // noi tag vao voi list2 lon hon
                l2.getLastNode()->pNext = pHead; // tro duoi list2 ve head de tro thanh lien ket vong;
            }else{
                tag->pNext = pHead;
            }
       }
};

int main(){
    Linked *l = new Linked();
    // l->addData(1);
    // l->addData(5);
    // l->addData(2);
    // l->addData(3);
    // l->addData(4);
    // l->addData(5);
    
    // Nhap / xuat Linked
    // l->input();
    // l->show();

    // Max - Min
    // l->findMax();
    // l->findMin();

    //
    // cout <<l->totalNodes() << endl;
    l->show();
    // l->insertRandom(6,2);

    // l->AddNodeAfterNodeX(3,5);
    // l->deletePosRandom(4);
    // l->deleteNodeX(2);
    // l->interchangeSort();
    // l->selectionSort();
    // l->bubbleSort();

    l->quickSort();
    l->show();
    delete l;
    system("pause");
    return 0;
}
