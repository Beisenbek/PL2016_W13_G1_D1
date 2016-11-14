#include <iostream>
#include <map>
#include <vector>


using namespace std;

bool f(pair<string,int> l, pair<string,int> r){
	if(l.second < r.second) return false;
	if(l.second == r.second && l.first > r.first) return false; 
	return true;
}


int main(){

	freopen("input.txt","r",stdin);

	map<string, int> candidates;
	string name;
	int cnt;

	while(cin >> name >> cnt){
		candidates[name]+= cnt;
	}

	map<string,int>::iterator it;
	vector<pair<string, int> > res;
		
	for(it = candidates.begin(); it!=candidates.end(); ++it){
		res.push_back(*it);
	}

	sort(res.begin(), res.end(),f);

	for(unsigned long i = 0; i < res.size(); ++i){
		cout << res[i].first << " " << res[i].second << endl;
	}

	return 0;
}