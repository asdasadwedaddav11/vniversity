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
	int flag;//ʧ�ܴ���
	int num;//�¶���ĸ�ĸ��� 
	string know;//��֪����ĸ 
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
		cout<<"��������²����ĸ��";
		char x;
		cin>>x;
		int n=word.size();
		int jud=0;//�ж�flag�Ƿ����仯 
		for(int i=0;i<n;i++){
			if(x==word[i]){
				know[num]=x;
				num++;
				jud=1;
				cout<<"�¶��ˣ�"<<endl;
				break;
			}
		} 
		if(jud==0){
			flag++; 
			cout<<"��´���"<<endl;
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
	cout<<"���������һ�����ֳ�ȡ���ʣ���ʼ��Ϸ��";
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
			cout<<"��ϲ���ʤ�ˣ�";
			break;
			}
		}
		if(flag==6) cout<<"���ź������ˡ�";
	}
