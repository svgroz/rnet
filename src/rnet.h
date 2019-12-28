#ifndef RNET_H
#define RNET_H

#include <functional>
#include <memory>
#include "asio.hpp"

class RServer {
 public:
  RServer(unsigned short port, const std::function<void()> doOnConnection,
          const std::function<void(std::error_code)> doOnError);
  virtual ~RServer();

 private:
  asio::io_context context;
  asio::ip::tcp::acceptor tcpAcceptor;
  const std::function<void()> doOnConnection;
  const std::function<void(std::error_code)> doOnError;
  virtual void DoOnConnection() const;
  virtual void DoOnError(const std::error_code error_code) const;
};

#endif
