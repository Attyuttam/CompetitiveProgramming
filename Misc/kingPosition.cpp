#include<bits/stdc++.h>
#include<limits.h>
#include<cmath>
using namespace std;
//INCORRECT
int maxKings = 0;
int r,c;
vector< vector<int> > arrangeKingsInChessBoard(vector< vector<int> > chessBoard, string bitMask){
	for(int i=0;i<bitMask.length();i++){
		if(bitMask[i]=='1'){
			chessBoard[floor(i/c)][i%c] = 1;
		}
	}
	return chessBoard;
}
bool eligibleBoard(vector< vector<int> > chessBoard){
	if(r>2 && c==2){
		if(chessBoard[0][0]==1 && chessBoard[1][0]==1 && chessBoard[1][1]==1 && chessBoard[0][1]==1){
			return false;
		}
		if(chessBoard[r-1][0]==1 && chessBoard[r-1][1]==1 &&chessBoard[r-2][0]==1 &&chessBoard[r-2][1]==1 ){
			return false;
		}
		for(int j=1;j<c-1;j++){
			if(chessBoard[0][j]==1 && chessBoard[0][j-1]==1 && chessBoard[0][j+1]==1 && chessBoard[1][j]==1 && chessBoard[1][j-1]==1 && chessBoard[1][j+1]==1){
				return false;
			}
		}
		return true;
	}
	else if(r==2 && c>2){
		if(chessBoard[0][0]==1 && chessBoard[1][0]==1 && chessBoard[1][1]==1 && chessBoard[0][1]==1){
			return false;
		}
		if(chessBoard[0][c-1]==1 && chessBoard[0][c-2]==1 &&chessBoard[1][c-2]==1 &&chessBoard[1][c-1]==1 ){
			return false;
		}
		for(int j=1;j<c-1;j++){
			if(chessBoard[0][j]==1 && chessBoard[0][j-1]==1 && chessBoard[0][j+1]==1 && chessBoard[1][j]==1 && chessBoard[1][j-1]==1 && chessBoard[1][j+1]==1){
				return false;
			}
		}
		return true;
	}
	else if(r==2 && c==1){
		if(chessBoard[0][0]==1 && chessBoard[1][0]==1)return false;
		return true;
	}
	else if(r==1 && c==2){
		if(chessBoard[0][1]==1 && chessBoard[0][0]==1)return false;
		return true;
	}else if(r==1 && c>2){
		for(int j=1;j<c-1;j++){
			if(chessBoard[0][j]==1 && chessBoard[0][j-1]==1 && chessBoard[0][j+1]==1 ){
				return false;
			}
		}
	}
	else if(r>2 && c==1){
		for(int i=1;i<r-1;i++){
			if(chessBoard[i][0]==1 && chessBoard[i-1][0]==1 && chessBoard[i+1][0]==1 ){
				return false;
			}
		}
	}else if(r==2 && c==2){
		int countOfNumberOfKingsOnBoard=0;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				countOfNumberOfKingsOnBoard++;
			}
		}
		if(countOfNumberOfKingsOnBoard==1)return true;
		return false;
		
	}else if(r==1 && c==1){
		return false;
	}else{
		for(int i=1;i<r-1;i++){
			for(int j=1;j<c-1;j++){
				if(chessBoard[i][j]==1 && chessBoard[i-1][j-1]==1 && chessBoard[i-1][j]==1 && chessBoard[i-1][j+1]==1 &&chessBoard[i][j-1]==1 &&chessBoard[i][j+1]==1 &&chessBoard[i+1][j-1]==1 &&chessBoard[i+1][j]==1 &&chessBoard[i+1][j+1]==1){
					return false;
				}
			}
		}
	}
	return true;
}
int numberOfKings(string bitMask){
	int count=0;
	for(int i=0;i<bitMask.length();i++){
		if(bitMask[i]=='1')count++;
	}
	return count;
}
vector< vector<int> > initializeChessBoard(vector< vector<int> > chessBoard){
	for(int i=0;i<r;i++){
		vector<int>  tempVec;
		for(int j=0;j<c;j++){
			tempVec.push_back(0);
		}
		chessBoard.push_back(tempVec);
	}
	return chessBoard;
}
void print(vector< vector<int> > chessBoard){
	for(int i=0;i<chessBoard.size();i++){
		for(int j=0;j<chessBoard[i].size();j++){
			cout<<chessBoard[i][j]<<" ";
		}
		cout<<endl;
	}
}
void generateChessBoardWithKings(string bitMask){
	vector< vector<int> > chessBoard;
	chessBoard = initializeChessBoard(chessBoard);
	//print(chessBoard);
	chessBoard = arrangeKingsInChessBoard(chessBoard,bitMask);
	//print(chessBoard);
	if(eligibleBoard(chessBoard) && numberOfKings(bitMask)>maxKings){
		maxKings = numberOfKings(bitMask);
		//print(chessBoard);
	}
}
void generateBitMask(int n,string bitMask){
	if(n>0){
		generateBitMask(n-1,bitMask+"0");
		generateBitMask(n-1,bitMask+"1");
	}else{
		//cout<<"bitMask: "<<bitMask<<endl;
		generateChessBoardWithKings(bitMask);
	}
}
void generatePositions(int numberOfCells){
	generateBitMask(numberOfCells,"");
}
int main(){
	//cin>>r>>c;
	for(int i=0;i<10;i++){
		r=i;
		c=i;
		cout<<r<<" -- "<<c<<endl;
		int numberOfCells = r*c;
		generatePositions(numberOfCells);
		cout<<maxKings<<endl;;
	}
	
}
