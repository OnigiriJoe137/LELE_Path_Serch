// LELE_Path_Serch.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/graph_utility.hpp>

using namespace std;
using namespace boost;

typedef adjacency_list< vecS, vecS, directedS,no_property,property<edge_weight_t, int>> Graph;

typedef graph_traits<Graph>::vertex_descriptor Vertex;

typedef pair<int,int> Edge;

int main()
{
	//辺のリスト
	Edge links[] = {
		Edge(0,1), Edge(0,2),
		Edge(1,2), Edge(1,4),
		Edge(2,0), Edge(2,3),
		Edge(3,4), 
	};
	//各辺の距離
	//　重み
	int weights[] = {
		1, 1,
		1, 1,
		1, 1,
		1, 
	};
	const size_t nEdges = sizeof(links)/sizeof(*links);
	
	//５点のグラフを構築
	Graph g( links, links+nEdges, weights, 5 );

	Vertex p[5] = { 0 };

	Vertex s = 0;
	dijkstra_shortest_paths(g, s, visitor(make_dijkstra_visitor(record_predecessors(p, on_edge_relaxed()))));

	cout << "shortest paths tree" << endl;


	adjacency_list<> tree(5);
	graph_traits<Graph>::vertex_iterator vi, vend;
	for( tie(vi, vend) = vertices(g); vi!=vend; ++vi){
		if( *vi != p[*vi] ){
			add_edge( p[*vi], *vi, tree);
		}
	}
	print_graph(tree);
    return 0;
}
