#ifndef RNET_H
#define RNET_H

#include <asio.hpp>

class rserver {
	public:
			rserver();
	private:
			const asio::io_context context;
};
 
#endif

