#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

long long count = 0;

void Task(){
	for(int i = 0 ; i < 1000000 ; i++) count++;
}

int main(){
	thread t1(Task);
	thread t2(Task);

	t1.join();
	t2.join();

	cout<<count<<endl;

	return 0;
}
