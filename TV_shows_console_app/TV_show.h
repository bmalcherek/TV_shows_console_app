#pragma once
#import "VOD.h"
#import <string>


class TV_show : public VOD {
private:
	int number_of_episodes, current_episode;
public:
	//TV_show(float, std::string, int, int, int);
	void set_number_of_episodes(int ep) { number_of_episodes = ep; }
	int get_numer_of_episodes() { return number_of_episodes; }
	void set_current_episode(int c) { current_episode = c; }
	int get_current_episode() { return current_episode; }
};