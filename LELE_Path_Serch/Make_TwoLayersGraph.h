#pragma once
#include <list>

//Boostの設定
//頂点のBundle設定
typedef struct Vertex
{
	int key; //頂点番号
	int x;	//x座標
	int y;	//y座標
	struct Net *netnumber;	//ネット番号 0はネットではない 
} Vertex;

//枝のBundle設定
typedef struct Edge {
	int weight; //辺の重み
} Edge;

//グラフのBundle設定
struct Graph_Layer {
	string name;
};

//ネットの情報：個数とか位置座標とか
typedef struct Net {
	const int net_number; //ネット端子の個数
	const int terminal_coordinate_x; //端子のx座標
	const int terminal_coordinate_y; //端子のy座標
	const int *next_terminal; //次の端子
} Net;

typedef boost::adjacency_list <
	boost::vecS,	//頂点はvector 
	boost::listS,	//辺はベクター
	boost::undirectedS,		//無向枝
	Vertex,		//VertexProperties　頂点の型　//任意クスをプロパティにする
	Edge,	//EdgeProperties ,重み
	Graph_Layer	//GraphProperties
> Serch_Graph;

struct TwoLayersGraph {	
	TwoLayersGraph(const int,const int,const int); //２層グラフを作成する
	~TwoLayersGraph();
};

class Input_data {
	Net *net_first_pointer; //ネットの頂点を指す最初のポインタ
public:
	Input_data(int argc, char *argv[]);	//コンストラクタ
	~Input_data();	//デストラクタ
};


