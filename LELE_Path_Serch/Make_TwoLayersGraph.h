#pragma once
#include <list>

//���_��Bundle�ݒ�
const struct Vertex
{
	int key; //���_�ԍ�
	int x;	//x���W
	int y;	//y���W
	struct Net *netnumber;	//�l�b�g�ԍ� 0�̓l�b�g�ł͂Ȃ� 
};


//�}��Bundle�ݒ�
const struct Edge {
	int weight; //�ӂ̏d��
};

//�O���t��Bundle�ݒ�
const struct Graph_Layer {
	string name;
};

//�l�b�g
typedef struct Net {
	const int net_number; //�l�b�g�[�q�̌�
	const int terminal_coordinate_x; //�[�q��x���W
	const int terminal_coordinate_y; //�[�q��y���W
	const int *next_terminal; //���̒[�q
} Net;


struct TwoLayersGraph
{
	typedef boost::adjacency_list <
		boost::listS,	//���_�̓��X�g 
		boost::vecS,	//�ӂ̓x�N�^�[
		boost::undirectedS,		//�����}
		Vertex,		//���_��Bundle�v���p�e�B
		Edge,	//�ӂ�Bundle�v���p�e�B
		Graph_Layer	//�O���t��Bundle�v���p�e�B
	> Serch_Graph;	

	TwoLayersGraph(const int x,const int y,const int nets_number);	//�i�q�O���t�̍s�Ɨ�A�l�b�g��
	~TwoLayersGraph();
};

class Input_data {
	struct Net *net_first_pointer; //�l�b�g�̒��_���w���̍ŏ��̃|�C���^
public:
	Input_data(int argc, char *argv[]);	//�R���X�g���N�g
	~Input_data();	//�f�X�g���N�^

};
