//�Ƚ����е��ַ��������ϣ��keyΪ�ַ�����valueΪ<����˳�򣬳��ִ���>��˳��ȡ��ͬ���ַ�������Сֵ������һֱ�ۼ�
//����Ļ�������set��д�Ƚ��������������򣬴�����ͬ�򰴳���˳������
//�����������hashʱ�临�Ӷȿ�����Ϊ��O(n)
//�������set���Ǻ������������Ϊ��O(nlgn) ,�ܵĸ��ӶȾ��������
#include<iostream>
#include<unordered_map>
#include<set>
#include<string.h>
using namespace std;
struct info{//��¼���ֵ�˳�򣬺ʹ���
	int rank;
	int count;
	info(int rank, int count){
		this->rank = rank;
		this->count = count;
	}
};
struct fullinfo{//һ�������Ľ�����ַ����ʹ���
	string file;
	int rank;
	int count;
	fullinfo(string file, int rank, int count){
		this->file = file;
		this->rank = rank;
		this->count = count;
	}
};
struct classcomp {//set�ıȽ���
	bool operator()(const struct fullinfo& f1, const struct fullinfo& f2){
		if (f1.count == f2.count)
			return f1.rank<f2.rank;
		return f1.count>f2.count;
	}
};
typedef struct info INFO;
typedef struct fullinfo FULLINFO;
int main(){
	unordered_map<string, INFO> record;
	unordered_map<string, INFO>::iterator it;
	unordered_map<string, INFO>::const_iterator itfind;
	set<FULLINFO, classcomp> ret;
	set<FULLINFO, classcomp>::iterator sit;
	string linestr;//һ������
	string file;//�ļ���+�к�
	int pos;//�ո��λ��
	int i = 1;
	while (getline(cin, linestr)){
		if (linestr.length() == 0)
			break;
		pos = linestr.rfind("\\");
		file = linestr.substr(pos + 1);//��ֵõ�����filename��count
		itfind = record.find(file);//��map�в鿴�Ƿ��Ѿ����˸��ַ�����û������룬���������1
		if (itfind == record.end()){
			INFO tmpi(i, 1);
			record.insert(pair<string, INFO>(file, tmpi));
		} else{
			INFO tmpi(itfind->second.rank, itfind->second.count + 1);
			record.erase(file);
			record.insert(pair<string, INFO>(file, tmpi));
		}
		i++;
	}
	for (it = record.begin(); it != record.end(); it++){
		FULLINFO tmpfull(it->first, it->second.rank, it->second.count);//���������set����
		ret.insert(tmpfull);
	}
	for (i = 0, sit = ret.begin(); sit != ret.end() && i < 8; ++sit, ++i){//������8����¼��file����16λ
		if (file.find(" ") <= 16){
			cout << (*sit).file << " " << (*sit).count << endl;
		} else{
			cout << (*sit).file.substr(file.find(" ") - 16) << " " << (*sit).count << endl;
		}

	}
	return 0;
}