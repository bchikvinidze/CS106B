#include<iostream>
#include<set>
#include<stdio.h>
#include<vector>
using namespace std;
//უახლოესი მშობლის პოვნა
struct Node{
	Node * left=NULL, *right=NULL;//გასატესტად დამჭირდა, ხე კორექტული უნდა გადმოგვცენ
	int val;
};
//პოულობს პირველი წვეროდან(ფესვიდან) გზას შესაბამის
// წვერომდე მარტივი რეკურსიით
bool get_path(Node *root, Node * child, vector<Node *> &path,Node *cur_node){
    //ვიპოვეთ
    if (cur_node==child){
        path.push_back(cur_node);
        return true;
    }
    //თუ მარცხნივ წასვლით ვპოულობთ
    if (cur_node->left!=NULL)
        if (get_path(root,child,path,cur_node->left)){
                path.push_back(cur_node);//გზას უნდა დაემატოს
            return true;
        }
    //თუ მარჯვნივ წასვლით ვპოულობთ
    if (cur_node->right!=NULL)
        if (get_path(root,child,path,cur_node->right)){
            path.push_back(cur_node);//გზას უნდა დაემატოს
            return true;
        }
    //საერთოდ ვერ ვპოულობთ
    return false;
}
Node * ParentSearch(Node* root, Node* childOne, Node* childTwo){
    vector<Node *> path1;
    get_path(root,childOne,path1,root);//პირველამდე გზა
    vector<Node *> path2;
    get_path(root,childTwo,path2,root);//მეორემდე გზა
    set<Node *> tmp;
    for (int i=0;i<path1.size();i++)
        tmp.insert(path1[i]);
    for (int i=0;i<path2.size();i++)
        if (tmp.count(path2[i]))//თუ მეორემდე გზაში ქვემოდან შეგვხვდა
            return path2[i];
    return NULL;
}
//მოცემულია ბმული სია და ერთნაირსახელებიანი ელემენტებიდან
//მხოლოდ ერთი უნდა დავტოვოთ

struct node{
    string name;
    node *next;
};
void removeDublicates(node* head){
    vector<string> tmp;
    tmp.push_back(head->name);
    node *cur_node=head;
    node *prev=new node;
    while(cur_node->next!=NULL){
        prev=cur_node;
        cur_node=cur_node->next;
        string cur_name=cur_node->name;
        bool b=false;
        for (int i=0;i<tmp.size();i++)
            if (tmp[i]==cur_name){//თუ დუბლიკატია
                prev->next=cur_node->next;
                delete cur_node;
                cur_node=prev;
                b=true;
                break;
            }
            if (cur_node==NULL) break;
            if (b) continue;
            tmp.push_back(cur_name);
    }
}
// თუ n იყოფა რომელიმე მოცემულ რიცხვზე, n/a[i]-ურზე
// გადასვლა შეგვეძლება. ასევე დაშვებულია n-1ზე გადასვლა
// და გვაინტერესებს 1-მდე დაყვნაის რამდენი განსხვავებული გზა არსებობს
int PathCount(int n,  vector<int> &a){
    if (n==1)
        return 1;
    int res=0;
    res+=PathCount(n-1,a);
    for (int i=0;i<a.size();i++)
        if (n%a[i]==0)
            res+=PathCount(n/a[i],a);
    return res;
}
//პირობაში რაც წერია იმას აკეთბს პირდაპირ
//მაგრამ თვს ვერ დავდებ რომ სწორი ამოხსნაა
//შეიძლება ითხოვდნენ რომ ინფორმაცია არ დაკარგო,
//რაც ჩემთან ხდება.
class FileSystem{
    private:
        vector<string> cur_folders;
        string active_folder;
        vector<string> cur_files;
    public:
        vector<string> getFolderList();
        vector<string> getFileList();
        bool createFolder(string name);
        bool createFile(string name);
        bool selectFolder(string name);
};
vector<string> FileSystem::getFolderList(){
    return cur_folders;
}
vector<string> FileSystem::getFileList(){
    return cur_files;
}
bool FileSystem::createFolder(string name){
    for (int i=0;i<cur_folders.size();i++)
        if (cur_folders[i]==name)
            return false;
    cur_folders.push_back(name);
    return true;
}
bool FileSystem::createFile(string name){
    for (int i=0;i<cur_files.size();i++)
        if (cur_files[i]==name)
            return false;
    cur_files.push_back(name);
    return true;
}
bool FileSystem::selectFolder(string name){
    for (int i=0;i<cur_folders.size();i++)
        if (cur_folders[i]==name){
            active_folder=name;
            cur_folders.clear();
            cur_files.clear();
            return true;
        }
     return false;
}

int main(){

}
