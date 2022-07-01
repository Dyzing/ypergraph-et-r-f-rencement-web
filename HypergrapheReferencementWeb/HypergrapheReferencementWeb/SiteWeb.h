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
	static int static_node_id;
	float pageRank;
	SiteWeb();
	SiteWeb(std::string const& sw, std::vector<int> const & viss);
	std::string display_vec_id_ss() const;
	void toString() const;

private:

};

