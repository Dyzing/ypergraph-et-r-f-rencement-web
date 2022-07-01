#include "SiteWeb.h"

SiteWeb::SiteWeb()
	: siteweb(""), node_id(-1), pageRank(0.2f)
{
}

SiteWeb::SiteWeb(std::string const& sw, std::vector<int> const& viss, int const& id)
	: siteweb(sw), vec_id_siteSortant(viss), node_id(id), pageRank(0.25)
{
}

//bool SiteWeb::operator==(SiteWeb const& sw)
//{
//	if (this->siteweb == sw.siteweb &&
//		this->node_id == sw.node_id)
//	{
//		return true;
//	}
//	else
//		return false;
//}
