#include "stdafx.h"
#include "Make_TwoLayersGraph.h"
#include <fstream>
#include <string>

//using namespace std;
//using namespace boost;

//TwoLayersgraph:関数宣言

//コンストラクタ:２層グラフを作成する　１層ごとに分けた方よくね？
//x行y列の２層のグラフ グラフのは０行０列から始まることに注意
TwoLayersGraph::TwoLayersGraph(const int x, const int y, const int nets_number)
{
	Serch_Graph blue;
	blue[boost::graph_bundle].name = "blue";
	Serch_Graph red;
	red[boost::graph_bundle].name = "red";

	//頂点の追加
	std::map<int, Serch_Graph::vertex_descriptor> vertex_list; //頂点リスト 外部から参照できるように後でする
	for (int i = 0, const int vmax = x * y; i < vmax; i++) { //頂点番号は左上が0 行と列も0からカウントする
		vertex_list[i] = add_vertex(blue); //頂点を１つ追加
		blue[vertex_list[i]].key = i;	//頂点番号
		blue[vertex_list[i]].x = i % x;	//x座標
		blue[vertex_list[i]].y = i / x;	//y座標

		Serch_Graph::vertex_descriptor v2 = add_vertex(red);
		red[v2].key = i;
		red[v2].x = i % x;
		red[v2].y = i / x;
	}

	//辺を追加
	//左上
	add_edge(vertex_list[0], vertex_list[1], blue);	//青、横	
	add_edge(vertex_list[0], vertex_list[0 + x], blue);	//青、縦
	add_edge(vertex_list[0], vertex_list[1], red);	//赤、横
	add_edge(vertex_list[0], vertex_list[0 + x], red);	//赤、縦
	//右上
	add_edge(vertex_list[x-1], vertex_list[x-2], blue);	
	add_edge(vertex_list[x - 1], vertex_list[x +x], blue);
	add_edge(vertex_list[x - 1], vertex_list[x - 2], red);
	add_edge(vertex_list[x - 1], vertex_list[x + x], red);
	//右下
	add_edge(vertex_list[x*y-1], vertex_list[x*y-2], blue);
	add_edge(vertex_list[x*y - 1], vertex_list[x*y - x], blue);
	add_edge(vertex_list[x*y - 1], vertex_list[x*y - 2], red);
	add_edge(vertex_list[x*y - 1], vertex_list[x*y - x], red);
	//左下
	add_edge(vertex_list[(y-1)*x], vertex_list[(y-1)*x+1], blue);
	add_edge(vertex_list[(y - 1)*x], vertex_list[(y - 1)*x -x], blue);
	add_edge(vertex_list[(y - 1)*x], vertex_list[(y - 1)*x + 1], red);
	add_edge(vertex_list[(y - 1)*x], vertex_list[(y - 1)*x - x], red);
	//第1行
	for (int i = 1; i < x - 1; i++) {
		add_edge(vertex_list[i], vertex_list[i + 1],blue);
		add_edge(vertex_list[i], vertex_list[i + 1], red);
		add_edge(vertex_list[i], vertex_list[i + 1], blue);
	}
}

//デストラクタ:2層グラフを削除する
TwoLayersGraph::~TwoLayersGraph()
{
}

//Input_dataクラス:関数定義
Input_data::Input_data(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "Error: This program needs .in file and .dat file." << std::endl;
		return;
	}

	//入力ファイルを読み込む
	//コマンドライン引数が.inなのか.datなのか調べる
	std::string str = "";
	str = argv[1];
	if ((int)str.find(".in") != -1) { //第i引数が.inファイルだった場合

		//ファイルオブジェクトを生成
		std::ifstream ifs(argv[1]); //ifstream : ファイルに対する入力ストリーム
		if (!ifs) {
			std::cout << "Error: File can not be opend" << std::endl;
			return;
		}
		
		//.inファイルのEOFまで１行ずつ読み込んで各ネットの座標を記録
		while(getline(ifs, str)) {
			
		}
		ifs.close();
	}
	else if((int)str.find(".dat") != -1) {

	}

	else {
		std::cout << "Error: This program needs .in file and .dat file." << std::endl;
		return;
	}
	
}

Input_data::~Input_data() {

}