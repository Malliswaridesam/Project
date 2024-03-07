#include<iostream>
#include<string>
using namespace std;
char space[3][3]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'}
};
string n1;
string n2;
char token = 'x';
int row;
int column;
bool tie = false;

void functionone(){
    
    cout<< "    |    |   "<<"\n";

    cout<<" "<<space[0][0]<< "  | "<<space[0][1]<<"  | "<<space[0][2]<<"\n";

    cout<< "    |    |   "<<"\n";

    cout<< "----"<<""<<"-----"<<""<<"----"<<"\n";

    cout<< "    |    |   "<<"\n";

    cout<<" "<<space[1][0]<< "  | "<<space[1][1]<<"  | "<<space[1][2]<<"\n";

    cout<< "    |    |   "<<"\n";

    cout<< "----"<<""<<"-----"<<""<<"----"<<"\n";

    cout<< "    |    |   "<<"\n";

    cout<<" "<<space[2][0]<< "  | "<<space[2][1]<<"  | "<<space[2][2]<<"\n";

    cout<< "    |    |   "<<"\n";
    
   
}
void functiontwo(){
    int digit;
    if(token == 'x'){
        cout<< "Please enter (1-9)"<< n1<<":";
        cin>>digit;
    }
    if(token == 'o'){
        cout<<"please enter "<<n2<<":";
        cin>>digit;
    }
    if(digit ==1){
        row=0;
        column=0;
    }
    else if (digit == 2){
        row = 0;
        column=1;

    }
    else if(digit ==3){
        row=0;
        column=2;
    }
    else if(digit == 4){
        row =1;
        column=0;

    }
    else if(digit == 5){
        row =1;
        column=1;
        
    }
    else if(digit == 6){
        row =1;
        column=2;
        
    }
    
     else if(digit == 7){
        row =2;
        column=0;
        
    }
     else if(digit == 8){
        row =2;
        column=1;
        
    }
     else if(digit == 9){
        row =2;
        column=2;
        
    }
    else{
        cout<<"Invalid digit!!!"<<endl;

    }
    if (token == 'x' && space[row][column]!='x' && space[row][column]!='o'){
        space[row][column]='x';
        token='o';
    }
    else if(token == 'o' && space[row][column]!='x' && space[row][column]!='o'){
        space[row][column]='o';
        token ='x';
    }
    else{
        cout<<"Invalid! Try again"<<endl;
        functiontwo();
    } 
    }
bool functionthree(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i] == space[1][i] && space[0][i]== space[2][i]){
            return true;
        }
        }
        if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]){
            return true;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(space[i][j] != 'x' &&  space[i][j] != 'o') {
                    return false;
                }
            }
        }
        tie =true;
        return false;
}


int main(){
    cout<<"Enter the name of player 1:";
    cin>>n1;
    cout<<"Enter the name of player 2:";
    cin>>n2;
    // cout<<n1;
    // cout<<"\t"<<n2;
    // functionone();
     
     while (!functionthree()){
        functionone();
        functiontwo();  
        functionthree();
     }
     if ( token == 'x' && tie == false){
        cout<<n2<<" wins the game";
     }
     else if(token == 'o' && tie == false){
        cout<<n1<<" wins the game";
     }
     else{
        cout<<"It's a draw";
     }
return 0;
}