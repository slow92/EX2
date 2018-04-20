#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>
#include <algorithm>



const size_t vector_size = 1000;
const size_t low_bound = 0;
const size_t up_bound = 1000000;


void vector_sort(std::vector<int> vec){
	std::cout<<"asd \n";
	auto start = std::chrono::system_clock::now();
	std::sort(vec.begin(), vec.end());
	auto stop = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = stop-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
	std::cout << "vector sorting at " << std::ctime(&end_time)
	<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void list_sort(std::list<int> lis){
	auto start = std::chrono::system_clock::now();
	lis.sort();
	auto stop = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = stop-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
	std::cout << "list sorting at " << std::ctime(&end_time)
	<< "elapsed time: " << elapsed_seconds.count() << "s\n";
} 


void vector_list_sort(std::vector<int> vec, std::list<int> lis){
	auto start = std::chrono::system_clock::now();
	std::copy (lis.begin(),lis.end(),back_inserter(vec));
	std::sort(vec.begin(), vec.end());
	std::copy (vec.begin(),vec.end(),back_inserter(lis));
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "list to vector sorting and back to list at " << std::ctime(&end_time)
	<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
 
int main()
{
	std::random_device dev;
	std::mt19937 gen(dev());
	std::uniform_int_distribution<int> distribution(low_bound, up_bound);

	std::vector<int> vi0, vi;
	std::list<int> li;
	std::cout<<"Hello world"<<std::endl;

 	
    for (size_t n=0; n<vector_size; ++n){
       vi0.push_back(distribution(gen));
	vi.push_back(vi0[n]);
	li.push_back(vi0[n]);        
	}
	vector_sort(vi0);
	list_sort(li);
	vector_list_sort(vi,li);
	
	return 0;

}
