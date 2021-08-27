#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

// ����Ӧ���� �������ƶ�����
//vector<pair<int, int>> move_type = { {1, 1},{1, 0},{1, -1},{0, -1},{-1, -1},{-1, 0},{-1, 1},{0, 1} };
// �������� ��˵ {5,4} �����{5,5} �����ƶ���{4,4}�����{5,4}�����ƶ�
// ����������ӷ������ǽ�  ״̬ 0 1 2 3 4 5 6 7 ������˳ʱ��90����ת�� ����˵����ǰλ��״̬�䵽��������λ��ȥ
const vector<pair<int, int>> move_type = { {-1, 1},{0, 1} ,{1, 1},{1, 0},{1, -1},{0, -1},{-1, -1},{-1, 0} };
int Judge(pair<int, int> direction) {
	int res;
	for (int i = 0; i < 8; ++i) {
		if (direction == move_type[i]) {
			res = i;
			return res;
		}
	}
	return -1;
}
void encode(const vector<pair<int, int>>& inBuffer, vector<uint8_t>& outBuffer) {
	// todo:
	// outBuffer ��ǰ8���ֽڱ�ʾ ��ʼ�㣬 ���� �˸�Ԫ�أ�������ʼ��

	if (inBuffer.size() < 1)
		return;
	// 1.������ʼ��Ĵ洢----------------------------------------------------------------
	int startx = inBuffer[0].first;
	int starty = inBuffer[0].second;
	// x ����洢
	for (int i = 0; i < 4; ++i) {
		uint8_t tmp = (startx >> (24 - 8 * i)) & 0xf;
		outBuffer.push_back(tmp);
	}
	// y����洢
	for (int i = 4; i < 8; ++i) {
		uint8_t tmp = starty >> (24 - 8 * i);
		outBuffer.push_back(tmp);
	}
	// 2. �����ж��ƶ������ͣ������䱣��---------------------------------------------------------------------
	vector<int> temp; // ��ʱ�����ƶ�����
	for (int i = 1; i < inBuffer.size(); ++i) {
		pair<int, int> tmp;
		tmp.first = inBuffer[i].first - inBuffer[i - 1].first;
		tmp.second = inBuffer[i].second - inBuffer[i - 1].second;
		int ret = Judge(tmp); // �ƶ�������
		if (ret < 0) {
			printf("judge error!\n");
			return;
		}
		temp.push_back(ret);
	}
	// 3. ���ƶ����ͽ�����Ϣѹ��------------------------------------------------------------------------
	for (int i = 0; i < temp.size(); i += 2) {
		char d1 = 0x47; // ����λ 0100 0111
		char d2 = 0xf8; // ����λ 1111 1000
		d1 = (d1 & temp[i]) | 0x40;  // �� 0100 0000�� ������λ��1
		if (i + 1 < temp.size()) {
			// ������λ ��ʾ�� �ڶ����� ���� ��3λ����5λ��
			// �� 1100 0000 ������λ�͵���λ��1��
			d2 = (d2 & (temp[i + 1] << 3)) | 0xc0;  
		}
		else {
			d2 = 0x00;
		}
		uint8_t code = d1 | d2;
		outBuffer.push_back(code);
	}
}

void decode(const vector<uint8_t>& inBuffer, vector<pair<int, int>>& outBuffer) {
	// todo:
	/* ���벽�裺
	  ���Ƚ�� ��ʼ�㣬 �ڽ��ÿһ����״̬��8�֣��� ��״̬��Ӧ�Ĵ� ��ʼ�� ���� �����ǰ��
	*/
	if (inBuffer.size() < 8) {
		// ˵�� ����ʼ�� ��û�д洢
		return;
	}
	//-----------------------------1. ����� ��ʼ��------------------------------------------------
	int startx = 0x00000000;
	int starty = 0x00000000;
	for (int i = 0; i < 4; ++i) {
		startx = (startx << (i * 8)) | (inBuffer[i] & 0x000000ff);
	}
	for (int i = 4; i < 8; ++i) {
		starty = (starty << ((i-4) * 8)) | (inBuffer[i] & 0x000000ff);
	}
	outBuffer.push_back(make_pair(startx, starty));
	if (inBuffer.size() == 8) {
		// ˵��ֻ�洢����ʼ�㣬�����ڽ��к���������
		return;
	}
	// ����״̬ �� 0-7 ���б���---------------------------------------------------------------
	// ��0-2λ ��ʾ ǰһ��״̬�� ��3-5λ ��ʾ��һ��״̬�� ��ҪŪ����������
	// ͬʱ��ֻ��Ҫ�����һ��Ԫ�صĵ�7λ �����жϣ��жϵ�3-5λ�Ƿ�����ݣ�
	vector<int> save;
	int state1, state2; // ����һ���ֽ��д洢�� ����״̬
	uint8_t code2;      // ���� ѹ���洢�� һ���ֽ�����
	// �Գ����һλ��ѹ������ ���� ��ѹ��
	for (int i = 8; i < inBuffer.size()-1; ++i) {
		code2 = inBuffer[i];
		state1 = code2 & 0x00000007;// 0x00 00 00 0000 0111  ȡ����λ����
		state2 = (code2 & 0x00000038) >> 3;// 0x00 00 00 0011 1000 ȡ����λ����
		save.push_back(state1);
		save.push_back(state2);
	}
	// �����һλѹ�����ݽ��� ��ѹ���� ע���ж� ��λ �Ƿ�洢 ״̬����
	code2 = inBuffer[inBuffer.size() - 1]; 
	state1 = code2 & 0x00000007; // ȡ����λ����
	save.push_back(state1);
	if ((code2 & 0x00000080) >> 7 == 1) {
		// ˵�� ����λ�洢������
		state2 = (code2 & 0x00000038) >> 3;// 0x00 00 00 0011 1000 ȡ����λ����
		save.push_back(state2);
	}
	pair<int, int> prev = outBuffer[0]; // ������һ���ڵ��λ��
	pair<int, int> cur;
	// ������������״̬ ��Ϊ ����ֵ������ǰһʱ�̵�������б仯��
	for (int i = 0; i < save.size(); ++i) {
		cur.first = prev.first + move_type[save[i]].first;
		cur.second = prev.second + move_type[save[i]].second;
		prev = cur;
		outBuffer.push_back(cur);
	}
}


void test() {
	vector<pair<int, int>> bData;
	vector<uint8_t> zipData;
	bData.push_back(make_pair(5, 5));
	bData.push_back(make_pair(5, 4));
	bData.push_back(make_pair(4, 4));
	bData.push_back(make_pair(4, 5));
	bData.push_back(make_pair(4, 6));
	bData.push_back(make_pair(3, 6));
	// ���ԭʼ·��
	std::cout << "bData src:" << '\n';
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}
	////ѹ������
	encode(bData, zipData);
	std::cout << zipData.size() << std::endl;
	// ���ѹ������
	cout << "zipData: " << endl;
	for (vector<uint8_t>::iterator it = zipData.begin(); it != zipData.end(); it++)
	{
		printf("%08x, ", *it);
	}
	cout << endl;

	// ��ѹ���� 
	bData.clear();
	decode(zipData, bData);

	////�����ѹ������·��
	cout << "bData dest:" << endl;
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}

}
int main()
{
	test();
	/*
	cout << sizeof(uint8_t) << endl;	//1�ֽ�
										//system("pause");
	vector<pair<int, int>> bData;
	vector<uint8_t> zipData;
	bData.push_back(make_pair(10019, 1124));
	bData.push_back(make_pair(10019, 1123));
	bData.push_back(make_pair(10019, 1122));
	bData.push_back(make_pair(10018, 1123));

	bData.push_back(make_pair(10018, 1122));
	bData.push_back(make_pair(10018, 1121));

	//���ԭʼ·��
	cout << "bData src:" << endl;
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}
	////ѹ������
	encode(bData, zipData);
	// std::cout << zipData.size() << std::endl;
	

	
	////��ѹ���� 
	bData.clear();
	decode(zipData, bData);

	////�����ѹ������·��
	cout << "bData dest:" << endl;
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}
	getchar();
	*/
	return 0;
}
