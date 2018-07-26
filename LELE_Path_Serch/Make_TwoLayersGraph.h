#pragma once


const struct Vertex
{
	int key; //頂点番号
	int x;	//x座標
	int y;	//y座標
	struct Net *netnumber;	//ネット番号 0はネットではない 
};

const struct Net {
	const int net_number; //ネット端子の個数
	const int terminal_coordinate_x; //端子のx座標
	const int terminal_coordinate_y; //端子のy座標
	const int *next_terminal; //次の端子
};


const struct Edge {
	int weight; //辺の重み
};

const struct Graph_Layer {
	string name;
};



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

