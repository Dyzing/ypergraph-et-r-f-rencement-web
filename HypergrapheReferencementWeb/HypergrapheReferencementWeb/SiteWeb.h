#pragma once

#include <iostream>
#include <vector>
#include <string>

class SiteWeb
{
public:

	std::string siteweb;
	std::vector<int> vec_id_siteSortant;
	int node_id;
	float pageRank;
	SiteWeb();
	SiteWeb(std::string const& sw, std::vector<int> const & viss, int const& id);

	//bool operator==(SiteWeb const& sw);
private:

};

