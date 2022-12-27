#include <iostream>
#include <thread>
#include <atomic> 

using namespace std;

long long count = 0;
atomic <long long> count_atm(0);

void Task(){
	for(int i = 0 ; i < 1000000 ; i++){
		count++;
		count_atm++;
	}
}

int main(){
	thread t1(Task);
	thread t2(Task);

	t1.join();
	t2.join();

	//This is normal variable 
	cout<<count<<endl;
	//This is atomic variable i.e., context switching happens only when manipulation is completed
	cout<<count_atm<<endl;

	return 0;
}
