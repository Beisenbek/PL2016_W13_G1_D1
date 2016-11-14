#include <iostream>
#include <map>
#include <vector>


using namespace std;

struct candidate{
	string candidate_name;
	int candidate_votes;
	void printInfo(){
		cout << candidate_name << " " << candidate_votes  << endl;
		//printf("%s %i\n",candidate_name.c_str(), candidate_votes);
	}
};

bool f(candidate l, candidate r){
	if(l.candidate_votes < r.candidate_votes) return false;
	if(l.candidate_votes == r.candidate_votes && 
	   l.candidate_name > r.candidate_name) return false; 
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
	vector<candidate> res;
		
	for(it = candidates.begin(); it!=candidates.end(); ++it){
		candidate c;
		c.candidate_name = (*it).first;
		c.candidate_votes = (*it).second;
		res.push_back(c);
	}

	sort(res.begin(), res.end(),f);

	for(unsigned long i = 0; i < res.size(); ++i){
		res[i].printInfo();
	}

	return 0;
}