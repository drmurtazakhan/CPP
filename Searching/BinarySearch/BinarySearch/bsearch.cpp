#include <iostream>
#include <string>

using namespace std;

void printintAry(int a[], int N) {
     for (int i = 0; i < N; i++)
		 cout << a[i] << " "; 
	 cout <<"\n"; 
}


int  bsearch(int x[], int v, int N){
	

	int mid,diff;
	int from=0;
	int to=N-1;	

	while (from<=to){
		mid = (from + to) / 2;
		diff = x[mid] - v;
		if(diff == 0) // a[mid] == v
			return mid;		
		else if (diff < 0) // a[mid] < v 
			from = mid+1;
		else
			to = mid-1;
	}
	
	return -1;
}

int main()
{
	int x[]={2,4,7,10,30,33,40,50};
	const int N=sizeof x / sizeof x[0];
    
	int v;
	int indx;

    
	printintAry(x, N);
	cout <<"Size of array is: "<< N << "\n";
	cout <<"Index range: "<< 0; cout <<" to "<< N-1<< "\n";;  
	cout << "Enter the value to be search :";
    cin  >> v;
  
		
	indx=bsearch(x, v, N);
	cout << "found at index: " << indx << "\n";
	return 0;
}