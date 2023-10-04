#include<iostream>
#include<vector>
using namespace std;

class petrolPump{
    public:
    int petrol;
    int distance;
    petrolPump(int petrol,int distance){
        this -> petrol = petrol;
        this -> distance = distance;
    }
};

int tour(vector<petrolPump> p){

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int rear = 0 ; rear < p.size() ; rear++){
        balance += p[rear].petrol - p[rear].distance;
        if(balance < 0){
            start = rear + 1;
            deficit += balance;
            balance = 0;
        }
    }

    if(deficit + balance >= 0)
        return start;

    return -1;

}
int main(){
    vector<petrolPump> p;
    vector<int> petrol = {4,6,7,4};
    vector<int> distance = {6,5,3,5};
    for(int i = 0; i < petrol.size() ; i++){
        petrolPump obj(petrol[i],distance[i]);
        p.push_back(obj);
    }

    cout<<tour(p);
}