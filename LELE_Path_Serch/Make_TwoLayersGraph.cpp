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

//Input_data�N���X�̊֐���`
Input_data::Input_data(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Error: This program needs .in file and .dat file." << endl;
		return;
	}

	//���̓t�@�C����ǂݍ���
	//�R�}���h���C��������.in�Ȃ̂�.dat�Ȃ̂����ׂ�
	string str = "";
	str = argv[1];
	if ((int)str.find(".in") != -1) { //��i������.in�t�@�C���������ꍇ

		//�t�@�C���I�u�W�F�N�g�𐶐�
		ifstream ifs(argv[1]); //ifstream : �t�@�C���ɑ΂�����̓X�g���[��
		if (!ifs) {
			cout << "Error: File can not be opend" << endl;
			return;
		}
		
		//.in�t�@�C����EOF�܂łP�s���ǂݍ���Ŋe�l�b�g�̍��W���L�^
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