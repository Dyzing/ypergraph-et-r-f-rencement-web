#include "BlocSite.h"

int BlocSite::static_node_id_bs = 0;

BlocSite::BlocSite()
	: domaine(""), node_id_bs(static_node_id_bs++), outdegree(0.25)
{
}
