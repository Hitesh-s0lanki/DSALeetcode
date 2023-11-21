#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

// pair<int, int> 
// First -> burst Time
// Second -> Process Number

class compareSFC{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return  a.first > b.first;
    }
};


float FCFS(vector<int> burstTime, vector<int> arrivalTime){
    int processCount = burstTime.size();
    vector<int> copy = burstTime;

    vector<int> completeTime(processCount);

    int cnt = 0;
    for(int i = 0;i < processCount;i++){
        while(copy[i] != 0){
            cnt++;
            copy[i] --;
        }
        completeTime[i] = cnt;
    }

    int weightTime = 0;

    for(int i = 0; i < processCount;i ++){
        int turnAroundTime = abs(arrivalTime[i] - completeTime[i]);
        weightTime += abs(turnAroundTime - burstTime[i]);
    }

    return float(weightTime/float(processCount));
}

void insertArivalProcess(vector<int> burstTime, vector<int> &arrivalTime,priority_queue<pair<int, int>, vector<pair<int,int>>, compareSFC> &pq, bool toggle){
    int processCount = burstTime.size();
    for(int i = 0;i < processCount; i++){
        if(toggle){
            arrivalTime[i]--;
        }
        if(arrivalTime[i] == 0 && burstTime[i] != 0){
            arrivalTime[i]--;
            pq.push({burstTime[i],i});
        }
    }
}

float NonPreemptiveSFC(vector<int> burstTime, vector<int> arrivalTime){
    int processCount = burstTime.size();
    vector<int> copy = arrivalTime;

    priority_queue<pair<int, int>, vector<pair<int,int>>, compareSFC> pq;
    insertArivalProcess(burstTime , copy, pq, false);

    int totalWeightTime = 0;
    int cnt = 0;
    while(!pq.empty()){
        pair<int, int> element = pq.top();
        pq.pop();
        while(burstTime[element.second] != 0){
            burstTime[element.second]--;
            cnt++;
            insertArivalProcess(burstTime , copy, pq, true);
        }

        int tnt = abs(cnt - arrivalTime[element.second]);
        totalWeightTime += abs(tnt - element.first);
    }

    return float(totalWeightTime/float(processCount));
}


float PreemptiveSJF(vector<int> burstTime, vector<int> arrivalTime){
    int processCount = burstTime.size();
    vector<int> copy = arrivalTime;

    priority_queue<pair<int, int>, vector<pair<int,int>>, compareSFC> pq;
    insertArivalProcess(burstTime , copy, pq, false);

    int totalWeightTime = 0;
    int cnt = 0;
    while(!pq.empty()){
        pair<int, int> element = pq.top();
        pq.pop();
        while(burstTime[element.second] != 0){
            burstTime[element.second]--;
            cnt++;
            insertArivalProcess(burstTime , copy, pq, true);
            if(!pq.empty() && pq.top().first < burstTime[element.second]){
                pq.push({burstTime[element.second] ,element.second});
                break;
            }
        }
        if(burstTime[element.second] == 0){
            int tnt = abs(cnt - arrivalTime[element.second]);
            totalWeightTime += abs(tnt - element.first);
        }
    }

    return float(totalWeightTime/float(processCount));
}

void insertInJobQueue(vector<int> burstTime,vector<int> &arrivalTime,queue<pair<int, int>> &jobQueue, bool toggle){
    int processCount = burstTime.size();

    for(int i = 0;i < processCount; i++){
        if(toggle){
            arrivalTime[i] --;
        }
        if(arrivalTime[i] == 0 && burstTime[i] != 0){
            arrivalTime[i] --;
            jobQueue.push({burstTime[i], i});
        }
    }
}

float roundRobin(vector<int> burstTime, vector<int> arrivalTime, int timeQuantum){
    int processCount = burstTime.size();
    queue<pair<int,int>> jobQueue;

    vector<int> copy = arrivalTime;
    insertInJobQueue(burstTime, copy, jobQueue, false);

    int totalWeightTime = 0;
    int completeTime = 0;
    while(!jobQueue.empty()){
        int limit = timeQuantum;
        pair<int, int> element = jobQueue.front();
        jobQueue.pop();

        while(limit != 0 && burstTime[element.second] != 0){
            completeTime++;
            burstTime[element.second]--;
            limit--;
            insertInJobQueue(burstTime, copy, jobQueue, true);
        }

        if(burstTime[element.second] == 0){
            int tnt = abs(completeTime - arrivalTime[element.second]);
            totalWeightTime += abs(tnt - element.first);
        }else{
            jobQueue.push(element);
        }
    }
    

    return float(totalWeightTime/float(processCount));
}


int main(){
    // int n = 3;

    // vector<int> burstTime = {5 ,2 ,1};
    // vector<int> arrivalTime = {0, 0, 0};

    int n;
    cout<<"Enter the Number of process : ";
    cin>>n;

    
    vector<int> burstTime(n);
    vector<int> arrivalTime(n);

    for(int i = 0;i < n;i++){
        cout<<"for process "<<i + 1<<endl;
        cout<<"Enter the Burst Time : ";
        cin>>burstTime[i];
        cout<<"Enter the Arrival Time : ";
        cin>>arrivalTime[i];
    }


    cout<<"FCFS of this is : "<<FCFS(burstTime, arrivalTime)<<endl;
    cout<<"SJF of this is : "<<NonPreemptiveSFC(burstTime, arrivalTime)<<endl;
    cout<<"Preemptive SJF of this is : "<<PreemptiveSJF(burstTime, arrivalTime)<<endl;
    cout<<endl;
    int time;
    cout<<"Enter the time Quantum for roundRobin : ";
    cin>>time;
    cout<<endl;
    cout<<"RoundRobin of this is : "<<roundRobin(burstTime, arrivalTime, 1)<<endl;
}
