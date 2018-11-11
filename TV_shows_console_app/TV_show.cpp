#include "TV_show.h"


bool TV_show::check_if_all_ep_watched(int viewed) {
	if (current_episode + viewed == number_of_episodes) {
		set_was_watched(true);
		return true;
	}
	else {
		return false;
	}
}