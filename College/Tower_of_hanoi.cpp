#include<iostream>
using namespace std;

void tower_of_hanoi(int n,char from_disk,char to_disk,char aux_disk){
    if(n == 0) return;
    tower_of_hanoi(n-1, from_disk, aux_disk, to_disk);
    cout<<"From disk : "<<from_disk<<" "<<"To Disk : "<<to_disk<<endl;
    tower_of_hanoi(n-1, aux_disk, to_disk, from_disk);
}

int main(){
    int Disk = 5;
    tower_of_hanoi(Disk,'A','C','B');
}
  