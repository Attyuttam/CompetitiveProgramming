#include<bits/stdc++.h>
using namespace std;
long maxNumberOfKings = 0;
int r,c;
//NOT POSSIBLE USING BACKTRACKING
void print(int chessBoard[100][100]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<chessBoard[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool allVisited(int arr[100][100]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==0)return false;
		}
	}
	return true;
}
long numberOfKings(int arr[100][100]){
	long count=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==1)count++;
		}
	}
	return count;
}
bool eligibleBoard(int chessBoard[100][100]){
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
bool eligible(int cB[100][100]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(cB[i][j]==1){
			
				if(!((j-1>0 && j-1<c && cB[i][j-1]==0)||(j+1>0 && j+1<c && cB[i][j+1]==0) ||
	 			  (i-1>0 && i-1<r && j-1>0 && j-1<c && cB[i-1][j-1]==0)||(i-1>0 && i-1<r &&cB[i-1][j]==0)|| (i-1>0 && i-1<r && j+1>0 && j+1<c && cB[i-1][j+1]==0) ||
	   			  (i+1>0 && i+1<r && j-1>0 && j-1<c && cB[i+1][j-1]==0)||(i+1>0 && i+1<r &&cB[i+1][j]==0)|| (i+1>0 && i+1<r && j+1>0 && j+1<c && cB[i+1][j+1]==0))){
		   			return false;
				}
			}
		}
	}
	return true;
}

void generateBoard(int i,int j,int cB[100][100],int cB_v[100][100]){
//	cout<<i<<" "<<j<<endl;
	if(i>=0 && j>=0 && i<r && j<c && cB_v[i][j]!=1){
		cB_v[i][j]=1;
//		if((j-1>0 && j-1<c && cB[i][j-1]==0)||(j+1>0 && j+1<c && cB[i][j+1]==0) ||
//		   (i-1>0 && i-1<r && j-1>0 && j-1<c && cB[i-1][j-1]==0)||(i-1>0 && i-1<r &&cB[i-1][j]==0)|| (i-1>0 && i-1<r && j+1>0 && j+1<c && cB[i-1][j+1]==0) ||
//		   (i+1>0 && i+1<r && j-1>0 && j-1<c && cB[i+1][j-1]==0)||(i+1>0 && i+1<r &&cB[i+1][j]==0)|| (i+1>0 && i+1<r && j+1>0 && j+1<c && cB[i+1][j+1]==0)){
//		
//		   	cB[i][j]=1;
//		
//		}
//	   if(eligible(cB)){
//			cB[i][j]=1;
//		}
		
		generateBoard(i,j-1,cB,cB_v);
		cB[i][j]=1;
		generateBoard(i,j-1,cB,cB_v);
		
		
		generateBoard(i,j+1,cB,cB_v);
		generateBoard(i-1,j-1,cB,cB_v);
		generateBoard(i-1,j,cB,cB_v);
		generateBoard(i-1,j+1,cB,cB_v);
		generateBoard(i+1,j-1,cB,cB_v);
		generateBoard(i+1,j,cB,cB_v);
		generateBoard(i+1,j+1,cB,cB_v);
		
	}else{
		long nK = numberOfKings(cB);
		//print(cB);
		//cout<<"-----"<<endl;
		if(allVisited(cB_v) && eligible(cB) &&  nK>maxNumberOfKings){
			maxNumberOfKings = nK;
			print(cB);
		}
	}
}
int main(){
	
	cin>>r>>c;
	int cB[100][100];
	int cB_v[100][100];

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cB[i][j]=0;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cB_v[i][j]=0;
		}
	}
	generateBoard(0,0,cB,cB_v);
	cout<<maxNumberOfKings<<endl;
	
	return 0;
}

