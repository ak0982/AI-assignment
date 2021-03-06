/*
name amar-kumar
roll no -1801016


1.State space:
       Here sate space is a 8x8 matrix where the position of a queen is represented by 1
2.State transition operator:
		adding a new queen which is denoted by 1 in the subsequent row.
3.intitial state:
		a 8 x 8 null matrix.
4.Goal state:
		When all the rows are filled with a single queen at non attacking positions,


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool solution=false;
int cost=0;
struct board{
	int mat[8][8],queens,h,p,t;
};
vector<board> q1;
void print(board &temp);
board initial(board &b1);
bool isvalid(board &temp);
void states(vector<board> &q1);
bool compare(board b1,board b2);


int main(){

	board b1;

	initial(b1);

	q1.push_back(b1);

    while(!q1.empty()&&solution==false){


    	states(q1);

	
	}


	return 0;
}

void states(vector<board> &q1)
{
	board temp;
	bool oc=true;
	int size=q1.size();
	sort(q1.begin(),q1.end(),compare);
	temp=q1.front();
    vector<board>::iterator it; 
    it = q1.begin(); 
    q1.erase(it); 
	int q=temp.queens;
    if(temp.queens==8) {
    	print(temp);
    	
    	cout<<"cost is "<<cost<<endl;
    	solution=true;
    	return;
	}
	for(int i=0;i<8;i++){
		temp.mat[q][i]=1;
		int pre=temp.p;
		temp.queens++;
		temp.h--;
		temp.p=pre+1;
		if(q==0||isvalid(temp)){
			
			q1.push_back(temp);
			cost++;
		}
		temp.queens--;
		temp.h++;
		temp.p=pre;
		temp.mat[q][i]=0;
	}
}


bool isvalid(board &temp)
{
	int q=temp.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(temp.mat[q-1][i]==1) break;
	}
	for(int j=q-2;j>=0;j--){
		if(temp.mat[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) break;
		if(temp.mat[j][i2]==1) return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) break;
		if(temp.mat[j][i2]==1) return false;
		i2++;
	}
	return true;
}




bool compare(board b1,board b2)
{
	return (b1.h+b1.p<b2.h+b2.p);
}

board initial(board &b1)
{
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			b1.mat[i][j]=0;
		}
	}
	b1.queens=0;
	b1.p=0;
	b1.h=(8-b1.queens);
    b1.t=0;
	return b1;
}
void print(board &temp)
{
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<temp.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
}


