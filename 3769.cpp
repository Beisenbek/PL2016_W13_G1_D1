#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

struct customer{
	string name;
	map<string,int> items;
	void printInfo(){
		cout << name << ":" << endl;
		std::map<string, int>::iterator it;
		for(it = items.begin(); it != items.end(); ++it){
			cout << (*it).first << " " << (*it).second << endl;
		}
	}
};

bool f(customer l, customer r){
	if(l.name > r.name) return false;
	return true;
}


int main(){

	freopen("input.txt","r",stdin);

	vector<customer> v;
	string customer_name;
	string item_name;
	int item_cnt;


	while(cin >> customer_name >> item_name >> item_cnt){
		customer c;
		c.name = customer_name;

		int ind = -1;

		for(unsigned long i = 0; i < v.size(); ++i){
			if(v[i].name == customer_name){
				ind  = i;
				break;
			}
		}

		if(ind != -1){
			v[ind].items[item_name] += item_cnt;
		}else{
			c.items[item_name] = item_cnt;
			v.push_back(c);
		}
	}

	sort(v.begin(),v.end(),f);

	for(unsigned long i = 0; i < v.size(); ++i){
		v[i].printInfo();
	}

	return 0;
}