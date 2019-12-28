#include "rnet.h"
#include <asio.hpp>
#include <iostream>
#include <memory>

using asio::ip::tcp;

RServer::RServer(unsigned short port,
                 const std::function<void()> doOnConnection,
                 const std::function<void(std::error_code)> doOnError)
    : context(),
      tcpAcceptor(context, tcp::endpoint(tcp::v4(), port)),
      doOnConnection(doOnConnection),
      doOnError(doOnError) {
  std::cout << "rserver created" << std::endl;
}

RServer::~RServer() { std::cout << "rserver deleted" << std::endl; }

void RServer::DoOnConnection() const {
  if (this->doOnConnection) {
    this->doOnConnection();
  }
}

void RServer::DoOnError(const std::error_code errorCode) const {
  if (this->doOnError) {
    this->doOnError(errorCode);
  }
}

int main() {
  RServer(
      8080, []() {}, [](const std::error_code) {});
  return 0;
}
