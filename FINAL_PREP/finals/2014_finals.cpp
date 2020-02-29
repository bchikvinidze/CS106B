#include<iostream>
#include<vector>
#include <set>
using namespace std;
//ამოწმებს მოცემული სტრუქტურით მოცემული გრაფი ხეა თუ არა
struct Node {
	string town;
	Node * left=NULL, *right=NULL;
};
//სეტში ვინახავთ ყველა გავლილ წვეროს, თუ ერთზე მეტჯერ გავივლით
// ხე არაა
bool isRoot(Node * cur,set<Node *> &st){
    if (st.count(cur))
        return false;
    st.insert(cur);
    //მარცხენა წიბო
    if (cur->left!=NULL){
        if (!isRoot(cur->left,st))
            return false;
    }
    //მარჯვენა წიბო
    if (cur->right!=NULL){
        if (!isRoot(cur->right,st))
            return false;
    }
    return true;
}

bool isTreeRoot(Node * head){
    set<Node *> st;
    return isRoot(head,st);
}
//მეექვსე ამოცანა, კლასად გავაკეთე
//hospital.begin() მიმთითებელია პირველ წევრზე ვექტორში

class MultQueue{
    private:
        struct patient{
            string name;
            int prt;//priority
        };
        vector<patient> empty_vector;
        vector< vector<patient> > hospital;
    public:
        MultQueue();
        void addQueue();
        string dequeue(int i);
        void enqueue(string s, int p);
        int size();
        void removeQueue(int i);
};
//თავიდან ორი ცალით ვიწყებთ
MultQueue::MultQueue(){
    hospital.push_back(empty_vector);
    hospital.push_back(empty_vector);
}
//ცარიელის დამატება
void MultQueue::addQueue(){
    hospital.push_back(empty_vector);
}
//რადგან დალაგებულად ვინახავთ, პირდაპირ პირველივეს
//ამოვაგდგებთ და დავაბრუნებთ
string MultQueue::dequeue(int i){
    i--;
    string res=hospital[i][0].name;
    hospital[i].erase(hospital[i].begin());
    return res;
}
//ვეძებთ დასამატებელ ადგილს და ვამატებთ
void MultQueue::enqueue(string name, int prior){
    patient new_p={name,prior};//სტრუქტურაზე პირდაპირ ასე მინიჭება შეიძლება
    int pos=-1,best_pos=2000000000;
    int j=0;
    for (int i=0;i<hospital.size();i++){
        for (j=0;j<hospital[i].size();j++){
             if (prior<=hospital[i][j].prt)
                break;
        }
        if (j<best_pos)
            best_pos=j,pos=i;
    }
    //ნაპოვნ ადგილას "ჩავტენოთ" პაციენტი
    hospital[pos].insert(hospital[pos].begin()+best_pos,new_p);
}
//უბრალოდ ყრაოდენობა პაციენტების
int MultQueue::size(){
    int res=0;
    for (int i=0;i<hospital.size();i++)
        res+=hospital[i].size();
    return res;
}
//ყველას გადავანაწილებთ უკვე დაწერილი ფუნქციით და შესაბამის ვექტორს საერთოდ წავშლი
void MultQueue::removeQueue(int i){
    i--;
    while(hospital[i].size()>0){
        dequeue(i+1);
    }
    hospital.erase(hospital.begin()+i);//შესაბამისი რიგის წაშლა
}
int main(){

}
