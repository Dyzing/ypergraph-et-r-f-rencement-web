#pragma once

#include <iostream>
#include <vector>
#include "SiteWeb.h"


class BlocSite
{
public:
	std::string domaine;
	int node_id_bs;
	static int static_node_id_bs;
	float outdegree;
	std::vector<SiteWeb> vec_sw;
	std::vector<int> vec_id_sw_sortant;

	BlocSite();

private:
};

