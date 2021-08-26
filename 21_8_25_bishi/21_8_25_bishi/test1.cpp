#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

// 正常应该是 这样的移动方向
//vector<pair<int, int>> move_type = { {1, 1},{1, 0},{1, -1},{0, -1},{-1, -1},{-1, 0},{-1, 1},{0, 1} };
// 但是例子 上说 {5,4} 相对于{5,5} 向下移动，{4,4}相对于{5,4}向左移动
// 所以针对例子分析，是将  状态 0 1 2 3 4 5 6 7 进行了顺时针90度旋转， 或者说，当前位置状态变到了下两个位置去
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
	// outBuffer 的前8个字节表示 起始点， 即用 八个元素，保存起始点

	if (inBuffer.size() < 1)
		return;
	// 1.进行起始点的存储----------------------------------------------------------------
	int startx = inBuffer[0].first;
	int starty = inBuffer[0].second;
	// x 坐标存储
	for (int i = 0; i < 4; ++i) {
		uint8_t tmp = (startx >> (24 - 8 * i)) & 0xf;
		outBuffer.push_back(tmp);
	}
	// y坐标存储
	for (int i = 4; i < 8; ++i) {
		uint8_t tmp = starty >> (24 - 8 * i);
		outBuffer.push_back(tmp);
	}
	// 2. 首先判断移动的类型，并将其保存---------------------------------------------------------------------
	vector<int> temp; // 临时保存移动类型
	for (int i = 1; i < inBuffer.size(); ++i) {
		pair<int, int> tmp;
		tmp.first = inBuffer[i].first - inBuffer[i - 1].first;
		tmp.second = inBuffer[i].second - inBuffer[i - 1].second;
		int ret = Judge(tmp); // 移动的类型
		if (ret < 0) {
			printf("judge error!\n");
			return;
		}
		temp.push_back(ret);
	}
	// 3. 将移动类型进行信息压缩------------------------------------------------------------------------
	for (int i = 0; i < temp.size(); i += 2) {
		char d1 = 0x47; // 低三位 0100 0111
		char d2 = 0xf8; // 高三位 1111 1000
		d1 = (d1 & temp[i]) | 0x40;  // 或 0100 0000， 将第六位置1
		if (i + 1 < temp.size()) {
			// 左移三位 表示将 第二个数 存在 第3位到第5位上
			// 或 1100 0000 将第六位和第七位置1，
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
	/* 解码步骤：
	  首先解出 起始点， 在解出每一步的状态（8种）， 将状态对应的从 起始点 加上 解出当前点
	*/
	if (inBuffer.size() < 8) {
		// 说明 连起始点 都没有存储
		return;
	}
	//-----------------------------1. 解码出 起始点------------------------------------------------
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
		// 说明只存储了起始点，不用在进行后续操作。
		return;
	}
	// 解码状态 用 0-7 进行保存---------------------------------------------------------------
	// 第0-2位 表示 前一个状态， 第3-5位 表示后一个状态， 不要弄反。。。。
	// 同时，只需要对最后一个元素的第7位 进行判断（判断第3-5位是否存数据）
	vector<int> save;
	int state1, state2; // 保存一个字节中存储的 两个状态
	uint8_t code2;      // 保存 压缩存储的 一个字节数据
	// 对除最后一位的压缩数据 进行 解压缩
	for (int i = 8; i < inBuffer.size()-1; ++i) {
		code2 = inBuffer[i];
		state1 = code2 & 0x00000007;// 0x00 00 00 0000 0111  取低三位数据
		state2 = (code2 & 0x00000038) >> 3;// 0x00 00 00 0011 1000 取高三位数据
		save.push_back(state1);
		save.push_back(state2);
	}
	// 对最后一位压缩数据进行 解压缩， 注意判断 高位 是否存储 状态数据
	code2 = inBuffer[inBuffer.size() - 1]; 
	state1 = code2 & 0x00000007; // 取低三位数据
	save.push_back(state1);
	if ((code2 & 0x00000080) >> 7 == 1) {
		// 说明 高三位存储了数据
		state2 = (code2 & 0x00000038) >> 3;// 0x00 00 00 0011 1000 取高三位数据
		save.push_back(state2);
	}
	pair<int, int> prev = outBuffer[0]; // 保存上一个节点的位置
	pair<int, int> cur;
	// 将解码后的数据状态 变为 坐标值（根据前一时刻的坐标进行变化）
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
	// 输出原始路径
	std::cout << "bData src:" << '\n';
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}
	////压缩数据
	encode(bData, zipData);
	std::cout << zipData.size() << std::endl;
	// 输出压缩数据
	cout << "zipData: " << endl;
	for (vector<uint8_t>::iterator it = zipData.begin(); it != zipData.end(); it++)
	{
		printf("%08x, ", *it);
	}
	cout << endl;

	// 解压数据 
	bData.clear();
	decode(zipData, bData);

	////输出解压出来的路径
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
	cout << sizeof(uint8_t) << endl;	//1字节
										//system("pause");
	vector<pair<int, int>> bData;
	vector<uint8_t> zipData;
	bData.push_back(make_pair(10019, 1124));
	bData.push_back(make_pair(10019, 1123));
	bData.push_back(make_pair(10019, 1122));
	bData.push_back(make_pair(10018, 1123));

	bData.push_back(make_pair(10018, 1122));
	bData.push_back(make_pair(10018, 1121));

	//输出原始路径
	cout << "bData src:" << endl;
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}
	////压缩数据
	encode(bData, zipData);
	// std::cout << zipData.size() << std::endl;
	

	
	////解压数据 
	bData.clear();
	decode(zipData, bData);

	////输出解压出来的路径
	cout << "bData dest:" << endl;
	for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end(); it++)
	{
		cout << it->first << "," << it->second << endl;
	}
	getchar();
	*/
	return 0;
}
