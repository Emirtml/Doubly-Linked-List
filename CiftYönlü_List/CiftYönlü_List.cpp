#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;  // prev = bir önceki;
};

node* tail, * head; // global degisken 

void Add(int x) {

    node* temp = new node();  //(node*)malloc(1 * sizeof(node*));
    temp->next = temp->prev = NULL;
    temp->data = x;
    
    if (!head) { // head bosmu
        head = tail = temp;
        return;
    }

    tail->next = temp;   // dönüslü listin oldugu yer
    temp->prev = tail;
    tail = temp;
    
    return;
}

void Listele() {
    node* temp = head;
    while (temp) { // != yerine do kullanınca düzeliyor
        cout << temp->data<<endl;
        temp = temp->next;
    }
    cout << endl;

}

void TerstenListele() {
    node* temp = tail;
    cout << "tersten sirali list:" << endl;
    while (temp) { // != yerine do kullanınca düzeliyor.
        cout << temp->data << endl;
        temp = temp->prev;
    }
    cout << endl;
}

int pop(int x) {
    
    if (head->data == x) {
        struct node* t = head;
        head = head->next;
        free(t);
        head->prev = NULL;
        return 1;
    }
    
    struct  node* index = head;
    struct  node* tprev = index;
    while (index->data != x && index != NULL) {
        tprev = index;
        index = index->next;
    }
    if (index == NULL) {
        cout << "silinecek eleman listede yok" << endl;
        return 1;
    }
    tprev->next = index->next;
    index->next->prev = tprev;
}

int main()
{
    Add(11); Add(22); Add(33); Add(31);
    pop(22);
   
    Listele();
    TerstenListele();

   return 0;
}



