#include "stdafx.h"
#include "Make_TwoLayersGraph.h"
#include <fstream>
#include <string>

using namespace std;
using namespace boost;


TwoLayersGraph::TwoLayersGraph(const int x,const int y,const int nets_number)
{
	Serch_Graph blue_graph;
	blue_graph[graph_bundle].name = "blue";

	Serch_Graph red_graph;
	red_graph[graph_bundle].name = "red";

	for (int i = 0, const int vmax = x * y; i != vmax; i++) {
		Serch_Graph::vertex_descriptor v = add_vertex(blue_graph);
		blue_graph[v].key = i;
		blue_graph[v].x = i % x;
		blue_graph[v].y = i / x;

		Serch_Graph::vertex_descriptor v2 = add_vertex(red_graph);
		red_graph[v2].key = i;
		red_graph[v2].x = i % x;
		red_graph[v2].y = i / x;
	}

}


TwoLayersGraph::~TwoLayersGraph()
{
}

//Input_dataクラスの関数定義
Input_data::Input_data(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Error: This program needs .in file and .dat file." << endl;
		return;
	}

	//入力ファイルを読み込む
	//コマンドライン引数が.inなのか.datなのか調べる
	string str = "";
	str = argv[1];
	if ((int)str.find(".in") != -1) { //第i引数が.inファイルだった場合

		//ファイルオブジェクトを生成
		ifstream ifs(argv[1]); //ifstream : ファイルに対する入力ストリーム
		if (!ifs) {
			cout << "Error: File can not be opend" << endl;
			return;
		}
		
		//.inファイルのEOFまで１行ずつ読み込んで各ネットの座標を記録
		for (int l,m,s	; getline(ifs, str) ;) {
			
		}

		ifs.close();

	}
	else if((int)str.find(".dat") != -1) {

	}
	else {
		cout << "Error: This program needs .in file and .dat file." << endl;
		return;
	}
	
}

Input_data::~Input_data() {

}