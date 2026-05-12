#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
void linear_search(int arr[],int n){
    int target =rand();
     for(int i=0; i<n; i++){
            if(arr[i]==target){
                break;
            }
        }
}
int calculate_time(int arr[],int n){
    int total_time= 0;
    for(int i=0; i<100; i++){
        for(int i=0; i<n; i++){
            arr[i] = rand();
        }
        auto x = system_clock::now();
       linear_search(arr,n);
        auto y = system_clock::now();
         total_time += duration_cast<nanoseconds>(y - x).count();

      
    }
    return total_time/100;
}

int main(){
    int arr[10000];
    for(int i=1000; i<10000; i+=1000){
        int ans = calculate_time(arr,i);
        cout<<"For size "<<i<<" the time taken was "<<ans<<"ns"<<endl;
    }
    return 0;
}