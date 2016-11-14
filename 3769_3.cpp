#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	//freopen("input.txt","r",stdin);

	map<string,map<string,long long> > m;
	string customer_name;
	string item_name;
	int item_cnt;

	while(cin >> customer_name >> item_name >> item_cnt){
		m[customer_name][item_name] += item_cnt;
	}

	map<string,map<string,long long> > :: iterator i;
	map<string,long long>  :: iterator item;

	for(i = m.begin(); i!=m.end(); ++i){
		cout << (*i).first << ":" << endl;
		map <string, long long> items = (*i).second;
		for(item = items.begin(); item != items.end(); ++item){
			if((*item).second != 0){
				cout << (*item).first << " " << (*item).second << endl;
			}
		}
	}


	return 0;
}