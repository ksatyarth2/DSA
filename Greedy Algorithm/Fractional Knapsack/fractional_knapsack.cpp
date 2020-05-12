#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void pairsort(const vector<double>&a, vector<int> &b, int n) 
{ 
    vector< pair <double,int> > vect; 
    for (int i=0; i<n; i++) 
		vect.push_back( make_pair(a[i],b[i]) ); 
    sort(vect.begin(), vect.end(),greater< pair <double,int> >()); 
    	for (int i=0; i<n; i++) 
        b[i]=vect[i].second;
} 

double get_optimal_value(int capacity, vector<int> weights, vector<int> values,int n) {
  double value = 0.0,a;
  vector<double>ratio(n);
  for (int i = 0; i < n; i++)
  {
    ratio[i]=(double(values[i])/double(weights[i]));
  }
  pairsort(ratio,weights,n);
  pairsort(ratio,values,n);
  
  sort(ratio.begin(), ratio.end(), greater<double>()); 
  
  for (int i = 0; i < n; i++)
  {
    if(capacity==0) return value;
    a=min(weights[i],capacity);
    value=value+a*ratio[i];
    // weights[i]-=a;
    capacity-=a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
get_optimal_value(capacity, weights, values,n);

  double optimal_value = get_optimal_value(capacity, weights, values,n);

std::cout << std::fixed << std::setprecision(4) << optimal_value<<endl;
  // cout.fixed<<setprecision(3);
  // cout << optimal_value << endl;
  return 0;
}
