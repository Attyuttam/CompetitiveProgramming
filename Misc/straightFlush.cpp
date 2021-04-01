#include<bits/stdc++.h>
using namespace std;
char suits[4] = {'H','C','D','S'};
char valuesInCard1[13] = {'A','K','Q','J','T','9','8','7','6','5','4','3','2'};
char valuesInCard2[13] = {'K','Q','J','T','A','9','8','7','6','5','4','3','2'};

bool allOfTheSameSuit(vector<string> fiveCards){
	if(fiveCards[0][1] == fiveCards[1][1] &&
	 fiveCards[1][1] == fiveCards[2][1] &&
	 fiveCards[2][1] == fiveCards[3][1] &&
	 fiveCards[3][1] == fiveCards[4][1]){
	 	return true;
	 }
	return false;
}
vector<char> extractRanks(vector<string> fiveCards){
	vector<char> temp;
	for(int i =0;i<5;i++){
		temp.push_back(fiveCards[i][0]);
	}

	return temp;
}
bool isThereAnyAce(vector<char> ranks){
	for(int i=0;i<ranks.size();i++){
		if(ranks[i]=='A'){
			return true;
		}
	}
	return false;
}
bool aceIsNotSetProperlyAtFirstOrLast(vector<char> ranks){
	if(ranks[0]!='A' && ranks[ranks.size()-1]!='A')return true;
	if(ranks[0] == 'A' && ranks[1]!='K')return true;
	if(ranks[4] == 'A' && ranks[3]!='10')return true;
	return false;
}
int getIndexOfFromOne(char rank){
	for(int i=0;i<13;i++){
		if(rank == valuesInCard1[i]){
			return i;
		}
	}
}
int getIndexOfFromTwo(char rank){
	for(int i=0;i<13;i++){
		if(rank == valuesInCard2[i]){
			return i;
		}
	}
}
bool checkOrderedRankingInTwo(vector<char> ranks){
	vector<int> indexOfRanks;
	//cout<<endl<<"gonna check the ordering now";
	for(int i=0;i<ranks.size();i++){
		indexOfRanks.push_back(getIndexOfFromTwo(ranks[i]));
		//cout<<"index: "<<indexOfRanks[i]<<endl;
	}
	sort(indexOfRanks.begin(),indexOfRanks.end());
	for(int i=0;i<indexOfRanks.size()-1;i++){
		if(indexOfRanks[i]+1!=indexOfRanks[i+1]){
			return false;
		}
	}
	return true;
}
bool checkOrderedRankingInOne(vector<char> ranks){
	vector<int> indexOfRanks;
	//cout<<endl<<"gonna check the ordering now";
	for(int i=0;i<ranks.size();i++){
		indexOfRanks.push_back(getIndexOfFromOne(ranks[i]));
		//cout<<"index: "<<indexOfRanks[i]<<endl;
	}
	sort(indexOfRanks.begin(),indexOfRanks.end());
	for(int i=0;i<indexOfRanks.size()-1;i++){
		if(indexOfRanks[i]+1!=indexOfRanks[i+1]){
			return checkOrderedRankingInTwo(ranks);
		}
	}
	return true;
}
bool orderedRanking(vector<string> fiveCards){
	vector<char> ranks = extractRanks(fiveCards);
//	if(isThereAnyAce(ranks)){
//		if(ranks[0]=='A'){
//			ranks.erase(ranks.begin()+0);
//			return checkOrderedRanking(ranks);
//		}
//		if(ranks[ranks.size()-1]=='A'){
//			vector<char> temp;
//			for(int i=0;i<4;i++){
//				temp.push_back(ranks[i]);
//			}
//			return checkOrderedRanking(temp);
//		}
//	}
	return checkOrderedRankingInOne(ranks);
	
}
string checkStraightFlush(vector< string > fiveCards){
	if(allOfTheSameSuit(fiveCards)){
		if(orderedRanking(fiveCards)){
			return "YES";
		}
	}
	return "NO";
}
vector<string> takeInput(){
	vector<string> fiveCards;
	string temp;
	for(int i=0;i<5;i++){
		cin>>temp;
		fiveCards.push_back(temp);
	}
	return fiveCards;
}
int main(){
	vector< string > fiveCards;
	fiveCards = takeInput();
	cout<<checkStraightFlush(fiveCards);
	return 0;
}
