#include "stdafx.h"
#include "Make_TwoLayersGraph.h"
#include <fstream>
#include <string>

using namespace std;
using namespace boost;

//TwoLayersgraph:関数宣言

//コンストラクタ:２層グラフを作成する　
//x行y列の２層のグラフ グラフのは０行０列から始まることに注意
TwoLayersGraph::TwoLayersGraph(const int x, const int y, const int nets_number)
{
	Serch_Graph blue;
	blue[graph_bundle].name = "blue";
	Serch_Graph red;
	red[graph_bundle].name = "red";

	//頂点の追加
	std::map<int, Serch_Graph::vertex_descriptor> desc;
	for (int i = 0, const int vmax = x * y; i < vmax; i++) { //頂点番号は左上が0 行と列も0からカウントする
		desc[i] = add_vertex(blue); //頂点を１つ追加
		blue[desc[i]].key = i;	//頂点番号
		blue[desc[i]].x = i % x;	//x座標
		blue[desc[i]].y = i / x;	//y座標

		Serch_Graph::vertex_descriptor v2 = add_vertex(red);
		red[v2].key = i;
		red[v2].x = i % x;
		red[v2].y = i / x;
	}

}

//デストラクタ:2層グラフを削除する
TwoLayersGraph::~TwoLayersGraph()
{
}

//Input_dataクラス:関数定義
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
		while(getline(ifs, str)) {
			
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