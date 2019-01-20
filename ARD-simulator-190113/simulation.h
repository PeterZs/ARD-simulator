#pragma once
#include <vector>
#include <memory>
#include <string>
#include <SDL.h>

class Partition;
class Boundary;
class SoundSource;

class Simulation
{
	std::vector<std::shared_ptr<Partition>> partitions_;
	std::vector<std::shared_ptr<Boundary>> boundaries_;
	std::vector<std::shared_ptr<SoundSource>> sources_;

	int model_map_[10][10] = {0};

	int x_start_, x_end_;
	int y_start_, y_end_;
	int z_start_, z_end_;

	int size_x_, size_y_, size_z_;

	double duration_;

	int time_step_{ 0 };

	bool ready_;
	std::vector<Uint32> pixels_;

	struct Info
	{
		size_t num_partitions{ 0 };
		size_t num_dct_partitions{ 0 };
		size_t num_sources{ 0 };
		size_t num_boundaries{ 0 };
		std::vector<std::vector<char>> model_map;
	} info_;

public:
	static double dh_;
	static double dt_;
	static double c0_;

	Simulation(std::vector<std::shared_ptr<Partition>> &partitions, std::vector<std::shared_ptr<SoundSource>> &sources);
	~Simulation();

	void Update();

	void Info();
	//FindBoundaries();

	int size_x()
	{
		return size_x_;
	}
	int size_y()
	{
		return size_y_;
	}
	int size_z()
	{
		return size_z_;
	}
	bool ready()
	{
		return ready_;
	}
	decltype(pixels_) pixels()
	{
		return pixels_;
	}
};
