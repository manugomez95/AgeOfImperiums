#include "Utils.h"

int Utils::randomRange(int start, int end) {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> distrib(start, end);
	return int(distrib(rng));
}