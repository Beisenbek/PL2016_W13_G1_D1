#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

struct customer{
	string name;
	map<string,long long> items;
	void printInfo(){
		cout << name << ":" << endl;
		std::map<string, long long>::iterator it;
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

	map<string,customer> m;
	string customer_name;
	string item_name;
	int item_cnt;

	while(cin >> customer_name >> item_name >> item_cnt){
		customer c;
		c.name = customer_name;
		c.items[item_name] = item_cnt;

		if(m.find(c.name) != m.end()){
			m[c.name].items[item_name] += item_cnt;
		}else{
			m[c.name] = c;
		}

	}

	map<string,customer> :: iterator it;

	for(it = m.begin(); it!=m.end(); ++it){
		(*it).second.printInfo();
	}


	return 0;
}