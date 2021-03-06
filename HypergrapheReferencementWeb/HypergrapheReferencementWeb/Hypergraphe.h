#pragma once

#include <iostream>
#include <vector>
#include "BlocSite.h"
#include "SiteWeb.h"

class Hypergraphe
{
public:
	std::vector<BlocSite> vec_bs;
	std::vector< std::vector<SiteWeb> > vec_all_site;
	Hypergraphe();
	void Fill_vec_bs();
	void split(std::string str, char seperator, std::string res_strings[]);
	void UpdatePageRank();
	void Fill_vec_nb_arc_bloc();
	void init_vec_nab();
	void sort_vec_bs_sw();

	void toString() const;
private:

};

