#include "stdafx.h"
#include "Make_TwoLayersGraph.h"

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
