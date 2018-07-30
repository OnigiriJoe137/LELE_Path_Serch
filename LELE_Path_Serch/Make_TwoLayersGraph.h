#pragma once
#include <list>

//頂点のBundle設定
const struct Vertex
{
	int key; //頂点番号
	int x;	//x座標
	int y;	//y座標
	struct Net *netnumber;	//ネット番号 0はネットではない 
};


//枝のBundle設定
const struct Edge {
	int weight; //辺の重み
};

//グラフのBundle設定
const struct Graph_Layer {
	string name;
};

//ネット
typedef struct Net {
	const int net_number; //ネット端子の個数
	const int terminal_coordinate_x; //端子のx座標
	const int terminal_coordinate_y; //端子のy座標
	const int *next_terminal; //次の端子
} Net;


struct TwoLayersGraph
{
	typedef boost::adjacency_list <
		boost::listS,	//頂点はリスト 
		boost::vecS,	//辺はベクター
		boost::undirectedS,		//無向枝
		Vertex,		//頂点のBundleプロパティ
		Edge,	//辺のBundleプロパティ
		Graph_Layer	//グラフのBundleプロパティ
	> Serch_Graph;	

	TwoLayersGraph(const int x,const int y,const int nets_number);	//格子グラフの行と列、ネット数
	~TwoLayersGraph();
};

class Input_data {
	struct Net *net_first_pointer; //ネットの頂点を指すの最初のポインタ
public:
	Input_data(int argc, char *argv[]);	//コンストラクト
	~Input_data();	//デストラクタ

};
