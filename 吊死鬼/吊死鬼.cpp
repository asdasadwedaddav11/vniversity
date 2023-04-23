#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;
string lexicon_test(int i){
	srand(i);
	vector<string> word;
	string temp;
	temp="hello";word.push_back(temp);
	temp="acadimaic";word.push_back(temp);
	return word[rand()%2]; 
}
class Hangman{
	string word;
	int flag;//失败次数
	int num;//猜对字母的个数 
	string know;//已知的字母 
	public:
	Hangman(){
	} 
	Hangman(int i){
		word=lexicon_test(i);
		flag=0;
		num=0;
	}
	void draw(){
		if(flag==0){
			cout<<"____"<<endl;
			cout<<"|  I"<<endl;
			cout<<"   I"<<endl;
			cout<<"   I"<<endl;
			cout<<"___I"<<endl;
		} 
		else if(flag==1){
			cout<<"____"<<endl;
			cout<<"|  I"<<endl;
			cout<<"O  I"<<endl;
			cout<<"   I"<<endl;
			cout<<"   I"<<endl;
			cout<<"___I"<<endl;
		} 
		else if(flag==2){
			cout<<" ____"<<endl;
			cout<<" |  I"<<endl;
			cout<<" O  I"<<endl;
			cout<<" |  I"<<endl;
			cout<<"    I"<<endl;
			cout<<" ___I"<<endl;
		}
		else if(flag==3){
			cout<<"  ____"<<endl;
			cout<<"  |  I"<<endl;
			cout<<"  O  I"<<endl;
			cout<<" /|  I"<<endl;
			cout<<"     I"<<endl;
			cout<<"  ___I"<<endl;
		}
		else if(flag==4){
			cout<<"  ____"<<endl;
			cout<<"  |  I"<<endl;
			cout<<"  O  I"<<endl;
			cout<<" /|\\ I"<<endl;
			cout<<"     I"<<endl;
			cout<<"  ___I"<<endl;
		}
		else if(flag==5){
			cout<<"  ____"<<endl;
			cout<<"  |  I"<<endl;
			cout<<"  O  I"<<endl;
			cout<<" /|\\ I"<<endl;
			cout<<" /   I"<<endl;
			cout<<"  ___I"<<endl;
		}
		else if(flag==6){
			cout<<"  ____"<<endl;
			cout<<"  |  I"<<endl;
			cout<<"  O  I"<<endl;
			cout<<" /|\\ I"<<endl;
			cout<<" / \\ I"<<endl;
			cout<<"  ___I"<<endl;
		}
	}
	void known(){
		int n=word.size();
		cout<<"Word:";
		for(int i=0;i<n;i++){
			int k=0;
			char temp=word[i];
			for(int j=0;j<n;j++){
				if(know[j]==temp){
					k=1;
					break;
				}
			}
			if(k==0) cout<<"_";
			else cout<<temp;
		}
		cout<<endl;
	}
	void play(){
		cout<<"请输入你猜测的字母：";
		char x;
		cin>>x;
		int n=word.size();
		int jud=0;//判断flag是否发生变化 
		for(int i=0;i<n;i++){
			if(x==word[i]){
				know[num]=x;
				num++;
				jud=1;
				cout<<"猜对了！"<<endl;
				break;
			}
		} 
		if(jud==0){
			flag++; 
			cout<<"你猜错了"<<endl;
		}
	}
	int return_flag(){
		return flag;
	}
	int win(){
		int m;
		m=word.size();
		int i;
		for(i=0;i<m;i++){
			int k=0;
			cout<<i;
			for(int j=0;j<m;j++){
				if(word[i]==know[j]){
					k=1;
					break;
				}
			}
			if(k==0){
				break;
			}
		}
		if(i==m) return 1;
		else return 0;
	}
};
int main(){
	cout<<"请随便输入一个数字抽取单词，开始游戏：";
	int i;
	cin>>i;
	Hangman begin(i);
	int flag;
	flag=begin.return_flag();
	begin.draw();
	begin.known();
	while(flag!=6){
		begin.play();
		begin.draw();
		begin.known();
		flag=begin.return_flag(); 
		if(begin.win()==1){
			cout<<"恭喜你获胜了！";
			break;
			}
		}
		if(flag==6) cout<<"很遗憾你输了。";
	}
