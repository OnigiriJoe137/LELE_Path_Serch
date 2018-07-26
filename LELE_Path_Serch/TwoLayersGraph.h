#pragma once
class TwoLayersGraph
{
	const int x;
	const int y;
	const int net;
public:
	TwoLayersGraph();
	~TwoLayersGraph();
	int get_xy_coordinates(int key);
};
