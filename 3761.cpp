#include <iostream>
#include <map>


using namespace std;


int main(){

	freopen("input.txt","r",stdin);

	map<string, int> candidates;
	string name;
	int cnt;

	while(cin >> name >> cnt){
		candidates[name]+= cnt;
	}

	map<string,int>::iterator it;

	for(it = candidates.begin(); it!=candidates.end(); ++it){
		cout << (*it).first << " " << (*it).second << endl;
	}


	return 0;
}